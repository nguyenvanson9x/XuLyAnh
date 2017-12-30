#pragma once

namespace XuLyAnh {
	using namespace System;
	public ref class VideoProcess
	{
	public:
		VideoProcess();
		void ArithmeticMean(System::String^ path);
		void GeometricMean(System::String^ path);
		void HarmonicMean(System::String^ path);
		void ContraharmonicMean(System::String^ path);

		void AlphaTrimmed(System::String^ path);
		void MidpointFilter(System::String^ path);
		void MaxMinFilter(System::String^ path);
		void MedianFilter(System::String^ path);
	};

}

