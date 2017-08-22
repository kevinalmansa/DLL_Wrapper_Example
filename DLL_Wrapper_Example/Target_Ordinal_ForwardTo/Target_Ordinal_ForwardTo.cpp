// Target_Ordinal_ForwardTo.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Target_Ordinal_ForwardTo.h"

extern "C" int			ordinal_forward_test(void) {
	printf("Successfully Forwarded by Ordinal\n");
	return 0;
}

extern "C" int			named_forward_test(void) {
	printf("Successfully forwarded by Name\n");
	return 0;
}
