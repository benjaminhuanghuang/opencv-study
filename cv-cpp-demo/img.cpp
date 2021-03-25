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
  Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
  Mat imgDia;
  dilate(imgCanny, imgDia, kernel);
  imshow("Image Dilation", imgDia);

  //========== Erosion
  Mat imgErode;
  erode(imgDia, imgErode, kernel);
  imshow("Image Erode", imgErode);

  //=========== Resize
  Mat imgResize;
  //resize(img, imgResize, Size(200,300));

  resize(img, imgResize, Size(), 0.5, 0.5);
  imshow("Resize", imgResize);

  //=========== Clip
  Rect rect(200, 200, 150, 150);
  Mat imgClip = img(rect);

  imshow("Crop", imgClip);


  //============ Warp 
  float w = 250, h = 350;
  Point2f src[4]= {{519, 142}, {771,190}, {405, 395}, {674, 457}};
  Point2f dst[4]= {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w,h}};
  Mat matrix = getPerspectiveTransform(src, dst);
  Mat imgWarp;
  warpPerspective(img, imgWarp, matrix, Point(w, h));
  imshow("Img Warp", imgWarp);

  waitKey(5000); // 0 means infinite
  return 0;
}
