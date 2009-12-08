#pragma once


namespace MazeWindow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  LengthBox;
	private: System::Windows::Forms::TextBox^  WidthBox;


	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Button^  ColorButton;
	private: System::Windows::Forms::Button^  ExitButton;
	private: System::Windows::Forms::Button^  GenerateButton;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LengthBox = (gcnew System::Windows::Forms::TextBox());
			this->WidthBox = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->ColorButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->GenerateButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Maze Length:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Maze Width:";
			// 
			// LengthBox
			// 
			this->LengthBox->Location = System::Drawing::Point(91, 10);
			this->LengthBox->MaxLength = 3;
			this->LengthBox->Name = L"LengthBox";
			this->LengthBox->Size = System::Drawing::Size(30, 20);
			this->LengthBox->TabIndex = 1;
			this->LengthBox->WordWrap = false;
			// 
			// WidthBox
			// 
			this->WidthBox->Location = System::Drawing::Point(91, 32);
			this->WidthBox->MaxLength = 3;
			this->WidthBox->Name = L"WidthBox";
			this->WidthBox->Size = System::Drawing::Size(30, 20);
			this->WidthBox->TabIndex = 3;
			this->WidthBox->WordWrap = false;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(120, 63);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(101, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Generating Method:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 93);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Solving Method:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(120, 90);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 125);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Maze Color:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(82, 122);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 9;
			// 
			// ColorButton
			// 
			this->ColorButton->Location = System::Drawing::Point(82, 149);
			this->ColorButton->Name = L"ColorButton";
			this->ColorButton->Size = System::Drawing::Size(89, 23);
			this->ColorButton->TabIndex = 10;
			this->ColorButton->Text = L"Custom Color...";
			this->ColorButton->UseVisualStyleBackColor = true;
			this->ColorButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(197, 206);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(75, 23);
			this->ExitButton->TabIndex = 12;
			this->ExitButton->Text = L"Exit";
			this->ExitButton->UseVisualStyleBackColor = true;
			// 
			// GenerateButton
			// 
			this->GenerateButton->Location = System::Drawing::Point(116, 206);
			this->GenerateButton->Name = L"GenerateButton";
			this->GenerateButton->Size = System::Drawing::Size(75, 23);
			this->GenerateButton->TabIndex = 11;
			this->GenerateButton->Text = L"Generate!";
			this->GenerateButton->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 241);
			this->Controls->Add(this->GenerateButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->ColorButton);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->WidthBox);
			this->Controls->Add(this->LengthBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Maze Generator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void InitializeComponent() {
			 this->SuspendLayout();
			 // 
			 // Form1
			 // 
			 this->ClientSize = System::Drawing::Size(292, 266);
			 this->Name = L"Form1";
			 this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			 this->ResumeLayout(false);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

