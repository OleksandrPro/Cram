#pragma once
#include "Cram.h"

namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			gameBoard = gcnew Board(pbBoard, textBox1, textBox2, 10, 4);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbBoard;
		   Board^ gameBoard;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pbBoard = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBoard))->BeginInit();
			this->SuspendLayout();
			// 
			// pbBoard
			// 
			this->pbBoard->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbBoard->Location = System::Drawing::Point(115, 12);
			this->pbBoard->Name = L"pbBoard";
			this->pbBoard->Size = System::Drawing::Size(490, 350);
			this->pbBoard->TabIndex = 0;
			this->pbBoard->TabStop = false;
			this->pbBoard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pbBoard_Paint);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(115, 379);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(490, 49);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(115, 456);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(490, 124);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 611);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pbBoard);
			this->MaximumSize = System::Drawing::Size(750, 650);
			this->MinimumSize = System::Drawing::Size(750, 650);
			this->Name = L"MainForm";
			this->Text = L"Cram";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pbBoard_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBoard))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void pbBoard_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		gameBoard->DrawBoard();
	}
	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{		
		int x;
		int y;
		bool move = false;
		bool rotate = false;
		bool setPlayer = false;

		if (e->KeyCode == Keys::S)
		{
			x = 0;
			y = 1;
			move = true;
		} 
		else if (e->KeyCode == Keys::W)
		{
			x = 0;
			y = -1;
			move = true;
		} 
		else if (e->KeyCode == Keys::D)
		{
			x = 1;
			y = 0;
			move = true;
		} 
		else if (e->KeyCode == Keys::A)
		{
			x = -1;
			y = 0;
			move = true;
		}
		else if (e->KeyCode == Keys::R)
		{
			rotate = true;
		}
		else if (e->KeyCode == Keys::E)
		{
			setPlayer = true;
		}
		if (move)
		{
			gameBoard->MovePointer(x, y);
		}
		if (rotate)
		{
			gameBoard->RotatePointer();
		}
		if (setPlayer)
		{
			gameBoard->setCellToPlayer();
		}
	}
};
}
