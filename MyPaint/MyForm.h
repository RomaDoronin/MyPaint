#pragma once
#include "TObject.h"

namespace MyPaint {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		bool flag;

		TObject* Obj;
		TGroup* Gr;

		int MoveX, MoveY;

	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	public:
		Graphics ^ g;
		

		MyForm(void)
		{
			InitializeComponent();

			g = this->CreateGraphics();
			Gr = new TGroup();
			flag = false;
			MoveX = 0; MoveY = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  radioButton1;
	protected:
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::GroupBox^  groupBox1;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 31);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(55, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Точка";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 54);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(57, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Линия";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 77);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(62, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Эллипс";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(6, 100);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(105, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Прямоугольник";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton7);
			this->groupBox1->Controls->Add(this->radioButton6);
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Location = System::Drawing::Point(396, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(115, 225);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Геометрический объект";
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(6, 202);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(104, 17);
			this->radioButton7->TabIndex = 6;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"Двигать группу";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(6, 179);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(68, 17);
			this->radioButton6->TabIndex = 5;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Двигать";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(6, 124);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(48, 17);
			this->radioButton5->TabIndex = 4;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Круг";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Enabled = false;
			this->checkBox1->Location = System::Drawing::Point(402, 260);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->checkBox1->Size = System::Drawing::Size(88, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Прорисовка";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(402, 283);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(122, 30);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"Добавляем\r\nэлементы в группу";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(523, 361);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (radioButton1->Checked)
		{
			Obj = new TPoint(e->X, e->Y);

			if (checkBox2->Checked)
			{
				Gr->Insert(Obj);
			}
		}

		if (radioButton2->Checked)
		{
			Obj = new TLine(e->X, e->Y);

			if (checkBox2->Checked)
			{
				Gr->Insert(Obj);
			}
		}

		if (radioButton3->Checked)
		{
			Obj = new TEllips(e->X, e->Y);

			if (checkBox2->Checked)
			{
				Gr->Insert(Obj);
			}
		}

		if (radioButton4->Checked)
		{
			Obj = new TRectangle(e->X, e->Y);

			if (checkBox2->Checked)
			{
				Gr->Insert(Obj);
			}
		}

		if (radioButton5->Checked)
		{
			Obj = new TCircle(e->X, e->Y);

			if (checkBox2->Checked)
			{
				Gr->Insert(Obj);
			}
		}

		flag = true;

		if (radioButton6->Checked)
		{
			MoveX = e->X;
			MoveY = e->Y;
		}

		if (radioButton7->Checked)
		{
			MoveX = e->X;
			MoveY = e->Y;
		}
	}

	private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (radioButton1->Checked)
		{
			Obj->Draw(g);
		}

		if (radioButton2->Checked)
		{
			Obj->SetSecondKor(e->X, e->Y);
			Obj->Draw(g);
		}

		if (radioButton3->Checked)
		{
			Obj->SetSecondKor(e->X, e->Y);
			Obj->Draw(g);
		}

		if (radioButton4->Checked)
		{
			Obj->SetSecondKor(e->X, e->Y);
			Obj->Draw(g);
		}

		if (radioButton5->Checked)
		{			
			Obj->SetSecondKor(e->X, e->Y);
			Obj->Draw(g);
		}

		if (radioButton6->Checked)
		{
			Obj->Move(g, e->X - MoveX, e->Y - MoveY);
		}

		if (radioButton7->Checked)
		{
			Gr->Move(g, e->X - MoveX, e->Y - MoveY);
		}

		flag = false;
	}

	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if ((flag) && (checkBox1->Checked))
		{
			if (radioButton6->Checked)
			{
				Obj->Move(g, e->X - MoveX, e->Y - MoveY);
			}
			else if ((radioButton7->Checked))
				Gr->Move(g, e->X, e->Y);
			else 		
			{
				Obj->Hide(g);
				Obj->SetSecondKor(e->X - MoveX, e->Y - MoveY);
				Obj->Draw(g);
			}
		}
	}
};
}
