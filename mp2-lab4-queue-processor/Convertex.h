#pragma once
#include <string>

public class Convertex
{

private:
	Convertex() {}

public:
	static std::string StringTo_string(System::String^ str);

	static int StringTo_int(System::String^ str);
	static float StringTo_float(System::String^ str);
	static double StringTo_double(System::String^ str);

	static std::string Read_string(System::Windows::Forms::TextBox^ tb);
	static int Read_int(System::Windows::Forms::TextBox^ tb);
	static float Read_float(System::Windows::Forms::TextBox^ tb);
	static double Read_double(System::Windows::Forms::TextBox^ tb);
};