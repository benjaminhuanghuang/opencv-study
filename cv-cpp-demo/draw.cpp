#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
  Mat img(512, 512, CV_8UC3, Scalar(255, 0, 0));

  circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);

  rectangle(img, Point(130, 226), Point(386, 286), Scalar(255, 255, 255), 3);

  line(img, Point(130, 226), Point(386, 286), Scalar(255, 255, 255), 2);

  putText(img, "Hello", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);

  imshow("Image", img);

  waitKey(5000); // 0 means infinite

  return 0;
}
