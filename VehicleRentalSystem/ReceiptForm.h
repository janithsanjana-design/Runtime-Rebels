#pragma once
#include "UiTheme.h"
#include "Booking.h"

namespace VehicleRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>Booking receipt shown after a booking is confirmed.  (open this file in the Visual Studio designer to edit the layout)</summary>
	public ref class ReceiptForm : public System::Windows::Forms::Form
	{
	public:
		ReceiptForm(void)
		{
			InitializeComponent();
		}

	protected:
		~ReceiptForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  txtReceipt;
	private: System::Windows::Forms::Panel^  pnlBottom;
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Label^  lblHeader;

	private:
		/// <summary>Required designer variable.</summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>Designer-managed code: edit the layout in the designer, not by hand.</summary>
		void InitializeComponent(void)
		{
			this->txtReceipt = (gcnew System::Windows::Forms::TextBox());
			this->pnlBottom = (gcnew System::Windows::Forms::Panel());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblHeader = (gcnew System::Windows::Forms::Label());
			this->pnlBottom->SuspendLayout();
			this->SuspendLayout();
			//
			// txtReceipt
			//
			this->txtReceipt->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->txtReceipt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtReceipt->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtReceipt->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtReceipt->Multiline = true;
			this->txtReceipt->ReadOnly = true;
			this->txtReceipt->Size = System::Drawing::Size(460, 450);
			this->txtReceipt->TabStop = false;
			this->txtReceipt->Name = L"txtReceipt";
			this->txtReceipt->TabIndex = 0;
			//
			// pnlBottom
			//
			this->pnlBottom->Controls->Add(this->btnClose);
			this->pnlBottom->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pnlBottom->Size = System::Drawing::Size(460, 54);
			this->pnlBottom->Name = L"pnlBottom";
			this->pnlBottom->TabIndex = 1;
			//
			// btnClose
			//
			this->btnClose->BackColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnClose->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->btnClose->Location = System::Drawing::Point(12, 8);
			this->btnClose->Size = System::Drawing::Size(120, 38);
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Name = L"btnClose";
			this->btnClose->TabIndex = 0;
			this->btnClose->Click += gcnew System::EventHandler(this, &ReceiptForm::btnClose_Click);
			//
			// lblHeader
			//
			this->lblHeader->BackColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblHeader->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->lblHeader->Size = System::Drawing::Size(460, 56);
			this->lblHeader->Text = L"Booking Confirmed";
			this->lblHeader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblHeader->Name = L"lblHeader";
			this->lblHeader->TabIndex = 2;
			//
			// ReceiptForm
			//
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(244, 246, 248);
			this->ClientSize = System::Drawing::Size(460, 560);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Booking Receipt";
			this->Controls->Add(this->txtReceipt);
			this->Controls->Add(this->pnlBottom);
			this->Controls->Add(this->lblHeader);
			this->Name = L"ReceiptForm";
			this->pnlBottom->ResumeLayout(false);
			this->pnlBottom->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

public:
	ReceiptForm(Booking^ b)
	{
		InitializeComponent();
		txtReceipt->Text = BuildText(b);
		txtReceipt->Select(0, 0);
	}

private:
	System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}

	static String^ BuildText(Booking^ b)
	{
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		String^ line = "  ------------------------------------------";
		sb->AppendLine();
		sb->AppendLine("  Booking No : " + Convert::ToString(b->Id));
		sb->AppendLine("  Date       : " + b->CreatedOn.ToString("yyyy-MM-dd HH:mm"));
		sb->AppendLine(line);
		sb->AppendLine("  Customer   : " + b->CustomerInfo->Name);
		sb->AppendLine("  NIC        : " + b->CustomerInfo->Nic);
		sb->AppendLine("  Phone      : " + b->CustomerInfo->Phone);
		sb->AppendLine(line);
		sb->AppendLine("  Vehicle    : " + b->VehicleName);
		sb->AppendLine("  Driver     : " + (String::IsNullOrEmpty(b->DriverName) ? "Not requested" : b->DriverName));
		sb->AppendLine("  Pick-up    : " + b->FromDate.ToString("yyyy-MM-dd"));
		sb->AppendLine("  Return     : " + b->ToDate.ToString("yyyy-MM-dd"));
		sb->AppendLine("  Days       : " + Convert::ToString(b->Days));
		sb->AppendLine(line);
		sb->AppendLine("  Vehicle    : " + UiTheme::Money(b->VehicleCost) + "  (" +
			UiTheme::Money(b->VehicleDailyRate) + " x " + Convert::ToString(b->Days) + ")");
		sb->AppendLine("  Driver     : " + UiTheme::Money(b->DriverCost));
		sb->AppendLine("  TOTAL      : " + UiTheme::Money(b->Total));
		sb->AppendLine("  Advance    : " + UiTheme::Money(b->Advance));
		sb->AppendLine("  BALANCE DUE: " + UiTheme::Money(b->Balance));
		sb->AppendLine(line);
		sb->AppendLine("  Please pay the balance when you return");
		sb->AppendLine("  the vehicle. Thank you!");
		return sb->ToString();
	}
	};
}
