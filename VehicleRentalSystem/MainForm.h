#pragma once
#include "UiTheme.h"
#include "LoginForm.h"
#include "VehicleForm.h"
#include "DriverForm.h"
#include "HireForm.h"
#include "DashboardForm.h"

namespace VehicleRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>Home screen with four big buttons.  (open this file in the Visual Studio designer to edit the layout)</summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btnVehicle;
	private: System::Windows::Forms::Button^  btnDriver;
	private: System::Windows::Forms::Button^  btnHire;
	private: System::Windows::Forms::Button^  btnDashboard;
	private: System::Windows::Forms::TableLayoutPanel^  tlpTiles;
	private: System::Windows::Forms::Label^  lblAppTitle;
	private: System::Windows::Forms::Label^  lblSubtitle;
	private: System::Windows::Forms::Panel^  pnlHeader;

	private:
		/// <summary>Required designer variable.</summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>Designer-managed code: edit the layout in the designer, not by hand.</summary>
		void InitializeComponent(void)
		{
			this->btnVehicle = (gcnew System::Windows::Forms::Button());
			this->btnDriver = (gcnew System::Windows::Forms::Button());
			this->btnHire = (gcnew System::Windows::Forms::Button());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->tlpTiles = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblAppTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->tlpTiles->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnVehicle
			// 
			this->btnVehicle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->btnVehicle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnVehicle->FlatAppearance->BorderSize = 0;
			this->btnVehicle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVehicle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVehicle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->btnVehicle->Location = System::Drawing::Point(52, 52);
			this->btnVehicle->Margin = System::Windows::Forms::Padding(12);
			this->btnVehicle->Name = L"btnVehicle";
			this->btnVehicle->Size = System::Drawing::Size(416, 201);
			this->btnVehicle->TabIndex = 0;
			this->btnVehicle->Text = L"Register Vehicle\r\n\r\nAdd a vehicle and set the owner\'s price";
			this->btnVehicle->UseVisualStyleBackColor = false;
			this->btnVehicle->Click += gcnew System::EventHandler(this, &MainForm::btnVehicle_Click);
			// 
			// btnDriver
			// 
			this->btnDriver->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->btnDriver->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnDriver->FlatAppearance->BorderSize = 0;
			this->btnDriver->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDriver->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDriver->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->btnDriver->Location = System::Drawing::Point(492, 52);
			this->btnDriver->Margin = System::Windows::Forms::Padding(12);
			this->btnDriver->Name = L"btnDriver";
			this->btnDriver->Size = System::Drawing::Size(416, 201);
			this->btnDriver->TabIndex = 1;
			this->btnDriver->Text = L"Register Driver\r\n\r\nAdd a driver customers can request";
			this->btnDriver->UseVisualStyleBackColor = false;
			this->btnDriver->Click += gcnew System::EventHandler(this, &MainForm::btnDriver_Click);
			// 
			// btnHire
			// 
			this->btnHire->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->btnHire->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnHire->FlatAppearance->BorderSize = 0;
			this->btnHire->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHire->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHire->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->btnHire->Location = System::Drawing::Point(52, 277);
			this->btnHire->Margin = System::Windows::Forms::Padding(12);
			this->btnHire->Name = L"btnHire";
			this->btnHire->Size = System::Drawing::Size(416, 201);
			this->btnHire->TabIndex = 2;
			this->btnHire->Text = L"Hire a Vehicle\r\n\r\nBook a vehicle, with or without a driver";
			this->btnHire->UseVisualStyleBackColor = false;
			this->btnHire->Click += gcnew System::EventHandler(this, &MainForm::btnHire_Click);
			// 
			// btnDashboard
			// 
			this->btnDashboard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->btnDashboard->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDashboard->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->btnDashboard->Location = System::Drawing::Point(492, 277);
			this->btnDashboard->Margin = System::Windows::Forms::Padding(12);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Size = System::Drawing::Size(416, 201);
			this->btnDashboard->TabIndex = 3;
			this->btnDashboard->Text = L"Admin Dashboard\r\n\r\nIncome, vehicles and owner payments";
			this->btnDashboard->UseVisualStyleBackColor = false;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &MainForm::btnDashboard_Click);
			// 
			// tlpTiles
			// 
			this->tlpTiles->ColumnCount = 2;
			this->tlpTiles->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tlpTiles->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tlpTiles->Controls->Add(this->btnVehicle, 0, 0);
			this->tlpTiles->Controls->Add(this->btnDriver, 1, 0);
			this->tlpTiles->Controls->Add(this->btnHire, 0, 1);
			this->tlpTiles->Controls->Add(this->btnDashboard, 1, 1);
			this->tlpTiles->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlpTiles->Location = System::Drawing::Point(0, 110);
			this->tlpTiles->Name = L"tlpTiles";
			this->tlpTiles->Padding = System::Windows::Forms::Padding(40);
			this->tlpTiles->RowCount = 2;
			this->tlpTiles->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tlpTiles->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tlpTiles->Size = System::Drawing::Size(960, 530);
			this->tlpTiles->TabIndex = 0;
			// 
			// lblAppTitle
			// 
			this->lblAppTitle->AutoSize = true;
			this->lblAppTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 26, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAppTitle->ForeColor = System::Drawing::Color::SkyBlue;
			this->lblAppTitle->Location = System::Drawing::Point(40, 20);
			this->lblAppTitle->Name = L"lblAppTitle";
			this->lblAppTitle->Size = System::Drawing::Size(477, 60);
			this->lblAppTitle->TabIndex = 0;
			this->lblAppTitle->Text = L"Vehicle Rental System";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->lblSubtitle->Location = System::Drawing::Point(44, 72);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(185, 25);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Rent vehicles simply ";
			this->lblSubtitle->Click += gcnew System::EventHandler(this, &MainForm::lblSubtitle_Click);
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->pnlHeader->Controls->Add(this->lblAppTitle);
			this->pnlHeader->Controls->Add(this->lblSubtitle);
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Location = System::Drawing::Point(0, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(960, 110);
			this->pnlHeader->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->ClientSize = System::Drawing::Size(960, 640);
			this->Controls->Add(this->tlpTiles);
			this->Controls->Add(this->pnlHeader);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Vehicle Rental System";
			this->tlpTiles->ResumeLayout(false);
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private:
	System::Void btnVehicle_Click(System::Object^  sender, System::EventArgs^  e)
	{
		VehicleForm^ f = gcnew VehicleForm();
		f->ShowDialog(this);
		delete f;
	}

	System::Void btnDriver_Click(System::Object^  sender, System::EventArgs^  e)
	{
		DriverForm^ f = gcnew DriverForm();
		f->ShowDialog(this);
		delete f;
	}

	System::Void btnHire_Click(System::Object^  sender, System::EventArgs^  e)
	{
		HireForm^ f = gcnew HireForm();
		f->ShowDialog(this);
		delete f;
	}

	System::Void btnDashboard_Click(System::Object^  sender, System::EventArgs^  e)
	{
		LoginForm^ login = gcnew LoginForm();
		System::Windows::Forms::DialogResult result = login->ShowDialog(this);
		delete login;
		if (result != System::Windows::Forms::DialogResult::OK) return;

		DashboardForm^ f = gcnew DashboardForm();
		f->ShowDialog(this);
		delete f;
	}
	private: System::Void lblSubtitle_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
