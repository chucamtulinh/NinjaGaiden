#include <Windows.h>
#include "debug.h"
#include <fstream>
#include <iostream> 
#include <string>
#include <cstring>

using namespace std;


void DebugOut(wchar_t *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	wchar_t dbg_out[4096];
	vswprintf_s(dbg_out, fmt, argp);
	va_end(argp);
	OutputDebugString(dbg_out);

	/*std::wstring string(dbg_out);
	std::string str(string.begin(), string.end());
	out << str;*/


}