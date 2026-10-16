#pragma once
#include "Db.h"
#include "UiTheme.h"
#include "CommissionCalculator.h"

namespace VehicleRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>Register a vehicle with its owner and the amount the owner wants to earn.  (open this file in the Visual Studio designer to edit the layout)</summary>
	public ref class VehicleForm : public System::Windows::Forms::Form
	{
	public:
		VehicleForm(void)
		{
			InitializeComponent();
			cboType->DataSource = Enum::GetValues(VehicleType::typeid);
			cboFuel->Items->AddRange(gcnew array<Object^> { "Petrol", "Diesel", "Hybrid", "Electric" });
			cboFuel->SelectedIndex = 0;
			numYear->Maximum = Decimal(DateTime::Now.Year + 1);
			numYear->Value = Decimal(DateTime::Now.Year);
			UiTheme::StyleGrid(dgv);
			UpdateBreakdown();
			LoadGrid();
		}

	protected:
		~VehicleForm()
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
	private: System::Windows::Forms::Label^  lblHeadOwner;
	private: System::Windows::Forms::Label^  lblFor_txtOwnerName;
	private: System::Windows::Forms::TextBox^  txtOwnerName;
	private: System::Windows::Forms::Label^  lblFor_txtNic;
	private: System::Windows::Forms::TextBox^  txtNic;
	private: System::Windows::Forms::Label^  lblFor_txtPhone;
	private: System::Windows::Forms::TextBox^  txtPhone;
	private: System::Windows::Forms::Label^  lblFor_txtAddress;
	private: System::Windows::Forms::TextBox^  txtAddress;
	private: System::Windows::Forms::Label^  lblFor_txtBank;
	private: System::Windows::Forms::TextBox^  txtBank;
	private: System::Windows::Forms::Label^  lblHeadVehicle;
	private: System::Windows::Forms::Label^  lblFor_txtPlate;
	private: System::Windows::Forms::TextBox^  txtPlate;
	private: System::Windows::Forms::Label^  lblFor_cboType;
	private: System::Windows::Forms::ComboBox^  cboType;
	private: System::Windows::Forms::Label^  lblFor_txtBrand;
	private: System::Windows::Forms::TextBox^  txtBrand;
	private: System::Windows::Forms::Label^  lblFor_txtModel;
	private: System::Windows::Forms::TextBox^  txtModel;
	private: System::Windows::Forms::Label^  lblFor_numYear;
	private: System::Windows::Forms::NumericUpDown^  numYear;
	private: System::Windows::Forms::Label^  lblFor_numSeats;
	private: System::Windows::Forms::NumericUpDown^  numSeats;
	private: System::Windows::Forms::Label^  lblFor_cboFuel;
	private: System::Windows::Forms::ComboBox^  cboFuel;
	private: System::Windows::Forms::Label^  lblHeadEarn;
	private: System::Windows::Forms::Label^  lblFor_numOwnerAmount;
	private: System::Windows::Forms::NumericUpDown^  numOwnerAmount;
	private: System::Windows::Forms::Label^  lblBreakdown;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnClear;
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
			this->lblHeadOwner = (gcnew System::Windows::Forms::Label());
			this->lblFor_txtOwnerName = (gcnew System::Windows::Forms::Label());
			this->txtOwnerName = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtNic = (gcnew System::Windows::Forms::Label());
			this->txtNic = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtPhone = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtAddress = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtBank = (gcnew System::Windows::Forms::Label());
			this->txtBank = (gcnew System::Windows::Forms::TextBox());
			this->lblHeadVehicle = (gcnew System::Windows::Forms::Label());
			this->lblFor_txtPlate = (gcnew System::Windows::Forms::Label());
			this->txtPlate = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_cboType = (gcnew System::Windows::Forms::Label());
			this->cboType = (gcnew System::Windows::Forms::ComboBox());
			this->lblFor_txtBrand = (gcnew System::Windows::Forms::Label());
			this->txtBrand = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtModel = (gcnew System::Windows::Forms::Label());
			this->txtModel = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_numYear = (gcnew System::Windows::Forms::Label());
			this->numYear = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblFor_numSeats = (gcnew System::Windows::Forms::Label());
			this->numSeats = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblFor_cboFuel = (gcnew System::Windows::Forms::Label());
			this->cboFuel = (gcnew System::Windows::Forms::ComboBox());
			this->lblHeadEarn = (gcnew System::Windows::Forms::Label());
			this->lblFor_numOwnerAmount = (gcnew System::Windows::Forms::Label());
			this->numOwnerAmount = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblBreakdown = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numYear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSeats))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numOwnerAmount))->BeginInit();
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
			this->btnDelete->Click += gcnew System::EventHandler(this, &VehicleForm::btnDelete_Click);
			//
			// pnlInput
			//
			this->pnlInput->Controls->Add(this->lblHeadOwner);
			this->pnlInput->Controls->Add(this->lblFor_txtOwnerName);
			this->pnlInput->Controls->Add(this->txtOwnerName);
			this->pnlInput->Controls->Add(this->lblFor_txtNic);
			this->pnlInput->Controls->Add(this->txtNic);
			this->pnlInput->Controls->Add(this->lblFor_txtPhone);
			this->pnlInput->Controls->Add(this->txtPhone);
			this->pnlInput->Controls->Add(this->lblFor_txtAddress);
			this->pnlInput->Controls->Add(this->txtAddress);
			this->pnlInput->Controls->Add(this->lblFor_txtBank);
			this->pnlInput->Controls->Add(this->txtBank);
			this->pnlInput->Controls->Add(this->lblHeadVehicle);
			this->pnlInput->Controls->Add(this->lblFor_txtPlate);
			this->pnlInput->Controls->Add(this->txtPlate);
			this->pnlInput->Controls->Add(this->lblFor_cboType);
			this->pnlInput->Controls->Add(this->cboType);
			this->pnlInput->Controls->Add(this->lblFor_txtBrand);
			this->pnlInput->Controls->Add(this->txtBrand);
			this->pnlInput->Controls->Add(this->lblFor_txtModel);
			this->pnlInput->Controls->Add(this->txtModel);
			this->pnlInput->Controls->Add(this->lblFor_numYear);
			this->pnlInput->Controls->Add(this->numYear);
			this->pnlInput->Controls->Add(this->lblFor_numSeats);
			this->pnlInput->Controls->Add(this->numSeats);
			this->pnlInput->Controls->Add(this->lblFor_cboFuel);
			this->pnlInput->Controls->Add(this->cboFuel);
			this->pnlInput->Controls->Add(this->lblHeadEarn);
			this->pnlInput->Controls->Add(this->lblFor_numOwnerAmount);
			this->pnlInput->Controls->Add(this->numOwnerAmount);
			this->pnlInput->Controls->Add(this->lblBreakdown);
			this->pnlInput->Controls->Add(this->btnSave);
			this->pnlInput->Controls->Add(this->btnClear);
			this->pnlInput->AutoScroll = true;
			this->pnlInput->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlInput->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlInput->Size = System::Drawing::Size(420, 600);
			this->pnlInput->Name = L"pnlInput";
			this->pnlInput->TabIndex = 1;
			//
			// lblHeadOwner
			//
			this->lblHeadOwner->AutoSize = true;
			this->lblHeadOwner->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHeadOwner->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblHeadOwner->Location = System::Drawing::Point(15, 10);
			this->lblHeadOwner->Text = L"Owner details";
			this->lblHeadOwner->Name = L"lblHeadOwner";
			this->lblHeadOwner->TabIndex = 0;
			//
			// lblFor_txtOwnerName
			//
			this->lblFor_txtOwnerName->AutoSize = true;
			this->lblFor_txtOwnerName->Location = System::Drawing::Point(15, 43);
			this->lblFor_txtOwnerName->Text = L"Full name";
			this->lblFor_txtOwnerName->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtOwnerName->Name = L"lblFor_txtOwnerName";
			this->lblFor_txtOwnerName->TabIndex = 1;
			//
			// txtOwnerName
			//
			this->txtOwnerName->Location = System::Drawing::Point(150, 40);
			this->txtOwnerName->Size = System::Drawing::Size(245, 25);
			this->txtOwnerName->Name = L"txtOwnerName";
			this->txtOwnerName->TabIndex = 2;
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
			// lblFor_txtBank
			//
			this->lblFor_txtBank->AutoSize = true;
			this->lblFor_txtBank->Location = System::Drawing::Point(15, 179);
			this->lblFor_txtBank->Text = L"Bank account";
			this->lblFor_txtBank->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtBank->Name = L"lblFor_txtBank";
			this->lblFor_txtBank->TabIndex = 9;
			//
			// txtBank
			//
			this->txtBank->Location = System::Drawing::Point(150, 176);
			this->txtBank->Size = System::Drawing::Size(245, 25);
			this->txtBank->Name = L"txtBank";
			this->txtBank->TabIndex = 10;
			//
			// lblHeadVehicle
			//
			this->lblHeadVehicle->AutoSize = true;
			this->lblHeadVehicle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHeadVehicle->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblHeadVehicle->Location = System::Drawing::Point(15, 216);
			this->lblHeadVehicle->Text = L"Vehicle details";
			this->lblHeadVehicle->Name = L"lblHeadVehicle";
			this->lblHeadVehicle->TabIndex = 11;
			//
			// lblFor_txtPlate
			//
			this->lblFor_txtPlate->AutoSize = true;
			this->lblFor_txtPlate->Location = System::Drawing::Point(15, 249);
			this->lblFor_txtPlate->Text = L"Plate number";
			this->lblFor_txtPlate->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtPlate->Name = L"lblFor_txtPlate";
			this->lblFor_txtPlate->TabIndex = 12;
			//
			// txtPlate
			//
			this->txtPlate->Location = System::Drawing::Point(150, 246);
			this->txtPlate->Size = System::Drawing::Size(245, 25);
			this->txtPlate->Name = L"txtPlate";
			this->txtPlate->TabIndex = 13;
			//
			// lblFor_cboType
			//
			this->lblFor_cboType->AutoSize = true;
			this->lblFor_cboType->Location = System::Drawing::Point(15, 283);
			this->lblFor_cboType->Text = L"Type";
			this->lblFor_cboType->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_cboType->Name = L"lblFor_cboType";
			this->lblFor_cboType->TabIndex = 14;
			//
			// cboType
			//
			this->cboType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboType->FormattingEnabled = true;
			this->cboType->Location = System::Drawing::Point(150, 280);
			this->cboType->Size = System::Drawing::Size(245, 25);
			this->cboType->Name = L"cboType";
			this->cboType->TabIndex = 15;
			//
			// lblFor_txtBrand
			//
			this->lblFor_txtBrand->AutoSize = true;
			this->lblFor_txtBrand->Location = System::Drawing::Point(15, 317);
			this->lblFor_txtBrand->Text = L"Brand";
			this->lblFor_txtBrand->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtBrand->Name = L"lblFor_txtBrand";
			this->lblFor_txtBrand->TabIndex = 16;
			//
			// txtBrand
			//
			this->txtBrand->Location = System::Drawing::Point(150, 314);
			this->txtBrand->Size = System::Drawing::Size(245, 25);
			this->txtBrand->Name = L"txtBrand";
			this->txtBrand->TabIndex = 17;
			//
			// lblFor_txtModel
			//
			this->lblFor_txtModel->AutoSize = true;
			this->lblFor_txtModel->Location = System::Drawing::Point(15, 351);
			this->lblFor_txtModel->Text = L"Model";
			this->lblFor_txtModel->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_txtModel->Name = L"lblFor_txtModel";
			this->lblFor_txtModel->TabIndex = 18;
			//
			// txtModel
			//
			this->txtModel->Location = System::Drawing::Point(150, 348);
			this->txtModel->Size = System::Drawing::Size(245, 25);
			this->txtModel->Name = L"txtModel";
			this->txtModel->TabIndex = 19;
			//
			// lblFor_numYear
			//
			this->lblFor_numYear->AutoSize = true;
			this->lblFor_numYear->Location = System::Drawing::Point(15, 385);
			this->lblFor_numYear->Text = L"Year";
			this->lblFor_numYear->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_numYear->Name = L"lblFor_numYear";
			this->lblFor_numYear->TabIndex = 20;
			//
			// numYear
			//
			this->numYear->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1980, 0, 0, 0});
			this->numYear->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2100, 0, 0, 0});
			this->numYear->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2024, 0, 0, 0});
			this->numYear->Location = System::Drawing::Point(150, 382);
			this->numYear->Size = System::Drawing::Size(245, 25);
			this->numYear->Name = L"numYear";
			this->numYear->TabIndex = 21;
			//
			// lblFor_numSeats
			//
			this->lblFor_numSeats->AutoSize = true;
			this->lblFor_numSeats->Location = System::Drawing::Point(15, 419);
			this->lblFor_numSeats->Text = L"Seats";
			this->lblFor_numSeats->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_numSeats->Name = L"lblFor_numSeats";
			this->lblFor_numSeats->TabIndex = 22;
			//
			// numSeats
			//
			this->numSeats->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numSeats->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {60, 0, 0, 0});
			this->numSeats->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			this->numSeats->Location = System::Drawing::Point(150, 416);
			this->numSeats->Size = System::Drawing::Size(245, 25);
			this->numSeats->Name = L"numSeats";
			this->numSeats->TabIndex = 23;
			//
			// lblFor_cboFuel
			//
			this->lblFor_cboFuel->AutoSize = true;
			this->lblFor_cboFuel->Location = System::Drawing::Point(15, 453);
			this->lblFor_cboFuel->Text = L"Fuel";
			this->lblFor_cboFuel->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_cboFuel->Name = L"lblFor_cboFuel";
			this->lblFor_cboFuel->TabIndex = 24;
			//
			// cboFuel
			//
			this->cboFuel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboFuel->FormattingEnabled = true;
			this->cboFuel->Location = System::Drawing::Point(150, 450);
			this->cboFuel->Size = System::Drawing::Size(245, 25);
			this->cboFuel->Name = L"cboFuel";
			this->cboFuel->TabIndex = 25;
			//
			// lblHeadEarn
			//
			this->lblHeadEarn->AutoSize = true;
			this->lblHeadEarn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHeadEarn->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblHeadEarn->Location = System::Drawing::Point(15, 490);
			this->lblHeadEarn->Text = L"Owner's earning";
			this->lblHeadEarn->Name = L"lblHeadEarn";
			this->lblHeadEarn->TabIndex = 26;
			//
			// lblFor_numOwnerAmount
			//
			this->lblFor_numOwnerAmount->AutoSize = true;
			this->lblFor_numOwnerAmount->Location = System::Drawing::Point(15, 523);
			this->lblFor_numOwnerAmount->Text = L"Owner wants / day";
			this->lblFor_numOwnerAmount->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblFor_numOwnerAmount->Name = L"lblFor_numOwnerAmount";
			this->lblFor_numOwnerAmount->TabIndex = 27;
			//
			// numOwnerAmount
			//
			this->numOwnerAmount->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->numOwnerAmount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->numOwnerAmount->ThousandsSeparator = true;
			this->numOwnerAmount->Location = System::Drawing::Point(150, 520);
			this->numOwnerAmount->Size = System::Drawing::Size(245, 25);
			this->numOwnerAmount->Name = L"numOwnerAmount";
			this->numOwnerAmount->TabIndex = 28;
			this->numOwnerAmount->ValueChanged += gcnew System::EventHandler(this, &VehicleForm::numOwnerAmount_ValueChanged);
			//
			// lblBreakdown
			//
			this->lblBreakdown->BackColor = System::Drawing::Color::FromArgb(234, 244, 246);
			this->lblBreakdown->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblBreakdown->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblBreakdown->Location = System::Drawing::Point(15, 560);
			this->lblBreakdown->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
			this->lblBreakdown->Size = System::Drawing::Size(380, 80);
			this->lblBreakdown->Text = L"breakdown";
			this->lblBreakdown->Name = L"lblBreakdown";
			this->lblBreakdown->TabIndex = 29;
			//
			// btnSave
			//
			this->btnSave->BackColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->btnSave->FlatAppearance->BorderSize = 0;
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSave->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->btnSave->Location = System::Drawing::Point(15, 656);
			this->btnSave->Size = System::Drawing::Size(150, 38);
			this->btnSave->Text = L"Save Vehicle";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Name = L"btnSave";
			this->btnSave->TabIndex = 30;
			this->btnSave->Click += gcnew System::EventHandler(this, &VehicleForm::btnSave_Click);
			//
			// btnClear
			//
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(107, 119, 133);
			this->btnClear->FlatAppearance->BorderSize = 0;
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnClear->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->btnClear->Location = System::Drawing::Point(175, 656);
			this->btnClear->Size = System::Drawing::Size(90, 38);
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Name = L"btnClear";
			this->btnClear->TabIndex = 31;
			this->btnClear->Click += gcnew System::EventHandler(this, &VehicleForm::btnClear_Click);
			//
			// lblTitle
			//
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->lblTitle->Location = System::Drawing::Point(20, 13);
			this->lblTitle->Text = L"Register Vehicle";
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
			this->btnBack->Click += gcnew System::EventHandler(this, &VehicleForm::btnBack_Click);
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
			// VehicleForm
			//
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(244, 246, 248);
			this->ClientSize = System::Drawing::Size(1150, 700);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Vehicle Rental System - Register Vehicle";
			this->Controls->Add(this->pnlBody);
			this->Controls->Add(this->pnlHeader);
			this->Name = L"VehicleForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numYear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSeats))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numOwnerAmount))->EndInit();
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
	System::Void numOwnerAmount_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		UpdateBreakdown();
	}

	/// Shows the live price breakdown while the owner amount changes.
	void UpdateBreakdown()
	{
		Decimal owner = numOwnerAmount->Value;
		Decimal customer = CommissionCalculator::CustomerPrice(owner);
		Decimal commission = CommissionCalculator::Commission(customer);
		String^ percent = Math::Round(CommissionCalculator::Rate * Decimal(100)).ToString("0");

		lblBreakdown->Text =
			"Owner gets:  " + UiTheme::Money(owner) + " / day\r\n" +
			"Company " + percent + "%:  " + UiTheme::Money(commission) + "\r\n" +
			"Customer pays:  " + UiTheme::Money(customer) + " / day";
	}

	System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			String^ plate = txtPlate->Text->Trim()->ToUpper();
			for each (Vehicle^ existing in Db::Vehicles->GetAll())
			{
				if (existing->PlateNumber == plate)
					throw gcnew ArgumentException("A vehicle with this plate number is already registered.");
			}

			// Setters validate every value and throw ArgumentException with a friendly message.
			VehicleRentalSystem::Owner^ owner = gcnew VehicleRentalSystem::Owner();
			owner->Name = txtOwnerName->Text;
			owner->Nic = txtNic->Text;
			owner->Phone = txtPhone->Text;
			owner->Address = txtAddress->Text;
			owner->BankAccount = txtBank->Text;

			Vehicle^ vehicle = Vehicle::Create(safe_cast<VehicleType>(cboType->SelectedItem));
			vehicle->PlateNumber = txtPlate->Text;
			vehicle->Brand = txtBrand->Text;
			vehicle->Model = txtModel->Text;
			vehicle->Year = Decimal::ToInt32(numYear->Value);
			vehicle->Seats = Decimal::ToInt32(numSeats->Value);
			vehicle->Fuel = cboFuel->Text;
			vehicle->OwnerDailyAmount = numOwnerAmount->Value;
			vehicle->OwnerInfo = owner;
			vehicle->Status = VehicleStatus::Available;

			Db::Vehicles->Add(vehicle);
			UiTheme::Info(this, "Vehicle " + vehicle->PlateNumber + " registered.\r\nCustomers will pay " +
				UiTheme::Money(vehicle->CustomerDailyRate) + " per day.");
			ClearForm();
			LoadGrid();
		}
		catch (ArgumentException^ ex)
		{
			UiTheme::Warn(this, ex->Message);
		}
	}

	System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ClearForm();
	}

	System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (dgv->CurrentRow == nullptr) { UiTheme::Warn(this, "Select a vehicle first."); return; }

		int id = safe_cast<int>(dgv->CurrentRow->Cells["Id"]->Value);
		Vehicle^ vehicle = Db::Vehicles->GetById(id);
		if (vehicle == nullptr) return;

		for each (Booking^ b in Db::Bookings->GetAll())
		{
			if (b->VehicleId == id)
			{
				UiTheme::Warn(this, "This vehicle has bookings, so it cannot be deleted.");
				return;
			}
		}
		if (!UiTheme::Confirm(this, "Delete vehicle " + vehicle->PlateNumber + "?")) return;

		Db::Vehicles->Remove(id);
		LoadGrid();
	}

	void ClearForm()
	{
		for each (TextBox^ box in gcnew array<TextBox^> { txtOwnerName, txtNic, txtPhone, txtAddress, txtBank, txtPlate, txtBrand, txtModel })
			box->Clear();
		numOwnerAmount->Value = Decimal(0);
		numSeats->Value = Decimal(4);
		cboType->SelectedIndex = 0;
		cboFuel->SelectedIndex = 0;
	}

	void LoadGrid()
	{
		DataTable^ t = gcnew DataTable();
		t->Columns->Add("Id", int::typeid);
		for each (String^ name in gcnew array<String^> { "Plate", "Type", "Vehicle", "Seats", "Fuel", "Owner", "Owner / day", "Customer / day", "Status" })
			t->Columns->Add(name);

		for each (Vehicle^ v in Db::Vehicles->GetAll())
		{
			t->Rows->Add(gcnew array<Object^> {
				v->Id,
				v->PlateNumber,
				v->Type.ToString(),
				v->Brand + " " + v->Model + " (" + Convert::ToString(v->Year) + ")",
				Convert::ToString(v->Seats),
				v->Fuel,
				v->OwnerInfo->Name,
				UiTheme::Money(v->OwnerDailyAmount),
				UiTheme::Money(v->CustomerDailyRate),
				v->Status.ToString() });
		}

		dgv->DataSource = t;
		dgv->Columns["Id"]->Visible = false;
	}
	};
}
