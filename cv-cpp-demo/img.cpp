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
  imshow("Image", img);

  //========== Gray
  Mat imgGray;
  cvtColor(img, imgGray, COLOR_BGR2GRAY);
  imshow("Image Gray", imgGray);

  //========== Blur
  Mat imgBlur;
  GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
  imshow("Image Blur", imgBlur);

  //========== Canny
  Mat imgCanny;
  Canny(imgBlur, imgCanny, 50, 150);
  imshow("Image Canny", imgCanny);

  //========== Dilate
  Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
  Mat imgDia;
  dilate(imgCanny, imgDia, kernel);
  imshow("Image Dilation", imgDia);

  //========== Erosion
  Mat imgErode;
  erode(imgDia, imgErode, kernel);
  imshow("Image Erode", imgErode);
  waitKey(5000); // 0 means infinite
  return 0;
}
