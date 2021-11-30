#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Exception.h"

Exception::Exception(const char* _file, const char* _func, int _line, const char* _desc)
{
	size_t n1 = strlen(_file);
	file = new char[n1 + 1];
	strcpy(file, _file);

	size_t n2 = strlen(_func);
	func = new char[n2 + 1];
	strcpy(func, _func);

	size_t n3 = strlen(_desc);
	desc = new char[n3 + 1];
	strcpy(desc, _desc);

	line = _line;
}

Exception::Exception(const Exception& e)
{
	size_t n1 = strlen(e.file);
	file = new char[n1 + 1];
	strcpy(file, e.file);

	size_t n2 = strlen(e.func);
	func = new char[n2 + 1];
	strcpy(func, e.func);

	size_t n3 = strlen(e.desc);
	desc = new char[n3 + 1];
	strcpy(desc, e.desc);

	line = e.line;
}

Exception::~Exception()
{
	delete[] file;
	delete[] func;
	delete[] desc;
}