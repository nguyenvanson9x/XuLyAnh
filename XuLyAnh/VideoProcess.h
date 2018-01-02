#pragma once
#include <iostream>
#include <vcclr.h>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
namespace XuLyAnh {
	using namespace System;
	using namespace Runtime::InteropServices;
	public ref class VideoProcess
	{
	public:
		VideoProcess();
		void ArithmeticMean(System::String^ path, int times);
		void GeometricMean(System::String^ path, int times);
		void HarmonicMean(System::String^ path, int times);
		void _HarmonicMean(const Mat &src, Mat &dst);
		void ContraharmonicMean(System::String^ path, int times);
		void _ContraharmonicMean(const Mat &src, Mat &dst, int kernel, double P);

		void AlphaTrimmed(System::String ^path, int times);
		void MidpointFilter(System::String ^path, int times);
		void MaxMinFilter(System::String ^path, int times);
		void MedianFilter(System::String ^path, int times);

		string toString(System::String ^ s);
		const char* toChar(System::String ^s);
		void alphatrimmedmeanfilter(double* image, double* result, int N, int M, int alpha);
		void _alphatrimmedmeanfilter(const double* image, double* result, int N, int M, int alpha);
		int alphatrimmed(Mat img, int alpha);
	};

}

