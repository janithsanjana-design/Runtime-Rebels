#pragma once
#include "Db.h"
#include "UiTheme.h"

namespace VehicleRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>Register drivers. Customers can request them only while hiring a vehicle.  (open this file in the Visual Studio designer to edit the layout)</summary>
	public ref class DriverForm : public System::Windows::Forms::Form
	{
	public:
		DriverForm(void)
		{
			InitializeComponent();
			dtExpiry->MinDate = DateTime::Today.AddDays(1);
			dtExpiry->Value = DateTime::Today.AddYears(1);
			UiTheme::StyleGrid(dgv);
			LoadGrid();
		}

	protected:
		~DriverForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  pnlBody;
	private: System::Windows::Forms::Panel^  pnlGrid;
	private: System::Windows::Forms::DataGridView^  dgv;
	private: System::Windows::Forms::Panel^  pnlGridBottom;
	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::Panel^  pnlInput;
	private: System::Windows::Forms::Label^  lblHeadDriver;
	private: System::Windows::Forms::Label^  lblFor_txtName;
	private: System::Windows::Forms::TextBox^  txtName;
	private: System::Windows::Forms::Label^  lblFor_txtNic;
	private: System::Windows::Forms::TextBox^  txtNic;
	private: System::Windows::Forms::Label^  lblFor_txtPhone;
	private: System::Windows::Forms::TextBox^  txtPhone;
	private: System::Windows::Forms::Label^  lblFor_txtAddress;
	private: System::Windows::Forms::TextBox^  txtAddress;
	private: System::Windows::Forms::Label^  lblFor_txtLicence;
	private: System::Windows::Forms::TextBox^  txtLicence;
	private: System::Windows::Forms::Label^  lblFor_dtExpiry;
	private: System::Windows::Forms::DateTimePicker^  dtExpiry;
	private: System::Windows::Forms::Label^  lblFor_numCharge;
	private: System::Windows::Forms::NumericUpDown^  numCharge;
	private: System::Windows::Forms::Label^  lblNote;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Label^  lblTitle;
	private: System::Windows::Forms::Button^  btnBack;
	private: System::Windows::Forms::Panel^  pnlHeader;

	private:
		/// <summary>Required designer variable.</summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>Designer-managed code: edit the layout in the designer, not by hand.</summary>
		void InitializeComponent(void)
		{
			this->pnlBody = (gcnew System::Windows::Forms::Panel());
			this->pnlGrid = (gcnew System::Windows::Forms::Panel());
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->pnlGridBottom = (gcnew System::Windows::Forms::Panel());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->pnlInput = (gcnew System::Windows::Forms::Panel());
			this->lblHeadDriver = (gcnew System::Windows::Forms::Label());
			this->lblFor_txtName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtNic = (gcnew System::Windows::Forms::Label());
			this->txtNic = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtPhone = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtAddress = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtLicence = (gcnew System::Windows::Forms::Label());
			this->txtLicence = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_dtExpiry = (gcnew System::Windows::Forms::Label());
			this->dtExpiry = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblFor_numCharge = (gcnew System::Windows::Forms::Label());
			this->numCharge = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblNote = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCharge))->BeginInit();
			this->pnlBody->SuspendLayout();
			this->pnlGrid->SuspendLayout();
			this->pnlGridBottom->SuspendLayout();
			this->pnlInput->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->SuspendLayout();
			//
			// pnlBody
			//
			this->pnlBody->Controls->Add(this->pnlGrid);
			this->pnlBody->Controls->Add(this->pnlInput);
			this->pnlBody->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlBody->Padding = System::Windows::Forms::Padding(16, 16, 16, 16);
			this->pnlBody->Size = System::Drawing::Size(1150, 636);
			this->pnlBody->Name = L"pnlBody";
			this->pnlBody->TabIndex = 0;
			//
			// pnlGrid
			//
			this->pnlGrid->Controls->Add(this->dgv);
			this->pnlGrid->Controls->Add(this->pnlGridBottom);
			this->pnlGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlGrid->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->pnlGrid->Name = L"pnlGrid";
			this->pnlGrid->TabIndex = 0;
			//
			// dgv
			//
			this->dgv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv->Name = L"dgv";
			this->dgv->TabIndex = 0;
			//
			// pnlGridBottom
			//
			this->pnlGridBottom->Controls->Add(this->btnDelete);
			this->pnlGridBottom->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pnlGridBottom->Size = System::Drawing::Size(600, 52);
			this->pnlGridBottom->Name = L"pnlGridBottom";
			this->pnlGridBottom->TabIndex = 1;
			//
			// btnDelete
			//
			this->btnDelete->BackColor = System::Drawing::Color::FromArgb(214, 69, 69);
			this->btnDelete->FlatAppearance->BorderSize = 0;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnDelete->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->btnDelete->Location = System::Drawing::Point(10, 8);
			this->btnDelete->Size = System::Drawing::Size(160, 38);
			this->btnDelete->Text = L"Delete Selected";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->TabIndex = 0;
			this->btnDelete->Click += gcnew System::EventHandler(this, &DriverForm::btnDelete_Click);
			//
			// pnlInput
			//
			this->pnlInput->Controls->Add(this->lblHeadDriver);
			this->pnlInput->Controls->Add(this->lblFor_txtName);
			this->pnlInput->Controls->Add(this->txtName);
			this->pnlInput->Controls->Add(this->lblFor_txtNic);
			this->pnlInput->Controls->Add(this->txtNic);
			this->pnlInput->Controls->Add(this->lblFor_txtPhone);
			this->pnlInput->Controls->Add(this->txtPhone);
			this->pnlInput->Controls->Add(this->lblFor_txtAddress);
			this->pnlInput->Controls->Add(this->txtAddress);
			this->pnlInput->Controls->Add(this->lblFor_txtLicence);
			this->pnlInput->Controls->Add(this->txtLicence);
			this->pnlInput->Controls->Add(this->lblFor_dtExpiry);
			this->pnlInput->Controls->Add(this->dtExpiry);
			this->pnlInput->Controls->Add(this->lblFor_numCharge);
			this->pnlInput->Controls->Add(this->numCharge);
			this->pnlInput->Controls->Add(this->lblNote);
			this->pnlInput->Controls->Add(this->btnSave);
			this->pnlInput->AutoScroll = true;
			this->pnlInput->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlInput->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlInput->Size = System::Drawing::Size(420, 600);
			this->pnlInput->Name = L"pnlInput";
			this->pnlInput->TabIndex = 1;
			//
			// lblHeadDriver
			//
			this->lblHeadDriver->AutoSize = true;
			this->lblHeadDriver->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHeadDriver->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblHeadDriver->Location = System::Drawing::Point(15, 10);
			this->lblHeadDriver->Text = L"Driver details";
			this->lblHeadDriver->Name = L"lblHeadDriver";
			this->lblHeadDriver->TabIndex = 0;
			//
			// lblFor_txtName
			//
			this->lblFor_txtName->AutoSize = true;
			this->lblFor_txtName->Location = System::Drawing::Point(15, 43);
			this->lblFor_txtName->Text = L"Full name";
			this->lblFor_txtName->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtName->Name = L"lblFor_txtName";
			this->lblFor_txtName->TabIndex = 1;
			//
			// txtName
			//
			this->txtName->Location = System::Drawing::Point(150, 40);
			this->txtName->Size = System::Drawing::Size(245, 25);
			this->txtName->Name = L"txtName";
			this->txtName->TabIndex = 2;
			//
			// lblFor_txtNic
			//
			this->lblFor_txtNic->AutoSize = true;
			this->lblFor_txtNic->Location = System::Drawing::Point(15, 77);
			this->lblFor_txtNic->Text = L"NIC";
			this->lblFor_txtNic->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtNic->Name = L"lblFor_txtNic";
			this->lblFor_txtNic->TabIndex = 3;
			//
			// txtNic
			//
			this->txtNic->Location = System::Drawing::Point(150, 74);
			this->txtNic->Size = System::Drawing::Size(245, 25);
			this->txtNic->Name = L"txtNic";
			this->txtNic->TabIndex = 4;
			//
			// lblFor_txtPhone
			//
			this->lblFor_txtPhone->AutoSize = true;
			this->lblFor_txtPhone->Location = System::Drawing::Point(15, 111);
			this->lblFor_txtPhone->Text = L"Phone";
			this->lblFor_txtPhone->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtPhone->Name = L"lblFor_txtPhone";
			this->lblFor_txtPhone->TabIndex = 5;
			//
			// txtPhone
			//
			this->txtPhone->Location = System::Drawing::Point(150, 108);
			this->txtPhone->Size = System::Drawing::Size(245, 25);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->TabIndex = 6;
			//
			// lblFor_txtAddress
			//
			this->lblFor_txtAddress->AutoSize = true;
			this->lblFor_txtAddress->Location = System::Drawing::Point(15, 145);
			this->lblFor_txtAddress->Text = L"Address";
			this->lblFor_txtAddress->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtAddress->Name = L"lblFor_txtAddress";
			this->lblFor_txtAddress->TabIndex = 7;
			//
			// txtAddress
			//
			this->txtAddress->Location = System::Drawing::Point(150, 142);
			this->txtAddress->Size = System::Drawing::Size(245, 25);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->TabIndex = 8;
			//
			// lblFor_txtLicence
			//
			this->lblFor_txtLicence->AutoSize = true;
			this->lblFor_txtLicence->Location = System::Drawing::Point(15, 179);
			this->lblFor_txtLicence->Text = L"Licence number";
			this->lblFor_txtLicence->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtLicence->Name = L"lblFor_txtLicence";
			this->lblFor_txtLicence->TabIndex = 9;
			//
			// txtLicence
			//
			this->txtLicence->Location = System::Drawing::Point(150, 176);
			this->txtLicence->Size = System::Drawing::Size(245, 25);
			this->txtLicence->Name = L"txtLicence";
			this->txtLicence->TabIndex = 10;
			//
			// lblFor_dtExpiry
			//
			this->lblFor_dtExpiry->AutoSize = true;
			this->lblFor_dtExpiry->Location = System::Drawing::Point(15, 213);
			this->lblFor_dtExpiry->Text = L"Licence expiry";
			this->lblFor_dtExpiry->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_dtExpiry->Name = L"lblFor_dtExpiry";
			this->lblFor_dtExpiry->TabIndex = 11;
			//
			// dtExpiry
			//
			this->dtExpiry->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtExpiry->Location = System::Drawing::Point(150, 210);
			this->dtExpiry->Size = System::Drawing::Size(245, 25);
			this->dtExpiry->Name = L"dtExpiry";
			this->dtExpiry->TabIndex = 12;
			//
			// lblFor_numCharge
			//
			this->lblFor_numCharge->AutoSize = true;
			this->lblFor_numCharge->Location = System::Drawing::Point(15, 247);
			this->lblFor_numCharge->Text = L"Charge / day";
			this->lblFor_numCharge->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_numCharge->Name = L"lblFor_numCharge";
			this->lblFor_numCharge->TabIndex = 13;
			//
			// numCharge
			//
			this->numCharge->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			this->numCharge->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
			this->numCharge->ThousandsSeparator = true;
			this->numCharge->Location = System::Drawing::Point(150, 244);
			this->numCharge->Size = System::Drawing::Size(245, 25);
			this->numCharge->Name = L"numCharge";
			this->numCharge->TabIndex = 14;
			//
			// lblNote
			//
			this->lblNote->ForeColor = System::Drawing::Color::FromArgb(107, 119, 133);
			this->lblNote->Location = System::Drawing::Point(15, 290);
			this->lblNote->Size = System::Drawing::Size(380, 44);
			this->lblNote->Text = L"Note: a driver can only be requested by customers who are hiring a vehicle.";
			this->lblNote->Name = L"lblNote";
			this->lblNote->TabIndex = 15;
			//
			// btnSave
			//
			this->btnSave->BackColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->btnSave->FlatAppearance->BorderSize = 0;
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSave->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->btnSave->Location = System::Drawing::Point(15, 345);
			this->btnSave->Size = System::Drawing::Size(150, 38);
			this->btnSave->Text = L"Save Driver";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Name = L"btnSave";
			this->btnSave->TabIndex = 16;
			this->btnSave->Click += gcnew System::EventHandler(this, &DriverForm::btnSave_Click);
			//
			// lblTitle
			//
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->lblTitle->Location = System::Drawing::Point(20, 13);
			this->lblTitle->Text = L"Register Driver";
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->TabIndex = 0;
			//
			// btnBack
			//
			this->btnBack->BackColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->btnBack->FlatAppearance->BorderSize = 0;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnBack->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->btnBack->Location = System::Drawing::Point(980, 13);
			this->btnBack->Size = System::Drawing::Size(150, 38);
			this->btnBack->Text = L"< Back to Menu";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBack->Name = L"btnBack";
			this->btnBack->TabIndex = 1;
			this->btnBack->Click += gcnew System::EventHandler(this, &DriverForm::btnBack_Click);
			//
			// pnlHeader
			//
			this->pnlHeader->Controls->Add(this->lblTitle);
			this->pnlHeader->Controls->Add(this->btnBack);
			this->pnlHeader->BackColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Size = System::Drawing::Size(1150, 64);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->TabIndex = 1;
			//
			// DriverForm
			//
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(244, 246, 248);
			this->ClientSize = System::Drawing::Size(1150, 700);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Vehicle Rental System - Register Driver";
			this->Controls->Add(this->pnlBody);
			this->Controls->Add(this->pnlHeader);
			this->Name = L"DriverForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCharge))->EndInit();
			this->pnlBody->ResumeLayout(false);
			this->pnlBody->PerformLayout();
			this->pnlGrid->ResumeLayout(false);
			this->pnlGrid->PerformLayout();
			this->pnlGridBottom->ResumeLayout(false);
			this->pnlGridBottom->PerformLayout();
			this->pnlInput->ResumeLayout(false);
			this->pnlInput->PerformLayout();
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Close();
		}

private:
	System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			String^ licence = txtLicence->Text->Trim()->ToUpper();
			for each (Driver^ existing in Db::Drivers->GetAll())
			{
				if (existing->LicenceNumber == licence)
					throw gcnew ArgumentException("A driver with this licence number is already registered.");
			}

			Driver^ driver = gcnew Driver();
			driver->Name = txtName->Text;
			driver->Nic = txtNic->Text;
			driver->Phone = txtPhone->Text;
			driver->Address = txtAddress->Text;
			driver->LicenceNumber = txtLicence->Text;
			driver->LicenceExpiry = dtExpiry->Value.Date;
			driver->DailyCharge = numCharge->Value;

			Db::Drivers->Add(driver);
			UiTheme::Info(this, "Driver " + driver->Name + " registered.");

			for each (TextBox^ box in gcnew array<TextBox^> { txtName, txtNic, txtPhone, txtAddress, txtLicence })
				box->Clear();
			numCharge->Value = Decimal(0);
			LoadGrid();
		}
		catch (ArgumentException^ ex)
		{
			UiTheme::Warn(this, ex->Message);
		}
	}

	System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (dgv->CurrentRow == nullptr) { UiTheme::Warn(this, "Select a driver first."); return; }

		int id = safe_cast<int>(dgv->CurrentRow->Cells["Id"]->Value);
		Driver^ driver = Db::Drivers->GetById(id);
		if (driver == nullptr) return;

		for each (Booking^ b in Db::Bookings->GetAll())
		{
			if (b->DriverId == id)
			{
				UiTheme::Warn(this, "This driver has bookings, so the driver cannot be deleted.");
				return;
			}
		}
		if (!UiTheme::Confirm(this, "Delete driver " + driver->Name + "?")) return;

		Db::Drivers->Remove(id);
		LoadGrid();
	}

	void LoadGrid()
	{
		DataTable^ t = gcnew DataTable();
		t->Columns->Add("Id", int::typeid);
		for each (String^ name in gcnew array<String^> { "Name", "NIC", "Phone", "Licence", "Expiry", "Per day", "Status" })
			t->Columns->Add(name);

		for each (Driver^ d in Db::Drivers->GetAll())
		{
			t->Rows->Add(gcnew array<Object^> {
				d->Id,
				d->Name,
				d->Nic,
				d->Phone,
				d->LicenceNumber,
				d->LicenceExpiry.ToString("yyyy-MM-dd"),
				UiTheme::Money(d->DailyCharge),
				d->IsBusy ? "Busy" : "Available" });
		}

		dgv->DataSource = t;
		dgv->Columns["Id"]->Visible = false;
	}
	};
}
