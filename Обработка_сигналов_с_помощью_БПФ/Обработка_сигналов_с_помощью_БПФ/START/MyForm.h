#pragma once

namespace START {

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
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::GroupBox^ groupBox10;
	private: System::Windows::Forms::GroupBox^ groupBox11;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;






	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart4;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->groupBox10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
			this->groupBox11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox12);
			this->groupBox1->Controls->Add(this->textBox11);
			this->groupBox1->Location = System::Drawing::Point(24, 23);
			this->groupBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox1->Size = System::Drawing::Size(400, 148);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметры сигнала";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 100);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"2^N             N =";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(132, 42);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 25);
			this->label1->TabIndex = 6;
			this->label1->Text = L"fd =";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(188, 87);
			this->textBox12->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(196, 31);
			this->textBox12->TabIndex = 5;
			this->textBox12->Text = L"9";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(188, 37);
			this->textBox11->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(196, 31);
			this->textBox11->TabIndex = 4;
			this->textBox11->Text = L"1024";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->textBox10);
			this->groupBox2->Location = System::Drawing::Point(24, 183);
			this->groupBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox2->Size = System::Drawing::Size(400, 98);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Параметры шума";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 50);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(151, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Энергия (%) =";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(188, 37);
			this->textBox10->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(196, 31);
			this->textBox10->TabIndex = 3;
			this->textBox10->Text = L"20";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Location = System::Drawing::Point(24, 292);
			this->groupBox3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox3->Size = System::Drawing::Size(400, 192);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Гармоника N1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(132, 150);
			this->label7->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 25);
			this->label7->TabIndex = 23;
			this->label7->Text = L"φ =";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(188, 137);
			this->textBox3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(196, 31);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(140, 100);
			this->label8->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(36, 25);
			this->label8->TabIndex = 22;
			this->label8->Text = L"f =";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(132, 50);
			this->label9->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(44, 25);
			this->label9->TabIndex = 21;
			this->label9->Text = L"A =";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(188, 87);
			this->textBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(196, 31);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"30";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(188, 37);
			this->textBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(196, 31);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"3";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label4);
			this->groupBox4->Controls->Add(this->textBox4);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->textBox5);
			this->groupBox4->Controls->Add(this->textBox6);
			this->groupBox4->Location = System::Drawing::Point(24, 496);
			this->groupBox4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox4->Size = System::Drawing::Size(400, 192);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Гармоника N2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(130, 150);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 25);
			this->label4->TabIndex = 20;
			this->label4->Text = L"φ =";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(188, 137);
			this->textBox4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(196, 31);
			this->textBox4->TabIndex = 2;
			this->textBox4->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(138, 100);
			this->label5->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 25);
			this->label5->TabIndex = 19;
			this->label5->Text = L"f =";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(130, 50);
			this->label6->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 25);
			this->label6->TabIndex = 18;
			this->label6->Text = L"A =";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(188, 87);
			this->textBox5->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(196, 31);
			this->textBox5->TabIndex = 1;
			this->textBox5->Text = L"10";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(188, 37);
			this->textBox6->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(196, 31);
			this->textBox6->TabIndex = 0;
			this->textBox6->Text = L"9";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label10);
			this->groupBox5->Controls->Add(this->textBox7);
			this->groupBox5->Controls->Add(this->label11);
			this->groupBox5->Controls->Add(this->textBox8);
			this->groupBox5->Controls->Add(this->label12);
			this->groupBox5->Controls->Add(this->textBox9);
			this->groupBox5->Location = System::Drawing::Point(24, 700);
			this->groupBox5->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox5->Size = System::Drawing::Size(400, 192);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Гармоника N3";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(128, 150);
			this->label10->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(44, 25);
			this->label10->TabIndex = 17;
			this->label10->Text = L"φ =";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(188, 137);
			this->textBox7->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(196, 31);
			this->textBox7->TabIndex = 2;
			this->textBox7->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(136, 100);
			this->label11->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(36, 25);
			this->label11->TabIndex = 16;
			this->label11->Text = L"f =";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(188, 87);
			this->textBox8->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(196, 31);
			this->textBox8->TabIndex = 1;
			this->textBox8->Text = L"50";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(128, 50);
			this->label12->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(44, 25);
			this->label12->TabIndex = 15;
			this->label12->Text = L"A =";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(188, 37);
			this->textBox9->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(196, 31);
			this->textBox9->TabIndex = 0;
			this->textBox9->Text = L"2";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label13);
			this->groupBox6->Controls->Add(this->textBox13);
			this->groupBox6->Location = System::Drawing::Point(24, 904);
			this->groupBox6->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox6->Size = System::Drawing::Size(400, 98);
			this->groupBox6->TabIndex = 4;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Параметры восстановления";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(26, 50);
			this->label13->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(151, 25);
			this->label13->TabIndex = 9;
			this->label13->Text = L"Энергия (%) =";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(188, 37);
			this->textBox13->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(196, 31);
			this->textBox13->TabIndex = 3;
			this->textBox13->Text = L"50";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->textBox14);
			this->groupBox7->Location = System::Drawing::Point(24, 1013);
			this->groupBox7->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox7->Size = System::Drawing::Size(400, 98);
			this->groupBox7->TabIndex = 5;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Отклонение";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(12, 37);
			this->textBox14->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(372, 31);
			this->textBox14->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(24, 1127);
			this->button1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(400, 44);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Сгенерировать сигнал";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->chart1);
			this->groupBox8->Location = System::Drawing::Point(436, 23);
			this->groupBox8->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox8->Size = System::Drawing::Size(912, 538);
			this->groupBox8->TabIndex = 8;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Исходный сигнал";
			// 
			// chart1
			// 
			chartArea1->AxisX->MaximumAutoSize = 10;
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisY->MaximumAutoSize = 10;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->DockedToChartArea = L"ChartArea1";
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 37);
			this->chart1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Black;
			series1->Legend = L"Legend1";
			series1->Name = L"Исходный сигнал";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Blue;
			series2->IsVisibleInLegend = false;
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Green;
			series3->IsVisibleInLegend = false;
			series3->Legend = L"Legend1";
			series3->Name = L" ";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::Red;
			series4->IsVisibleInLegend = false;
			series4->Legend = L"Legend1";
			series4->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(888, 490);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->chart3);
			this->groupBox9->Location = System::Drawing::Point(436, 633);
			this->groupBox9->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox9->Size = System::Drawing::Size(912, 538);
			this->groupBox9->TabIndex = 9;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Частотный спектр";
			// 
			// chart3
			// 
			chartArea2->AxisX->MaximumAutoSize = 10;
			chartArea2->AxisX->Minimum = 0;
			chartArea2->AxisY->MaximumAutoSize = 10;
			chartArea2->AxisY->Minimum = 0;
			chartArea2->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea2);
			legend2->DockedToChartArea = L"ChartArea1";
			legend2->Name = L"Legend1";
			this->chart3->Legends->Add(legend2);
			this->chart3->Location = System::Drawing::Point(12, 37);
			this->chart3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->chart3->Name = L"chart3";
			series5->BorderWidth = 2;
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series5->Color = System::Drawing::Color::Red;
			series5->Legend = L"Legend1";
			series5->Name = L"Исходный спектр";
			series6->BorderWidth = 2;
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series6->Color = System::Drawing::Color::Black;
			series6->Legend = L"Legend1";
			series6->Name = L"Очищенный спектр";
			this->chart3->Series->Add(series5);
			this->chart3->Series->Add(series6);
			this->chart3->Size = System::Drawing::Size(888, 490);
			this->chart3->TabIndex = 2;
			this->chart3->Text = L"chart3";
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->chart4);
			this->groupBox10->Location = System::Drawing::Point(1402, 633);
			this->groupBox10->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox10->Size = System::Drawing::Size(912, 538);
			this->groupBox10->TabIndex = 11;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Востановленный сигнал";
			// 
			// chart4
			// 
			chartArea3->AxisX->MaximumAutoSize = 10;
			chartArea3->AxisY->MaximumAutoSize = 10;
			chartArea3->Name = L"ChartArea1";
			this->chart4->ChartAreas->Add(chartArea3);
			legend3->DockedToChartArea = L"ChartArea1";
			legend3->Name = L"Legend1";
			this->chart4->Legends->Add(legend3);
			this->chart4->Location = System::Drawing::Point(12, 37);
			this->chart4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->chart4->Name = L"chart4";
			series7->BorderWidth = 2;
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series7->Color = System::Drawing::Color::Red;
			series7->Legend = L"Legend1";
			series7->Name = L"Исходный сигнал";
			series8->BorderWidth = 2;
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series8->Color = System::Drawing::Color::Black;
			series8->Legend = L"Legend1";
			series8->Name = L"Востановленный сигнал";
			this->chart4->Series->Add(series7);
			this->chart4->Series->Add(series8);
			this->chart4->Size = System::Drawing::Size(890, 490);
			this->chart4->TabIndex = 3;
			this->chart4->Text = L"chart4";
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->chart2);
			this->groupBox11->Location = System::Drawing::Point(1402, 23);
			this->groupBox11->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox11->Size = System::Drawing::Size(912, 538);
			this->groupBox11->TabIndex = 10;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Сигнал с шумом";
			// 
			// chart2
			// 
			chartArea4->AxisX->MaximumAutoSize = 10;
			chartArea4->AxisX->Minimum = 0;
			chartArea4->AxisY->MaximumAutoSize = 10;
			chartArea4->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea4);
			legend4->DockedToChartArea = L"ChartArea1";
			legend4->Name = L"Legend1";
			this->chart2->Legends->Add(legend4);
			this->chart2->Location = System::Drawing::Point(12, 37);
			this->chart2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->chart2->Name = L"chart2";
			series9->BorderWidth = 2;
			series9->ChartArea = L"ChartArea1";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series9->Color = System::Drawing::Color::Red;
			series9->Legend = L"Legend1";
			series9->Name = L"Сигнал с шумом";
			this->chart2->Series->Add(series9);
			this->chart2->Size = System::Drawing::Size(888, 490);
			this->chart2->TabIndex = 1;
			this->chart2->Text = L"chart2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2324, 1177);
			this->Controls->Add(this->groupBox10);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox11);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox9->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->groupBox10->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
			this->groupBox11->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

	         
};
}
