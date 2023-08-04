#pragma once

namespace NumberGuessingGame {

    using namespace System;

    public ref class MyForm : public System::Windows::Forms::Form {
    public:
        MyForm() {
            InitializeComponent();
            InitializeGame();
        }

    protected:
        ~MyForm() {
            if (components) {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ txtGuess;
    private: System::Windows::Forms::Button^ btnGuess;
    private: System::Windows::Forms::Label^ lblResult;
    private: int secretNumber;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;

    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void) {
               this->txtGuess = (gcnew System::Windows::Forms::TextBox());
               this->btnGuess = (gcnew System::Windows::Forms::Button());
               this->lblResult = (gcnew System::Windows::Forms::Label());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // 
               // txtGuess
               // 
               this->txtGuess->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->txtGuess->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->txtGuess->Location = System::Drawing::Point(344, 156);
               this->txtGuess->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
               this->txtGuess->Multiline = true;
               this->txtGuess->Name = L"txtGuess";
               this->txtGuess->Size = System::Drawing::Size(187, 31);
               this->txtGuess->TabIndex = 0;
               this->txtGuess->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
               // 
               // btnGuess
               // 
               this->btnGuess->BackColor = System::Drawing::Color::Red;
               this->btnGuess->Location = System::Drawing::Point(560, 156);
               this->btnGuess->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
               this->btnGuess->Name = L"btnGuess";
               this->btnGuess->Size = System::Drawing::Size(208, 31);
               this->btnGuess->TabIndex = 1;
               this->btnGuess->Text = L"Guess";
               this->btnGuess->UseVisualStyleBackColor = false;
               this->btnGuess->Click += gcnew System::EventHandler(this, &MyForm::btnGuess_Click);
               // 
               // lblResult
               // 
               this->lblResult->AutoSize = true;
               this->lblResult->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                   static_cast<System::Int32>(static_cast<System::Byte>(64)));
               this->lblResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->lblResult->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->lblResult->Location = System::Drawing::Point(169, 226);
               this->lblResult->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->lblResult->Name = L"lblResult";
               this->lblResult->Size = System::Drawing::Size(0, 42);
               this->lblResult->TabIndex = 2;
               this->lblResult->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
                   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->label1->Location = System::Drawing::Point(61, 9);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(419, 52);
               this->label1->TabIndex = 3;
               this->label1->Text = L"Guess The Number";
               this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label2->Location = System::Drawing::Point(76, 95);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(886, 29);
               this->label2->TabIndex = 4;
               this->label2->Text = L"We have selected a random number between 1 - 100. Let\'s See if you can Guess it";
               this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
               this->label3->Location = System::Drawing::Point(75, 156);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(229, 31);
               this->label3->TabIndex = 5;
               this->label3->Text = L"Enter Your Guess";
               // 
               // MyForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::OldLace;
               this->ClientSize = System::Drawing::Size(1094, 303);
               this->Controls->Add(this->label3);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->lblResult);
               this->Controls->Add(this->btnGuess);
               this->Controls->Add(this->txtGuess);
               this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
               this->Name = L"MyForm";
               this->Text = L"Number Guessing Game";
               this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private: void InitializeGame() {
        // Generate a random number between 1 and 100
        Random^ rand = gcnew Random();
        secretNumber = rand->Next(1, 101);
    }

    private: System::Void btnGuess_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            int userGuess = Int32::Parse(txtGuess->Text);

            if (userGuess == secretNumber) {
                lblResult->Text = "Congratulations! You guessed the number.";
            }
            else if (userGuess < secretNumber) {
                lblResult->Text = "Try a higher number.";
            }
            else {
                lblResult->Text = "Try a lower number.";
            }
        }
        catch (FormatException^) {
            lblResult->Text = "Please enter a valid number.";
        }
        catch (OverflowException^) {
            lblResult->Text = "Number is too large or too small.";
        }
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
