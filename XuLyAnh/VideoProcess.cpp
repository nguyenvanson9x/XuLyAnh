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
			Vec3b v = frame.at<Vec3b>(3, 3);
			cout << (double)v.val[1] << " " << (double)v.val[2] << " " << (double)v.val[3] << endl;
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
			Vec3b v = frame.at<Vec3b>(3, 3);
			cout << (double)v.val[1] << " " << (double)v.val[2] << " " << (double)v.val[3] << endl;
			for (i = 0; i < times; i++)
				blur(frame, frame, cvSize(5, 5), cvPoint(-1, -1));
			imshow("Out", frame);
			if (waitKey(30) >= 0) break;
		}
	}
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


#pragma region Utility Method

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

void XuLyAnh::VideoProcess::alphatrimmedmeanfilter(double * image, double * result, int N, int M, int alpha)
{
	//   Check arguments
	if (!image || N < 1 || M < 1 || alpha < 0 || 8 < alpha || alpha & 1)
		return;
	//   Allocate memory for signal extension
	double* extension = new double[(N + 2) * (M + 2)];
	//   Check memory allocation
	if (!extension)
		return;
	//   Create image extension
	for (int i = 0; i < M; ++i)
	{
		memcpy(extension + (N + 2) * (i + 1) + 1, image + N * i, N * sizeof(double));
		extension[(N + 2) * (i + 1)] = image[N * i];
		extension[(N + 2) * (i + 2) - 1] = image[N * (i + 1) - 1];
	}
	//   Fill first line of image extension
	memcpy(extension, extension + N + 2, (N + 2) * sizeof(double));
	//   Fill last line of image extension
	memcpy(extension + (N + 2) * (M + 1), extension + (N + 2) * M, (N + 2) * sizeof(double));
	//   Call alpha-trimmed mean filter implementation
	_alphatrimmedmeanfilter(extension, result ? result : image, N + 2, M + 2, alpha);
	//   Free memory
	delete[] extension;
}

void XuLyAnh::VideoProcess::_alphatrimmedmeanfilter(const double* image, double* result, int N, int M, int alpha)
{
	//   Start of the trimmed ordered set
	const int start = alpha >> 1;
	//   End of the trimmed ordered set
	const int end = 9 - (alpha >> 1);
	//   Move window through all elements of the image
	for (int m = 1; m < M - 1; ++m)
		for (int n = 1; n < N - 1; ++n)
		{
			//   Pick up window elements
			int k = 0;
			double window[9];
			for (int j = m - 1; j < m + 2; ++j)
				for (int i = n - 1; i < n + 2; ++i)
					window[k++] = image[j * N + i];
			//   Order elements (only necessary part of them)
			for (int j = 0; j < end; ++j)
			{
				//   Find position of minimum element
				int min = j;
				for (int l = j + 1; l < 9; ++l)
					if (window[l] < window[min])
						min = l;
				//   Put found minimum element in its place
				const double temp = window[j];
				window[j] = window[min];
				window[min] = temp;
			}
			//   Target index in result image
			const int target = (m - 1) * (N - 2) + n - 1;
			//   Get result - the mean value of the elements in trimmed set
			result[target] = window[start];
			for (int j = start + 1; j < end; ++j)
				result[target] += window[j];
			result[target] /= 9 - alpha;
		}
}

#pragma endregion

