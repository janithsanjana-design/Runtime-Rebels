#include "UiTheme.h"

namespace VehicleRentalSystem
{
	using namespace System::Globalization;

	Font^ UiTheme::Regular::get()
	{
		if (_regular == nullptr) _regular = gcnew System::Drawing::Font("Segoe UI", 10.0f);
		return _regular;
	}

	Font^ UiTheme::Bold::get()
	{
		if (_bold == nullptr) _bold = gcnew System::Drawing::Font("Segoe UI", 10.0f, FontStyle::Bold);
		return _bold;
	}

	Font^ UiTheme::Title::get()
	{
		if (_title == nullptr) _title = gcnew System::Drawing::Font("Segoe UI", 18.0f, FontStyle::Bold);
		return _title;
	}

	String^ UiTheme::Money(Decimal value)
	{
		String^ format = (value == Math::Round(value)) ? "N0" : "N2";
		return "Rs. " + value.ToString(format, CultureInfo::InvariantCulture);
	}

	Button^ UiTheme::MakeButton(String^ text, Color color, int width)
	{
		Button^ b = gcnew Button();
		b->Text = text;
		b->BackColor = color;
		b->ForeColor = Color::White;
		b->FlatStyle = FlatStyle::Flat;
		b->Font = Bold;
		b->Width = width;
		b->Height = 38;
		b->Cursor = Cursors::Hand;
		b->Margin = System::Windows::Forms::Padding(3, 8, 3, 3);
		b->FlatAppearance->BorderSize = 0;
		b->FlatAppearance->MouseOverBackColor = ControlPaint::Light(color, 0.2f);
		return b;
	}

	Label^ UiTheme::MakeLabel(String^ text, bool bold)
	{
		Label^ l = gcnew Label();
		l->Text = text;
		l->AutoSize = true;
		l->Font = bold ? Bold : Regular;
		l->ForeColor = bold ? Primary : Color::FromArgb(50, 50, 50);
		l->Anchor = AnchorStyles::Left;
		l->Margin = System::Windows::Forms::Padding(3, 8, 3, 3);
		return l;
	}

	void UiTheme::StyleGrid(DataGridView^ g)
	{
		g->ReadOnly = true;
		g->AllowUserToAddRows = false;
		g->AllowUserToDeleteRows = false;
		g->AllowUserToResizeRows = false;
		g->MultiSelect = false;
		g->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		g->RowHeadersVisible = false;
		g->BackgroundColor = Color::White;
		g->BorderStyle = System::Windows::Forms::BorderStyle::None;
		g->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
		g->GridColor = Color::FromArgb(225, 230, 235);
		g->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
		g->EnableHeadersVisualStyles = false;
		g->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
		g->ColumnHeadersHeight = 34;
		g->ColumnHeadersDefaultCellStyle->BackColor = Primary;
		g->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
		g->ColumnHeadersDefaultCellStyle->Font = Bold;
		g->ColumnHeadersDefaultCellStyle->SelectionBackColor = Primary;
		g->DefaultCellStyle->Font = Regular;
		g->DefaultCellStyle->SelectionBackColor = Accent;
		g->DefaultCellStyle->SelectionForeColor = Color::White;
		g->AlternatingRowsDefaultCellStyle->BackColor = RowAlt;
		g->RowTemplate->Height = 28;
	}

	TableLayoutPanel^ UiTheme::FieldTable()
	{
		TableLayoutPanel^ t = gcnew TableLayoutPanel();
		t->Dock = DockStyle::Top;
		t->AutoSize = true;
		t->ColumnCount = 2;
		t->Padding = System::Windows::Forms::Padding(4);
		t->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 140));
		t->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100));
		return t;
	}

	void UiTheme::AddHeading(TableLayoutPanel^ t, String^ text)
	{
		Label^ l = MakeLabel(text, true);
		l->Font = gcnew System::Drawing::Font("Segoe UI", 11.0f, FontStyle::Bold);
		l->ForeColor = Accent;
		l->Margin = System::Windows::Forms::Padding(3, 12, 3, 3);
		AddWide(t, l);
	}

	void UiTheme::AddField(TableLayoutPanel^ t, String^ label, Control^ input)
	{
		int row = t->RowStyles->Count;
		t->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
		t->RowCount = row + 1;
		input->Dock = DockStyle::Fill;
		input->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
		t->Controls->Add(MakeLabel(label, false), 0, row);
		t->Controls->Add(input, 1, row);
	}

	void UiTheme::AddWide(TableLayoutPanel^ t, Control^ c)
	{
		int row = t->RowStyles->Count;
		t->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
		t->RowCount = row + 1;
		t->Controls->Add(c, 0, row);
		t->SetColumnSpan(c, 2);
	}

	NumericUpDown^ UiTheme::MakeMoneyBox(int max, int step)
	{
		NumericUpDown^ n = gcnew NumericUpDown();
		n->Minimum = Decimal(0);
		n->Maximum = Decimal(max);
		n->Increment = Decimal(step);
		n->DecimalPlaces = 0;
		n->ThousandsSeparator = true;
		return n;
	}

	Panel^ UiTheme::MakeCard()
	{
		Panel^ p = gcnew Panel();
		p->BackColor = Color::White;
		p->Dock = DockStyle::Fill;
		p->Margin = System::Windows::Forms::Padding(6);
		p->Padding = System::Windows::Forms::Padding(10);
		p->AutoScroll = true;
		return p;
	}

	void UiTheme::Info(IWin32Window^ owner, String^ message)
	{
		MessageBox::Show(owner, message, "Vehicle Rental System", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	void UiTheme::Warn(IWin32Window^ owner, String^ message)
	{
		MessageBox::Show(owner, message, "Please check", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	bool UiTheme::Confirm(IWin32Window^ owner, String^ message)
	{
		return MessageBox::Show(owner, message, "Please confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
			== System::Windows::Forms::DialogResult::Yes;
	}
}
