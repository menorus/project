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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ N;
	private: System::Windows::Forms::Label^ fd;
	private: System::Windows::Forms::Label^ t01;
	private: System::Windows::Forms::Label^ S1;
	private: System::Windows::Forms::Label^ A1;






	private: System::Windows::Forms::Label^ to2;
	private: System::Windows::Forms::Label^ S2;
	private: System::Windows::Forms::Label^ A2;




	private: System::Windows::Forms::Label^ t03;
	private: System::Windows::Forms::Label^ S3;
	private: System::Windows::Forms::Label^ A3;
	private: System::Windows::Forms::Label^ Sh;
	private: System::Windows::Forms::Label^ Ah;
	private: System::Windows::Forms::TextBox^ textBoxN;
	private: System::Windows::Forms::TextBox^ textBoxfd;
	private: System::Windows::Forms::TextBox^ textBoxt01;
	private: System::Windows::Forms::TextBox^ textBoxS1;
	private: System::Windows::Forms::TextBox^ textBoxA1;










	private: System::Windows::Forms::TextBox^ textBoxt02;
	private: System::Windows::Forms::TextBox^ textBoxS2;
	private: System::Windows::Forms::TextBox^ textBoxA2;




	private: System::Windows::Forms::TextBox^ textBoxt03;
	private: System::Windows::Forms::TextBox^ textBoxS3;
	private: System::Windows::Forms::TextBox^ textBoxA3;
	private: System::Windows::Forms::TextBox^ textBoxSh;
	private: System::Windows::Forms::TextBox^ textBoxAh;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;





	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->N = (gcnew System::Windows::Forms::Label());
			this->fd = (gcnew System::Windows::Forms::Label());
			this->t01 = (gcnew System::Windows::Forms::Label());
			this->S1 = (gcnew System::Windows::Forms::Label());
			this->A1 = (gcnew System::Windows::Forms::Label());
			this->to2 = (gcnew System::Windows::Forms::Label());
			this->S2 = (gcnew System::Windows::Forms::Label());
			this->A2 = (gcnew System::Windows::Forms::Label());
			this->t03 = (gcnew System::Windows::Forms::Label());
			this->S3 = (gcnew System::Windows::Forms::Label());
			this->A3 = (gcnew System::Windows::Forms::Label());
			this->Sh = (gcnew System::Windows::Forms::Label());
			this->Ah = (gcnew System::Windows::Forms::Label());
			this->textBoxN = (gcnew System::Windows::Forms::TextBox());
			this->textBoxfd = (gcnew System::Windows::Forms::TextBox());
			this->textBoxt01 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxS1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxt02 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxS2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxt03 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxS3 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA3 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSh = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAh = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, -1);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->Name = L"исходный сигнал";
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Lime;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(898, 207);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(0, 212);
			this->chart2->Name = L"chart2";
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Lime;
			series3->Legend = L"Legend1";
			series3->Name = L"импульсная характеристика";
			this->chart2->Series->Add(series3);
			this->chart2->Size = System::Drawing::Size(898, 208);
			this->chart2->TabIndex = 1;
			this->chart2->Text = L"chart2";
			// 
			// chart3
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart3->Legends->Add(legend3);
			this->chart3->Location = System::Drawing::Point(0, 426);
			this->chart3->Name = L"chart3";
			series4->BorderWidth = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::Fuchsia;
			series4->Legend = L"Legend1";
			series4->Name = L"свертка";
			this->chart3->Series->Add(series4);
			this->chart3->Size = System::Drawing::Size(898, 207);
			this->chart3->TabIndex = 2;
			this->chart3->Text = L"chart3";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1052, 521);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(199, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Выполнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// N
			// 
			this->N->AutoSize = true;
			this->N->Location = System::Drawing::Point(923, 359);
			this->N->Name = L"N";
			this->N->Size = System::Drawing::Size(24, 16);
			this->N->TabIndex = 4;
			this->N->Text = L"N=";
			// 
			// fd
			// 
			this->fd->AutoSize = true;
			this->fd->Location = System::Drawing::Point(923, 391);
			this->fd->Name = L"fd";
			this->fd->Size = System::Drawing::Size(25, 16);
			this->fd->TabIndex = 5;
			this->fd->Text = L"fd=";
			// 
			// t01
			// 
			this->t01->AutoSize = true;
			this->t01->Location = System::Drawing::Point(9, 36);
			this->t01->Name = L"t01";
			this->t01->Size = System::Drawing::Size(24, 16);
			this->t01->TabIndex = 6;
			this->t01->Text = L"t0=";
			// 
			// S1
			// 
			this->S1->AutoSize = true;
			this->S1->Location = System::Drawing::Point(10, 71);
			this->S1->Name = L"S1";
			this->S1->Size = System::Drawing::Size(23, 16);
			this->S1->TabIndex = 7;
			this->S1->Text = L"S=";
			// 
			// A1
			// 
			this->A1->AutoSize = true;
			this->A1->Location = System::Drawing::Point(10, 100);
			this->A1->Name = L"A1";
			this->A1->Size = System::Drawing::Size(23, 16);
			this->A1->TabIndex = 8;
			this->A1->Text = L"A=";
			// 
			// to2
			// 
			this->to2->AutoSize = true;
			this->to2->Location = System::Drawing::Point(9, 32);
			this->to2->Name = L"to2";
			this->to2->Size = System::Drawing::Size(24, 16);
			this->to2->TabIndex = 9;
			this->to2->Text = L"t0=";
			// 
			// S2
			// 
			this->S2->AutoSize = true;
			this->S2->Location = System::Drawing::Point(11, 67);
			this->S2->Name = L"S2";
			this->S2->Size = System::Drawing::Size(23, 16);
			this->S2->TabIndex = 10;
			this->S2->Text = L"S=";
			// 
			// A2
			// 
			this->A2->AutoSize = true;
			this->A2->Location = System::Drawing::Point(10, 96);
			this->A2->Name = L"A2";
			this->A2->Size = System::Drawing::Size(23, 16);
			this->A2->TabIndex = 11;
			this->A2->Text = L"A=";
			// 
			// t03
			// 
			this->t03->AutoSize = true;
			this->t03->Location = System::Drawing::Point(9, 38);
			this->t03->Name = L"t03";
			this->t03->Size = System::Drawing::Size(24, 16);
			this->t03->TabIndex = 12;
			this->t03->Text = L"t0=";
			// 
			// S3
			// 
			this->S3->AutoSize = true;
			this->S3->Location = System::Drawing::Point(10, 70);
			this->S3->Name = L"S3";
			this->S3->Size = System::Drawing::Size(23, 16);
			this->S3->TabIndex = 13;
			this->S3->Text = L"S=";
			// 
			// A3
			// 
			this->A3->AutoSize = true;
			this->A3->Location = System::Drawing::Point(10, 96);
			this->A3->Name = L"A3";
			this->A3->Size = System::Drawing::Size(23, 16);
			this->A3->TabIndex = 14;
			this->A3->Text = L"A=";
			// 
			// Sh
			// 
			this->Sh->AutoSize = true;
			this->Sh->Location = System::Drawing::Point(16, 33);
			this->Sh->Name = L"Sh";
			this->Sh->Size = System::Drawing::Size(30, 16);
			this->Sh->TabIndex = 15;
			this->Sh->Text = L"Sh=";
			// 
			// Ah
			// 
			this->Ah->AutoSize = true;
			this->Ah->Location = System::Drawing::Point(9, 76);
			this->Ah->Name = L"Ah";
			this->Ah->Size = System::Drawing::Size(30, 16);
			this->Ah->TabIndex = 16;
			this->Ah->Text = L"Ah=";
			// 
			// textBoxN
			// 
			this->textBoxN->Location = System::Drawing::Point(953, 356);
			this->textBoxN->Name = L"textBoxN";
			this->textBoxN->Size = System::Drawing::Size(100, 22);
			this->textBoxN->TabIndex = 17;
			this->textBoxN->Text = L"32";
			// 
			// textBoxfd
			// 
			this->textBoxfd->Location = System::Drawing::Point(953, 391);
			this->textBoxfd->Name = L"textBoxfd";
			this->textBoxfd->Size = System::Drawing::Size(100, 22);
			this->textBoxfd->TabIndex = 18;
			this->textBoxfd->Text = L"10";
			// 
			// textBoxt01
			// 
			this->textBoxt01->Location = System::Drawing::Point(38, 30);
			this->textBoxt01->Name = L"textBoxt01";
			this->textBoxt01->Size = System::Drawing::Size(100, 22);
			this->textBoxt01->TabIndex = 19;
			this->textBoxt01->Text = L"0,5";
			// 
			// textBoxS1
			// 
			this->textBoxS1->Location = System::Drawing::Point(38, 65);
			this->textBoxS1->Name = L"textBoxS1";
			this->textBoxS1->Size = System::Drawing::Size(100, 22);
			this->textBoxS1->TabIndex = 20;
			this->textBoxS1->Text = L"0,1";
			// 
			// textBoxA1
			// 
			this->textBoxA1->Location = System::Drawing::Point(38, 97);
			this->textBoxA1->Name = L"textBoxA1";
			this->textBoxA1->Size = System::Drawing::Size(100, 22);
			this->textBoxA1->TabIndex = 21;
			this->textBoxA1->Text = L"1";
			// 
			// textBoxt02
			// 
			this->textBoxt02->Location = System::Drawing::Point(39, 32);
			this->textBoxt02->Name = L"textBoxt02";
			this->textBoxt02->Size = System::Drawing::Size(100, 22);
			this->textBoxt02->TabIndex = 22;
			this->textBoxt02->Text = L"1,5";
			// 
			// textBoxS2
			// 
			this->textBoxS2->Location = System::Drawing::Point(40, 64);
			this->textBoxS2->Name = L"textBoxS2";
			this->textBoxS2->Size = System::Drawing::Size(100, 22);
			this->textBoxS2->TabIndex = 23;
			this->textBoxS2->Text = L"0,1";
			// 
			// textBoxA2
			// 
			this->textBoxA2->Location = System::Drawing::Point(40, 93);
			this->textBoxA2->Name = L"textBoxA2";
			this->textBoxA2->Size = System::Drawing::Size(100, 22);
			this->textBoxA2->TabIndex = 24;
			this->textBoxA2->Text = L"2";
			// 
			// textBoxt03
			// 
			this->textBoxt03->Location = System::Drawing::Point(39, 35);
			this->textBoxt03->Name = L"textBoxt03";
			this->textBoxt03->Size = System::Drawing::Size(100, 22);
			this->textBoxt03->TabIndex = 25;
			this->textBoxt03->Text = L"2,5";
			// 
			// textBoxS3
			// 
			this->textBoxS3->Location = System::Drawing::Point(39, 70);
			this->textBoxS3->Name = L"textBoxS3";
			this->textBoxS3->Size = System::Drawing::Size(100, 22);
			this->textBoxS3->TabIndex = 26;
			this->textBoxS3->Text = L"0,1";
			// 
			// textBoxA3
			// 
			this->textBoxA3->Location = System::Drawing::Point(39, 99);
			this->textBoxA3->Name = L"textBoxA3";
			this->textBoxA3->Size = System::Drawing::Size(100, 22);
			this->textBoxA3->TabIndex = 27;
			this->textBoxA3->Text = L"1";
			// 
			// textBoxSh
			// 
			this->textBoxSh->Location = System::Drawing::Point(52, 30);
			this->textBoxSh->Name = L"textBoxSh";
			this->textBoxSh->Size = System::Drawing::Size(100, 22);
			this->textBoxSh->TabIndex = 28;
			this->textBoxSh->Text = L"0,3";
			// 
			// textBoxAh
			// 
			this->textBoxAh->Location = System::Drawing::Point(52, 73);
			this->textBoxAh->Name = L"textBoxAh";
			this->textBoxAh->Size = System::Drawing::Size(100, 22);
			this->textBoxAh->TabIndex = 29;
			this->textBoxAh->Text = L"1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBoxt01);
			this->groupBox1->Controls->Add(this->t01);
			this->groupBox1->Controls->Add(this->S1);
			this->groupBox1->Controls->Add(this->A1);
			this->groupBox1->Controls->Add(this->textBoxS1);
			this->groupBox1->Controls->Add(this->textBoxA1);
			this->groupBox1->Location = System::Drawing::Point(904, 25);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(159, 136);
			this->groupBox1->TabIndex = 30;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"1 купол";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBoxt02);
			this->groupBox2->Controls->Add(this->to2);
			this->groupBox2->Controls->Add(this->S2);
			this->groupBox2->Controls->Add(this->A2);
			this->groupBox2->Controls->Add(this->textBoxS2);
			this->groupBox2->Controls->Add(this->textBoxA2);
			this->groupBox2->Location = System::Drawing::Point(1069, 25);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(142, 136);
			this->groupBox2->TabIndex = 31;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"2 купол";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBoxt03);
			this->groupBox3->Controls->Add(this->t03);
			this->groupBox3->Controls->Add(this->S3);
			this->groupBox3->Controls->Add(this->A3);
			this->groupBox3->Controls->Add(this->textBoxS3);
			this->groupBox3->Controls->Add(this->textBoxA3);
			this->groupBox3->Location = System::Drawing::Point(1215, 25);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(156, 136);
			this->groupBox3->TabIndex = 32;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"3 купол";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBoxSh);
			this->groupBox4->Controls->Add(this->Sh);
			this->groupBox4->Controls->Add(this->Ah);
			this->groupBox4->Controls->Add(this->textBoxAh);
			this->groupBox4->Location = System::Drawing::Point(904, 177);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(173, 100);
			this->groupBox4->TabIndex = 33;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"для импульсной характеристики";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1016, 474);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(146, 22);
			this->textBox1->TabIndex = 34;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(920, 474);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 16);
			this->label1->TabIndex = 35;
			this->label1->Text = L"Отклонение:";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1375, 636);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBoxfd);
			this->Controls->Add(this->textBoxN);
			this->Controls->Add(this->fd);
			this->Controls->Add(this->N);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
};
}
