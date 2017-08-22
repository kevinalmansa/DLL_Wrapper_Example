#pragma once
#include <stdio.h>

#ifdef TARGET_DLL_EXPORTS  
#define NON_WRANGLED_API __declspec(dllexport)
#else
#define NON_WRANGLED_API __declspec(dllimport)
#endif

#pragma comment(linker, "/export:ord4=Target_Ordinal_ForwardTo.#1,@5,NONAME")
#pragma comment(linker, "/export:ordinal_forward_test=Target_Ordinal_ForwardTo.#1,@6")

#pragma comment(linker, "/export:ord5=Target_Ordinal_ForwardTo.named_forward_test,@7,NONAME")
#pragma comment(linker, "/export:named_forward_test=Target_Ordinal_ForwardTo.named_forward_test,@8")


extern "C" {
	int		print_hello(void);
	int		print_dll_name(void);
	int		add_numbers(int a, int b);
	int		ordinal_test(void);
};
