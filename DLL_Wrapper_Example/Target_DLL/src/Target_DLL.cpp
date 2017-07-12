// Target_DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Target_DLL.h"

extern "C" {
	int		print_hello(void) {
		printf("Hello\n");
		return 0;
	}

	int		print_dll_name(void) {
		printf("DLL_Wrapper_Target_DLL\n");
		return 0;
	}

	int		add_numbers(int a, int b) {
		printf("%d\n", a + b);
		return a + b;
	}
}