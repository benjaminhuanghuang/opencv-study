#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char **argv)
{
    std::string image_path = "car.jpg";
    Mat image = imread(image_path, IMREAD_COLOR);
    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}
