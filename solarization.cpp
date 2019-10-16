#define _USE_MATH_DEFINES
#include <cmath>



#include <opencv2/core.hpp>
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/types.hpp>
#include <iostream>
#include "Header.h"

using namespace std;
using namespace cv;

int main()
{
	
	/*
	//adaptive threshold;
	cv::Mat img = cv::imread("No.2-21(NG) (Custom).jpg", IMREAD_GRAYSCALE);
	adapt(img);
	*/

	//input image;
	cv::Mat img = cv::imread("No.2-21(NG) (Custom).jpg", IMREAD_GRAYSCALE);

	//solarization constant;
	double solar_const = 2 * M_PI / 255;

	//lookup table;
	vector<uint8_t> lut;

	for (size_t i = 0; i != 256; ++i)
	{
		lut.push_back((uint8_t)(100 * sin((solar_const)*i) + i));
	}

	//solarize;
	cv::Mat solarized;
	cv::LUT(img, lut, solarized);

	//print;
	cv::namedWindow("solarized", WINDOW_NORMAL);
	cv::resizeWindow("solarized", 520, 340);
	cv::imshow("solarized", solarized);

	//output;
	cv::imwrite("solarized.jpg", solarized);

	waitKey(-1);


	/*
	//Median blur
	cv::Mat blurred;
	cv::medianBlur(img, blurred, 75);
	cv::namedWindow("blur", WINDOW_NORMAL);
	cv::resizeWindow("blur", 520, 340);
	cv::imshow("blur", blurred);

	cv::Mat canny;

	// compute canny (don't blur with that image quality!!)
	cv::Canny(blurred, canny, 200, 20);
	cv::namedWindow("canny2", WINDOW_NORMAL); 
	cv::resizeWindow("canny2", 520, 340);
	cv::imshow("canny2", canny > 0);

	cv::waitKey(-1);
	return 0;
	*/


	/*
	cv::Mat reduced;
	cv::threshold(blurred, reduced, 100, 255, THRESH_BINARY);
	cv::namedWindow("reduced reflection", WINDOW_NORMAL);
	cv::resizeWindow("reduced reflection", 520, 340);
	cv::imshow("reduced reflection", reduced);
	cv::waitKey(-1);
	return 0;
	*/


}