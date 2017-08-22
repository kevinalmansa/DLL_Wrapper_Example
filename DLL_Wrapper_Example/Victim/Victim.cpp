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
	fnct_ptr	ord_test;

	fnct_ptr	frwd_ord_test;
	fnct_ptr	frwd_ord_to_named_test;

	fnct_ptr	frwd_named_test;
	fnct_ptr	frwd_named_to_ord_test;

	dllHandle = LoadLibraryA("Target_DLL.dll");
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

	ord_test = (fnct_ptr)GetProcAddress(dllHandle, MAKEINTRESOURCEA(4));
	if (ord_test == NULL)
	{
		std::cerr << "Could not locate ordinal number 4" << std::endl;
		return -1;
	}

	frwd_ord_test = (fnct_ptr)GetProcAddress(dllHandle, MAKEINTRESOURCEA(5));
	if (frwd_ord_test == NULL)
	{
		std::cerr << "Could not locate ordinal number 5" << std::endl;
		return -1;
	}

	//this should point to the same function as above
	frwd_ord_to_named_test = (fnct_ptr)GetProcAddress(dllHandle, "ordinal_forward_test");
	if (frwd_ord_to_named_test == NULL)
	{
		std::cerr << "Could not locate ordinal_forward_test" << std::endl;
		return -1;
	}

	frwd_named_test = (fnct_ptr)GetProcAddress(dllHandle, "named_forward_test");
	if (frwd_named_test == NULL)
	{
		std::cerr << "Could not locate named_forward_test" << std::endl;
		return -1;
	}

	frwd_named_to_ord_test = (fnct_ptr)GetProcAddress(dllHandle, MAKEINTRESOURCEA(7));
	if (frwd_named_to_ord_test == NULL)
	{
		std::cerr << "Could not locate ordinal number 7" << std::endl;
		return -1;
	}

	std::cout << "print_hello call: " << std::endl;
	print_hello();

	std::cout << "print_dll_name call: " << std::endl;
	print_dll_name();

	std::cout << "add_dll_name: " << std::endl;
	add_dll_name(4, 5);

	std::cout << "ordinal test:" << std::endl;
	ord_test();

	std::cout << "forwarded ordinal test:" << std::endl;
	frwd_ord_test();

	std::cout << "Testing a Named Export of a Forward to an Ordinal" << std::endl;
	frwd_ord_to_named_test();

	std::cout << "Testing a Forwarded Named Export" << std::endl;
	frwd_named_test();

	std::cout << "Testing an ordinal export forwarding to a named export" << std::endl;
	frwd_named_to_ord_test();

	return 0;
}

