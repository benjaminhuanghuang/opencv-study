'''
  1. import opencv
  2. load image
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

# Create widnow
cv2.namedWindow("faceImage")

# Show image
cv2.imshow('ufc show', img)

#
cv2.waitKey(0)

cv2.destroyAllWindow()
