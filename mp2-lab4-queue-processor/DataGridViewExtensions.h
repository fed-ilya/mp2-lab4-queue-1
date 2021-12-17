#pragma once
#include "Convertex.h"

//Adds a new element with textColor and scrolls DataGridView to it
void AddRowWithScroll(
	System::Windows::Forms::DataGridView^ dgv,
	System::Drawing::Color textColor,
	...cli::array<System::String^>^ row)
{
	//Adding
	dgv->Rows->Add(row);
	int lastIndex = dgv->RowCount - 1;
	dgv->Rows[lastIndex]->DefaultCellStyle->ForeColor = textColor;
	dgv->Rows[lastIndex]->DefaultCellStyle->SelectionForeColor = textColor;
	//Scrolling
	dgv->FirstDisplayedScrollingRowIndex = lastIndex;
}

void AddRowWithScroll(
	System::Windows::Forms::DataGridView^ dgv,
	System::Drawing::Color textColor,
	std::string row)
{
	AddRowWithScroll(dgv, textColor, Convertex::stringTo_String(row));
}