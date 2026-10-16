#pragma once

namespace VehicleRentalSystem
{
	using namespace System;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	/// Lets a ComboBox show friendly text while holding a real object.
	public ref class ListItem
	{
	public:
		String^ Text;
		Object^ Value;

		ListItem(String^ text, Object^ value)
		{
			Text = text;
			Value = value;
		}

		virtual String^ ToString() override { return Text; }
	};

	/// One place for colours, fonts and helper methods so every form looks the same.
	public ref class UiTheme abstract sealed
	{
	private:
		static Font^ _regular;
		static Font^ _bold;
		static Font^ _title;

	public:
		static property Color Primary { Color get() { return ColorTranslator::FromHtml("#1F3A5F"); } }
		static property Color Accent { Color get() { return ColorTranslator::FromHtml("#00A8A8"); } }
		static property Color Background { Color get() { return ColorTranslator::FromHtml("#F4F6F8"); } }
		static property Color Danger { Color get() { return ColorTranslator::FromHtml("#D64545"); } }
		static property Color Muted { Color get() { return ColorTranslator::FromHtml("#6B7785"); } }
		static property Color RowAlt { Color get() { return ColorTranslator::FromHtml("#EAF4F6"); } }

		static property Font^ Regular { Font^ get(); }
		static property Font^ Bold { Font^ get(); }
		static property Font^ Title { Font^ get(); }

		/// Formats money as "Rs. 10,000" (cents only when needed).
		static String^ Money(Decimal value);

		static Button^ MakeButton(String^ text, Color color, int width);
		static Label^ MakeLabel(String^ text, bool bold);
		static void StyleGrid(DataGridView^ g);

		// ---------- helpers for building label + input rows ----------

		/// Two-column table: labels on the left, inputs on the right.
		static TableLayoutPanel^ FieldTable();
		static void AddHeading(TableLayoutPanel^ t, String^ text);
		static void AddField(TableLayoutPanel^ t, String^ label, Control^ input);
		static void AddWide(TableLayoutPanel^ t, Control^ c);

		static NumericUpDown^ MakeMoneyBox(int max, int step);

		/// A white panel that groups related inputs.
		static Panel^ MakeCard();

		static void Info(IWin32Window^ owner, String^ message);
		static void Warn(IWin32Window^ owner, String^ message);
		static bool Confirm(IWin32Window^ owner, String^ message);
	};
}
