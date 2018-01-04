#pragma once
#include "VideoProcess.h"
namespace XuLyAnh {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  pnControl;
	private: System::Windows::Forms::Button^  btnSelectFile;
	private: System::Windows::Forms::Label^  lbPath;
	private: System::Windows::Forms::Label^  lbPhuongPhap;
	private: System::Windows::Forms::ComboBox^  cbPhuongPhap;
	private: System::Windows::Forms::Label^  lbSoLanChay;
	private: System::Windows::Forms::NumericUpDown^  txtSoLanChay;
	private: System::Windows::Forms::Button^  btnThucHien;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::String ^path;
		int times = 0;
		int method = -1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnControl = (gcnew System::Windows::Forms::Panel());
			this->btnThucHien = (gcnew System::Windows::Forms::Button());
			this->txtSoLanChay = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbSoLanChay = (gcnew System::Windows::Forms::Label());
			this->cbPhuongPhap = (gcnew System::Windows::Forms::ComboBox());
			this->lbPhuongPhap = (gcnew System::Windows::Forms::Label());
			this->lbPath = (gcnew System::Windows::Forms::Label());
			this->btnSelectFile = (gcnew System::Windows::Forms::Button());
			this->pnControl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtSoLanChay))->BeginInit();
			this->SuspendLayout();
			// 
			// pnControl
			// 
			this->pnControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnControl->BackColor = System::Drawing::SystemColors::Control;
			this->pnControl->Controls->Add(this->btnThucHien);
			this->pnControl->Controls->Add(this->txtSoLanChay);
			this->pnControl->Controls->Add(this->lbSoLanChay);
			this->pnControl->Controls->Add(this->cbPhuongPhap);
			this->pnControl->Controls->Add(this->lbPhuongPhap);
			this->pnControl->Controls->Add(this->lbPath);
			this->pnControl->Controls->Add(this->btnSelectFile);
			this->pnControl->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pnControl->Location = System::Drawing::Point(12, 12);
			this->pnControl->Name = L"pnControl";
			this->pnControl->Size = System::Drawing::Size(920, 477);
			this->pnControl->TabIndex = 1;
			// 
			// btnThucHien
			// 
			this->btnThucHien->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnThucHien->Location = System::Drawing::Point(16, 374);
			this->btnThucHien->Name = L"btnThucHien";
			this->btnThucHien->Size = System::Drawing::Size(100, 40);
			this->btnThucHien->TabIndex = 6;
			this->btnThucHien->Text = L"Run";
			this->btnThucHien->UseVisualStyleBackColor = true;
			this->btnThucHien->Click += gcnew System::EventHandler(this, &MyForm::btnThucHien_Click);
			// 
			// txtSoLanChay
			// 
			this->txtSoLanChay->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSoLanChay->Location = System::Drawing::Point(83, 291);
			this->txtSoLanChay->Name = L"txtSoLanChay";
			this->txtSoLanChay->Size = System::Drawing::Size(196, 33);
			this->txtSoLanChay->TabIndex = 5;
			this->txtSoLanChay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// lbSoLanChay
			// 
			this->lbSoLanChay->AutoSize = true;
			this->lbSoLanChay->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbSoLanChay->Location = System::Drawing::Point(16, 293);
			this->lbSoLanChay->Name = L"lbSoLanChay";
			this->lbSoLanChay->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->lbSoLanChay->Size = System::Drawing::Size(61, 25);
			this->lbSoLanChay->TabIndex = 4;
			this->lbSoLanChay->Text = L"Times";
			// 
			// cbPhuongPhap
			// 
			this->cbPhuongPhap->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbPhuongPhap->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbPhuongPhap->FormattingEnabled = true;
			this->cbPhuongPhap->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Arithmetic Mean", L"Geometric Mean", L"Harmonic Mean",
					L"Contraharmonic Mean", L"Alpha-Trimmed Mean Filter", L"Midpoint Filter", L"Max Filter", L"Min Filter", L"Median Filter"
			});
			this->cbPhuongPhap->Location = System::Drawing::Point(16, 221);
			this->cbPhuongPhap->Name = L"cbPhuongPhap";
			this->cbPhuongPhap->Size = System::Drawing::Size(263, 33);
			this->cbPhuongPhap->TabIndex = 3;
			this->cbPhuongPhap->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cbPhuongPhap_SelectedIndexChanged);
			// 
			// lbPhuongPhap
			// 
			this->lbPhuongPhap->AutoSize = true;
			this->lbPhuongPhap->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPhuongPhap->Location = System::Drawing::Point(16, 180);
			this->lbPhuongPhap->Name = L"lbPhuongPhap";
			this->lbPhuongPhap->Size = System::Drawing::Size(78, 25);
			this->lbPhuongPhap->TabIndex = 2;
			this->lbPhuongPhap->Text = L"Method";
			// 
			// lbPath
			// 
			this->lbPath->AutoSize = true;
			this->lbPath->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPath->Location = System::Drawing::Point(16, 117);
			this->lbPath->Name = L"lbPath";
			this->lbPath->Size = System::Drawing::Size(96, 21);
			this->lbPath->TabIndex = 1;
			this->lbPath->Text = L"Video\'s path";
			// 
			// btnSelectFile
			// 
			this->btnSelectFile->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSelectFile->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSelectFile->Location = System::Drawing::Point(16, 59);
			this->btnSelectFile->Name = L"btnSelectFile";
			this->btnSelectFile->Size = System::Drawing::Size(121, 40);
			this->btnSelectFile->TabIndex = 0;
			this->btnSelectFile->Text = L"Select video";
			this->btnSelectFile->UseVisualStyleBackColor = true;
			this->btnSelectFile->Click += gcnew System::EventHandler(this, &MyForm::btnSelectFile_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->ClientSize = System::Drawing::Size(944, 501);
			this->Controls->Add(this->pnControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Video Processing";
			this->pnControl->ResumeLayout(false);
			this->pnControl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtSoLanChay))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnSelectFile_Click(System::Object^  sender, System::EventArgs^  e) {
		// Get video's path
		OpenFileDialog ^choofdlog = gcnew OpenFileDialog();
		choofdlog->Filter = "All Files (*.*)|*.*";
		choofdlog->FilterIndex = 1;
		choofdlog->Multiselect = false;

		System::Windows::Forms::DialogResult ^dr = choofdlog->ShowDialog();
		
		path = choofdlog->FileName;
		lbPath->Text = path;
	}
	private: System::Void btnThucHien_Click(System::Object^  sender, System::EventArgs^  e) {
		getInput();
		VideoProcess ^vp = gcnew VideoProcess();
		if (path && path != "" && times > 0) {
			switch (method)
			{
			case 0: {
				vp->ArithmeticMean(path, times);
				break;
			}
			case 1: {
				vp->GeometricMean(path, times);
				break;
			}
			case 2: {
				vp->HarmonicMean(path, times);
				break;
			}
			case 3: {
				vp->ContraharmonicMean(path, times);
				break;
			}
			case 4: {
				vp->AlphaTrimmed(path, times);
				break;
			}
			case 5: {
				vp->MidpointFilter(path, times);
				break;
			}
			case 6: {
				vp->MaxFilter(path, times);
				break;
			}
			case 7: {
				vp->MinFilter(path, times);
				break;
			}
			case 8: {
				vp->MedianFilter(path, times);
				break;
			}
			default: {
				MessageBox::Show(this, "No selected method", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}
			}
		}
		else {
			MessageBox::Show(this, "Please select video file, run times.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: void getInput() {
		// Get times
		times = Int32::Parse(txtSoLanChay->Value.ToString());

		// Get method
		method = cbPhuongPhap->SelectedIndex;
	}

	private: System::Void cbPhuongPhap_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
