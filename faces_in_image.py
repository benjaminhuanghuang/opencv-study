'''
    From: https://techtutorialsx.com/2017/05/02/python-opencv-face-detection-and-counting/
'''

import numpy as np
import cv2
print(cv2.__version__)

# load the classifier with the CascadeClassifier function of the cv2 module, which receives 
# as input the path to the classifier file.
# https://github.com/opencv/opencv/tree/master/data/haarcascades
IMAGE_PATH = '/Users/bhuang/ben-github/opencv-study/imags/ufc.jpeg'
face_cascade = cv2.CascadeClassifier('./data/haarcascade_frontalface_default.xml')

image = cv2.imread(IMAGE_PATH) 
gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)

faces = face_cascade.detectMultiScale(
  gray,
  scaleFactor = 1.15,
  minNeighbors = 5,
  minSize = (5,5),
#   flags = cv2.HAAR_SCALE_IMAGE
)

# 处理人脸探测的结果
print ("Found {0} faces!".format(len(faces)))
for(x,y,w,h) in faces:
    cv2.rectangle(image,(x,y),(x+w,y+w),(0,255,0),2)
    # cv2.circle(image,((x+x+w)/2,(y+y+h)/2),w/2,(0,255,0),2)

cv2.imshow("image",image)
cv2.waitKey(0)
cv2.destroyAllWindows()