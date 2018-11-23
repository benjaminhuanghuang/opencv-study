import numpy as np
import cv2
# print(cv2.__version__)

# Open camera
capture = cv2.VideoCapture(0)

# Read video
cv2.namedWindow("camera video")
while True:
  # read frame
  ret, frame = capture.read()
  # display pic
  cv2.imshow('my camare', frame)

  if cv2.waitKey(5) & 0xFF == ord('q'):
    break

capture.release()

cv2.destroyAllWindows()