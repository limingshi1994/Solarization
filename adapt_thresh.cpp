#include <opencv2/core.hpp>
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/types.hpp>
#include <iostream>

using namespace std;
using namespace cv;

cv::Mat adapt(cv::Mat& m)
{
	cv::Mat res;

	cv::adaptiveThreshold(m, res, 255, ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 55, -10);

	cv::namedWindow("adpt", WINDOW_GUI_NORMAL);
	cv::imshow("adpt", res);
	cv::imwrite("adpt.jpg", res);
	waitKey(-1);
	return res;
}