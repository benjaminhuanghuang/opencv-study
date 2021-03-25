
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

void getContours(Mat imgDil, Mat img)
{
  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;

  findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
  drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
}

int main()
{
  string path = "ufc.jpeg";
  Mat img = imread(path);

  Mat imgGray, imgBlur, imgCanny, imgDia, imgErode;

  cvtColor(img, imgGray, COLOR_BGR2GRAY);

  GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);

  Canny(imgBlur, imgCanny, 50, 150);

  Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
  dilate(imgCanny, imgDia, kernel);

  getContours(imgDia, img);

  imshow("Img", img);
  waitKey(0); // 0 means infinite

  return 0;
}