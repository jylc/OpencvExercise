// RobustImageStitching.cpp: 定义应用程序的入口点。
//

#include "RobustImageStitching.h"
#include <opencv2/opencv.hpp>
using namespace std;

int main()
{
	cv::Mat left_img, right_img;
	left_img = cv::imread("./images/001/001.JPG", cv::IMREAD_UNCHANGED);
	right_img = cv::imread("./images/001/002.JPG", cv::IMREAD_UNCHANGED);
	if (!left_img.empty() && !right_img.empty())
	{
		cv::imshow("001", left_img);
		cv::imshow("002", right_img);
	}
	
	cout << "Hello CMake." << endl;
	cv::waitKey();
	return 0;
}
