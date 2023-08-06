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
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
//			gameBoard = gcnew Board(pbBoard, textBox1, textBox2, 10, 4);
			gameController = gcnew GameController(pbBoard, textBox1, textBox2, textSide, buttonStart, buttonDecreaseX, buttonIncreaseX, buttonDecreaseY, buttonIncreaseY);
//			gameController = gcnew GameController(pbBoard, textBox1, textBox2, buttonStart, buttonDecreaseX, buttonIncreaseX, buttonDecreaseY, buttonIncreaseY);
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbBoard;
		   //		   Board^ gameBoard;
		   GameController^ gameController;

		   const int DEFAULT_BOARD_SIZE_I = 7;
		   const int DEFAULT_BOARD_SIZE_J = 5;
		   const static int DEFAULT_FORM_SIZE_X = 750;
		   const static int DEFAULT_FORM_SIZE_Y = 650;
		   const static int bitMapSize = 70;
		   const static int DEFAULT_PICTURE_BOX_SIZE_X = 490;
		   const static int DEFAULT_PICTURE_BOX_SIZE_Y = 350;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ buttonStart;
	private: System::Windows::Forms::Button^ buttonDecreaseX;
	private: System::Windows::Forms::Button^ buttonIncreaseX;


	private: System::Windows::Forms::Button^ buttonDecreaseY;
	private: System::Windows::Forms::Button^ buttonIncreaseY;
	private: System::Windows::Forms::TextBox^ textSide;

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pbBoard = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->buttonDecreaseX = (gcnew System::Windows::Forms::Button());
			this->buttonIncreaseX = (gcnew System::Windows::Forms::Button());
			this->buttonDecreaseY = (gcnew System::Windows::Forms::Button());
			this->buttonIncreaseY = (gcnew System::Windows::Forms::Button());
			this->textSide = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBoard))->BeginInit();
			this->SuspendLayout();
			// 
			// pbBoard
			// 
			this->pbBoard->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbBoard->BackColor = System::Drawing::SystemColors::Control;
			this->pbBoard->Location = System::Drawing::Point(140, 0);
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
			this->textBox1->Size = System::Drawing::Size(490, 50);
			this->textBox1->TabIndex = 1;
			this->textBox1->TabStop = false;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
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
			this->textBox2->TabStop = false;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// buttonStart
			// 
			this->buttonStart->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStart->Location = System::Drawing::Point(235, 305);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(250, 50);
			this->buttonStart->TabIndex = 3;
			this->buttonStart->TabStop = false;
			this->buttonStart->Text = L"Start game";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonStart_MouseClick);
			// 
			// buttonDecreaseX
			// 
			this->buttonDecreaseX->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDecreaseX->Location = System::Drawing::Point(115, 58);
			this->buttonDecreaseX->Name = L"buttonDecreaseX";
			this->buttonDecreaseX->Size = System::Drawing::Size(100, 60);
			this->buttonDecreaseX->TabIndex = 4;
			this->buttonDecreaseX->TabStop = false;
			this->buttonDecreaseX->Text = L"-1";
			this->buttonDecreaseX->UseVisualStyleBackColor = true;
			this->buttonDecreaseX->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonDecreaseX_MouseClick);
			// 
			// buttonIncreaseX
			// 
			this->buttonIncreaseX->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonIncreaseX->Location = System::Drawing::Point(506, 58);
			this->buttonIncreaseX->Name = L"buttonIncreaseX";
			this->buttonIncreaseX->Size = System::Drawing::Size(100, 60);
			this->buttonIncreaseX->TabIndex = 5;
			this->buttonIncreaseX->TabStop = false;
			this->buttonIncreaseX->Text = L"+1";
			this->buttonIncreaseX->UseVisualStyleBackColor = true;
			this->buttonIncreaseX->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonIncreaseX_MouseClick);
			// 
			// buttonDecreaseY
			// 
			this->buttonDecreaseY->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDecreaseY->Location = System::Drawing::Point(115, 216);
			this->buttonDecreaseY->Name = L"buttonDecreaseY";
			this->buttonDecreaseY->Size = System::Drawing::Size(100, 60);
			this->buttonDecreaseY->TabIndex = 6;
			this->buttonDecreaseY->TabStop = false;
			this->buttonDecreaseY->Text = L"-1";
			this->buttonDecreaseY->UseVisualStyleBackColor = true;
			this->buttonDecreaseY->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonDecreaseY_MouseClick);
			// 
			// buttonIncreaseY
			// 
			this->buttonIncreaseY->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonIncreaseY->Location = System::Drawing::Point(506, 216);
			this->buttonIncreaseY->Name = L"buttonIncreaseY";
			this->buttonIncreaseY->Size = System::Drawing::Size(100, 60);
			this->buttonIncreaseY->TabIndex = 7;
			this->buttonIncreaseY->TabStop = false;
			this->buttonIncreaseY->Text = L"+1";
			this->buttonIncreaseY->UseVisualStyleBackColor = true;
			this->buttonIncreaseY->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonIncreaseY_MouseClick);
			// 
			// textSide
			// 
			this->textSide->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textSide->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textSide->Location = System::Drawing::Point(235, 58);
			this->textSide->Multiline = true;
			this->textSide->Name = L"textSide";
			this->textSide->Size = System::Drawing::Size(250, 60);
			this->textSide->TabIndex = 8;
			this->textSide->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textSide->TextChanged += gcnew System::EventHandler(this, &MainForm::textSide_TextChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 611);
			this->Controls->Add(this->textSide);
			this->Controls->Add(this->buttonIncreaseY);
			this->Controls->Add(this->buttonDecreaseY);
			this->Controls->Add(this->buttonIncreaseX);
			this->Controls->Add(this->buttonDecreaseX);
			this->Controls->Add(this->buttonStart);
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
		if (gameController->getIsGameWindow())
		{
			gameController->Draw();
		}
		//		gameController->Draw();

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
			gameController->MovePointer(x, y);
		}
		if (rotate)
		{
			gameController->RotatePointer();
		}
		if (setPlayer)
		{
			gameController->setCellToPlayer();
		}
	}
	private: System::Void buttonStart_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (gameController->getIsMainMenu())
		{
			gameController->gotoNewGameMenu();
		}
		else if (gameController->getIsNewGameMenu())
		{
			gameController->startGame(7, 5);
		}
		else if (gameController->getIsBoardSizeChooseMenu())
		{
			gameController->startGame(7, 5);
			//		gameController->calculateNewFormSize();
			//		gameController->startGame(gameController->getBoardSizeFromTextBox(textSide), gameController->getBoardSizeFromTextBox(textBox1));
		}
		else if (gameController->getIsGameWindow())
		{

		}

		this->Focus();
	}
	private: System::Void buttonIncreaseX_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
//		gameController->UpdateTextField(textSide, true);
	}
	private: System::Void buttonDecreaseX_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (gameController->getIsNewGameMenu())
		{
			gameController->gotoBoardSizeChooseMenu();
		}
		else if (gameController->getIsBoardSizeChooseMenu())
		{
//			gameController->UpdateTextField(textSide, false);
		}
		this->Focus();
	}
	private: System::Void buttonIncreaseY_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
//		gameController->UpdateTextField(textBox1, true);
	}
	private: System::Void buttonDecreaseY_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
//		gameController->UpdateTextField(textBox1, false);
	}

	private: System::Void textSide_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
//		gameController->checkTextCorrectness(textSide);
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
//		gameController->checkTextCorrectness(textBox1);
	}
	};
}
