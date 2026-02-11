#pragma once

#include "AddEditForm.h"

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace MySql::Data::MySqlClient;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			this->cmbShape->SelectedIndex = 0;
			this->rnd = gcnew Random();
			this->colorDialog = gcnew ColorDialog();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		String^ connString = "Server=localhost;Database=HDB;Uid=ArthurSonin;Pwd=56756727127ger!;";
		System::ComponentModel::Container^ components;

		System::Windows::Forms::TabControl^ tabControl;
		System::Windows::Forms::TabPage^ tabData;
		System::Windows::Forms::TabPage^ tabShapes;

		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::Button^ btnAdd;
		System::Windows::Forms::Button^ btnEdit;
		System::Windows::Forms::Button^ btnDelete;
		System::Windows::Forms::TextBox^ txtSearch;
		System::Windows::Forms::Button^ btnSearch;
		System::Windows::Forms::Button^ btnSave;
		System::Windows::Forms::Button^ btnLoad;
		System::Data::DataTable^ table;

		System::Windows::Forms::Panel^ panelControls;
		System::Windows::Forms::Panel^ panelCanvas;

		System::Windows::Forms::ComboBox^ cmbShape;
		System::Windows::Forms::NumericUpDown^ nudCount;
		System::Windows::Forms::NumericUpDown^ nudSize;
		System::Windows::Forms::Label^ lblCount;
		System::Windows::Forms::Label^ lblShape;
		System::Windows::Forms::Label^ lblSize;
		System::Windows::Forms::Label^ lblLabelText;
		System::Windows::Forms::TextBox^ txtLabelText;
		System::Windows::Forms::Button^ btnColor;
		System::Windows::Forms::Button^ btnGenerate;
		System::Windows::Forms::Button^ btnClear;
		System::Windows::Forms::ColorDialog^ colorDialog;
		Bitmap^ canvasBitmap;
	private: System::Windows::Forms::PictureBox^ picCanvas;


		   Random^ rnd;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabData = (gcnew System::Windows::Forms::TabPage());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabShapes = (gcnew System::Windows::Forms::TabPage());
			this->panelCanvas = (gcnew System::Windows::Forms::Panel());
			this->picCanvas = (gcnew System::Windows::Forms::PictureBox());
			this->panelControls = (gcnew System::Windows::Forms::Panel());
			this->lblCount = (gcnew System::Windows::Forms::Label());
			this->nudCount = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblShape = (gcnew System::Windows::Forms::Label());
			this->cmbShape = (gcnew System::Windows::Forms::ComboBox());
			this->lblSize = (gcnew System::Windows::Forms::Label());
			this->nudSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblLabelText = (gcnew System::Windows::Forms::Label());
			this->txtLabelText = (gcnew System::Windows::Forms::TextBox());
			this->btnColor = (gcnew System::Windows::Forms::Button());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->tabControl->SuspendLayout();
			this->tabData->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabShapes->SuspendLayout();
			this->panelCanvas->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCanvas))->BeginInit();
			this->panelControls->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSize))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabData);
			this->tabControl->Controls->Add(this->tabShapes);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(1129, 617);
			this->tabControl->TabIndex = 0;
			// 
			// tabData
			// 
			this->tabData->Controls->Add(this->btnAdd);
			this->tabData->Controls->Add(this->btnEdit);
			this->tabData->Controls->Add(this->btnDelete);
			this->tabData->Controls->Add(this->txtSearch);
			this->tabData->Controls->Add(this->btnSearch);
			this->tabData->Controls->Add(this->btnSave);
			this->tabData->Controls->Add(this->btnLoad);
			this->tabData->Controls->Add(this->dataGridView1);
			this->tabData->Location = System::Drawing::Point(4, 25);
			this->tabData->Name = L"tabData";
			this->tabData->Size = System::Drawing::Size(1121, 588);
			this->tabData->TabIndex = 0;
			this->tabData->Text = L"Medicines";
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(8, 8);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 30);
			this->btnAdd->TabIndex = 0;
			this->btnAdd->Text = L"Add";
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->Location = System::Drawing::Point(90, 8);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(75, 30);
			this->btnEdit->TabIndex = 1;
			this->btnEdit->Text = L"Edit";
			this->btnEdit->Click += gcnew System::EventHandler(this, &MyForm::btnEdit_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(172, 8);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 30);
			this->btnDelete->TabIndex = 2;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm::btnDelete_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(260, 12);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(200, 22);
			this->txtSearch->TabIndex = 3;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(470, 8);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 30);
			this->btnSearch->TabIndex = 4;
			this->btnSearch->Text = L"Search";
			this->btnSearch->Click += gcnew System::EventHandler(this, &MyForm::btnSearch_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(555, 8);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 30);
			this->btnSave->TabIndex = 5;
			this->btnSave->Text = L"Save";
			this->btnSave->Click += gcnew System::EventHandler(this, &MyForm::btnSave_Click);
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(637, 8);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(75, 30);
			this->btnLoad->TabIndex = 6;
			this->btnLoad->Text = L"Load";
			this->btnLoad->Click += gcnew System::EventHandler(this, &MyForm::btnLoad_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->ColumnHeadersHeight = 29;
			this->dataGridView1->Location = System::Drawing::Point(8, 44);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1110, 568);
			this->dataGridView1->TabIndex = 7;
			// 
			// tabShapes
			// 
			this->tabShapes->Controls->Add(this->panelCanvas);
			this->tabShapes->Controls->Add(this->panelControls);
			this->tabShapes->Location = System::Drawing::Point(4, 25);
			this->tabShapes->Name = L"tabShapes";
			this->tabShapes->Size = System::Drawing::Size(1121, 588);
			this->tabShapes->TabIndex = 1;
			this->tabShapes->Text = L"Shapes";
			// 
			// panelCanvas
			// 
			this->panelCanvas->Controls->Add(this->picCanvas);
			this->panelCanvas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelCanvas->Location = System::Drawing::Point(228, 0);
			this->panelCanvas->Name = L"panelCanvas";
			this->panelCanvas->Size = System::Drawing::Size(893, 588);
			this->panelCanvas->TabIndex = 0;
			// 
			// picCanvas
			// 
			this->picCanvas->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->picCanvas->Location = System::Drawing::Point(0, 0);
			this->picCanvas->Name = L"picCanvas";
			this->picCanvas->Size = System::Drawing::Size(893, 588);
			this->picCanvas->TabIndex = 0;
			this->picCanvas->TabStop = false;
			// 
			// panelControls
			// 
			this->panelControls->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelControls->Controls->Add(this->lblCount);
			this->panelControls->Controls->Add(this->nudCount);
			this->panelControls->Controls->Add(this->lblShape);
			this->panelControls->Controls->Add(this->cmbShape);
			this->panelControls->Controls->Add(this->lblSize);
			this->panelControls->Controls->Add(this->nudSize);
			this->panelControls->Controls->Add(this->lblLabelText);
			this->panelControls->Controls->Add(this->txtLabelText);
			this->panelControls->Controls->Add(this->btnColor);
			this->panelControls->Controls->Add(this->btnGenerate);
			this->panelControls->Controls->Add(this->btnClear);
			this->panelControls->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelControls->Location = System::Drawing::Point(0, 0);
			this->panelControls->Name = L"panelControls";
			this->panelControls->Size = System::Drawing::Size(228, 588);
			this->panelControls->TabIndex = 1;
			// 
			// lblCount
			// 
			this->lblCount->Location = System::Drawing::Point(10, 12);
			this->lblCount->Name = L"lblCount";
			this->lblCount->Size = System::Drawing::Size(120, 20);
			this->lblCount->TabIndex = 0;
			this->lblCount->Text = L"Count";
			// 
			// nudCount
			// 
			this->nudCount->Location = System::Drawing::Point(130, 10);
			this->nudCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->nudCount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudCount->Name = L"nudCount";
			this->nudCount->Size = System::Drawing::Size(80, 22);
			this->nudCount->TabIndex = 1;
			this->nudCount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			// 
			// lblShape
			// 
			this->lblShape->Location = System::Drawing::Point(10, 45);
			this->lblShape->Name = L"lblShape";
			this->lblShape->Size = System::Drawing::Size(120, 20);
			this->lblShape->TabIndex = 2;
			this->lblShape->Text = L"Shape";
			// 
			// cmbShape
			// 
			this->cmbShape->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbShape->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Rectangle", L"Pentagon", L"Triangle" });
			this->cmbShape->Location = System::Drawing::Point(10, 68);
			this->cmbShape->Name = L"cmbShape";
			this->cmbShape->Size = System::Drawing::Size(200, 24);
			this->cmbShape->TabIndex = 3;
			// 
			// lblSize
			// 
			this->lblSize->Location = System::Drawing::Point(10, 100);
			this->lblSize->Name = L"lblSize";
			this->lblSize->Size = System::Drawing::Size(120, 20);
			this->lblSize->TabIndex = 4;
			this->lblSize->Text = L"Size (radius)";
			// 
			// nudSize
			// 
			this->nudSize->Location = System::Drawing::Point(130, 98);
			this->nudSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 120, 0, 0, 0 });
			this->nudSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->nudSize->Name = L"nudSize";
			this->nudSize->Size = System::Drawing::Size(80, 22);
			this->nudSize->TabIndex = 5;
			this->nudSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 40, 0, 0, 0 });
			// 
			// lblLabelText
			// 
			this->lblLabelText->Location = System::Drawing::Point(10, 135);
			this->lblLabelText->Name = L"lblLabelText";
			this->lblLabelText->Size = System::Drawing::Size(120, 20);
			this->lblLabelText->TabIndex = 6;
			this->lblLabelText->Text = L"Element text";
			// 
			// txtLabelText
			// 
			this->txtLabelText->Location = System::Drawing::Point(10, 158);
			this->txtLabelText->Name = L"txtLabelText";
			this->txtLabelText->Size = System::Drawing::Size(200, 22);
			this->txtLabelText->TabIndex = 7;
			this->txtLabelText->Text = L"Lbl";
			// 
			// btnColor
			// 
			this->btnColor->BackColor = System::Drawing::Color::Black;
			this->btnColor->Location = System::Drawing::Point(10, 195);
			this->btnColor->Name = L"btnColor";
			this->btnColor->Size = System::Drawing::Size(40, 30);
			this->btnColor->TabIndex = 8;
			this->btnColor->UseVisualStyleBackColor = false;
			this->btnColor->Click += gcnew System::EventHandler(this, &MyForm::btnColor_Click);
			// 
			// btnGenerate
			// 
			this->btnGenerate->BackColor = System::Drawing::Color::YellowGreen;
			this->btnGenerate->Location = System::Drawing::Point(60, 195);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(70, 30);
			this->btnGenerate->TabIndex = 9;
			this->btnGenerate->Text = L"Generate";
			this->btnGenerate->UseVisualStyleBackColor = false;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &MyForm::btnGenerate_Click);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::Crimson;
			this->btnClear->Location = System::Drawing::Point(135, 195);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 30);
			this->btnClear->TabIndex = 10;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1129, 617);
			this->Controls->Add(this->tabControl);
			this->Name = L"MyForm";
			this->Text = L"Lab 4";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl->ResumeLayout(false);
			this->tabData->ResumeLayout(false);
			this->tabData->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabShapes->ResumeLayout(false);
			this->panelCanvas->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCanvas))->EndInit();
			this->panelControls->ResumeLayout(false);
			this->panelControls->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSize))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (System::ComponentModel::LicenseManager::UsageMode == System::ComponentModel::LicenseUsageMode::Designtime) return;

		try {
			this->table = gcnew DataTable();

			MySqlConnection^ conn = gcnew MySqlConnection(connString);

			String^ query = "SELECT * FROM Medicines";

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(query, conn);

			adapter->Fill(this->table);

			this->dataGridView1->DataSource = this->table;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка підключення до БД: " + ex->Message);
		}
	}

	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		AddEditForm^ dlg = gcnew AddEditForm();
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			DataRow^ r = this->table->NewRow();
			r["type"] = dlg->MedType;
			r["brand"] = dlg->Brand;
			r["manufacturer"] = dlg->Manufacturer;
			r["expiry_date"] = dlg->ExpiryDate;
			r["supplier"] = dlg->Supplier;
			r["price"] = dlg->Price;
			this->table->Rows->Add(r);
		}
	}

	private: System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) { MessageBox::Show("Select a row", "Edit", MessageBoxButtons::OK); return; }
		DataRowView^ drv = (DataRowView^)this->dataGridView1->SelectedRows[0]->DataBoundItem;
		AddEditForm^ dlg = gcnew AddEditForm();
		dlg->MedType = (String^)drv->Row["type"];
		dlg->Brand = (String^)drv->Row["brand"];
		dlg->Manufacturer = (String^)drv->Row["manufacturer"];
		dlg->ExpiryDate = (DateTime)drv->Row["expiry_date"];
		dlg->Supplier = (String^)drv->Row["supplier"];
		dlg->Price = (Decimal)drv->Row["price"];
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			drv->Row["type"] = dlg->MedType;
			drv->Row["brand"] = dlg->Brand;
			drv->Row["manufacturer"] = dlg->Manufacturer;
			drv->Row["expiry_date"] = dlg->ExpiryDate;
			drv->Row["supplier"] = dlg->Supplier;
			drv->Row["price"] = dlg->Price;
		}
	}

	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) { MessageBox::Show("Select a row", "Delete", MessageBoxButtons::OK); return; }
		DataRowView^ drv = (DataRowView^)this->dataGridView1->SelectedRows[0]->DataBoundItem;
		if (MessageBox::Show("Delete?", "Confirm", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			drv->Row->Delete();
		}
	}

	private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ q = this->txtSearch->Text->Trim()->Replace("'", "''");
		if (String::IsNullOrEmpty(q)) { this->dataGridView1->DataSource = this->table; return; }
		String^ filter = String::Format("brand LIKE '%{0}%' OR type LIKE '%{0}%'", q);
		DataView^ dv = gcnew DataView(this->table);
		dv->RowFilter = filter;
		this->dataGridView1->DataSource = dv;
	}

	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ path = Path::Combine(Application::StartupPath, "medicines.xml");
			this->table->WriteXml(path);
			MessageBox::Show("Saved to " + path, "Save", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) { MessageBox::Show("Save failed: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); }
	}

	private: System::Void btnLoad_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ path = Path::Combine(Application::StartupPath, "medicines.xml");
			if (!File::Exists(path)) { MessageBox::Show("No file: " + path, "Load", MessageBoxButtons::OK); return; }
			this->table->Clear();
			this->table->ReadXml(path);
			this->dataGridView1->DataSource = this->table;
		}
		catch (Exception^ ex) { MessageBox::Show("Load failed: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); }
	}

	private: System::Void picCanvas_Resize(System::Object^ sender, System::EventArgs^ e) {
		if (this->picCanvas == nullptr) return;
		Bitmap^ newBmp = gcnew Bitmap(this->picCanvas->Width > 0 ? this->picCanvas->Width : 1, this->picCanvas->Height > 0 ? this->picCanvas->Height : 1);
		Graphics^ g = Graphics::FromImage(newBmp);
		g->Clear(System::Drawing::Color::White);
		if (this->canvasBitmap != nullptr) {
			g->DrawImage(this->canvasBitmap, 0, 0);
		}
		delete g;
		this->canvasBitmap = newBmp;
		this->picCanvas->Image = this->canvasBitmap;
	}

	private: System::Void btnColor_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->btnColor->BackColor = this->colorDialog->Color;
		}
	}

	private: System::Void btnGenerate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->picCanvas == nullptr) return;
		if (this->canvasBitmap == nullptr || this->canvasBitmap->Width != this->picCanvas->Width || this->canvasBitmap->Height != this->picCanvas->Height) {
			this->canvasBitmap = gcnew Bitmap(this->picCanvas->Width > 0 ? this->picCanvas->Width : 1, this->picCanvas->Height > 0 ? this->picCanvas->Height : 1);
			this->picCanvas->Image = this->canvasBitmap;
		}
		int count = (int)this->nudCount->Value;
		float r = (float)this->nudSize->Value; 
		String^ shape = (String^)this->cmbShape->SelectedItem;
		String^ labelText = this->txtLabelText->Text;
		Pen^ pen = gcnew Pen(this->btnColor->BackColor, 2);

		Graphics^ g = Graphics::FromImage(this->canvasBitmap);
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		for (int i = 0; i < count; ++i) {
			int lowerX = (int)r;
			int lowerY = (int)r;
			int upperX = this->picCanvas->Width - (int)r;
			int upperY = this->picCanvas->Height - (int)r;
			if (upperX <= lowerX) upperX = lowerX + 1;
			if (upperY <= lowerY) upperY = lowerY + 1;

			int x = this->rnd->Next(lowerX, upperX);
			int y = this->rnd->Next(lowerY, upperY);

			PointF center = PointF((float)x, (float)y);

			DrawShape(g, center, r, shape, pen);

			if (!String::IsNullOrEmpty(labelText)) {
				float fontSize = (r / 3.0f) > 6.0f ? (r / 3.0f) : 6.0f;
				System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", fontSize);
				System::Drawing::SizeF sz = g->MeasureString(labelText, font);
				System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(this->btnColor->BackColor);
				System::Drawing::PointF pt = System::Drawing::PointF(center.X - sz.Width / 2.0f, center.Y - sz.Height / 2.0f);
				g->DrawString(labelText, font, brush, pt);
				delete brush;
				delete font;
			}
		}

		delete g;
		this->picCanvas->Refresh();
	}

	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->picCanvas != nullptr && this->canvasBitmap != nullptr) {
			Graphics^ g = Graphics::FromImage(this->canvasBitmap);
			g->Clear(System::Drawing::Color::White);
			delete g;
			this->picCanvas->Refresh();
		}
	}

	private: void DrawShape(Graphics^ g, PointF center, float r, String^ shape, Pen^ pen) {
		Pen^ thickCirclePen = gcnew Pen(pen->Color, 2.5);

		thickCirclePen->DashStyle = System::Drawing::Drawing2D::DashStyle::Solid;

		g->DrawEllipse(thickCirclePen, center.X - r, center.Y - r, 2 * r, 2 * r);

		if (shape == L"Rectangle") {
			float side = 2.0f * r;
			g->DrawRectangle(pen, center.X - r, center.Y - r, side, side);
		}
		else if (shape == L"Triangle") {
			int n = 3;
			float R = 2.0f * r;
			array<PointF>^ points = gcnew array<PointF>(n);
			float start = -(float)System::Math::PI / 2.0f;
			for (int i = 0; i < n; ++i) {
				float angle = start + (float)i * 2.0f * (float)System::Math::PI / (float)n;
				points[i] = PointF(center.X + R * (float)System::Math::Cos(angle),
					center.Y + R * (float)System::Math::Sin(angle));
			}
			g->DrawPolygon(pen, points);
		}
		else if (shape == L"Pentagon") {
			int n = 5;
			float R = r / (float)System::Math::Cos(System::Math::PI / 5.0);
			array<PointF>^ points = gcnew array<PointF>(n);
			float start = -(float)System::Math::PI / 2.0f;
			for (int i = 0; i < n; ++i) {
				float angle = start + (float)i * 2.0f * (float)System::Math::PI / (float)n;
				points[i] = PointF(center.X + R * (float)System::Math::Cos(angle),
					center.Y + R * (float)System::Math::Sin(angle));
			}
			g->DrawPolygon(pen, points);
		}
		delete thickCirclePen;
	}
	};
}