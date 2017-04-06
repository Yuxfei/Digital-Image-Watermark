#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("./image/wallhaven-21738.jpg");
	imshow("ԭʼͼ��", img);

	string text = "Yuxfei!";
	double textSize = 3.0;
	int colorNum = 128;
	int textWidth = 3;

	putText(img, text, cv::Point(img.cols * 0.1111, img.rows * 0.8888),
		cv::FONT_HERSHEY_PLAIN, textSize, cv::Scalar(colorNum, colorNum, colorNum), textWidth);

	imshow("ˮӡͼ��", img);

	waitKey(0);
	return 0;
}