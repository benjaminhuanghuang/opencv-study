#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
  VideoCapture cap;
  int deviceID = 0;        // 0 = open default camera
  int apiID = cv::CAP_ANY; // 0 = autodetect default API
  cap.open(deviceID, apiID);

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
