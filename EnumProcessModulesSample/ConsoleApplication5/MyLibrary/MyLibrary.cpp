// MyLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MyLibrary.h"


// This is an example of an exported variable
MYLIBRARY_API int nMyLibrary=0;

// This is an example of an exported function.
MYLIBRARY_API int fnMyLibrary(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see MyLibrary.h for the class definition
CMyLibrary::CMyLibrary()
{
    return;
}
