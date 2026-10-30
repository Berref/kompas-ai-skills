// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the STEP1EXPRES_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// STEP1EXPRES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef STEP1EXPRES_EXPORTS
#define STEP1EXPRES_API __declspec(dllexport)
#else
#define STEP1EXPRES_API __declspec(dllimport)
#endif

