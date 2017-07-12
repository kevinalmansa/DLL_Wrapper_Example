
#include "stdafx.h"
#include "intercepts.h"

extern "C" int	add_numbers(int a, int b)
{
	HINSTANCE			handle;
	FARPROC				intercepted_function;

	handle = LoadLibraryA("Target_DLL2.dll");
	if (handle == NULL)
	{
		printf("Error: Couldn't load Target DLL\n");
		return -1;
	}

	intercepted_function = GetProcAddress(handle, "add_numbers");
	if (intercepted_function == NULL)
	{
		printf("Error: Couldn't load function Target add_numbers\n");
		return -1;
	}

	// ARBITRARY CODE GOES HERE
	// CAN LOG PARAMATERS, EXECUTE ARBITRARY CODE, ETC
	printf("add_numbers Called. The function has been intercepted\n");

	// CALL INTERCEPTED FUNCTION
	// Note: This could also be done by casting intercepted_function to
	// the appropriate function pointer. Linking to an assembly routine
	// on the other hand gives a lower level control.
	c_ext_intercepts[1] = intercepted_function;
	add_numbers_bridge(a, b);

	return 0;
}

