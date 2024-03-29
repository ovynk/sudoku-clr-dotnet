#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Sudoku.h"

namespace sudoku {

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
		MyForm(void)
		{
			int N = 9;
			int cellSize = 40;
			int devide = 3;

			InitializeComponent();
			this->dataGridView_Sudoku->Size = System::Drawing::Size(N * cellSize + devide, N * cellSize + devide);

			sudoku = new Sudoku(N, 10); 
			sudoku->fillValues();

			MakeColsAndRows(N, N, cellSize, cellSize);
			FillSudoku(sudoku->mat);
			DivideSudoku(N, N);
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

	private: System::Windows::Forms::Panel^ panel_Main;
	private: System::Windows::Forms::DataGridView^ dataGridView_Sudoku;
	private: System::Windows::Forms::Button^ button_Check;
	private: System::Windows::Forms::Button^ button_NewGame;
	private: System::Windows::Forms::TextBox^ textBox_NEmptyCells;
	private: System::Windows::Forms::Label^ label_NEmptyCells;
	private: System::Windows::Forms::Label^ label_CountWins;

	private: Sudoku* sudoku;
	private: int16_t countWins = 0;
	private: bool isSudokuCompleted = false;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel_Main = (gcnew System::Windows::Forms::Panel());
			this->label_CountWins = (gcnew System::Windows::Forms::Label());
			this->label_NEmptyCells = (gcnew System::Windows::Forms::Label());
			this->textBox_NEmptyCells = (gcnew System::Windows::Forms::TextBox());
			this->button_NewGame = (gcnew System::Windows::Forms::Button());
			this->button_Check = (gcnew System::Windows::Forms::Button());
			this->dataGridView_Sudoku = (gcnew System::Windows::Forms::DataGridView());
			this->panel_Main->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Sudoku))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_Main
			// 
			this->panel_Main->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel_Main->Controls->Add(this->label_CountWins);
			this->panel_Main->Controls->Add(this->label_NEmptyCells);
			this->panel_Main->Controls->Add(this->textBox_NEmptyCells);
			this->panel_Main->Controls->Add(this->button_NewGame);
			this->panel_Main->Controls->Add(this->button_Check);
			this->panel_Main->Controls->Add(this->dataGridView_Sudoku);
			this->panel_Main->Location = System::Drawing::Point(12, 12);
			this->panel_Main->Name = L"panel_Main";
			this->panel_Main->Size = System::Drawing::Size(549, 399);
			this->panel_Main->TabIndex = 0;
			// 
			// label_CountWins
			// 
			this->label_CountWins->AutoSize = true;
			this->label_CountWins->Location = System::Drawing::Point(438, 16);
			this->label_CountWins->Name = L"label_CountWins";
			this->label_CountWins->Size = System::Drawing::Size(74, 13);
			this->label_CountWins->TabIndex = 4;
			this->label_CountWins->Text = L"Count wins : 0";
			// 
			// label_NEmptyCells
			// 
			this->label_NEmptyCells->AutoSize = true;
			this->label_NEmptyCells->Location = System::Drawing::Point(438, 87);
			this->label_NEmptyCells->Name = L"label_NEmptyCells";
			this->label_NEmptyCells->Size = System::Drawing::Size(82, 13);
			this->label_NEmptyCells->TabIndex = 3;
			this->label_NEmptyCells->Text = L"N of empty cells";
			// 
			// textBox_NEmptyCells
			// 
			this->textBox_NEmptyCells->Location = System::Drawing::Point(441, 103);
			this->textBox_NEmptyCells->Name = L"textBox_NEmptyCells";
			this->textBox_NEmptyCells->Size = System::Drawing::Size(79, 20);
			this->textBox_NEmptyCells->TabIndex = 1;
			this->textBox_NEmptyCells->Tag = L"";
			this->textBox_NEmptyCells->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button_NewGame
			// 
			this->button_NewGame->Location = System::Drawing::Point(441, 60);
			this->button_NewGame->Name = L"button_NewGame";
			this->button_NewGame->Size = System::Drawing::Size(79, 23);
			this->button_NewGame->TabIndex = 2;
			this->button_NewGame->Text = L"New game";
			this->button_NewGame->UseVisualStyleBackColor = true;
			this->button_NewGame->Click += gcnew System::EventHandler(this, &MyForm::button_NewGame_Click);
			// 
			// button_Check
			// 
			this->button_Check->Location = System::Drawing::Point(441, 31);
			this->button_Check->Name = L"button_Check";
			this->button_Check->Size = System::Drawing::Size(79, 23);
			this->button_Check->TabIndex = 1;
			this->button_Check->Text = L"Check";
			this->button_Check->UseVisualStyleBackColor = true;
			this->button_Check->Click += gcnew System::EventHandler(this, &MyForm::button_Check_Click);
			// 
			// dataGridView_Sudoku
			// 
			this->dataGridView_Sudoku->AllowUserToAddRows = false;
			this->dataGridView_Sudoku->AllowUserToDeleteRows = false;
			this->dataGridView_Sudoku->AllowUserToResizeColumns = false;
			this->dataGridView_Sudoku->AllowUserToResizeRows = false;
			this->dataGridView_Sudoku->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Sudoku->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Info;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView_Sudoku->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView_Sudoku->Location = System::Drawing::Point(38, 15);
			this->dataGridView_Sudoku->MultiSelect = false;
			this->dataGridView_Sudoku->Name = L"dataGridView_Sudoku";
			this->dataGridView_Sudoku->RowHeadersVisible = false;
			this->dataGridView_Sudoku->Size = System::Drawing::Size(371, 371);
			this->dataGridView_Sudoku->TabIndex = 0;
			this->dataGridView_Sudoku->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->dataGridView_Sudoku->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::dataGridView1_EditingControlShowing);
			this->dataGridView_Sudoku->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::dataGridView1_KeyPress);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(573, 423);
			this->Controls->Add(this->panel_Main);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Sudoku";
			this->panel_Main->ResumeLayout(false);
			this->panel_Main->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Sudoku))->EndInit();
			this->ResumeLayout(false);

		}

		void MakeColsAndRows(int cols, int rows, int col_s, int row_s)
		{
			for (int i = 0; i < cols; i++)
			{
				this->dataGridView_Sudoku->Columns->Add(i.ToString(), i.ToString());
				this->dataGridView_Sudoku->Columns[i]->Width = col_s;
			}

			this->dataGridView_Sudoku->Rows->Add(rows);
			for (int i = 0; i < rows; i++)
			{
				this->dataGridView_Sudoku->Rows[i]->Height = row_s;
			}
		}

		void FillSudoku(int** vals)
		{
			// if cells are readonly reset them to false
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{			
					this->dataGridView_Sudoku->Rows[i]->Cells[j]->ReadOnly = false;								
				}
			}

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (vals[i][j] != 0)
					{
						this->dataGridView_Sudoku->Rows[i]->Cells[j]->Value = vals[i][j];
						this->dataGridView_Sudoku->Rows[i]->Cells[j]->ReadOnly = true;
					}
					else
					{
						this->dataGridView_Sudoku->Rows[i]->Cells[j]->Value = "";
					}
				}
			}
		}

		void DivideSudoku(int rows, int cols)
		{
			rows -= 1;
			cols -= 1;
			for (int r = 2; r < rows; r += 3)
			{
				this->dataGridView_Sudoku->Rows[r]->DividerHeight = 3;
			}
			for (int c = 2; c < cols; c += 3)
			{		
				this->dataGridView_Sudoku->Columns[c]->DividerWidth = 3;
			}
		}

	#pragma endregion

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}

	private: System::Void dataGridView1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
		{
			// Cancel the input
			e->Handled = true;
		}
	}

	private: System::Void dataGridView1_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e) {
		// Remove any previous KeyPress event handler
		e->Control->KeyPress -= gcnew KeyPressEventHandler(this, &MyForm::dataGridView1_KeyPress);
		
		TextBox^ tb = dynamic_cast<TextBox^> (e->Control);
		tb->MaxLength = 1;

		// If the cast is successful, attach a new KeyPress event handler
		if (tb != nullptr)
		{
			tb->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::dataGridView1_KeyPress);
		}
	}
	
	private: System::Void button_Check_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (this->dataGridView_Sudoku->Rows[i]->Cells[j]->Value == nullptr ||
					this->dataGridView_Sudoku->Rows[i]->Cells[j]->Value->ToString() != sudoku->copymat[i][j].ToString())
				{
					MessageBox::Show("Incorrect sudoku");
					return;
				}
			}
		}
		if (!isSudokuCompleted)
		{
			countWins++;
			this->label_CountWins->Text = "Count wins : " + countWins;
			isSudokuCompleted = true;
		}
		MessageBox::Show("Correct sudoku");
	}

	private: System::Void button_NewGame_Click(System::Object^ sender, System::EventArgs^ e) {
		int n;
		std::string s = msclr::interop::marshal_as<std::string>(textBox_NEmptyCells->Text->ToString());
		try
		{
			n = std::stoi(s);
		}
		catch (...)
		{
			n = 26;
		}

		sudoku = new Sudoku(9, n);
		sudoku->fillValues();

		FillSudoku(sudoku->mat);
		DivideSudoku(9, 9);
		isSudokuCompleted = false;
	}

};
}
