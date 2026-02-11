#pragma once

#include <vcclr.h>

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AddEditForm : public System::Windows::Forms::Form
	{
	public:
		AddEditForm(void)
		{
			InitializeComponent();
		}

		// Properties expected by MyForm
		property String^ MedType {
			String^ get() { return this->txtType->Text; }
			void set(String^ value) { this->txtType->Text = value; }
		}
		property String^ Brand {
			String^ get() { return this->txtBrand->Text; }
			void set(String^ value) { this->txtBrand->Text = value; }
		}
		property String^ Manufacturer {
			String^ get() { return this->txtManufacturer->Text; }
			void set(String^ value) { this->txtManufacturer->Text = value; }
		}
		property DateTime ExpiryDate {
			DateTime get() { return this->dtpExpiry->Value; }
			void set(DateTime value) { this->dtpExpiry->Value = value; }
		}
		property String^ Supplier {
			String^ get() { return this->txtSupplier->Text; }
			void set(String^ value) { this->txtSupplier->Text = value; }
		}
		property Decimal Price {
			Decimal get() {
				Decimal tmp = Decimal(0);
				Decimal::TryParse(this->txtPrice->Text, tmp);
				return tmp;
			}
			void set(Decimal value) { this->txtPrice->Text = value.ToString(); }
		}

	protected:
		~AddEditForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// Labels
		System::Windows::Forms::Label^ lblType;
		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblManufacturer;
		System::Windows::Forms::Label^ lblExpiry;
		System::Windows::Forms::Label^ lblSupplier;
		System::Windows::Forms::Label^ lblPrice;

		// Inputs
		System::Windows::Forms::TextBox^ txtType;
		System::Windows::Forms::TextBox^ txtBrand;
		System::Windows::Forms::TextBox^ txtManufacturer;
		System::Windows::Forms::DateTimePicker^ dtpExpiry;
		System::Windows::Forms::TextBox^ txtSupplier;
		System::Windows::Forms::TextBox^ txtPrice;

		// Buttons
		System::Windows::Forms::Button^ btnOK;
		System::Windows::Forms::Button^ btnCancel;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblType = (gcnew System::Windows::Forms::Label());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->lblManufacturer = (gcnew System::Windows::Forms::Label());
			this->lblExpiry = (gcnew System::Windows::Forms::Label());
			this->lblSupplier = (gcnew System::Windows::Forms::Label());
			this->lblPrice = (gcnew System::Windows::Forms::Label());

			this->txtType = (gcnew System::Windows::Forms::TextBox());
			this->txtBrand = (gcnew System::Windows::Forms::TextBox());
			this->txtManufacturer = (gcnew System::Windows::Forms::TextBox());
			this->dtpExpiry = (gcnew System::Windows::Forms::DateTimePicker());
			this->txtSupplier = (gcnew System::Windows::Forms::TextBox());
			this->txtPrice = (gcnew System::Windows::Forms::TextBox());

			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());

			this->SuspendLayout();

			// lblType
			this->lblType->AutoSize = true;
			this->lblType->Location = System::Drawing::Point(12, 15);
			this->lblType->Name = L"lblType";
			this->lblType->Size = System::Drawing::Size(35, 17);
			this->lblType->Text = L"Type";

			// txtType
			this->txtType->Location = System::Drawing::Point(120, 12);
			this->txtType->Name = L"txtType";
			this->txtType->Size = System::Drawing::Size(200, 22);

			// lblBrand
			this->lblBrand->AutoSize = true;
			this->lblBrand->Location = System::Drawing::Point(12, 50);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(44, 17);
			this->lblBrand->Text = L"Brand";

			// txtBrand
			this->txtBrand->Location = System::Drawing::Point(120, 47);
			this->txtBrand->Name = L"txtBrand";
			this->txtBrand->Size = System::Drawing::Size(200, 22);

			// lblManufacturer
			this->lblManufacturer->AutoSize = true;
			this->lblManufacturer->Location = System::Drawing::Point(12, 85);
			this->lblManufacturer->Name = L"lblManufacturer";
			this->lblManufacturer->Size = System::Drawing::Size(86, 17);
			this->lblManufacturer->Text = L"Manufacturer";

			// txtManufacturer
			this->txtManufacturer->Location = System::Drawing::Point(120, 82);
			this->txtManufacturer->Name = L"txtManufacturer";
			this->txtManufacturer->Size = System::Drawing::Size(200, 22);

			// lblExpiry
			this->lblExpiry->AutoSize = true;
			this->lblExpiry->Location = System::Drawing::Point(12, 120);
			this->lblExpiry->Name = L"lblExpiry";
			this->lblExpiry->Size = System::Drawing::Size(45, 17);
			this->lblExpiry->Text = L"Expiry";

			// dtpExpiry
			this->dtpExpiry->Location = System::Drawing::Point(120, 115);
			this->dtpExpiry->Name = L"dtpExpiry";
			this->dtpExpiry->Size = System::Drawing::Size(200, 22);

			// lblSupplier
			this->lblSupplier->AutoSize = true;
			this->lblSupplier->Location = System::Drawing::Point(12, 155);
			this->lblSupplier->Name = L"lblSupplier";
			this->lblSupplier->Size = System::Drawing::Size(57, 17);
			this->lblSupplier->Text = L"Supplier";

			// txtSupplier
			this->txtSupplier->Location = System::Drawing::Point(120, 152);
			this->txtSupplier->Name = L"txtSupplier";
			this->txtSupplier->Size = System::Drawing::Size(200, 22);

			// lblPrice
			this->lblPrice->AutoSize = true;
			this->lblPrice->Location = System::Drawing::Point(12, 190);
			this->lblPrice->Name = L"lblPrice";
			this->lblPrice->Size = System::Drawing::Size(37, 17);
			this->lblPrice->Text = L"Price";

			// txtPrice
			this->txtPrice->Location = System::Drawing::Point(120, 187);
			this->txtPrice->Name = L"txtPrice";
			this->txtPrice->Size = System::Drawing::Size(200, 22);

			// btnOK
			this->btnOK->Location = System::Drawing::Point(120, 230);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(75, 30);
			this->btnOK->Text = L"OK";
			this->btnOK->Click += gcnew System::EventHandler(this, &AddEditForm::btnOK_Click);

			// btnCancel
			this->btnCancel->Location = System::Drawing::Point(245, 230);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 30);
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;

			// AddEditForm
			this->AcceptButton = this->btnOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 280);
			this->Controls->Add(this->lblType);
			this->Controls->Add(this->txtType);
			this->Controls->Add(this->lblBrand);
			this->Controls->Add(this->txtBrand);
			this->Controls->Add(this->lblManufacturer);
			this->Controls->Add(this->txtManufacturer);
			this->Controls->Add(this->lblExpiry);
			this->Controls->Add(this->dtpExpiry);
			this->Controls->Add(this->lblSupplier);
			this->Controls->Add(this->txtSupplier);
			this->Controls->Add(this->lblPrice);
			this->Controls->Add(this->txtPrice);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->btnCancel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddEditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Add / Edit Medicine";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
		// Basic validation: required fields and numeric price
		if (String::IsNullOrWhiteSpace(this->txtType->Text)) {
			MessageBox::Show("Type required", "Validation", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (String::IsNullOrWhiteSpace(this->txtBrand->Text)) {
			MessageBox::Show("Brand required", "Validation", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		Decimal price;
		if (!Decimal::TryParse(this->txtPrice->Text, price)) {
			MessageBox::Show("Price must be a valid decimal number", "Validation", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	};
}
