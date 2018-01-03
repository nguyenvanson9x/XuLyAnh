#include "MyForm.h"

using namespace XuLyAnh;

[STAThreadAttribute]
int main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
	return 0;
}