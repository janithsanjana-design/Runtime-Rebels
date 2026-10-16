// Entry point of the Vehicle Rental System (C++/CLI Windows Forms, .NET Framework 4.8, MySQL)
#include "Db.h"
#include "DbSettingsForm.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

/// Friendly message instead of a crash window.
ref class ErrorHandler abstract sealed
{
public:
	static void OnThreadException(Object^ sender, System::Threading::ThreadExceptionEventArgs^ e)
	{
		MessageBox::Show("Something went wrong:\r\n" + e->Exception->Message, "Vehicle Rental System",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
};

[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::ThreadException += gcnew System::Threading::ThreadExceptionEventHandler(&ErrorHandler::OnThreadException);

	// Connect to MySQL. If it fails, ask for the connection settings and try again.
	while (true)
	{
		try
		{
			VehicleRentalSystem::Db::Initialize();
			break;
		}
		catch (Exception^ ex)
		{
			VehicleRentalSystem::DbSettingsForm^ settings = gcnew VehicleRentalSystem::DbSettingsForm();
			settings->ShowMessage("Could not connect to MySQL:\r\n" + ex->Message);
			if (settings->ShowDialog() != System::Windows::Forms::DialogResult::OK) return 1;
		}
	}

	Application::Run(gcnew VehicleRentalSystem::MainForm());
	return 0;
}
