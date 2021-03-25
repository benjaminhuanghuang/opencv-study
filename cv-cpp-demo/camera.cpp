#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
  VideoCapture cap;
  cap.open(0, cv::CAP_ANY);
  if (!cap.isOpened())
  {
    cerr << "ERROR! Unable to open camera\n";
    return -1;
  }
  Mat frame;

  while (1)
  {
    cap.read(frame);
    // check if we succeeded
    if (frame.empty())
    {
      cerr << "ERROR! blank frame grabbed\n";
      break;
    }
    imshow("Live", frame);
    waitKey(1);
  }
  return 0;
}
