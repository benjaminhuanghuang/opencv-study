#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
  string path = "../resources/sample.mp4";

  VideoCapture cap(path);

  Mat img;
  while(true){
    cap.read(img);
    imshow("Video", img);
    waitKey(100);
    
  }
  waitKey(5000); // 0 means infinite
  return 0;
}
