#pragma once

#include <cmath>

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components) delete components;
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label9;

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
		
		PointF CalculateHermite(float t, PointF p1, PointF p2, PointF v1, PointF v2) {
			float t2 = t * t;
			float t3 = t2 * t;

			// Базисні функції поліномів Ерміта
			float h1 = 2 * t3 - 3 * t2 + 1;
			float h2 = t3 - 2 * t2 + t;
			float h3 = -2 * t3 + 3 * t2;
			float h4 = t3 - t2;

			float x = h1 * p1.X + h2 * v1.X + h3 * p2.X + h4 * v2.X;
			float y = h1 * p1.Y + h2 * v1.Y + h3 * p2.Y + h4 * v2.Y;

			return PointF(x, y);
		}

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(69, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"100";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(69, 35);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"200";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(69, 64);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"350";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(69, 93);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"200";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(69, 122);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 4;
			this->textBox5->Text = L"0";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(69, 151);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 5;
			this->textBox6->Text = L"-300";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(69, 180);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 22);
			this->textBox7->TabIndex = 6;
			this->textBox7->Text = L"0";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(69, 209);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 22);
			this->textBox8->TabIndex = 7;
			this->textBox8->Text = L"300";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(69, 238);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 29);
			this->button1->TabIndex = 8;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(175, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(698, 556);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 10;
			this->label1->Text = L"P1(x1)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 16);
			this->label2->TabIndex = 11;
			this->label2->Text = L"P1(y1)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 16);
			this->label3->TabIndex = 12;
			this->label3->Text = L"P2(x2)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 93);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 16);
			this->label4->TabIndex = 13;
			this->label4->Text = L"P2(y2)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 122);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"V1(vx1)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 151);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(52, 16);
			this->label6->TabIndex = 15;
			this->label6->Text = L"V1(vy1)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 180);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(51, 16);
			this->label7->TabIndex = 16;
			this->label7->Text = L"V2(vx2)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(5, 209);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(52, 16);
			this->label8->TabIndex = 17;
			this->label8->Text = L"V2(vy2)";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(13, 13);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(887, 597);
			this->tabControl1->TabIndex = 18;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->textBox6);
			this->tabPage1->Controls->Add(this->textBox7);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->textBox8);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(879, 568);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Ermit";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->textBox9);
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(879, 568);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Kylbabka K";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(22, 16);
			this->label9->TabIndex = 3;
			this->label9->Text = L"K=";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 34);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 52);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Намалювати петрушку";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(34, 6);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(132, 22);
			this->textBox9->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox2->Location = System::Drawing::Point(172, 6);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(704, 559);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox2_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(912, 616);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Invalidate(); // Викликаємо перерисовку PictureBox
	}

		   void DrawDandelion(Graphics^ g, Pen^ pen, float x, float y, float length, float angle, int order) {
			   if (order <= 0) return;

			   // Обчислюємо кінцеву точку поточного відрізка
			   float xEnd = x + (float)(length * Math::Cos(angle));
			   float yEnd = y + (float)(length * Math::Sin(angle));

			   g->DrawLine(pen, x, y, xEnd, yEnd);

			   // Для "Кульбабки" зазвичай випускають кілька гілок на кінці
			   // Можна варіювати кількість гілок (наприклад, 5) та кут розхилу
			   int branches = 5;
			   float spreadAngle = 1.2f; // загальний кут розхилу в радіанах

			   for (int i = 0; i < branches; i++) {
				   float newAngle = angle - (spreadAngle / 2) + (i * spreadAngle / (branches - 1));
				   // Кожна наступна гілка коротша (наприклад, на 0.6)
				   DrawDandelion(g, pen, xEnd, yEnd, length * 0.6f, newAngle, order - 1);
			   }
		   }
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;


		try {
			// Зчитуємо дані (зберігаємо ваші назви textBox1-8)
			PointF P1(float::Parse(textBox1->Text), float::Parse(textBox2->Text));
			PointF P2(float::Parse(textBox3->Text), float::Parse(textBox4->Text));
			PointF V1(float::Parse(textBox5->Text), float::Parse(textBox6->Text));
			PointF V2(float::Parse(textBox7->Text), float::Parse(textBox8->Text));

			Pen^ curvePen = gcnew Pen(Color::Blue, 2);
			PointF prevPoint = P1;

			// Цикл малювання Ерміта
			for (float t = 0.01f; t <= 1.0f; t += 0.01f) {
				PointF currPoint = CalculateHermite(t, P1, P2, V1, V2);
				g->DrawLine(curvePen, prevPoint, currPoint);
				prevPoint = currPoint;
			}

			// Позначаємо контрольні точки
			g->FillEllipse(Brushes::Red, (float)(P1.X - 4), (float)(P1.Y - 4), 8.0f, 8.0f);
			g->FillEllipse(Brushes::Red, (float)(P2.X - 4), (float)(P2.Y - 4), 8.0f, 8.0f);
		}
		catch (...) {
			// Якщо дані некоректні, просто виводимо підказку
			g->DrawString("Введіть коректні числа", this->Font, Brushes::Gray, 10, 10);
		}
	}

		   private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			   Graphics^ g = e->Graphics;
			   g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			   try {
				   int K = int::Parse(textBox9->Text); // Порядок фракталу

				   // Початкові координати (центр або низ екрану)
				   float startX = pictureBox2->Width / 2.0f;
				   float startY = pictureBox2->Height * 0.8f;
				   float initialLength = 100.0f;
				   float initialAngle = -Math::PI / 2.0f; // Вгору

				   Pen^ dandelionPen = gcnew Pen(Color::Green, 1);

				   // Запускаємо рекурсію
				   DrawDandelion(g, dandelionPen, startX, startY, initialLength, initialAngle, K);
			   }
			   catch (...) {
				   g->DrawString("Введіть коректний порядок K", this->Font, Brushes::Red, 10, 10);
			   }
		   }

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBox2->Invalidate();
}
};
}
