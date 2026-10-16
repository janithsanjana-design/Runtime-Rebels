#pragma once
#include "Db.h"
#include "UiTheme.h"
#include "BookingService.h"
#include "ReportService.h"
#include "ReceiptForm.h"
#include "VehicleNotAvailableException.h"

namespace VehicleRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>New booking tab and a return-a-vehicle tab.  (open this file in the Visual Studio designer to edit the layout)</summary>
	public ref class HireForm : public System::Windows::Forms::Form
	{
	public:
		HireForm(void)
		{
			InitializeComponent();
			cboType->Items->Add(gcnew ListItem("Any type", nullptr));
			for each (VehicleType t in Enum::GetValues(VehicleType::typeid))
				cboType->Items->Add(gcnew ListItem(t.ToString(), t));
			cboType->SelectedIndex = 0;
			
			dtFrom->MinDate = DateTime::Today;
			dtTo->MinDate = DateTime::Today;
			dtFrom->Value = DateTime::Today;
			dtTo->Value = DateTime::Today.AddDays(1);
			
			UiTheme::StyleGrid(dgvActive);
			
			_ready = true;
			RefreshChoices();
			LoadActiveBookings();
		}

	protected:
		~HireForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  pnlBody;
	private: System::Windows::Forms::TabControl^  tabs;
	private: System::Windows::Forms::TabPage^  tabNew;
	private: System::Windows::Forms::TabPage^  tabReturn;
	private: System::Windows::Forms::Panel^  pnlNewRight;
	private: System::Windows::Forms::Panel^  pnlGap;
	private: System::Windows::Forms::Panel^  pnlNewLeft;
	private: System::Windows::Forms::Label^  lblHead1;
	private: System::Windows::Forms::Label^  lblFor_txtName;
	private: System::Windows::Forms::TextBox^  txtName;
	private: System::Windows::Forms::Label^  lblFor_txtNic;
	private: System::Windows::Forms::TextBox^  txtNic;
	private: System::Windows::Forms::Label^  lblFor_txtPhone;
	private: System::Windows::Forms::TextBox^  txtPhone;
	private: System::Windows::Forms::Label^  lblFor_txtAddress;
	private: System::Windows::Forms::TextBox^  txtAddress;
	private: System::Windows::Forms::Label^  lblHead2;
	private: System::Windows::Forms::Label^  lblFor_cboType;
	private: System::Windows::Forms::ComboBox^  cboType;
	private: System::Windows::Forms::Label^  lblFor_numPassengers;
	private: System::Windows::Forms::NumericUpDown^  numPassengers;
	private: System::Windows::Forms::Label^  lblFor_dtFrom;
	private: System::Windows::Forms::DateTimePicker^  dtFrom;
	private: System::Windows::Forms::Label^  lblFor_dtTo;
	private: System::Windows::Forms::DateTimePicker^  dtTo;
	private: System::Windows::Forms::Label^  lblCapDays;
	private: System::Windows::Forms::Label^  lblDays;
	private: System::Windows::Forms::Label^  lblHead3;
	private: System::Windows::Forms::Label^  lblFor_cboVehicle;
	private: System::Windows::Forms::ComboBox^  cboVehicle;
	private: System::Windows::Forms::Label^  lblCapDriver;
	private: System::Windows::Forms::CheckBox^  chkDriver;
	private: System::Windows::Forms::Label^  lblFor_cboDriver;
	private: System::Windows::Forms::ComboBox^  cboDriver;
	private: System::Windows::Forms::Label^  lblHead4;
	private: System::Windows::Forms::Label^  lblCapVehicleCost;
	private: System::Windows::Forms::Label^  lblVehicleCost;
	private: System::Windows::Forms::Label^  lblCapDriverCost;
	private: System::Windows::Forms::Label^  lblDriverCost;
	private: System::Windows::Forms::Label^  lblCapTotal;
	private: System::Windows::Forms::Label^  lblTotal;
	private: System::Windows::Forms::Label^  lblCapMin;
	private: System::Windows::Forms::Label^  lblMinAdvance;
	private: System::Windows::Forms::Label^  lblFor_numAdvance;
	private: System::Windows::Forms::NumericUpDown^  numAdvance;
	private: System::Windows::Forms::Label^  lblCapBalance;
	private: System::Windows::Forms::Label^  lblBalance;
	private: System::Windows::Forms::Button^  btnConfirm;
	private: System::Windows::Forms::DataGridView^  dgvActive;
	private: System::Windows::Forms::Panel^  pnlReturnBottom;
	private: System::Windows::Forms::Button^  btnReturn;
	private: System::Windows::Forms::Panel^  pnlReturnTop;
	private: System::Windows::Forms::Label^  lblReturnInfo;
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
			this->tabs = (gcnew System::Windows::Forms::TabControl());
			this->tabNew = (gcnew System::Windows::Forms::TabPage());
			this->tabReturn = (gcnew System::Windows::Forms::TabPage());
			this->pnlNewRight = (gcnew System::Windows::Forms::Panel());
			this->pnlGap = (gcnew System::Windows::Forms::Panel());
			this->pnlNewLeft = (gcnew System::Windows::Forms::Panel());
			this->lblHead1 = (gcnew System::Windows::Forms::Label());
			this->lblFor_txtName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtNic = (gcnew System::Windows::Forms::Label());
			this->txtNic = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtPhone = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtAddress = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblHead2 = (gcnew System::Windows::Forms::Label());
			this->lblFor_cboType = (gcnew System::Windows::Forms::Label());
			this->cboType = (gcnew System::Windows::Forms::ComboBox());
			this->lblFor_numPassengers = (gcnew System::Windows::Forms::Label());
			this->numPassengers = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblFor_dtFrom = (gcnew System::Windows::Forms::Label());
			this->dtFrom = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblFor_dtTo = (gcnew System::Windows::Forms::Label());
			this->dtTo = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblCapDays = (gcnew System::Windows::Forms::Label());
			this->lblDays = (gcnew System::Windows::Forms::Label());
			this->lblHead3 = (gcnew System::Windows::Forms::Label());
			this->lblFor_cboVehicle = (gcnew System::Windows::Forms::Label());
			this->cboVehicle = (gcnew System::Windows::Forms::ComboBox());
			this->lblCapDriver = (gcnew System::Windows::Forms::Label());
			this->chkDriver = (gcnew System::Windows::Forms::CheckBox());
			this->lblFor_cboDriver = (gcnew System::Windows::Forms::Label());
			this->cboDriver = (gcnew System::Windows::Forms::ComboBox());
			this->lblHead4 = (gcnew System::Windows::Forms::Label());
			this->lblCapVehicleCost = (gcnew System::Windows::Forms::Label());
			this->lblVehicleCost = (gcnew System::Windows::Forms::Label());
			this->lblCapDriverCost = (gcnew System::Windows::Forms::Label());
			this->lblDriverCost = (gcnew System::Windows::Forms::Label());
			this->lblCapTotal = (gcnew System::Windows::Forms::Label());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->lblCapMin = (gcnew System::Windows::Forms::Label());
			this->lblMinAdvance = (gcnew System::Windows::Forms::Label());
			this->lblFor_numAdvance = (gcnew System::Windows::Forms::Label());
			this->numAdvance = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblCapBalance = (gcnew System::Windows::Forms::Label());
			this->lblBalance = (gcnew System::Windows::Forms::Label());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->dgvActive = (gcnew System::Windows::Forms::DataGridView());
			this->pnlReturnBottom = (gcnew System::Windows::Forms::Panel());
			this->btnReturn = (gcnew System::Windows::Forms::Button());
			this->pnlReturnTop = (gcnew System::Windows::Forms::Panel());
			this->lblReturnInfo = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numPassengers))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAdvance))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvActive))->BeginInit();
			this->pnlBody->SuspendLayout();
			this->tabs->SuspendLayout();
			this->tabNew->SuspendLayout();
			this->tabReturn->SuspendLayout();
			this->pnlNewRight->SuspendLayout();
			this->pnlGap->SuspendLayout();
			this->pnlNewLeft->SuspendLayout();
			this->pnlReturnBottom->SuspendLayout();
			this->pnlReturnTop->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->SuspendLayout();
			//
			// pnlBody
			//
			this->pnlBody->Controls->Add(this->tabs);
			this->pnlBody->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlBody->Padding = System::Windows::Forms::Padding(16, 16, 16, 16);
			this->pnlBody->Size = System::Drawing::Size(1150, 636);
			this->pnlBody->Name = L"pnlBody";
			this->pnlBody->TabIndex = 0;
			//
			// tabs
			//
			this->tabs->Controls->Add(this->tabNew);
			this->tabs->Controls->Add(this->tabReturn);
			this->tabs->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabs->SelectedIndex = 0;
			this->tabs->Name = L"tabs";
			this->tabs->TabIndex = 0;
			this->tabs->SelectedIndexChanged += gcnew System::EventHandler(this, &HireForm::tabs_SelectedIndexChanged);
			//
			// tabNew
			//
			this->tabNew->Controls->Add(this->pnlNewRight);
			this->tabNew->Controls->Add(this->pnlGap);
			this->tabNew->Controls->Add(this->pnlNewLeft);
			this->tabNew->BackColor = System::Drawing::Color::FromArgb(244, 246, 248);
			this->tabNew->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
			this->tabNew->Text = L"  New Booking  ";
			this->tabNew->UseVisualStyleBackColor = false;
			this->tabNew->Name = L"tabNew";
			//
			// tabReturn
			//
			this->tabReturn->Controls->Add(this->dgvActive);
			this->tabReturn->Controls->Add(this->pnlReturnBottom);
			this->tabReturn->Controls->Add(this->pnlReturnTop);
			this->tabReturn->BackColor = System::Drawing::Color::FromArgb(244, 246, 248);
			this->tabReturn->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
			this->tabReturn->Text = L"  Return a Vehicle  ";
			this->tabReturn->UseVisualStyleBackColor = false;
			this->tabReturn->Name = L"tabReturn";
			//
			// pnlNewRight
			//
			this->pnlNewRight->Controls->Add(this->lblHead3);
			this->pnlNewRight->Controls->Add(this->lblFor_cboVehicle);
			this->pnlNewRight->Controls->Add(this->cboVehicle);
			this->pnlNewRight->Controls->Add(this->lblCapDriver);
			this->pnlNewRight->Controls->Add(this->chkDriver);
			this->pnlNewRight->Controls->Add(this->lblFor_cboDriver);
			this->pnlNewRight->Controls->Add(this->cboDriver);
			this->pnlNewRight->Controls->Add(this->lblHead4);
			this->pnlNewRight->Controls->Add(this->lblCapVehicleCost);
			this->pnlNewRight->Controls->Add(this->lblVehicleCost);
			this->pnlNewRight->Controls->Add(this->lblCapDriverCost);
			this->pnlNewRight->Controls->Add(this->lblDriverCost);
			this->pnlNewRight->Controls->Add(this->lblCapTotal);
			this->pnlNewRight->Controls->Add(this->lblTotal);
			this->pnlNewRight->Controls->Add(this->lblCapMin);
			this->pnlNewRight->Controls->Add(this->lblMinAdvance);
			this->pnlNewRight->Controls->Add(this->lblFor_numAdvance);
			this->pnlNewRight->Controls->Add(this->numAdvance);
			this->pnlNewRight->Controls->Add(this->lblCapBalance);
			this->pnlNewRight->Controls->Add(this->lblBalance);
			this->pnlNewRight->Controls->Add(this->btnConfirm);
			this->pnlNewRight->AutoScroll = true;
			this->pnlNewRight->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlNewRight->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlNewRight->Name = L"pnlNewRight";
			this->pnlNewRight->TabIndex = 0;
			//
			// pnlGap
			//
			this->pnlGap->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlGap->Size = System::Drawing::Size(10, 500);
			this->pnlGap->Name = L"pnlGap";
			this->pnlGap->TabIndex = 1;
			//
			// pnlNewLeft
			//
			this->pnlNewLeft->Controls->Add(this->lblHead1);
			this->pnlNewLeft->Controls->Add(this->lblFor_txtName);
			this->pnlNewLeft->Controls->Add(this->txtName);
			this->pnlNewLeft->Controls->Add(this->lblFor_txtNic);
			this->pnlNewLeft->Controls->Add(this->txtNic);
			this->pnlNewLeft->Controls->Add(this->lblFor_txtPhone);
			this->pnlNewLeft->Controls->Add(this->txtPhone);
			this->pnlNewLeft->Controls->Add(this->lblFor_txtAddress);
			this->pnlNewLeft->Controls->Add(this->txtAddress);
			this->pnlNewLeft->Controls->Add(this->lblHead2);
			this->pnlNewLeft->Controls->Add(this->lblFor_cboType);
			this->pnlNewLeft->Controls->Add(this->cboType);
			this->pnlNewLeft->Controls->Add(this->lblFor_numPassengers);
			this->pnlNewLeft->Controls->Add(this->numPassengers);
			this->pnlNewLeft->Controls->Add(this->lblFor_dtFrom);
			this->pnlNewLeft->Controls->Add(this->dtFrom);
			this->pnlNewLeft->Controls->Add(this->lblFor_dtTo);
			this->pnlNewLeft->Controls->Add(this->dtTo);
			this->pnlNewLeft->Controls->Add(this->lblCapDays);
			this->pnlNewLeft->Controls->Add(this->lblDays);
			this->pnlNewLeft->AutoScroll = true;
			this->pnlNewLeft->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlNewLeft->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlNewLeft->Size = System::Drawing::Size(460, 500);
			this->pnlNewLeft->Name = L"pnlNewLeft";
			this->pnlNewLeft->TabIndex = 2;
			//
			// lblHead1
			//
			this->lblHead1->AutoSize = true;
			this->lblHead1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHead1->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblHead1->Location = System::Drawing::Point(15, 10);
			this->lblHead1->Text = L"1. Customer details";
			this->lblHead1->Name = L"lblHead1";
			this->lblHead1->TabIndex = 0;
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
			// lblHead2
			//
			this->lblHead2->AutoSize = true;
			this->lblHead2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHead2->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblHead2->Location = System::Drawing::Point(15, 190);
			this->lblHead2->Text = L"2. Your requirement";
			this->lblHead2->Name = L"lblHead2";
			this->lblHead2->TabIndex = 9;
			//
			// lblFor_cboType
			//
			this->lblFor_cboType->AutoSize = true;
			this->lblFor_cboType->Location = System::Drawing::Point(15, 223);
			this->lblFor_cboType->Text = L"Vehicle type";
			this->lblFor_cboType->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_cboType->Name = L"lblFor_cboType";
			this->lblFor_cboType->TabIndex = 10;
			//
			// cboType
			//
			this->cboType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboType->FormattingEnabled = true;
			this->cboType->Location = System::Drawing::Point(150, 220);
			this->cboType->Size = System::Drawing::Size(245, 25);
			this->cboType->Name = L"cboType";
			this->cboType->TabIndex = 11;
			this->cboType->SelectedIndexChanged += gcnew System::EventHandler(this, &HireForm::cboType_SelectedIndexChanged);
			//
			// lblFor_numPassengers
			//
			this->lblFor_numPassengers->AutoSize = true;
			this->lblFor_numPassengers->Location = System::Drawing::Point(15, 257);
			this->lblFor_numPassengers->Text = L"Passengers";
			this->lblFor_numPassengers->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_numPassengers->Name = L"lblFor_numPassengers";
			this->lblFor_numPassengers->TabIndex = 12;
			//
			// numPassengers
			//
			this->numPassengers->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numPassengers->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {60, 0, 0, 0});
			this->numPassengers->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numPassengers->Location = System::Drawing::Point(150, 254);
			this->numPassengers->Size = System::Drawing::Size(245, 25);
			this->numPassengers->Name = L"numPassengers";
			this->numPassengers->TabIndex = 13;
			this->numPassengers->ValueChanged += gcnew System::EventHandler(this, &HireForm::numPassengers_ValueChanged);
			//
			// lblFor_dtFrom
			//
			this->lblFor_dtFrom->AutoSize = true;
			this->lblFor_dtFrom->Location = System::Drawing::Point(15, 291);
			this->lblFor_dtFrom->Text = L"Pick-up date";
			this->lblFor_dtFrom->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_dtFrom->Name = L"lblFor_dtFrom";
			this->lblFor_dtFrom->TabIndex = 14;
			//
			// dtFrom
			//
			this->dtFrom->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtFrom->Location = System::Drawing::Point(150, 288);
			this->dtFrom->Size = System::Drawing::Size(245, 25);
			this->dtFrom->Name = L"dtFrom";
			this->dtFrom->TabIndex = 15;
			this->dtFrom->ValueChanged += gcnew System::EventHandler(this, &HireForm::dtFrom_ValueChanged);
			//
			// lblFor_dtTo
			//
			this->lblFor_dtTo->AutoSize = true;
			this->lblFor_dtTo->Location = System::Drawing::Point(15, 325);
			this->lblFor_dtTo->Text = L"Return date";
			this->lblFor_dtTo->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_dtTo->Name = L"lblFor_dtTo";
			this->lblFor_dtTo->TabIndex = 16;
			//
			// dtTo
			//
			this->dtTo->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtTo->Location = System::Drawing::Point(150, 322);
			this->dtTo->Size = System::Drawing::Size(245, 25);
			this->dtTo->Name = L"dtTo";
			this->dtTo->TabIndex = 17;
			this->dtTo->ValueChanged += gcnew System::EventHandler(this, &HireForm::dtTo_ValueChanged);
			//
			// lblCapDays
			//
			this->lblCapDays->AutoSize = true;
			this->lblCapDays->Location = System::Drawing::Point(15, 359);
			this->lblCapDays->Text = L"Rental days";
			this->lblCapDays->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblCapDays->Name = L"lblCapDays";
			this->lblCapDays->TabIndex = 18;
			//
			// lblDays
			//
			this->lblDays->AutoSize = true;
			this->lblDays->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblDays->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblDays->Location = System::Drawing::Point(150, 359);
			this->lblDays->Text = L"-";
			this->lblDays->Name = L"lblDays";
			this->lblDays->TabIndex = 19;
			//
			// lblHead3
			//
			this->lblHead3->AutoSize = true;
			this->lblHead3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHead3->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblHead3->Location = System::Drawing::Point(15, 10);
			this->lblHead3->Text = L"3. Choose vehicle";
			this->lblHead3->Name = L"lblHead3";
			this->lblHead3->TabIndex = 0;
			//
			// lblFor_cboVehicle
			//
			this->lblFor_cboVehicle->AutoSize = true;
			this->lblFor_cboVehicle->Location = System::Drawing::Point(15, 43);
			this->lblFor_cboVehicle->Text = L"Available vehicles";
			this->lblFor_cboVehicle->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_cboVehicle->Name = L"lblFor_cboVehicle";
			this->lblFor_cboVehicle->TabIndex = 1;
			//
			// cboVehicle
			//
			this->cboVehicle->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboVehicle->FormattingEnabled = true;
			this->cboVehicle->Location = System::Drawing::Point(150, 40);
			this->cboVehicle->Size = System::Drawing::Size(420, 25);
			this->cboVehicle->Name = L"cboVehicle";
			this->cboVehicle->TabIndex = 2;
			this->cboVehicle->SelectedIndexChanged += gcnew System::EventHandler(this, &HireForm::cboVehicle_SelectedIndexChanged);
			//
			// lblCapDriver
			//
			this->lblCapDriver->AutoSize = true;
			this->lblCapDriver->Location = System::Drawing::Point(15, 79);
			this->lblCapDriver->Text = L"Driver";
			this->lblCapDriver->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblCapDriver->Name = L"lblCapDriver";
			this->lblCapDriver->TabIndex = 3;
			//
			// chkDriver
			//
			this->chkDriver->AutoSize = true;
			this->chkDriver->Location = System::Drawing::Point(150, 77);
			this->chkDriver->Text = L"Yes, I need a driver";
			this->chkDriver->UseVisualStyleBackColor = true;
			this->chkDriver->Name = L"chkDriver";
			this->chkDriver->TabIndex = 4;
			this->chkDriver->CheckedChanged += gcnew System::EventHandler(this, &HireForm::chkDriver_CheckedChanged);
			//
			// lblFor_cboDriver
			//
			this->lblFor_cboDriver->AutoSize = true;
			this->lblFor_cboDriver->Location = System::Drawing::Point(15, 111);
			this->lblFor_cboDriver->Text = L"Select driver";
			this->lblFor_cboDriver->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_cboDriver->Name = L"lblFor_cboDriver";
			this->lblFor_cboDriver->TabIndex = 5;
			//
			// cboDriver
			//
			this->cboDriver->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboDriver->FormattingEnabled = true;
			this->cboDriver->Enabled = false;
			this->cboDriver->Location = System::Drawing::Point(150, 108);
			this->cboDriver->Size = System::Drawing::Size(420, 25);
			this->cboDriver->Name = L"cboDriver";
			this->cboDriver->TabIndex = 6;
			this->cboDriver->SelectedIndexChanged += gcnew System::EventHandler(this, &HireForm::cboDriver_SelectedIndexChanged);
			//
			// lblHead4
			//
			this->lblHead4->AutoSize = true;
			this->lblHead4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHead4->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblHead4->Location = System::Drawing::Point(15, 156);
			this->lblHead4->Text = L"4. Price and advance";
			this->lblHead4->Name = L"lblHead4";
			this->lblHead4->TabIndex = 7;
			//
			// lblCapVehicleCost
			//
			this->lblCapVehicleCost->AutoSize = true;
			this->lblCapVehicleCost->Location = System::Drawing::Point(15, 189);
			this->lblCapVehicleCost->Text = L"Vehicle cost";
			this->lblCapVehicleCost->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblCapVehicleCost->Name = L"lblCapVehicleCost";
			this->lblCapVehicleCost->TabIndex = 8;
			//
			// lblVehicleCost
			//
			this->lblVehicleCost->AutoSize = true;
			this->lblVehicleCost->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblVehicleCost->Location = System::Drawing::Point(150, 189);
			this->lblVehicleCost->Text = L"-";
			this->lblVehicleCost->Name = L"lblVehicleCost";
			this->lblVehicleCost->TabIndex = 9;
			//
			// lblCapDriverCost
			//
			this->lblCapDriverCost->AutoSize = true;
			this->lblCapDriverCost->Location = System::Drawing::Point(15, 217);
			this->lblCapDriverCost->Text = L"Driver cost";
			this->lblCapDriverCost->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblCapDriverCost->Name = L"lblCapDriverCost";
			this->lblCapDriverCost->TabIndex = 10;
			//
			// lblDriverCost
			//
			this->lblDriverCost->AutoSize = true;
			this->lblDriverCost->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblDriverCost->Location = System::Drawing::Point(150, 217);
			this->lblDriverCost->Text = L"-";
			this->lblDriverCost->Name = L"lblDriverCost";
			this->lblDriverCost->TabIndex = 11;
			//
			// lblCapTotal
			//
			this->lblCapTotal->AutoSize = true;
			this->lblCapTotal->Location = System::Drawing::Point(15, 245);
			this->lblCapTotal->Text = L"Total";
			this->lblCapTotal->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblCapTotal->Name = L"lblCapTotal";
			this->lblCapTotal->TabIndex = 12;
			//
			// lblTotal
			//
			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTotal->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblTotal->Location = System::Drawing::Point(150, 245);
			this->lblTotal->Text = L"-";
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->TabIndex = 13;
			//
			// lblCapMin
			//
			this->lblCapMin->AutoSize = true;
			this->lblCapMin->Location = System::Drawing::Point(15, 273);
			this->lblCapMin->Text = L"Minimum advance";
			this->lblCapMin->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblCapMin->Name = L"lblCapMin";
			this->lblCapMin->TabIndex = 14;
			//
			// lblMinAdvance
			//
			this->lblMinAdvance->AutoSize = true;
			this->lblMinAdvance->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblMinAdvance->Location = System::Drawing::Point(150, 273);
			this->lblMinAdvance->Text = L"-";
			this->lblMinAdvance->Name = L"lblMinAdvance";
			this->lblMinAdvance->TabIndex = 15;
			//
			// lblFor_numAdvance
			//
			this->lblFor_numAdvance->AutoSize = true;
			this->lblFor_numAdvance->Location = System::Drawing::Point(15, 303);
			this->lblFor_numAdvance->Text = L"Advance you pay";
			this->lblFor_numAdvance->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_numAdvance->Name = L"lblFor_numAdvance";
			this->lblFor_numAdvance->TabIndex = 16;
			//
			// numAdvance
			//
			this->numAdvance->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {0, 0, 0, 0});
			this->numAdvance->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000000, 0, 0, 0});
			this->numAdvance->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {0, 0, 0, 0});
			this->numAdvance->DecimalPlaces = 2;
			this->numAdvance->ThousandsSeparator = true;
			this->numAdvance->Location = System::Drawing::Point(150, 300);
			this->numAdvance->Size = System::Drawing::Size(245, 25);
			this->numAdvance->Name = L"numAdvance";
			this->numAdvance->TabIndex = 17;
			this->numAdvance->ValueChanged += gcnew System::EventHandler(this, &HireForm::numAdvance_ValueChanged);
			//
			// lblCapBalance
			//
			this->lblCapBalance->AutoSize = true;
			this->lblCapBalance->Location = System::Drawing::Point(15, 336);
			this->lblCapBalance->Text = L"Balance due";
			this->lblCapBalance->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblCapBalance->Name = L"lblCapBalance";
			this->lblCapBalance->TabIndex = 18;
			//
			// lblBalance
			//
			this->lblBalance->AutoSize = true;
			this->lblBalance->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblBalance->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblBalance->Location = System::Drawing::Point(150, 336);
			this->lblBalance->Text = L"-";
			this->lblBalance->Name = L"lblBalance";
			this->lblBalance->TabIndex = 19;
			//
			// btnConfirm
			//
			this->btnConfirm->BackColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->btnConfirm->FlatAppearance->BorderSize = 0;
			this->btnConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConfirm->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnConfirm->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->btnConfirm->Location = System::Drawing::Point(15, 385);
			this->btnConfirm->Size = System::Drawing::Size(180, 38);
			this->btnConfirm->Text = L"Confirm Booking";
			this->btnConfirm->UseVisualStyleBackColor = false;
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->TabIndex = 20;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &HireForm::btnConfirm_Click);
			//
			// dgvActive
			//
			this->dgvActive->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvActive->Name = L"dgvActive";
			this->dgvActive->TabIndex = 0;
			//
			// pnlReturnBottom
			//
			this->pnlReturnBottom->Controls->Add(this->btnReturn);
			this->pnlReturnBottom->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pnlReturnBottom->Size = System::Drawing::Size(600, 52);
			this->pnlReturnBottom->Name = L"pnlReturnBottom";
			this->pnlReturnBottom->TabIndex = 1;
			//
			// btnReturn
			//
			this->btnReturn->BackColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->btnReturn->FlatAppearance->BorderSize = 0;
			this->btnReturn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReturn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnReturn->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->btnReturn->Location = System::Drawing::Point(3, 8);
			this->btnReturn->Size = System::Drawing::Size(180, 38);
			this->btnReturn->Text = L"Return Vehicle";
			this->btnReturn->UseVisualStyleBackColor = false;
			this->btnReturn->Name = L"btnReturn";
			this->btnReturn->TabIndex = 0;
			this->btnReturn->Click += gcnew System::EventHandler(this, &HireForm::btnReturn_Click);
			//
			// pnlReturnTop
			//
			this->pnlReturnTop->Controls->Add(this->lblReturnInfo);
			this->pnlReturnTop->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlReturnTop->Size = System::Drawing::Size(600, 36);
			this->pnlReturnTop->Name = L"pnlReturnTop";
			this->pnlReturnTop->TabIndex = 2;
			//
			// lblReturnInfo
			//
			this->lblReturnInfo->AutoSize = true;
			this->lblReturnInfo->ForeColor = System::Drawing::Color::FromArgb(107, 119, 133);
			this->lblReturnInfo->Location = System::Drawing::Point(3, 8);
			this->lblReturnInfo->Text = L"Select a booking and click 'Return Vehicle' when the customer brings the vehicle back.";
			this->lblReturnInfo->Name = L"lblReturnInfo";
			this->lblReturnInfo->TabIndex = 0;
			//
			// lblTitle
			//
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->lblTitle->Location = System::Drawing::Point(20, 13);
			this->lblTitle->Text = L"Hire a Vehicle";
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
			this->btnBack->Click += gcnew System::EventHandler(this, &HireForm::btnBack_Click);
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
			// HireForm
			//
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(244, 246, 248);
			this->ClientSize = System::Drawing::Size(1150, 700);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Vehicle Rental System - Hire a Vehicle";
			this->Controls->Add(this->pnlBody);
			this->Controls->Add(this->pnlHeader);
			this->Name = L"HireForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numPassengers))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAdvance))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvActive))->EndInit();
			this->pnlBody->ResumeLayout(false);
			this->pnlBody->PerformLayout();
			this->tabs->ResumeLayout(false);
			this->tabNew->ResumeLayout(false);
			this->tabReturn->ResumeLayout(false);
			this->pnlNewRight->ResumeLayout(false);
			this->pnlNewRight->PerformLayout();
			this->pnlGap->ResumeLayout(false);
			this->pnlGap->PerformLayout();
			this->pnlNewLeft->ResumeLayout(false);
			this->pnlNewLeft->PerformLayout();
			this->pnlReturnBottom->ResumeLayout(false);
			this->pnlReturnBottom->PerformLayout();
			this->pnlReturnTop->ResumeLayout(false);
			this->pnlReturnTop->PerformLayout();
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
	bool _ready;      // becomes true when the form has finished loading
	bool _updating;   // stops events from calling each other in a loop

	// ---------------------------------------------------------------- events

	System::Void tabs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (_ready) LoadActiveBookings();
	}

	System::Void cboType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) { RefreshChoices(); }
	System::Void numPassengers_ValueChanged(System::Object^  sender, System::EventArgs^  e) { RefreshChoices(); }
	System::Void dtTo_ValueChanged(System::Object^  sender, System::EventArgs^  e) { RefreshChoices(); }
	System::Void cboVehicle_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) { Recalculate(); }
	System::Void cboDriver_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) { Recalculate(); }
	System::Void numAdvance_ValueChanged(System::Object^  sender, System::EventArgs^  e) { UpdateBalance(); }

	System::Void dtFrom_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!_ready) return;
		if (dtTo->Value.Date < dtFrom->Value.Date) dtTo->Value = dtFrom->Value;
		RefreshChoices();
	}

	System::Void chkDriver_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		cboDriver->Enabled = chkDriver->Checked;
		Recalculate();
	}

	property Vehicle^ SelectedVehicle
	{
		Vehicle^ get()
		{
			ListItem^ item = dynamic_cast<ListItem^>(cboVehicle->SelectedItem);
			if (item == nullptr) return nullptr;
			return safe_cast<Vehicle^>(item->Value);
		}
	}

	property Driver^ SelectedDriver
	{
		Driver^ get()
		{
			if (!chkDriver->Checked) return nullptr;
			ListItem^ item = dynamic_cast<ListItem^>(cboDriver->SelectedItem);
			if (item == nullptr) return nullptr;
			return safe_cast<Driver^>(item->Value);
		}
	}

	/// Reloads the vehicle and driver lists for the chosen type, passengers and dates.
	void RefreshChoices()
	{
		if (!_ready || _updating) return;
		_updating = true;
		try
		{
			DateTime fromDate = dtFrom->Value.Date;
			DateTime toDate = dtTo->Value.Date;

			cboVehicle->Items->Clear();
			cboDriver->Items->Clear();

			if (toDate < fromDate)
			{
				lblDays->Text = "Return date is before pick-up date";
			}
			else
			{
				lblDays->Text = Convert::ToString(BookingService::CountDays(fromDate, toDate)) + " day(s)";

				ListItem^ typeItem = safe_cast<ListItem^>(cboType->SelectedItem);
				bool anyType = (typeItem->Value == nullptr);
				VehicleType type = anyType ? VehicleType::Car : safe_cast<VehicleType>(typeItem->Value);
				int passengers = Decimal::ToInt32(numPassengers->Value);

				for each (Vehicle^ v in BookingService::GetAvailableVehicles(anyType, type, passengers, fromDate, toDate))
				{
					cboVehicle->Items->Add(gcnew ListItem(
						v->ToString() + "  (" + Convert::ToString(v->Seats) + " seats)  " +
						UiTheme::Money(v->CustomerDailyRate) + "/day", v));
				}
				for each (Driver^ d in BookingService::GetAvailableDrivers(toDate))
				{
					cboDriver->Items->Add(gcnew ListItem(d->Name + "  " + UiTheme::Money(d->DailyCharge) + "/day", d));
				}
			}

			if (cboVehicle->Items->Count > 0) cboVehicle->SelectedIndex = 0;
			if (cboDriver->Items->Count > 0) cboDriver->SelectedIndex = 0;
		}
		finally
		{
			_updating = false;
		}
		Recalculate();
	}

	/// Works out vehicle cost, driver cost, total and the minimum advance.
	void Recalculate()
	{
		if (!_ready || _updating) return;
		_updating = true;
		try
		{
			Vehicle^ vehicle = SelectedVehicle;
			DateTime fromDate = dtFrom->Value.Date;
			DateTime toDate = dtTo->Value.Date;

			if (vehicle == nullptr || toDate < fromDate)
			{
				lblVehicleCost->Text = "-";
				lblDriverCost->Text = "-";
				lblTotal->Text = "-";
				lblMinAdvance->Text = "-";
				numAdvance->Maximum = Decimal(100000000);
				numAdvance->Value = Decimal(0);
				numAdvance->Enabled = false;
			}
			else
			{
				Decimal total = CurrentTotal();
				int days = BookingService::CountDays(fromDate, toDate);
				Decimal vehicleCost = Decimal(days) * vehicle->CustomerDailyRate;
				Decimal driverCost = total - vehicleCost;
				Decimal minAdvance = BookingService::MinAdvance(total);

				lblVehicleCost->Text = UiTheme::Money(vehicleCost);
				lblDriverCost->Text = UiTheme::Money(driverCost);
				lblTotal->Text = UiTheme::Money(total);
				lblMinAdvance->Text = UiTheme::Money(minAdvance) + "  (25%)";

				numAdvance->Enabled = true;
				numAdvance->Maximum = total;
				numAdvance->Value = minAdvance;
			}
		}
		finally
		{
			_updating = false;
		}
		UpdateBalance();
	}

	void UpdateBalance()
	{
		if (!_ready || _updating) return;
		if (SelectedVehicle == nullptr) { lblBalance->Text = "-"; return; }
		lblBalance->Text = UiTheme::Money(CurrentTotal() - numAdvance->Value);
	}

	Decimal CurrentTotal()
	{
		Vehicle^ vehicle = SelectedVehicle;
		Driver^ driver = SelectedDriver;
		if (vehicle == nullptr) return Decimal::Zero;

		Decimal days = Decimal(BookingService::CountDays(dtFrom->Value, dtTo->Value));
		Decimal total = days * vehicle->CustomerDailyRate;
		if (driver != nullptr) total = total + days * driver->DailyCharge;
		return total;
	}

	// ---------------------------------------------------------------- actions

	System::Void btnConfirm_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			Customer^ customer = gcnew Customer();
			customer->Name = txtName->Text;
			customer->Nic = txtNic->Text;
			customer->Phone = txtPhone->Text;
			customer->Address = txtAddress->Text;

			Vehicle^ vehicle = SelectedVehicle;
			if (vehicle == nullptr)
				throw gcnew ArgumentException("No vehicle is available for these requirements. Try other dates or a different type.");

			Driver^ driver = SelectedDriver;
			if (chkDriver->Checked && driver == nullptr)
				throw gcnew ArgumentException("No driver is available for these dates. Untick 'I need a driver' or change the dates.");

			Booking^ booking = BookingService::CreateBooking(customer, vehicle, driver,
				dtFrom->Value, dtTo->Value, numAdvance->Value, false);

			ReceiptForm^ receipt = gcnew ReceiptForm(booking);
			receipt->ShowDialog(this);
			delete receipt;

			ClearCustomer();
			RefreshChoices();
			LoadActiveBookings();
		}
		catch (VehicleNotAvailableException^ ex)
		{
			UiTheme::Warn(this, ex->Message);
			RefreshChoices();
		}
		catch (ArgumentException^ ex)
		{
			UiTheme::Warn(this, ex->Message);
		}
	}

	void ClearCustomer()
	{
		txtName->Clear();
		txtNic->Clear();
		txtPhone->Clear();
		txtAddress->Clear();
		chkDriver->Checked = false;
		numPassengers->Value = Decimal(1);
	}

	System::Void btnReturn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (dgvActive->CurrentRow == nullptr) { UiTheme::Warn(this, "Select a booking first."); return; }

		int id = safe_cast<int>(dgvActive->CurrentRow->Cells["Id"]->Value);
		Booking^ booking = Db::Bookings->GetById(id);
		if (booking == nullptr) return;

		String^ message = "Customer: " + booking->CustomerInfo->Name + "\r\nVehicle: " + booking->VehicleName +
			"\r\n\r\nBalance to collect: " + UiTheme::Money(booking->Balance) +
			"\r\n\r\nMark this vehicle as returned?";
		if (!UiTheme::Confirm(this, message)) return;

		BookingService::CompleteBooking(booking);
		UiTheme::Info(this, "Booking completed. The vehicle is available again.");
		LoadActiveBookings();
		RefreshChoices();
	}

	void LoadActiveBookings()
	{
		DataTable^ t = gcnew DataTable();
		t->Columns->Add("Id", int::typeid);
		for each (String^ name in gcnew array<String^> { "Customer", "Phone", "Vehicle", "Driver", "From", "To", "Total", "Advance", "Balance" })
			t->Columns->Add(name);

		for each (Booking^ b in ReportService::GetActiveBookings())
		{
			t->Rows->Add(gcnew array<Object^> {
				b->Id,
				b->CustomerInfo->Name,
				b->CustomerInfo->Phone,
				b->VehicleName,
				String::IsNullOrEmpty(b->DriverName) ? "-" : b->DriverName,
				b->FromDate.ToString("yyyy-MM-dd"),
				b->ToDate.ToString("yyyy-MM-dd"),
				UiTheme::Money(b->Total),
				UiTheme::Money(b->Advance),
				UiTheme::Money(b->Balance) });
		}

		dgvActive->DataSource = t;
		dgvActive->Columns["Id"]->Visible = false;
	}
	};
}
