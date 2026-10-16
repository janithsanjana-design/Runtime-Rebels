#pragma once
#include "UiTheme.h"

namespace VehicleRentalSystem
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	/// A small hand-drawn bar chart (no extra libraries needed).
	public ref class BarChartPanel : Panel
	{
	public:
		String^ ChartTitle;
		List<String^>^ Labels;
		List<Decimal>^ Values;

		BarChartPanel()
		{
			this->DoubleBuffered = true;
			this->ResizeRedraw = true;
			this->BackColor = Color::White;
			ChartTitle = "Income per vehicle";
			Labels = gcnew List<String^>();
			Values = gcnew List<Decimal>();
		}

	protected:
		virtual void OnPaint(PaintEventArgs^ e) override
		{
			Panel::OnPaint(e);
			Graphics^ g = e->Graphics;
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			g->DrawString(ChartTitle, UiTheme::Bold, gcnew SolidBrush(UiTheme::Primary), 12.0f, 8.0f);

			Decimal max = Decimal::Zero;
			for each (Decimal v in Values)
			{
				if (v > max) max = v;
			}

			if (Values->Count == 0 || max <= Decimal::Zero)
			{
				g->DrawString("No income yet.", UiTheme::Regular, Brushes::Gray, 12.0f, 40.0f);
				return;
			}

			System::Drawing::Rectangle area(70, 38, this->Width - 90, this->Height - 38 - 40);
			if (area.Width < 50 || area.Height < 30) return;

			Pen^ axis = gcnew Pen(Color::FromArgb(200, 205, 210));
			System::Drawing::Font^ small = gcnew System::Drawing::Font("Segoe UI", 8.0f);

			// light grid lines with the money scale
			for (int i = 0; i <= 4; i++)
			{
				int y = area.Bottom - area.Height * i / 4;
				g->DrawLine(axis, area.Left, y, area.Right, y);
				String^ label = (max * Decimal(i) / Decimal(4)).ToString("N0");
				SizeF size = g->MeasureString(label, small);
				g->DrawString(label, small, Brushes::Gray, area.Left - size.Width - 4, y - size.Height / 2);
			}

			float slot = (float)area.Width / Values->Count;
			float barWidth = Math::Min(slot * 0.6f, 70.0f);

			for (int i = 0; i < Values->Count; i++)
			{
				float height = Convert::ToSingle(Values[i] / max) * area.Height;
				float x = area.Left + slot * i + (slot - barWidth) / 2;
				float top = area.Bottom - height;

				g->FillRectangle(gcnew SolidBrush(UiTheme::Accent), x, top, barWidth, height);

				String^ value = Values[i].ToString("N0");
				SizeF vs = g->MeasureString(value, small);
				g->DrawString(value, small, Brushes::DimGray, x + (barWidth - vs.Width) / 2, top - vs.Height);

				String^ name = Labels[i];
				if (name->Length > 14) name = name->Substring(0, 14);
				SizeF ns = g->MeasureString(name, small);
				g->DrawString(name, small, Brushes::Black, x + (barWidth - ns.Width) / 2, (float)area.Bottom + 4);
			}
		}
	};
}
