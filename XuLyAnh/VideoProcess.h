#pragma once
#include <iostream>
#include <vcclr.h>
using namespace std;

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
		void ContraharmonicMean(System::String^ path, int times);

		void AlphaTrimmed(System::String^ path, int times);
		void MidpointFilter(System::String^ path, int times);
		void MaxMinFilter(System::String^ path, int times);
		void MedianFilter(System::String^ path, int times);

		string toString(System::String ^ s);
		const char* toChar(System::String ^s);
	};

}

