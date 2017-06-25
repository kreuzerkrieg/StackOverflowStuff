// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MYLIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MYLIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

// This class is exported from the MyLibrary.dll
class MYLIBRARY_API CMyLibrary {
public:
	CMyLibrary(void);
	// TODO: add your methods here.
};

extern MYLIBRARY_API int nMyLibrary;

MYLIBRARY_API int fnMyLibrary(void);
