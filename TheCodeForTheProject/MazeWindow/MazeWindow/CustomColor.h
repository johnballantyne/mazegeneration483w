#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MazeWindow {

	/// <summary>
	/// Summary for CustomColor
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CustomColor : public System::Windows::Forms::Form
	{
	public:
		CustomColor(void)
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
		~CustomColor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  RLabel;
	private: System::Windows::Forms::TextBox^  RBox;
	private: System::Windows::Forms::TextBox^  GBox;
	private: System::Windows::Forms::TextBox^  BBox;
	private: System::Windows::Forms::Label^  GLabel;
	private: System::Windows::Forms::Label^  BLabel;
	private: System::Windows::Forms::Label^  Label1;
	private: System::Windows::Forms::Label^  Label2;
	private: System::Windows::Forms::Label^  Label3;
	private: System::Windows::Forms::Button^  OKButton;
	private: System::Windows::Forms::Button^  CancelButton;
	protected: 

	protected: 











	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->RLabel = (gcnew System::Windows::Forms::Label());
			this->RBox = (gcnew System::Windows::Forms::TextBox());
			this->GBox = (gcnew System::Windows::Forms::TextBox());
			this->BBox = (gcnew System::Windows::Forms::TextBox());
			this->GLabel = (gcnew System::Windows::Forms::Label());
			this->BLabel = (gcnew System::Windows::Forms::Label());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			this->Label2 = (gcnew System::Windows::Forms::Label());
			this->Label3 = (gcnew System::Windows::Forms::Label());
			this->OKButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// RLabel
			// 
			this->RLabel->AutoSize = true;
			this->RLabel->Location = System::Drawing::Point(12, 9);
			this->RLabel->Name = L"RLabel";
			this->RLabel->Size = System::Drawing::Size(18, 13);
			this->RLabel->TabIndex = 0;
			this->RLabel->Text = L"R:";
			// 
			// RBox
			// 
			this->RBox->Location = System::Drawing::Point(31, 6);
			this->RBox->MaxLength = 3;
			this->RBox->Name = L"RBox";
			this->RBox->Size = System::Drawing::Size(30, 20);
			this->RBox->TabIndex = 1;
			// 
			// GBox
			// 
			this->GBox->Location = System::Drawing::Point(31, 29);
			this->GBox->MaxLength = 3;
			this->GBox->Name = L"GBox";
			this->GBox->Size = System::Drawing::Size(30, 20);
			this->GBox->TabIndex = 4;
			// 
			// BBox
			// 
			this->BBox->Location = System::Drawing::Point(31, 52);
			this->BBox->MaxLength = 3;
			this->BBox->Name = L"BBox";
			this->BBox->Size = System::Drawing::Size(30, 20);
			this->BBox->TabIndex = 7;
			// 
			// GLabel
			// 
			this->GLabel->AutoSize = true;
			this->GLabel->Location = System::Drawing::Point(12, 32);
			this->GLabel->Name = L"GLabel";
			this->GLabel->Size = System::Drawing::Size(18, 13);
			this->GLabel->TabIndex = 3;
			this->GLabel->Text = L"G:";
			// 
			// BLabel
			// 
			this->BLabel->AutoSize = true;
			this->BLabel->Location = System::Drawing::Point(12, 55);
			this->BLabel->Name = L"BLabel";
			this->BLabel->Size = System::Drawing::Size(17, 13);
			this->BLabel->TabIndex = 6;
			this->BLabel->Text = L"B:";
			// 
			// Label1
			// 
			this->Label1->AutoSize = true;
			this->Label1->Location = System::Drawing::Point(62, 9);
			this->Label1->Name = L"Label1";
			this->Label1->Size = System::Drawing::Size(43, 13);
			this->Label1->TabIndex = 2;
			this->Label1->Text = L"(0, 255)";
			// 
			// Label2
			// 
			this->Label2->AutoSize = true;
			this->Label2->Location = System::Drawing::Point(62, 32);
			this->Label2->Name = L"Label2";
			this->Label2->Size = System::Drawing::Size(43, 13);
			this->Label2->TabIndex = 5;
			this->Label2->Text = L"(0, 255)";
			// 
			// Label3
			// 
			this->Label3->AutoSize = true;
			this->Label3->Location = System::Drawing::Point(62, 55);
			this->Label3->Name = L"Label3";
			this->Label3->Size = System::Drawing::Size(43, 13);
			this->Label3->TabIndex = 8;
			this->Label3->Text = L"(0, 255)";
			// 
			// OKButton
			// 
			this->OKButton->Location = System::Drawing::Point(36, 89);
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size(75, 23);
			this->OKButton->TabIndex = 9;
			this->OKButton->Text = L"OK";
			this->OKButton->UseVisualStyleBackColor = true;
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(117, 89);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 10;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &CustomColor::button2_Click);
			// 
			// CustomColor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(204, 125);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->OKButton);
			this->Controls->Add(this->Label3);
			this->Controls->Add(this->Label2);
			this->Controls->Add(this->Label1);
			this->Controls->Add(this->BLabel);
			this->Controls->Add(this->GLabel);
			this->Controls->Add(this->BBox);
			this->Controls->Add(this->GBox);
			this->Controls->Add(this->RBox);
			this->Controls->Add(this->RLabel);
			this->Name = L"CustomColor";
			this->Text = L"Custom Color";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
