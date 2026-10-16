#pragma once
#include "UiTheme.h"
#include "AuthService.h"

namespace VehicleRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>Admin login shown before the dashboard.  (open this file in the Visual Studio designer to edit the layout)</summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  lblFor_txtUser;
	private: System::Windows::Forms::TextBox^  txtUser;
	private: System::Windows::Forms::Label^  lblFor_txtPassword;
	private: System::Windows::Forms::TextBox^  txtPassword;
	private: System::Windows::Forms::Label^  lblHint;
	private: System::Windows::Forms::Button^  btnLogin;
	private: System::Windows::Forms::Label^  lblHeader;

	private:
		/// <summary>Required designer variable.</summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>Designer-managed code: edit the layout in the designer, not by hand.</summary>
		void InitializeComponent(void)
		{
			this->lblFor_txtUser = (gcnew System::Windows::Forms::Label());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->lblFor_txtPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblHint = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->lblHeader = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblFor_txtUser
			// 
			this->lblFor_txtUser->AutoSize = true;
			this->lblFor_txtUser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblFor_txtUser->Location = System::Drawing::Point(15, 88);
			this->lblFor_txtUser->Name = L"lblFor_txtUser";
			this->lblFor_txtUser->Size = System::Drawing::Size(87, 23);
			this->lblFor_txtUser->TabIndex = 0;
			this->lblFor_txtUser->Text = L"Username";
			// 
			// txtUser
			// 
			this->txtUser->Location = System::Drawing::Point(150, 85);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(195, 30);
			this->txtUser->TabIndex = 1;
			// 
			// lblFor_txtPassword
			// 
			this->lblFor_txtPassword->AutoSize = true;
			this->lblFor_txtPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblFor_txtPassword->Location = System::Drawing::Point(15, 123);
			this->lblFor_txtPassword->Name = L"lblFor_txtPassword";
			this->lblFor_txtPassword->Size = System::Drawing::Size(80, 23);
			this->lblFor_txtPassword->TabIndex = 2;
			this->lblFor_txtPassword->Text = L"Password";
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(150, 120);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(195, 30);
			this->txtPassword->TabIndex = 3;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// lblHint
			// 
			this->lblHint->AutoSize = true;
			this->lblHint->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(133)));
			this->lblHint->Location = System::Drawing::Point(15, 158);
			this->lblHint->Name = L"lblHint";
			this->lblHint->Size = System::Drawing::Size(296, 23);
			this->lblHint->TabIndex = 4;
			this->lblHint->Text = L"Enter Admin Username and Password";
			this->lblHint->Click += gcnew System::EventHandler(this, &LoginForm::lblHint_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->btnLogin->FlatAppearance->BorderSize = 0;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnLogin->Location = System::Drawing::Point(15, 192);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(330, 38);
			this->btnLogin->TabIndex = 5;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
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
			this->lblHeader->Size = System::Drawing::Size(360, 56);
			this->lblHeader->TabIndex = 6;
			this->lblHeader->Text = L"Admin Login";
			this->lblHeader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LoginForm
			// 
			this->AcceptButton = this->btnLogin;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->ClientSize = System::Drawing::Size(360, 250);
			this->Controls->Add(this->lblFor_txtUser);
			this->Controls->Add(this->txtUser);
			this->Controls->Add(this->lblFor_txtPassword);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblHint);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->lblHeader);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Admin Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	System::Void btnLogin_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (AuthService::Login(txtUser->Text->Trim(), txtPassword->Text))
		{
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else
		{
			UiTheme::Warn(this, "Wrong username or password.");
			txtPassword->Clear();
			txtPassword->Focus();
		}
	}
	private: System::Void lblHint_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
