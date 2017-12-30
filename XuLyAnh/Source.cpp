#include "MyForm.h"

using namespace XuLyAnh;

[STAThreadAttribute]
int main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());

	//VideoCapture cap("D:\\RELAX\\Picture\\Camera\\20130331_131548.mp4"); // open the default camera
	//if (!cap.isOpened())  // check if we succeeded
	//	return -1;

	//Mat edges;
	//namedWindow("edges", 1);
	//for (;;)
	//{
	//	Mat frame;
	//	cap >> frame; // get a new frame from camera
	//	cvtColor(frame, edges, COLOR_BGR2GRAY);
	//	//GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
	//	//Canny(edges, edges, 0, 30, 3);
	//	imshow("edges", frame);
	//	if (waitKey(30) >= 0) break;
	//}
	return 0;
}