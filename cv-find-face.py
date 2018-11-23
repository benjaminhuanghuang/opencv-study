'''
  1. import opencv
  2. load image
  3. load model
  4. adjuct image gray
  5. Check and mark face
  3. create window
  4. show image
  5. pause window
  6. close window
'''

import numpy as np
import cv2
# print(cv2.__version__)

# Load image
img = cv2.imread("./images/ufc.jpeg")

# Load model
face_cascade = cv2.CascadeClassifier(
    './data/haarcascade_frontalface_default.xml')

# Adjust image gray
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# find faces
faces = face_cascade.detectMultiScale(
    gray,
    # scaleFactor=1.15,
    # minNeighbors=5,
    # minSize=(5, 5),
    #   flags = cv2.HAAR_SCALE_IMAGE
)

# Mark faces
for(x, y, w, h) in faces:
    # image, location, size, color, line width
    cv2.rectangle(img, (x, y), (x+w, y+w), (0, 255, 0), 2)

# Create widnow
cv2.namedWindow("faceImage")

# Show image
cv2.imshow('ufc show', img)

#
cv2.waitKey(0)

cv2.destroyAllWindow()
