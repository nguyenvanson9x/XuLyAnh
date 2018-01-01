#include "VideoProcess.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace XuLyAnh;
VideoProcess::VideoProcess()
{
}

void VideoProcess::ArithmeticMean(System::String ^path, int times)
{
	int i;
	VideoCapture cap(toString(path)); // open the video
	if (cap.isOpened()) {  // check if we succeeded
		Mat edges;
		namedWindow("edges", 1);
		for (;;)
		{
			Mat frame, dest;
			cap >> frame; // get a new frame
			if (frame.empty())
				break;
			for (i = 0; i < times; i++)
				blur(frame, frame, cvSize(5, 5), cvPoint(-1, -1));
			imshow("Out", frame);
			if (waitKey(30) >= 0) break;
		}
	}


}

void VideoProcess::GeometricMean(System::String ^ path, int times)
{
}

void VideoProcess::HarmonicMean(System::String ^ path, int times)
{
}

void VideoProcess::ContraharmonicMean(System::String ^ path, int times)
{
}

void VideoProcess::AlphaTrimmed(System::String ^ path, int times)
{
}

void VideoProcess::MidpointFilter(System::String ^ path, int times)
{
}

void XuLyAnh::VideoProcess::MaxMinFilter(System::String ^ path, int times)
{
}

void XuLyAnh::VideoProcess::MedianFilter(System::String ^ path, int times)
{
}

string XuLyAnh::VideoProcess::toString(System::String ^ s) {
	string os;
	const char* chars = toChar(s);
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

const char * XuLyAnh::VideoProcess::toChar(System::String ^ s)
{
	return (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
}
