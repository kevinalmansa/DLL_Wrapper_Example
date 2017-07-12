#pragma once
#include <stdio.h>

#ifdef TARGET_DLL_EXPORTS  
#define NON_WRANGLED_API __declspec(dllexport)
#else
#define NON_WRANGLED_API __declspec(dllimport)
#endif

extern "C" {
	NON_WRANGLED_API int		print_hello(void);
	NON_WRANGLED_API int		print_dll_name(void);
	NON_WRANGLED_API int		add_numbers(int a, int b);
};
