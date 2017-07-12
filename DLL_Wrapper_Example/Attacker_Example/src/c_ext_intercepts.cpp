
/*
** Global array of function pointers used by bridge assembly function
** to JMP into target DLL and execute function normally after intercepting.
*/
#include "stdafx.h"
#include "intercepts.h"

void		*(c_ext_intercepts[2]) = {0};

