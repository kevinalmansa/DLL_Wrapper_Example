// Victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

typedef int(*fnct_ptr)();
typedef int(*fnct_ptr_two)(int, int);

int main()
{
	HINSTANCE	dllHandle;
	fnct_ptr	print_hello;
	fnct_ptr	print_dll_name;
	fnct_ptr_two	add_dll_name;

	dllHandle = LoadLibraryA("DLL_Wrapper_Target_DLL.dll");
	if (dllHandle == NULL)
	{
		std::cerr << "Error: Couldn't load Library" << std::endl;
		return -1;
	}

	print_hello = (fnct_ptr)GetProcAddress(dllHandle, "print_hello");
	if (print_hello == NULL)
	{
		std::cerr << "Could not locate print_hello in DLL" << std::endl;
		return -1;
	}

	print_dll_name = (fnct_ptr)GetProcAddress(dllHandle, "print_dll_name");
	if (print_dll_name == NULL)
	{
		std::cerr << "Could not locate print_dll_name" << std::endl;
		return -1;
	}

	add_dll_name = (fnct_ptr_two)GetProcAddress(dllHandle, "add_numbers");
	if (add_dll_name == NULL)
	{
		std::cerr << "Could not locate add_dll_name" << std::endl;
		return -1;
	}

	std::cout << "print_hello call: " << std::endl;
	print_hello();

	std::cout << "print_dll_name call: " << std::endl;
	print_dll_name();

	std::cout << "add_dll_name: " << std::endl;
	add_dll_name(4, 5);

	return 0;
}

