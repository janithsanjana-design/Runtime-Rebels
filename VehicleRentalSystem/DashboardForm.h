#pragma once
#include "UiTheme.h"
#include "BarChartPanel.h"
#include "ReportService.h"

namespace VehicleRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>Admin view: totals, rented vehicles, vehicle-wise income and a chart.  (open this file in the Visual Studio designer to edit the layout)</summary>
	public ref class DashboardForm : public System::Windows::Forms::Form
	{
	public:
		DashboardForm(void)
		{
			InitializeComponent();
			// Replace the placeholder Panel with the real BarChartPanel at runtime.
			// This guard prevents the code from running inside the VS Forms Designer,
			// which is what caused the "Unknown type VehicleRentalSystem.BarChartPanel" error.
			if (System::ComponentModel::LicenseManager::UsageMode != System::ComponentModel::LicenseUsageMode::Designtime)
			{
				BarChartPanel^ realChart = gcnew BarChartPanel();
				realChart->Dock = System::Windows::Forms::DockStyle::Fill;
				realChart->Name = L"chart";
				realChart->TabIndex = chart->TabIndex;
				pnlChart->Controls->Clear();
				pnlChart->Controls->Add(realChart);
				chart = realChart;
			}
			UiTheme::StyleGrid(dgvRented);
			UiTheme::StyleGrid(dgvIncome);
			LoadData();
		}

	protected:
		~DashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  pnlBody;
	private: System::Windows::Forms::Panel^  pnlGrids;
	private: System::Windows::Forms::TableLayoutPanel^  tlpGrids;
	private: System::Windows::Forms::Panel^  pnlRented;
	private: System::Windows::Forms::DataGridView^  dgvRented;
	private: System::Windows::Forms::Label^  lblRentedTitle;
	private: System::Windows::Forms::Panel^  pnlIncome;
	private: System::Windows::Forms::DataGridView^  dgvIncome;
	private: System::Windows::Forms::Label^  lblOwnerTotal;
	private: System::Windows::Forms::Label^  lblIncomeTitle;
	private: System::Windows::Forms::Panel^  pnlChart;
	private: System::Windows::Forms::Panel^  chart;   // typed as Panel so the VS designer can load this form; replaced at runtime with BarChartPanel
	private: System::Windows::Forms::Panel^  pnlCards;
	private: System::Windows::Forms::TableLayoutPanel^  tlpCards;
	private: System::Windows::Forms::Label^  lblTotalVehicles;
	private: System::Windows::Forms::Label^  lblCap1;
	private: System::Windows::Forms::Panel^  pnlStripe1;
	private: System::Windows::Forms::Panel^  pnlCard1;
	private: System::Windows::Forms::Label^  lblAvailable;
	private: System::Windows::Forms::Label^  lblCap2;
	private: System::Windows::Forms::Panel^  pnlStripe2;
	private: System::Windows::Forms::Panel^  pnlCard2;
	private: System::Windows::Forms::Label^  lblRented;
	private: System::Windows::Forms::Label^  lblCap3;
	private: System::Windows::Forms::Panel^  pnlStripe3;
	private: System::Windows::Forms::Panel^  pnlCard3;
	private: System::Windows::Forms::Label^  lblIncome;
	private: System::Windows::Forms::Label^  lblCap4;
	private: System::Windows::Forms::Panel^  pnlStripe4;
	private: System::Windows::Forms::Panel^  pnlCard4;
	private: System::Windows::Forms::Label^  lblProfit;
	private: System::Windows::Forms::Label^  lblCap5;
	private: System::Windows::Forms::Panel^  pnlStripe5;
	private: System::Windows::Forms::Panel^  pnlCard5;
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
			this->pnlGrids = (gcnew System::Windows::Forms::Panel());
			this->tlpGrids = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pnlRented = (gcnew System::Windows::Forms::Panel());
			this->dgvRented = (gcnew System::Windows::Forms::DataGridView());
			this->lblRentedTitle = (gcnew System::Windows::Forms::Label());
			this->pnlIncome = (gcnew System::Windows::Forms::Panel());
			this->dgvIncome = (gcnew System::Windows::Forms::DataGridView());
			this->lblOwnerTotal = (gcnew System::Windows::Forms::Label());
			this->lblIncomeTitle = (gcnew System::Windows::Forms::Label());
			this->pnlChart = (gcnew System::Windows::Forms::Panel());
			this->chart = (gcnew System::Windows::Forms::Panel());   // placeholder; swapped for real BarChartPanel in constructor
			this->pnlCards = (gcnew System::Windows::Forms::Panel());
			this->tlpCards = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblTotalVehicles = (gcnew System::Windows::Forms::Label());
			this->lblCap1 = (gcnew System::Windows::Forms::Label());
			this->pnlStripe1 = (gcnew System::Windows::Forms::Panel());
			this->pnlCard1 = (gcnew System::Windows::Forms::Panel());
			this->lblAvailable = (gcnew System::Windows::Forms::Label());
			this->lblCap2 = (gcnew System::Windows::Forms::Label());
			this->pnlStripe2 = (gcnew System::Windows::Forms::Panel());
			this->pnlCard2 = (gcnew System::Windows::Forms::Panel());
			this->lblRented = (gcnew System::Windows::Forms::Label());
			this->lblCap3 = (gcnew System::Windows::Forms::Label());
			this->pnlStripe3 = (gcnew System::Windows::Forms::Panel());
			this->pnlCard3 = (gcnew System::Windows::Forms::Panel());
			this->lblIncome = (gcnew System::Windows::Forms::Label());
			this->lblCap4 = (gcnew System::Windows::Forms::Label());
			this->pnlStripe4 = (gcnew System::Windows::Forms::Panel());
			this->pnlCard4 = (gcnew System::Windows::Forms::Panel());
			this->lblProfit = (gcnew System::Windows::Forms::Label());
			this->lblCap5 = (gcnew System::Windows::Forms::Label());
			this->pnlStripe5 = (gcnew System::Windows::Forms::Panel());
			this->pnlCard5 = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRented))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvIncome))->BeginInit();
			this->pnlBody->SuspendLayout();
			this->pnlGrids->SuspendLayout();
			this->tlpGrids->SuspendLayout();
			this->pnlRented->SuspendLayout();
			this->pnlIncome->SuspendLayout();
			this->pnlChart->SuspendLayout();
			this->pnlCards->SuspendLayout();
			this->tlpCards->SuspendLayout();
			this->pnlStripe1->SuspendLayout();
			this->pnlCard1->SuspendLayout();
			this->pnlStripe2->SuspendLayout();
			this->pnlCard2->SuspendLayout();
			this->pnlStripe3->SuspendLayout();
			this->pnlCard3->SuspendLayout();
			this->pnlStripe4->SuspendLayout();
			this->pnlCard4->SuspendLayout();
			this->pnlStripe5->SuspendLayout();
			this->pnlCard5->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->SuspendLayout();
			//
			// pnlBody
			//
			this->pnlBody->Controls->Add(this->pnlGrids);
			this->pnlBody->Controls->Add(this->pnlChart);
			this->pnlBody->Controls->Add(this->pnlCards);
			this->pnlBody->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlBody->Padding = System::Windows::Forms::Padding(16, 16, 16, 16);
			this->pnlBody->Size = System::Drawing::Size(1200, 716);
			this->pnlBody->Name = L"pnlBody";
			this->pnlBody->TabIndex = 0;
			//
			// pnlGrids
			//
			this->pnlGrids->Controls->Add(this->tlpGrids);
			this->pnlGrids->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlGrids->Name = L"pnlGrids";
			this->pnlGrids->TabIndex = 0;
			//
			// tlpGrids
			//
			this->tlpGrids->ColumnCount = 2;
			this->tlpGrids->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 42)));
			this->tlpGrids->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 58)));
			this->tlpGrids->RowCount = 1;
			this->tlpGrids->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tlpGrids->Controls->Add(this->pnlRented, 0, 0);
			this->tlpGrids->Controls->Add(this->pnlIncome, 1, 0);
			this->tlpGrids->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlpGrids->Name = L"tlpGrids";
			this->tlpGrids->TabIndex = 0;
			//
			// pnlRented
			//
			this->pnlRented->Controls->Add(this->dgvRented);
			this->pnlRented->Controls->Add(this->lblRentedTitle);
			this->pnlRented->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pnlRented->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlRented->Name = L"pnlRented";
			this->pnlRented->TabIndex = 0;
			//
			// dgvRented
			//
			this->dgvRented->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvRented->Name = L"dgvRented";
			this->dgvRented->TabIndex = 0;
			//
			// lblRentedTitle
			//
			this->lblRentedTitle->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblRentedTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblRentedTitle->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblRentedTitle->Size = System::Drawing::Size(100, 28);
			this->lblRentedTitle->Text = L"Rented vehicles (now)";
			this->lblRentedTitle->Name = L"lblRentedTitle";
			this->lblRentedTitle->TabIndex = 1;
			//
			// pnlIncome
			//
			this->pnlIncome->Controls->Add(this->dgvIncome);
			this->pnlIncome->Controls->Add(this->lblOwnerTotal);
			this->pnlIncome->Controls->Add(this->lblIncomeTitle);
			this->pnlIncome->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pnlIncome->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlIncome->Name = L"pnlIncome";
			this->pnlIncome->TabIndex = 1;
			//
			// dgvIncome
			//
			this->dgvIncome->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvIncome->Name = L"dgvIncome";
			this->dgvIncome->TabIndex = 0;
			//
			// lblOwnerTotal
			//
			this->lblOwnerTotal->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->lblOwnerTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblOwnerTotal->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblOwnerTotal->Size = System::Drawing::Size(100, 30);
			this->lblOwnerTotal->Text = L"";
			this->lblOwnerTotal->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblOwnerTotal->Name = L"lblOwnerTotal";
			this->lblOwnerTotal->TabIndex = 1;
			//
			// lblIncomeTitle
			//
			this->lblIncomeTitle->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblIncomeTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblIncomeTitle->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblIncomeTitle->Size = System::Drawing::Size(100, 28);
			this->lblIncomeTitle->Text = L"Income vehicle-wise";
			this->lblIncomeTitle->Name = L"lblIncomeTitle";
			this->lblIncomeTitle->TabIndex = 2;
			//
			// pnlChart
			//
			this->pnlChart->Controls->Add(this->chart);
			this->pnlChart->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pnlChart->Padding = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pnlChart->Size = System::Drawing::Size(600, 250);
			this->pnlChart->Name = L"pnlChart";
			this->pnlChart->TabIndex = 1;
			//
			// chart
			//
			this->chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chart->Name = L"chart";
			this->chart->TabIndex = 0;
			//
			// pnlCards
			//
			this->pnlCards->Controls->Add(this->tlpCards);
			this->pnlCards->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlCards->Size = System::Drawing::Size(600, 100);
			this->pnlCards->Name = L"pnlCards";
			this->pnlCards->TabIndex = 2;
			//
			// tlpCards
			//
			this->tlpCards->ColumnCount = 5;
			this->tlpCards->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tlpCards->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tlpCards->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tlpCards->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tlpCards->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tlpCards->RowCount = 1;
			this->tlpCards->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tlpCards->Controls->Add(this->pnlCard1, 0, 0);
			this->tlpCards->Controls->Add(this->pnlCard2, 1, 0);
			this->tlpCards->Controls->Add(this->pnlCard3, 2, 0);
			this->tlpCards->Controls->Add(this->pnlCard4, 3, 0);
			this->tlpCards->Controls->Add(this->pnlCard5, 4, 0);
			this->tlpCards->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlpCards->Name = L"tlpCards";
			this->tlpCards->TabIndex = 0;
			//
			// lblTotalVehicles
			//
			this->lblTotalVehicles->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblTotalVehicles->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTotalVehicles->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblTotalVehicles->Text = L"0";
			this->lblTotalVehicles->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblTotalVehicles->Name = L"lblTotalVehicles";
			this->lblTotalVehicles->TabIndex = 0;
			//
			// lblCap1
			//
			this->lblCap1->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblCap1->ForeColor = System::Drawing::Color::FromArgb(107, 119, 133);
			this->lblCap1->Size = System::Drawing::Size(100, 28);
			this->lblCap1->Text = L"Total vehicles";
			this->lblCap1->Name = L"lblCap1";
			this->lblCap1->TabIndex = 1;
			//
			// pnlStripe1
			//
			this->pnlStripe1->BackColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->pnlStripe1->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlStripe1->Size = System::Drawing::Size(6, 60);
			this->pnlStripe1->Name = L"pnlStripe1";
			this->pnlStripe1->TabIndex = 2;
			//
			// pnlCard1
			//
			this->pnlCard1->Controls->Add(this->lblTotalVehicles);
			this->pnlCard1->Controls->Add(this->lblCap1);
			this->pnlCard1->Controls->Add(this->pnlStripe1);
			this->pnlCard1->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlCard1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlCard1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pnlCard1->Padding = System::Windows::Forms::Padding(10, 6, 6, 6);
			this->pnlCard1->Name = L"pnlCard1";
			this->pnlCard1->TabIndex = 0;
			//
			// lblAvailable
			//
			this->lblAvailable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblAvailable->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblAvailable->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblAvailable->Text = L"0";
			this->lblAvailable->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblAvailable->Name = L"lblAvailable";
			this->lblAvailable->TabIndex = 0;
			//
			// lblCap2
			//
			this->lblCap2->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblCap2->ForeColor = System::Drawing::Color::FromArgb(107, 119, 133);
			this->lblCap2->Size = System::Drawing::Size(100, 28);
			this->lblCap2->Text = L"Available vehicles";
			this->lblCap2->Name = L"lblCap2";
			this->lblCap2->TabIndex = 1;
			//
			// pnlStripe2
			//
			this->pnlStripe2->BackColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->pnlStripe2->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlStripe2->Size = System::Drawing::Size(6, 60);
			this->pnlStripe2->Name = L"pnlStripe2";
			this->pnlStripe2->TabIndex = 2;
			//
			// pnlCard2
			//
			this->pnlCard2->Controls->Add(this->lblAvailable);
			this->pnlCard2->Controls->Add(this->lblCap2);
			this->pnlCard2->Controls->Add(this->pnlStripe2);
			this->pnlCard2->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlCard2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlCard2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pnlCard2->Padding = System::Windows::Forms::Padding(10, 6, 6, 6);
			this->pnlCard2->Name = L"pnlCard2";
			this->pnlCard2->TabIndex = 1;
			//
			// lblRented
			//
			this->lblRented->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblRented->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblRented->ForeColor = System::Drawing::Color::FromArgb(214, 69, 69);
			this->lblRented->Text = L"0";
			this->lblRented->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblRented->Name = L"lblRented";
			this->lblRented->TabIndex = 0;
			//
			// lblCap3
			//
			this->lblCap3->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblCap3->ForeColor = System::Drawing::Color::FromArgb(107, 119, 133);
			this->lblCap3->Size = System::Drawing::Size(100, 28);
			this->lblCap3->Text = L"Rented vehicles";
			this->lblCap3->Name = L"lblCap3";
			this->lblCap3->TabIndex = 1;
			//
			// pnlStripe3
			//
			this->pnlStripe3->BackColor = System::Drawing::Color::FromArgb(214, 69, 69);
			this->pnlStripe3->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlStripe3->Size = System::Drawing::Size(6, 60);
			this->pnlStripe3->Name = L"pnlStripe3";
			this->pnlStripe3->TabIndex = 2;
			//
			// pnlCard3
			//
			this->pnlCard3->Controls->Add(this->lblRented);
			this->pnlCard3->Controls->Add(this->lblCap3);
			this->pnlCard3->Controls->Add(this->pnlStripe3);
			this->pnlCard3->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlCard3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlCard3->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pnlCard3->Padding = System::Windows::Forms::Padding(10, 6, 6, 6);
			this->pnlCard3->Name = L"pnlCard3";
			this->pnlCard3->TabIndex = 2;
			//
			// lblIncome
			//
			this->lblIncome->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblIncome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblIncome->ForeColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->lblIncome->Text = L"0";
			this->lblIncome->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblIncome->Name = L"lblIncome";
			this->lblIncome->TabIndex = 0;
			//
			// lblCap4
			//
			this->lblCap4->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblCap4->ForeColor = System::Drawing::Color::FromArgb(107, 119, 133);
			this->lblCap4->Size = System::Drawing::Size(100, 28);
			this->lblCap4->Text = L"Total income";
			this->lblCap4->Name = L"lblCap4";
			this->lblCap4->TabIndex = 1;
			//
			// pnlStripe4
			//
			this->pnlStripe4->BackColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->pnlStripe4->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlStripe4->Size = System::Drawing::Size(6, 60);
			this->pnlStripe4->Name = L"pnlStripe4";
			this->pnlStripe4->TabIndex = 2;
			//
			// pnlCard4
			//
			this->pnlCard4->Controls->Add(this->lblIncome);
			this->pnlCard4->Controls->Add(this->lblCap4);
			this->pnlCard4->Controls->Add(this->pnlStripe4);
			this->pnlCard4->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlCard4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlCard4->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pnlCard4->Padding = System::Windows::Forms::Padding(10, 6, 6, 6);
			this->pnlCard4->Name = L"pnlCard4";
			this->pnlCard4->TabIndex = 3;
			//
			// lblProfit
			//
			this->lblProfit->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblProfit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblProfit->ForeColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->lblProfit->Text = L"0";
			this->lblProfit->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblProfit->Name = L"lblProfit";
			this->lblProfit->TabIndex = 0;
			//
			// lblCap5
			//
			this->lblCap5->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblCap5->ForeColor = System::Drawing::Color::FromArgb(107, 119, 133);
			this->lblCap5->Size = System::Drawing::Size(100, 28);
			this->lblCap5->Text = L"Company profit (10%)";
			this->lblCap5->Name = L"lblCap5";
			this->lblCap5->TabIndex = 1;
			//
			// pnlStripe5
			//
			this->pnlStripe5->BackColor = System::Drawing::Color::FromArgb(0, 168, 168);
			this->pnlStripe5->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlStripe5->Size = System::Drawing::Size(6, 60);
			this->pnlStripe5->Name = L"pnlStripe5";
			this->pnlStripe5->TabIndex = 2;
			//
			// pnlCard5
			//
			this->pnlCard5->Controls->Add(this->lblProfit);
			this->pnlCard5->Controls->Add(this->lblCap5);
			this->pnlCard5->Controls->Add(this->pnlStripe5);
			this->pnlCard5->BackColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->pnlCard5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlCard5->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pnlCard5->Padding = System::Windows::Forms::Padding(10, 6, 6, 6);
			this->pnlCard5->Name = L"pnlCard5";
			this->pnlCard5->TabIndex = 4;
			//
			// lblTitle
			//
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(255, 255, 255);
			this->lblTitle->Location = System::Drawing::Point(20, 13);
			this->lblTitle->Text = L"Admin Dashboard";
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
			this->btnBack->Location = System::Drawing::Point(1030, 13);
			this->btnBack->Size = System::Drawing::Size(150, 38);
			this->btnBack->Text = L"< Back to Menu";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBack->Name = L"btnBack";
			this->btnBack->TabIndex = 1;
			this->btnBack->Click += gcnew System::EventHandler(this, &DashboardForm::btnBack_Click);
			//
			// pnlHeader
			//
			this->pnlHeader->Controls->Add(this->lblTitle);
			this->pnlHeader->Controls->Add(this->btnBack);
			this->pnlHeader->BackColor = System::Drawing::Color::FromArgb(31, 58, 95);
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Size = System::Drawing::Size(1200, 64);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->TabIndex = 1;
			//
			// DashboardForm
			//
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(244, 246, 248);
			this->ClientSize = System::Drawing::Size(1200, 780);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MinimumSize = System::Drawing::Size(1100, 720);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Vehicle Rental System - Admin Dashboard";
			this->Controls->Add(this->pnlBody);
			this->Controls->Add(this->pnlHeader);
			this->Name = L"DashboardForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRented))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvIncome))->EndInit();
			this->pnlBody->ResumeLayout(false);
			this->pnlBody->PerformLayout();
			this->pnlGrids->ResumeLayout(false);
			this->pnlGrids->PerformLayout();
			this->tlpGrids->ResumeLayout(false);
			this->tlpGrids->PerformLayout();
			this->pnlRented->ResumeLayout(false);
			this->pnlRented->PerformLayout();
			this->pnlIncome->ResumeLayout(false);
			this->pnlIncome->PerformLayout();
			this->pnlChart->ResumeLayout(false);
			this->pnlChart->PerformLayout();
			this->pnlCards->ResumeLayout(false);
			this->pnlCards->PerformLayout();
			this->tlpCards->ResumeLayout(false);
			this->tlpCards->PerformLayout();
			this->pnlStripe1->ResumeLayout(false);
			this->pnlStripe1->PerformLayout();
			this->pnlCard1->ResumeLayout(false);
			this->pnlCard1->PerformLayout();
			this->pnlStripe2->ResumeLayout(false);
			this->pnlStripe2->PerformLayout();
			this->pnlCard2->ResumeLayout(false);
			this->pnlCard2->PerformLayout();
			this->pnlStripe3->ResumeLayout(false);
			this->pnlStripe3->PerformLayout();
			this->pnlCard3->ResumeLayout(false);
			this->pnlCard3->PerformLayout();
			this->pnlStripe4->ResumeLayout(false);
			this->pnlStripe4->PerformLayout();
			this->pnlCard4->ResumeLayout(false);
			this->pnlCard4->PerformLayout();
			this->pnlStripe5->ResumeLayout(false);
			this->pnlStripe5->PerformLayout();
			this->pnlCard5->ResumeLayout(false);
			this->pnlCard5->PerformLayout();
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
	void LoadData()
	{
		DashboardSummary^ s = ReportService::GetSummary();
		lblTotalVehicles->Text = Convert::ToString(s->TotalVehicles);
		lblAvailable->Text = Convert::ToString(s->AvailableVehicles);
		lblRented->Text = Convert::ToString(s->RentedVehicles);
		lblIncome->Text = UiTheme::Money(s->TotalIncome);
		lblProfit->Text = UiTheme::Money(s->CompanyProfit);

		lblOwnerTotal->Text = "Payable to owners: " + UiTheme::Money(s->OwnerPayable) +
			"     Company profit: " + UiTheme::Money(s->CompanyProfit);

		// rented vehicles right now
		DataTable^ rented = gcnew DataTable();
		for each (String^ name in gcnew array<String^> { "Vehicle", "Customer", "Driver", "Until", "Total" })
			rented->Columns->Add(name);
		for each (Booking^ b in ReportService::GetActiveBookings())
		{
			rented->Rows->Add(gcnew array<Object^> {
				b->VehicleName,
				b->CustomerInfo->Name,
				String::IsNullOrEmpty(b->DriverName) ? "-" : b->DriverName,
				b->ToDate.ToString("yyyy-MM-dd"),
				UiTheme::Money(b->Total) });
		}
		dgvRented->DataSource = rented;

		// income vehicle-wise (also feeds the chart)
		DataTable^ income = gcnew DataTable();
		for each (String^ name in gcnew array<String^> { "Vehicle", "Owner", "Rentals", "Income", "Owner payable", "Company profit" })
			income->Columns->Add(name);

		// Access chart-specific members via safe_cast (chart is typed Panel^ for designer compat)
		BarChartPanel^ barChart = dynamic_cast<BarChartPanel^>(chart);
		if (barChart != nullptr)
		{
			barChart->Labels->Clear();
			barChart->Values->Clear();
		}

		for each (VehicleIncomeRow^ r in ReportService::GetVehicleIncome())
		{
			income->Rows->Add(gcnew array<Object^> {
				r->Vehicle,
				r->Owner,
				Convert::ToString(r->Rentals),
				UiTheme::Money(r->Income),
				UiTheme::Money(r->OwnerPayable),
				UiTheme::Money(r->CompanyProfit) });

			if (barChart != nullptr)
			{
				array<String^>^ parts = r->Vehicle->Split(' ');
				barChart->Labels->Add(parts[0]);
				barChart->Values->Add(r->Income);
			}
		}
		dgvIncome->DataSource = income;
		chart->Invalidate();
	}
	};
}
