
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
  string path = "ufc.jpeg";
  Mat img = imread(path);

  int hmin = 0, smin = 110, vmin = 153;
  int hmax = 19, smax = 240, vmax = 255;

  namedWindow("Trackbars", (640, 200));
  createTrackbar("Hue min", "Trackbars", &hmin, 179);
  createTrackbar("Hue max", "Trackbars", &hmax, 179);
  createTrackbar("Sat min", "Trackbars", &smin, 179);
  createTrackbar("Sat max", "Trackbars", &smax, 179);
  createTrackbar("Val min", "Trackbars", &vmin, 179);
  createTrackbar("Val max", "Trackbars", &vmax, 179);

  //====
  Mat imgHSV, mask;
  cvtColor(img, imgHSV, COLOR_BGR2HSV);   

  Scalar lower(hmin, smin, vmin);
  Scalar upper(hmax, smax, vmax);

  inRange(imgHSV, lower, upper, mask);

  imshow("Img", img);
  imshow("Img HSV", imgHSV);
  imshow("Img Mask", mask);
  waitKey(0); // 0 means infinite

  return 0;
}