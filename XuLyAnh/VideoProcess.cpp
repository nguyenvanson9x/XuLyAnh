#include "VideoProcess.h"


//using namespace cv;
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

void XuLyAnh::VideoProcess::_HarmonicMean(const Mat & src, Mat & dst)
{

}

void VideoProcess::ContraharmonicMean(System::String ^ path, int times)
{
	int i, j;
	VideoCapture cap(toString(path)); // open the video
	if (!cap.isOpened()) // check if we succeeded
		cout << "Can't load video ";
	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame
		if (frame.empty())
			break;
		std::vector<cv::Mat> frame_gray;
		for (i = 0; i < frame.channels(); i++)
		{
			Mat dst;
			extractChannel(frame, dst, i);
			frame_gray.push_back(dst);
		}
		for (i = 0; i < times; i++)
			for (j = 0; i < frame.channels(); j++)
				_ContraharmonicMean(frame_gray[i], frame_gray[i], 3, -2);
		cv::merge(frame_gray, frame);
		imshow("Out", frame);
		if (waitKey(30) >= 0) break;
	}
}
//!TO-DO _ContraharmonicMean Filter là b? l?c dùng ?? kh? nhi?u, ch? dùng vs image 8bit - 24bit lo?i nhi?u gaussian
void VideoProcess::_ContraharmonicMean(const Mat &src, Mat &dst, int kernel, double P) // kernel là kích th??c ma tr?n m?t n?, P là giá tr? ?? chính xác dùng trong ph??ng trình d??i
{
	Mat temp = src.clone();
	for (int row = kernel / 2; row < temp.rows - kernel / 2 - 1; row++)
	{
		for (int col = kernel / 2; col < temp.cols - kernel / 2 - 1; col++)
		{
			double den = 0, num = 0;
			for (int i = -(kernel / 2); i <= (kernel / 2); i++)
			{
				for (int j = -(kernel / 2); j <= (kernel / 2); j++)
				{
					den += pow(temp.at<uchar>(row + i, col + j), P);
					num += pow(temp.at<uchar>(row + i, col + j), P + 1);
				}
			}
			dst.at<uchar>(row, col) = num / den;
		}
	}
	dst.convertTo(dst, CV_8U);
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

			Mat bgr[3];
			split(frame, bgr);
			double *image = (double*)frame.data;

			double *result = image;

			int alpha = 4;

			for (i = 0; i < times; i++) {
				// denoise image
				//alphatrimmedmeanfilter(image, result, frame.cols, frame.rows, alpha);
				alphatrimmed(frame, alpha);
			}
			//imshow("Out", bgr[1]);
			if (waitKey(30) >= 0) break;
		}
	}
}

void VideoProcess::MidpointFilter(System::String ^ path, int times)
{
	CvCapture* capture = cvCreateFileCapture(toChar(path));
	IplImage* frame;
	int i;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("Original", frame);
		// for max filter
		IplImage *dstMax = cvCreateImage(cvSize(frame->width, frame->height), frame->depth, 3);
		// for min filter
		IplImage *dstMin = cvCreateImage(cvSize(frame->width, frame->height), frame->depth, 3);
		// for result
		IplImage *dst = cvCreateImage(cvSize(frame->width, frame->height), frame->depth, 3);
		Mat result;
		for (i = 0; i < times; i++) {
			cvDilate(frame, dstMax, NULL, 1);
			cvErode(frame, dstMin, NULL, 1);
			cvAdd(dstMax, dstMin, dst, NULL);
			result = cvarrToMat(dst);
			result /= 2;
		}
		imshow("Result_Midpoint", result);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}

void XuLyAnh::VideoProcess::MaxMinFilter(System::String ^ path, int times)
{
	CvCapture* capture = cvCreateFileCapture(toChar(path));
	IplImage* frame;
	int i;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("Original", frame);
		IplImage *dstMax = cvCreateImage(cvSize(frame->width, frame->height), frame->depth, 3);
		for (i = 0; i < times; i++)
			cvDilate(frame, dstMax, NULL, 1);
		cvShowImage("Result_Max", dstMax);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}

void XuLyAnh::VideoProcess::MedianFilter(System::String ^ path, int times)
{
	int i;
	VideoCapture cap(toString(path)); // open the video
	if (!cap.isOpened()) // check if we succeeded
		cout << "Can't load video ";
	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame
		if (frame.empty())
			break;
		for (i = 0; i < times; i++)
			medianBlur(frame, frame, 3); //  3 là size ma tr?n m?t n? 
		imshow("Out", frame);
		if (waitKey(30) >= 0) break;
	}
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
	for (int i = 0; i < M; i++)
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

int XuLyAnh::VideoProcess::alphatrimmed(Mat img, int alpha)
{
	Mat img9 = img.clone();
	const int start = alpha >> 1;
	const int end = 9 - (alpha >> 1);

	//going through whole image
	for (int i = 1; i < img.rows - 1; i++)
	{
		for (int j = 1; j < img.cols - 1; j++)
		{
			uchar element[9];
			Vec3b element3[9];
			int k = 0;
			int a = 0;
			//selecting elements for window 3x3
			for (int m = i - 1; m < i + 2; m++)
			{
				for (int n = j - 1; n < j + 2; n++)
				{
					element3[a] = img.at<Vec3b>(m*img.cols + n);
					a++;
					for (int c = 0; c < img.channels(); c++)
					{
						element[k] += img.at<Vec3b>(m*img.cols + n)[c];
					}
					k++;
				}
			}
			//comparing and sorting elements in window (uchar element [9])
			for (int b = 0; b < end; b++)
			{
				int min = b;
				for (int d = b + 1; d < 9; d++)
				{
					if (element[d] < element[min])
					{
						min = d;
						const   uchar temp = element[b];
						element[b] = element[min];
						element[min] = temp;
						const   Vec3b temporary = element3[b];
						element3[b] = element3[min];
						element3[min] = temporary;
					}
				}

			}

			//  index in resultant image( after alpha-trimmed filter)
			int result = (i - 1) * (img.cols - 2) + j - 1;
			for (int l = start; l < end; l++)
				img9.at<Vec3b>(result) += element3[l];
			img9.at<Vec3b>(result) /= (9 - alpha);
		}
	}
	namedWindow("AlphaTrimmed Filter", WINDOW_AUTOSIZE);
	imshow("AlphaTrimmed Filter", img9);
	return 0;
}
#pragma endregion

