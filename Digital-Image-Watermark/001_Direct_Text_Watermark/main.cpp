#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("./image/wallhaven-21738.jpg");
	imshow("原始图像", img);

	string text = "Yuxfei!";  // 水印文字
	double textSize = 3.0;    // 文字大小
	int colorNum = 128;       // 文字颜色
	int textWidth = 3;        // 文字宽度

	putText(img, text, cv::Point(img.cols * 0.1111, img.rows * 0.8888),
		cv::FONT_HERSHEY_PLAIN, textSize, cv::Scalar(colorNum, colorNum, colorNum), textWidth);

	imshow("水印图像", img);
	imwrite("./image/wallhaven-21738-watermark.jpg", img);

	waitKey(0);
	return 0;
}
