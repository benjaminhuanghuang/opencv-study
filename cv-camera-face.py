import numpy as np
import cv2
# print(cv2.__version__)


# Load model
face_cascade = cv2.CascadeClassifier(
    './data/haarcascade_frontalface_default.xml')
# Open camera
capture = cv2.VideoCapture(0)

# Read video
cv2.namedWindow("camera video")
while True:
  # read frame
  ret, frame = capture.read()
  #
  gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

  # find faces
  faces = face_cascade.detectMultiScale(gray)

  # Mark faces
  for(x, y, w, h) in faces:
      # image, location, size, color, line width
      cv2.rectangle(frame, (x, y), (x+w, y+w), (0, 255, 0), 2)
      # display pic
      cv2.imshow('my camare', frame)

  if cv2.waitKey(5) & 0xFF == ord('q'):
    break

capture.release()

cv2.destroyAllWindows()
