#include "opencv.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
using namespace std;

int test1()
{
	Mat Mat_img;
	Mat color;
	Mat image_gray, dst1, dst2, dst3, dst4;
	Mat kernel1, kernel2, kernel3, kernel4;
	IplImage* image = 0; //openCV에서 사용되는 자료형이다.

	/*
	VideoCapture capture;
	if(!capture.open("http://143.248.218.23:8080/video?x.mjpeg"))
	{
	std::cout<<"nononono";
	return 0;
	}
	*/


	CvCapture* capture = cvCaptureFromCAM(0); //현재 인식된 웹캠을 찾고,

	namedWindow("Display window", WINDOW_NORMAL);
	//cvNamedWindow( "OpenCvCamtest", 0 ); // 화면을 그려줄 윈도우를 생성한다.
	//cvResizeWindow( "OpenCvCamtest", 320, 240 ); // 사이즈를 조절한다.(lpIImage를 할당하면서도 조절가능)

	/// Initialize arguments for the filter
	Point anchor = Point(-1, -1);
	double delta = 0;
	int ddepth = -1;
	int kernel_size = 4;

	kernel1 = Mat(4, 4, CV_32F);
	for (int i = 0; i < 4; i++)
	{
		kernel1.at<float>(0, i) = 1;
	}

	for (int i = 0; i < 4; i++)
	{
		kernel1.at<float>(1, i) = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		kernel1.at<float>(2, i) = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		kernel1.at<float>(3, i) = -1;
	}

	kernel2 = Mat(4, 4, CV_32F);
	for (int i = 0; i < 4; i++)
	{
		kernel2.at<float>(0, i) = -1;
	}

	for (int i = 0; i < 4; i++)
	{
		kernel2.at<float>(1, i) = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		kernel2.at<float>(2, i) = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		kernel2.at<float>(3, i) = 1;
	}

	kernel3 = Mat(4, 4, CV_32F);
	for (int i = 0; i < 4; i++)
	{
		kernel3.at<float>(i, 0) = -1;
	}

	for (int i = 0; i < 4; i++)
	{
		kernel3.at<float>(i, 1) = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		kernel3.at<float>(i, 2) = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		kernel3.at<float>(i, 3) = 1;
	}

	kernel4 = Mat(4, 4, CV_32F);
	for (int i = 0; i < 4; i++)
	{
		kernel4.at<float>(i, 0) = 1;
	}

	for (int i = 0; i < 4; i++)
	{
		kernel4.at<float>(i, 1) = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		kernel4.at<float>(i, 2) = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		kernel4.at<float>(i, 3) = -1;
	}


	while (1) {
		cvGrabFrame(capture);
		image = cvRetrieveFrame(capture); // 현재 인식된 장면을 받아오고image에 넣는다.
		Mat_img = cvarrToMat(image);
		//if(!capture.read(Mat_img))
		//   std::cout<<"nono";
		resize(Mat_img, color, Size(), 0.1, 0.1);//scalex, scaley
		cv::cvtColor(color, image_gray, CV_RGB2GRAY);

		//kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);

		/// Apply filter



		filter2D(image_gray, dst1, ddepth, kernel1, anchor, delta, BORDER_DEFAULT);
		filter2D(image_gray, dst2, ddepth, kernel2, anchor, delta, BORDER_DEFAULT);
		filter2D(image_gray, dst3, ddepth, kernel3, anchor, delta, BORDER_DEFAULT);
		filter2D(image_gray, dst4, ddepth, kernel4, anchor, delta, BORDER_DEFAULT);


		imshow("1", dst1);
		imshow("2", dst2);
		imshow("3", dst3);
		imshow("4", dst4);
		imshow("origin", Mat_img);
		waitKey(1);

		//cvShowImage( "OpenCvCamtest", image ); // image에 있는 장면을 윈도우에 그린다.
		//if( cvWaitKey(10) >= 0 ) // 이게 가장 중요한데 이 WaitKey 함수가 없으면 아무 것도 안그린다.
		//    break;
	}
	//cvReleaseCapture( &capture ); // 할당받았던 웹캠을 해제하고,
	//cvDestroyWindow( "OpenCvCamtest" ); // 윈도우를 종료한다.
}
/*
int test1(){
	cv::Mat image; // create an empty image

	image = cv::imread("D:\\opencv\\build\\doc\\opencv-logo.png"); // read an input image

	// define the window (optional)
	cv::namedWindow("Original Image");
	// show the image
	cv::imshow("Original Image", image);

	cv::waitKey(0); // 0 to indefinitely wait for a key pressed
	// specifying a positive value will wait for
	// the given amount of msec

	return 0;
}
*/