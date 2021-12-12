#pragma once
#include "TextBoxFilters.h"

namespace mp2lab4queueform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class QueueForm : public System::Windows::Forms::Form
	{
	public:
		QueueForm(void)
		{
			InitializeComponent();
			SetTransparency();
			label1->Select();
		}

	protected:
		~QueueForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbBackground;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tbPopProb;
	private: System::Windows::Forms::TextBox^ tbSize;
	private: System::Windows::Forms::TextBox^ tbMaxSize;
	private: System::Windows::Forms::TextBox^ tbPushProb;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Button^ btnStartStop;
	private: System::Windows::Forms::Label^ labelQueueSize;


	private: System::ComponentModel::IContainer^ components;

	private:
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QueueForm::typeid));
			this->pbBackground = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbPopProb = (gcnew System::Windows::Forms::TextBox());
			this->tbSize = (gcnew System::Windows::Forms::TextBox());
			this->tbMaxSize = (gcnew System::Windows::Forms::TextBox());
			this->tbPushProb = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStartStop = (gcnew System::Windows::Forms::Button());
			this->labelQueueSize = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBackground))->BeginInit();
			this->SuspendLayout();
			// 
			// pbBackground
			// 
			this->pbBackground->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbBackground.Image")));
			this->pbBackground->Location = System::Drawing::Point(0, 0);
			this->pbBackground->Name = L"pbBackground";
			this->pbBackground->Size = System::Drawing::Size(430, 555);
			this->pbBackground->TabIndex = 0;
			this->pbBackground->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label8->Location = System::Drawing::Point(267, 515);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 26);
			this->label8->TabIndex = 11;
			this->label8->Text = L"0";
			this->label8->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label7->Location = System::Drawing::Point(267, 487);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(24, 26);
			this->label7->TabIndex = 1;
			this->label7->Text = L"0";
			this->label7->Visible = false;
			// 
			// tbPopProb
			// 
			this->tbPopProb->BackColor = System::Drawing::Color::DimGray;
			this->tbPopProb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbPopProb->ForeColor = System::Drawing::Color::White;
			this->tbPopProb->Location = System::Drawing::Point(311, 142);
			this->tbPopProb->Name = L"tbPopProb";
			this->tbPopProb->Size = System::Drawing::Size(100, 29);
			this->tbPopProb->TabIndex = 5;
			this->tbPopProb->Text = L"0.6";
			this->tbPopProb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbPopProb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QueueForm::tbPopProb_KeyPress);
			// 
			// tbSize
			// 
			this->tbSize->BackColor = System::Drawing::Color::DimGray;
			this->tbSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbSize->ForeColor = System::Drawing::Color::White;
			this->tbSize->Location = System::Drawing::Point(311, 62);
			this->tbSize->Name = L"tbSize";
			this->tbSize->Size = System::Drawing::Size(100, 29);
			this->tbSize->TabIndex = 3;
			this->tbSize->Text = L"20";
			this->tbSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbSize->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QueueForm::tbSize_KeyPress);
			// 
			// tbMaxSize
			// 
			this->tbMaxSize->BackColor = System::Drawing::Color::DimGray;
			this->tbMaxSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbMaxSize->ForeColor = System::Drawing::Color::White;
			this->tbMaxSize->Location = System::Drawing::Point(311, 22);
			this->tbMaxSize->Name = L"tbMaxSize";
			this->tbMaxSize->Size = System::Drawing::Size(100, 29);
			this->tbMaxSize->TabIndex = 2;
			this->tbMaxSize->Text = L"100";
			this->tbMaxSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbMaxSize->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QueueForm::tbMaxSize_KeyPress);
			// 
			// tbPushProb
			// 
			this->tbPushProb->BackColor = System::Drawing::Color::DimGray;
			this->tbPushProb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbPushProb->ForeColor = System::Drawing::Color::White;
			this->tbPushProb->Location = System::Drawing::Point(311, 102);
			this->tbPushProb->Name = L"tbPushProb";
			this->tbPushProb->Size = System::Drawing::Size(100, 29);
			this->tbPushProb->TabIndex = 4;
			this->tbPushProb->Text = L"0.4";
			this->tbPushProb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbPushProb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QueueForm::tbPushProb_KeyPress);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label6->Location = System::Drawing::Point(146, 515);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 26);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Извлечено:";
			this->label6->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label5->Location = System::Drawing::Point(146, 487);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(118, 26);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Добавлено:";
			this->label5->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label4->Location = System::Drawing::Point(18, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(241, 26);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Вероятность извлечения:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label3->Location = System::Drawing::Point(18, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(243, 26);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Вероятность добавления:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label2->Location = System::Drawing::Point(18, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(248, 26);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Исходная длина очереди:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label1->Location = System::Drawing::Point(18, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(294, 26);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Максимальная длина очереди:";
			// 
			// btnStartStop
			// 
			this->btnStartStop->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnStartStop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStartStop->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 18.15652F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStartStop->ForeColor = System::Drawing::Color::White;
			this->btnStartStop->Location = System::Drawing::Point(18, 193);
			this->btnStartStop->Name = L"btnStartStop";
			this->btnStartStop->Size = System::Drawing::Size(393, 56);
			this->btnStartStop->TabIndex = 1;
			this->btnStartStop->Text = L"Запуск";
			this->btnStartStop->UseVisualStyleBackColor = false;
			this->btnStartStop->Click += gcnew System::EventHandler(this, &QueueForm::btnStartStop_Click);
			// 
			// labelQueueSize
			// 
			this->labelQueueSize->BackColor = System::Drawing::Color::Transparent;
			this->labelQueueSize->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 23.7913F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelQueueSize->ForeColor = System::Drawing::Color::MediumOrchid;
			this->labelQueueSize->Location = System::Drawing::Point(136, 346);
			this->labelQueueSize->Name = L"labelQueueSize";
			this->labelQueueSize->Size = System::Drawing::Size(166, 72);
			this->labelQueueSize->TabIndex = 13;
			this->labelQueueSize->Text = L"0";
			this->labelQueueSize->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelQueueSize->Visible = false;
			// 
			// QueueForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 555);
			this->Controls->Add(this->labelQueueSize);
			this->Controls->Add(this->btnStartStop);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tbPopProb);
			this->Controls->Add(this->tbSize);
			this->Controls->Add(this->tbMaxSize);
			this->Controls->Add(this->tbPushProb);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pbBackground);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"QueueForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Queue Visualizer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBackground))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		bool IsRunning = false;

	private: void SetTransparency()
	{
		label1->Parent = pbBackground;
		label2->Parent = pbBackground;
		label3->Parent = pbBackground;
		label4->Parent = pbBackground;
		label5->Parent = pbBackground;
		label6->Parent = pbBackground;
		label7->Parent = pbBackground;
		label8->Parent = pbBackground;
		tbMaxSize->Parent = pbBackground;
		tbSize->Parent = pbBackground;
		tbPushProb->Parent = pbBackground;
		tbPopProb->Parent = pbBackground;
		labelQueueSize->Parent = pbBackground;
	}

	private: Void tbMaxSize_KeyPress(Object^ sender, KeyPressEventArgs^ e)
	{
		TextBoxFilters::NaturalNumber(sender, e);
	}
	private: Void tbSize_KeyPress(Object^ sender, KeyPressEventArgs^ e)
	{
		TextBoxFilters::NaturalNumber(sender, e);
	}
	private: Void tbPushProb_KeyPress(Object^ sender, KeyPressEventArgs^ e)
	{
		TextBoxFilters::NonNegativeDecimalNumber(sender, e);
	}
	private: Void tbPopProb_KeyPress(Object^ sender, KeyPressEventArgs^ e)
	{
		TextBoxFilters::NonNegativeDecimalNumber(sender, e);
	}
	private: System::Void btnStartStop_Click(Object^ sender, EventArgs^ e)
	{
		if (!IsRunning)
		{
			IsRunning = true;
			//Запуск
			btnStartStop->Text = "Остановить";
		}
		else
		{
			IsRunning = false;
			//Остановка
			btnStartStop->Text = "Запуск";
		}
	}
	};
}
