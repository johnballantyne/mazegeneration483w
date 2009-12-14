#pragma once

#include<stdlib.h>
#include<string.h>
#include <msclr/marshal.h>
using namespace System;
using namespace msclr::interop;

namespace MazeWindow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MazeForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MazeForm : public System::Windows::Forms::Form
	{
	public:
		MazeForm(void)
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
		~MazeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TextBox^  LengthBox;






	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;






	private: System::Windows::Forms::Button^  ExitButton;
	private: System::Windows::Forms::Button^  GenerateButton;
	private: System::Windows::Forms::ComboBox^  GenerateBox;
	private: System::Windows::Forms::ComboBox^  SolveBox;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LengthBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->GenerateButton = (gcnew System::Windows::Forms::Button());
			this->GenerateBox = (gcnew System::Windows::Forms::ComboBox());
			this->SolveBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Maze Dimensions:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MazeForm::label1_Click);
			// 
			// LengthBox
			// 
			this->LengthBox->Location = System::Drawing::Point(107, 10);
			this->LengthBox->MaxLength = 3;
			this->LengthBox->Name = L"LengthBox";
			this->LengthBox->Size = System::Drawing::Size(30, 20);
			this->LengthBox->TabIndex = 1;
			this->LengthBox->WordWrap = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(101, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Generating Method:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 70);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Solving Method:";
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(188, 155);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(75, 23);
			this->ExitButton->TabIndex = 12;
			this->ExitButton->Text = L"Exit";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &MazeForm::ExitButton_Click);
			// 
			// GenerateButton
			// 
			this->GenerateButton->Location = System::Drawing::Point(107, 155);
			this->GenerateButton->Name = L"GenerateButton";
			this->GenerateButton->Size = System::Drawing::Size(75, 23);
			this->GenerateButton->TabIndex = 11;
			this->GenerateButton->Text = L"Generate!";
			this->GenerateButton->UseVisualStyleBackColor = true;
			this->GenerateButton->Click += gcnew System::EventHandler(this, &MazeForm::GenerateButton_Click);
			// 
			// GenerateBox
			// 
			this->GenerateBox->FormattingEnabled = true;
			this->GenerateBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Recursive Division (biased)", L"Recursive Division (unbiased)"});
			this->GenerateBox->Location = System::Drawing::Point(115, 40);
			this->GenerateBox->Name = L"GenerateBox";
			this->GenerateBox->Size = System::Drawing::Size(148, 21);
			this->GenerateBox->TabIndex = 5;
			this->GenerateBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MazeForm::GenerateBox_SelectedIndexChanged);
			// 
			// SolveBox
			// 
			this->SolveBox->FormattingEnabled = true;
			this->SolveBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Right-Hand Rule", L"Left-Hand Rule"});
			this->SolveBox->Location = System::Drawing::Point(115, 67);
			this->SolveBox->Name = L"SolveBox";
			this->SolveBox->Size = System::Drawing::Size(148, 21);
			this->SolveBox->TabIndex = 7;
			this->SolveBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MazeForm::SolveBox_SelectedIndexChanged);
			// 
			// MazeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(285, 190);
			this->Controls->Add(this->SolveBox);
			this->Controls->Add(this->GenerateButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->GenerateBox);
			this->Controls->Add(this->LengthBox);
			this->Controls->Add(this->label1);
			this->Name = L"MazeForm";
			this->Text = L"MazeNavigator";
			this->Load += gcnew System::EventHandler(this, &MazeForm::MazeForm_Load_1);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
/*private: System::Void InitializeComponent() {
			 this->SuspendLayout();
			 // 
			 // MazeForm
			 // 
			 this->ClientSize = System::Drawing::Size(292, 266);
			 this->Name = L"MazeForm";
			 this->Load += gcnew System::EventHandler(this, &MazeForm::MazeForm_Load);
			 this->ResumeLayout(false);
		 }*/
private: System::Void MazeForm_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void MazeForm_Load_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void GenerateBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void GenerateButton_Click(System::Object^  sender, System::EventArgs^  e) {
			marshal_context^ context = gcnew marshal_context();
			const char* len;
			len = context->marshal_as<const char*>( LengthBox->Text );
			const char* gen;
			gen = context->marshal_as<const char*>( GenerateBox->Text );
			const char* solve;
			solve = context->marshal_as<const char*>( SolveBox->Text );
			//const char* color;
			//color = context->marshal_as<const char*>( ColorBox->Text );
			int sendGen, sendSolve;

			int length = atoi( len );
			if( length < 2 || length > 100 )
			{
				MessageBox::Show( "Please enter a dimension between 2 and 100.", "Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
				return;
			}
			if( length % 2 == 1 )
				length--;
			if( strcmp( gen, "Recursive Division (biased)" ) == 0 )
				sendGen = 1;
			else if( strcmp( gen, "Recursive Division (unbiased)" ) == 0 )
				sendGen = 2;
			else
			{
				MessageBox::Show( "Please select a generation algorithm.", "Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
				return;
			}
			if( strcmp( solve, "Right-Hand Rule" ) == 0 )
				sendSolve = 1;
			else if( strcmp( solve, "Left-Hand Rule" ) == 0 )
				sendSolve = 2;
			else
			{
				MessageBox::Show( "Please select a solving algorithm.", "Entry Error",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
				return;
			}
			//open the program
			String^ thing = "MazeNavigator.exe " + length + " " + sendGen + " " + sendSolve;
			const char* sysCall;
			sysCall = context->marshal_as<const char*>( thing );
			MessageBox::Show( thing, "Success!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation );
			//system( sysCall );
		 }
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			exit(0);
		 }
private: System::Void SolveBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

