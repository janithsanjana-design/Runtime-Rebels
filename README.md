# Vehicle Rental System (C++/CLI, Windows Forms, .NET Framework 4.8, MySQL)

## What you need
- Visual Studio Community 2026 with **Desktop development with C++**, the **C++/CLI support for v145 build tools** component and the **.NET Framework 4.8 targeting pack**.
- **MySQL Server 8** running on the PC (Windows service `MySQL80`).
- `VehicleRentalSystem\lib\MySql.Data.dll` (MySQL Connector/NET). It is already in the project and is copied next to the exe when you build.

## Open and run
1. Open `VehicleRentalSystem.sln`.
2. Choose **Debug | x64** (or x86) and press **F5**.
3. On the first run a **MySQL connection** window appears. Enter the server (`localhost`), port (`3306`), database name (`vehicle_rental`), user (`root`) and **your MySQL password**, then click *Save and Connect*.
4. The program creates the database and tables by itself and adds sample vehicles, drivers and bookings once.

Connection settings are saved in `%AppData%\VehicleRentalSystem\dbconfig.ini` (plain text). Delete that file to be asked again.

Admin dashboard login: `admin` / `admin123`.

## Database tables (created automatically)
`owners`, `customers`, `vehicles` (-> owners), `drivers`, `bookings` (-> customers, vehicles, drivers), `app_meta`.
To start again with fresh sample data: `DROP DATABASE vehicle_rental;` in MySQL, then run the program.

## Designer view
Every screen is a normal Visual Studio form. In **Solution Explorer** double-click `VehicleForm.h`, `DriverForm.h`, `HireForm.h`, `DashboardForm.h`, `LoginForm.h`, `ReceiptForm.h`, `DbSettingsForm.h` or `MainForm.h` (or right-click -> **View Designer**) to drag, resize and restyle the panels, buttons and text boxes. Build the project once first so the designer can show the chart and the other custom parts. Event code (button clicks and so on) is in the same `.h` file below the `#pragma endregion` line.

## Files (`.h` declaration, `.cpp` implementation)
| Layer | Files |
|---|---|
| Models | `Enums.h`, `IEntity.h`, `Person.h/.cpp` (Person, Owner, Customer, Driver), `Vehicle.h/.cpp` (Vehicle, Car, Van, Suv, Bike, Bus), `Booking.h/.cpp` |
| Data (MySQL) | `IRepository.h`, `Repositories.h/.cpp`, `Db.h/.cpp` (connection, tables, settings), `SampleData.h/.cpp` |
| Services | `CommissionCalculator.h/.cpp` (the 10% rule), `BookingService.h/.cpp`, `ReportService.h/.cpp`, `AuthService.h`, `VehicleNotAvailableException.h` |
| Screens (designer) | `MainForm`, `VehicleForm`, `DriverForm`, `HireForm`, `ReceiptForm`, `LoginForm`, `DashboardForm`, `DbSettingsForm` (each a `.h` + `.resx`) |
| Helpers | `UiTheme.h/.cpp`, `BarChartPanel.h` |
| Entry point | `VehicleRentalSystem.cpp` |

## OOP used
- **Abstract class / inheritance:** `Person` -> `Owner`, `Customer`, `Driver`; `Vehicle` -> `Car`, `Van`, `Suv`, `Bike`, `Bus`.
- **Polymorphism:** `GetRole()`, `Type`, `GetDetails()` are overridden in each subclass.
- **Encapsulation:** private fields with validated properties (they throw `ArgumentException`).
- **Interfaces:** `IEntity`, `IRepository<T>` (implemented by the MySQL repositories).
- **Enums and a custom exception:** `VehicleType`, `VehicleStatus`, `BookingStatus`, `VehicleNotAvailableException`.

## Business rules
- Owner wants Rs. 9,000/day -> customer pays Rs. 10,000/day -> company earns Rs. 1,000/day (10%).
- Minimum advance = 25% of the total (`BookingService::MinAdvancePercent`).
- Drivers can only be chosen inside "Hire a Vehicle". Driver fees go to the driver, not into company income.
- Total income = vehicle rental money. Owner payable = 90% of it, company profit = 10%.

## Installing on another PC (Setup.exe)
`Installer\VehicleRentalSystem_Setup.exe` is a one-file installer. Copy it to the other PC and double-click it. It will:
1. check .NET Framework 4.8,
2. install the Visual C++ runtime if it is missing (Windows asks for permission once),
3. check that a MySQL service is installed and running (it only warns; it cannot install MySQL for you),
4. copy the program to `%LocalAppData%\Programs\VehicleRentalSystem`, add Desktop and Start-menu shortcuts and an entry in *Apps & features* (use that to uninstall; your MySQL data is kept),
5. start the program.

**MySQL Server must be installed on the other PC first** (https://dev.mysql.com/downloads/installer/), or you can type the address of another MySQL server in the connection window. The database and all tables are created automatically on the first start, so no SQL has to be run by hand (`Installer\database.sql` is only a reference copy).

To rebuild the setup after changing the program:
```
powershell -ExecutionPolicy Bypass -File Installer\build-setup.ps1
```
This builds Release x64 and recreates `Installer\VehicleRentalSystem_Setup.exe`.
