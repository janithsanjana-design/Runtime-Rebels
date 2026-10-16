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

	/// <summary>Asks for the MySQL server, user and password.  (open this file in the Visual Studio designer to edit the layout)</summary>
	public ref class DbSettingsForm : public System::Windows::Forms::Form
	{
	public:
		DbSettingsForm(void)
		{
			InitializeComponent();
			DbConfig^ cfg = DbConfig::Load();
			txtServer->Text = cfg->Server;
			txtPort->Text = Convert::ToString(cfg->Port);
			txtDatabase->Text = cfg->Database;
			txtUser->Text = cfg->User;
			txtPassword->Text = cfg->Password;
		}

	protected:
		~DbSettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  lblFor_txtServer;
	private: System::Windows::Forms::TextBox^  txtServer;
	private: System::Windows::Forms::Label^  lblFor_txtPort;
	private: System::Windows::Forms::TextBox^  txtPort;
	private: System::Windows::Forms::Label^  lblFor_txtDatabase;
	private: System::Windows::Forms::TextBox^  txtDatabase;
	private: System::Windows::Forms::Label^  lblFor_txtUser;
	private: System::Windows::Forms::TextBox^  txtUser;
	private: System::Windows::Forms::Label^  lblFor_txtPassword;
	private: System::Windows::Forms::TextBox^  txtPassword;
	private: System::Windows::Forms::Label^  lblMessage;
	private: System::Windows::Forms::Label^  lblNote;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::Label^  lblHeader;

	private:
		/// <summary>Required designer variable.</summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>Designer-managed code: edit the layout in the designer, not by hand.</summary>
		void InitializeComponent(void)
		{
			this->lblFor_txtServer = (gcnew System::Windows::Forms::Label());
			this->txtServer = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtPort = (gcnew System::Windows::Forms::Label());
			this->txtPort = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtDatabase = (gcnew System::Windows::Forms::Label());
			this->txtDatabase = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtUser = (gcnew System::Windows::Forms::Label());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->lblNote = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lblHeader = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblFor_txtServer
			// 
			this->lblFor_txtServer->AutoSize = true;
			this->lblFor_txtServer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblFor_txtServer->Location = System::Drawing::Point(15, 153);
			this->lblFor_txtServer->Name = L"lblFor_txtServer";
			this->lblFor_txtServer->Size = System::Drawing::Size(57, 23);
			this->lblFor_txtServer->TabIndex = 0;
			this->lblFor_txtServer->Text = L"Server";
			// 
			// txtServer
			// 
			this->txtServer->Location = System::Drawing::Point(150, 150);
			this->txtServer->Name = L"txtServer";
			this->txtServer->Size = System::Drawing::Size(270, 30);
			this->txtServer->TabIndex = 1;
			// 
			// lblFor_txtPort
			// 
			this->lblFor_txtPort->AutoSize = true;
			this->lblFor_txtPort->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblFor_txtPort->Location = System::Drawing::Point(15, 187);
			this->lblFor_txtPort->Name = L"lblFor_txtPort";
			this->lblFor_txtPort->Size = System::Drawing::Size(41, 23);
			this->lblFor_txtPort->TabIndex = 2;
			this->lblFor_txtPort->Text = L"Port";
			// 
			// txtPort
			// 
			this->txtPort->Location = System::Drawing::Point(150, 184);
			this->txtPort->Name = L"txtPort";
			this->txtPort->Size = System::Drawing::Size(270, 30);
			this->txtPort->TabIndex = 3;
			// 
			// lblFor_txtDatabase
			// 
			this->lblFor_txtDatabase->AutoSize = true;
			this->lblFor_txtDatabase->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblFor_txtDatabase->Location = System::Drawing::Point(15, 221);
			this->lblFor_txtDatabase->Name = L"lblFor_txtDatabase";
			this->lblFor_txtDatabase->Size = System::Drawing::Size(81, 23);
			this->lblFor_txtDatabase->TabIndex = 4;
			this->lblFor_txtDatabase->Text = L"Database";
			// 
			// txtDatabase
			// 
			this->txtDatabase->Location = System::Drawing::Point(150, 218);
			this->txtDatabase->Name = L"txtDatabase";
			this->txtDatabase->Size = System::Drawing::Size(270, 30);
			this->txtDatabase->TabIndex = 5;
			// 
			// lblFor_txtUser
			// 
			this->lblFor_txtUser->AutoSize = true;
			this->lblFor_txtUser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblFor_txtUser->Location = System::Drawing::Point(15, 255);
			this->lblFor_txtUser->Name = L"lblFor_txtUser";
			this->lblFor_txtUser->Size = System::Drawing::Size(44, 23);
			this->lblFor_txtUser->TabIndex = 6;
			this->lblFor_txtUser->Text = L"User";
			// 
			// txtUser
			// 
			this->txtUser->Location = System::Drawing::Point(150, 252);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(270, 30);
			this->txtUser->TabIndex = 7;
			// 
			// lblFor_txtPassword
			// 
			this->lblFor_txtPassword->AutoSize = true;
			this->lblFor_txtPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblFor_txtPassword->Location = System::Drawing::Point(15, 289);
			this->lblFor_txtPassword->Name = L"lblFor_txtPassword";
			this->lblFor_txtPassword->Size = System::Drawing::Size(80, 23);
			this->lblFor_txtPassword->TabIndex = 8;
			this->lblFor_txtPassword->Text = L"Password";
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(150, 286);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(270, 30);
			this->txtPassword->TabIndex = 9;
			this->txtPassword->UseSystemPasswordChar = true;
			this->txtPassword->TextChanged += gcnew System::EventHandler(this, &DbSettingsForm::txtPassword_TextChanged);
			// 
			// lblMessage
			// 
			this->lblMessage->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(214)), static_cast<System::Int32>(static_cast<System::Byte>(69)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->lblMessage->Location = System::Drawing::Point(15, 70);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(410, 70);
			this->lblMessage->TabIndex = 10;
			this->lblMessage->Text = L"Message";
			// 
			// lblNote
			// 
			this->lblNote->AutoSize = true;
			this->lblNote->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->lblNote->Location = System::Drawing::Point(15, 322);
			this->lblNote->Name = L"lblNote";
			this->lblNote->Size = System::Drawing::Size(524, 23);
			this->lblNote->TabIndex = 11;
			this->lblNote->Text = L"Settings are saved in %AppData%\\VehicleRentalSystem\\dbconfig.ini";
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->btnSave->FlatAppearance->BorderSize = 0;
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSave->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnSave->Location = System::Drawing::Point(15, 352);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(200, 38);
			this->btnSave->TabIndex = 12;
			this->btnSave->Text = L"Save and Connect";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &DbSettingsForm::btnSave_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->FlatAppearance->BorderSize = 0;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnCancel->Location = System::Drawing::Point(225, 352);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(120, 38);
			this->btnCancel->TabIndex = 13;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = false;
			// 
			// lblHeader
			// 
			this->lblHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->lblHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblHeader->Location = System::Drawing::Point(0, 0);
			this->lblHeader->Name = L"lblHeader";
			this->lblHeader->Size = System::Drawing::Size(440, 56);
			this->lblHeader->TabIndex = 14;
			this->lblHeader->Text = L"MySQL connection";
			this->lblHeader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DbSettingsForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(440, 410);
			this->Controls->Add(this->lblFor_txtServer);
			this->Controls->Add(this->txtServer);
			this->Controls->Add(this->lblFor_txtPort);
			this->Controls->Add(this->txtPort);
			this->Controls->Add(this->lblFor_txtDatabase);
			this->Controls->Add(this->txtDatabase);
			this->Controls->Add(this->lblFor_txtUser);
			this->Controls->Add(this->txtUser);
			this->Controls->Add(this->lblFor_txtPassword);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblMessage);
			this->Controls->Add(this->lblNote);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->lblHeader);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DbSettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Vehicle Rental System - Database";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

public:
	void ShowMessage(String^ message)
	{
		lblMessage->Text = message;
	}

private:
	System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int port;
		if (!Int32::TryParse(txtPort->Text->Trim(), port) || port < 1 || port > 65535)
		{
			UiTheme::Warn(this, "Port must be a number between 1 and 65535.");
			return;
		}
		if (txtServer->Text->Trim()->Length == 0 || txtDatabase->Text->Trim()->Length == 0 || txtUser->Text->Trim()->Length == 0)
		{
			UiTheme::Warn(this, "Server, database and user are required.");
			return;
		}

		DbConfig^ cfg = gcnew DbConfig();
		cfg->Server = txtServer->Text->Trim();
		cfg->Port = port;
		cfg->Database = txtDatabase->Text->Trim();
		cfg->User = txtUser->Text->Trim();
		cfg->Password = txtPassword->Text;
		cfg->Save();

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void txtPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
