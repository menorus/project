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
	private: System::Windows::Forms::Button^ button1;






	private: System::Windows::Forms::TextBox^ textBox2;





	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;




	private: System::Windows::Forms::Label^ label2;




	private: System::Windows::Forms::TextBox^ textBox7;


	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::GroupBox^ groupBox4;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;


	private: System::Windows::Forms::GroupBox^ groupBox6;

	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart4;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::CheckBox^ checkBox1;







	protected:




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->chart1);
			this->groupBox1->Location = System::Drawing::Point(24, 23);
			this->groupBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox1->Size = System::Drawing::Size(916, 212);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Сигнал";
			// 
			// chart1
			// 
			chartArea4->AxisX->MaximumAutoSize = 10;
			chartArea4->AxisX->Minimum = 0;
			chartArea4->AxisY->MaximumAutoSize = 5;
			chartArea4->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea4);
			this->chart1->Location = System::Drawing::Point(12, 37);
			this->chart1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->chart1->Name = L"chart1";
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series7->Color = System::Drawing::Color::Black;
			series7->Name = L"Series1";
			series7->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			series7->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			this->chart1->Series->Add(series7);
			this->chart1->Size = System::Drawing::Size(892, 163);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 37);
			this->button1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 44);
			this->button1->TabIndex = 1;
			this->button1->Text = L"СГЕНЕРИРОВАТЬ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 98);
			this->textBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(196, 31);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"100";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Location = System::Drawing::Point(952, 340);
			this->groupBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox2->Size = System::Drawing::Size(286, 306);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Управление";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(174, 100);
			this->checkBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(102, 29);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"AUTO";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 254);
			this->textBox5->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(196, 31);
			this->textBox5->TabIndex = 7;
			this->textBox5->Text = L"10";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(18, 198);
			this->button3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 44);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Акаекое";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(18, 92);
			this->button2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 44);
			this->button2->TabIndex = 5;
			this->button2->Text = L"пороговый";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 148);
			this->textBox4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(196, 31);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"1";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Location = System::Drawing::Point(952, 23);
			this->groupBox3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox3->Size = System::Drawing::Size(286, 306);
			this->groupBox3->TabIndex = 12;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Настройка сигнала";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 225);
			this->label5->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(218, 25);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Кол-во отсчетов 2^N";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 256);
			this->textBox3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(196, 31);
			this->textBox3->TabIndex = 17;
			this->textBox3->Text = L"9";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 142);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 25);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Кол-во синусоид";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 173);
			this->textBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(196, 31);
			this->textBox1->TabIndex = 15;
			this->textBox1->Text = L"3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 67);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(250, 25);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Частота дискретизации";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(6, 90);
			this->textBox7->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(196, 31);
			this->textBox7->TabIndex = 5;
			this->textBox7->Text = L"---";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(6, 165);
			this->textBox9->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(196, 31);
			this->textBox9->TabIndex = 14;
			this->textBox9->Text = L"---";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label4);
			this->groupBox4->Controls->Add(this->label3);
			this->groupBox4->Controls->Add(this->textBox7);
			this->groupBox4->Controls->Add(this->textBox9);
			this->groupBox4->Location = System::Drawing::Point(952, 658);
			this->groupBox4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox4->Size = System::Drawing::Size(286, 212);
			this->groupBox4->TabIndex = 15;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Оптимальная степень АР модели";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 135);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(217, 25);
			this->label4->TabIndex = 16;
			this->label4->Text = L"по критерию Акаике";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 60);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(203, 25);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Пороговм методом";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->chart4);
			this->groupBox6->Location = System::Drawing::Point(24, 565);
			this->groupBox6->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox6->Size = System::Drawing::Size(916, 304);
			this->groupBox6->TabIndex = 3;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"ИКА";
			// 
			// chart4
			// 
			chartArea5->AxisX->MaximumAutoSize = 10;
			chartArea5->AxisX->Minimum = 0;
			chartArea5->AxisY->MaximumAutoSize = 5;
			chartArea5->Name = L"ChartArea1";
			this->chart4->ChartAreas->Add(chartArea5);
			this->chart4->Location = System::Drawing::Point(12, 37);
			this->chart4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->chart4->Name = L"chart4";
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series8->Color = System::Drawing::Color::Black;
			series8->Name = L"Series1";
			series8->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			series8->YValuesPerPoint = 2;
			series8->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			series9->ChartArea = L"ChartArea1";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			series9->Name = L"Series2";
			series9->YValuesPerPoint = 2;
			this->chart4->Series->Add(series8);
			this->chart4->Series->Add(series9);
			this->chart4->Size = System::Drawing::Size(892, 256);
			this->chart4->TabIndex = 1;
			this->chart4->Text = L"chart4";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->chart3);
			this->groupBox7->Location = System::Drawing::Point(24, 246);
			this->groupBox7->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->groupBox7->Size = System::Drawing::Size(916, 308);
			this->groupBox7->TabIndex = 2;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"сингулярные числа";
			// 
			// chart3
			// 
			chartArea6->AxisX->MaximumAutoSize = 10;
			chartArea6->AxisX->Minimum = 0;
			chartArea6->AxisY->MaximumAutoSize = 5;
			chartArea6->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea6);
			this->chart3->Location = System::Drawing::Point(12, 25);
			this->chart3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->chart3->Name = L"chart3";
			series10->ChartArea = L"ChartArea1";
			series10->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series10->Color = System::Drawing::Color::Black;
			series10->Name = L"Series1";
			series10->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			series10->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			series11->ChartArea = L"ChartArea1";
			series11->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series11->Color = System::Drawing::Color::Red;
			series11->Name = L"Series2";
			series12->ChartArea = L"ChartArea1";
			series12->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series12->Name = L"Series3";
			series12->YValuesPerPoint = 2;
			this->chart3->Series->Add(series10);
			this->chart3->Series->Add(series11);
			this->chart3->Series->Add(series12);
			this->chart3->Size = System::Drawing::Size(892, 271);
			this->chart3->TabIndex = 1;
			this->chart3->Text = L"chart3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1252, 883);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
			this->groupBox7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
};
}
