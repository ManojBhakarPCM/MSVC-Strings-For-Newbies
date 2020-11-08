#include "stdafx.h"			// put all #include in this header file so that need not to compile each time with code in this file.
#include "targetver.h"
#include <stdio.h>			//	printf(), wprintf()
#include <conio.h>			//	just for _getch()
#include <windows.h>		//  wsprintf(), char, wchar_t, LPSTR,LPCSTR,LPWSTR,LPCWSTR...
//#include <tchar.h>		//  TCHAR, LPTSTR, LPCTSTR... I replaced TCHAR with wchar_t in _main(argv[]) also. now no need of all that crap.
//#include <iostream>		//  cin() , cout() , wcin() , wcout()... No need, I am happy with <stdio.h>'s printf family functions.
#include <string>			//  for std string

//--------------------------------------------------------------------------------------
// Written In Visual C++ 2008 Express Edition. Running On Windows 10, x64
// Author: ManojBhakarPCM
// Aim   :  to Provide noobs, a base about Strings and custum Functions. 
//			because i am noob and wasted entire month fighting to Errors on this topic.
//--------------------------------------------------------------------------------------

//using namespace std;

void defineTests(){
// define:: wchar_t* = LPWSTR ,const wchar_t* = LPCWSTR from "hard Coded String"
	wprintf(L"\n----------------------------\n # defining wchar_t from hardcoded strings \n----------------------------");

	wchar_t*		pUnicodeVariable						= L"defining wchar_t* form hard coded string is working fine";  // 'p' in begining of variable name stands for 'pointer to'
	LPWSTR			pUnicodeVariable_JustShortenedTheName	= L"LPWSTR is nothing but wchar_t*. shortened name of Long Pointer to Widechar STRing. we doing nothing special here";
	const wchar_t*	pUnicodeConstant						= L"defining const wchar_t* from hard coded string is working fine";
	LPCWSTR			pUnicodeConstant_JustShortenedTheName	= L"LPCWSTR is nothing but 'const wchar_t*'. shortened name of Long Pointer to Constant Widechar STRing. we doing nothing special here";

	wprintf(L"\n%s\n%s\n%s\n%s\n",pUnicodeVariable,pUnicodeVariable_JustShortenedTheName,pUnicodeConstant,pUnicodeConstant_JustShortenedTheName); //learn how would you print "wchar_t variants" here ;)

	printf("\n----------------------------\n # Converting wchar_t stuff from another 'wchar_t Variantes'\n----------------------------");
// Conversion :: wchar_t = LPWSTR ,const wchar_t = LPCWSTR from another variable

	wchar_t*		VariableFromConstant =		(wchar_t*)pUnicodeConstant;			// Un- Constanting aka removing 'C' from LPCWSTR just by casting.
	const wchar_t*  ConstantFromVariable =		pUnicodeVariable;           // Constanting aka adding 'C' in LPWSTR no casting needed. because variable are fathers of constants

	wprintf(L"\nThis String was Constant before Casting:: %s\nThis String was Variable before making it Constant:: %s\n",VariableFromConstant,ConstantFromVariable);

	printf("\n----------------------------\n # defining char from hardcoded strings \n----------------------------");
// define:: char* = LPSTR ,const char* = LPCSTR from "hard Coded String"

	char*		pSimpleAsciiVariableString		= "This is simpleAsciiString assigned to pSimpleAsciiVariableString from hardcoding"; // Notice there is no 'L';
	const char* pSimpleAsciiConstantString		= "This is simpleAsciiString assigned to pSimpleAsciiConstantString from hardcoding";
	LPSTR		pSimpleAsciiVar_shortenedName	= "LPSTR is nothing but char*, just shorted the name of Long Pointer to STRing. so we are doing nothing special here";
	LPCSTR		pSimpleAsciiConst_shortenedName = "LPCSTR is nothing but 'const char*', just shorted the name of Long Pointer to Constant STRing. nothing special.";

	printf("\n%s\n%s\n%s\n%s\n",pSimpleAsciiVariableString,pSimpleAsciiConstantString,pSimpleAsciiVar_shortenedName,pSimpleAsciiConst_shortenedName);

	printf("\n----------------------------\n # Converting Constant <--> Variable from Each Other \n----------------------------");

// Converting Constant to Variable and Variable to Constant.

	char*		pAsciiVariableFromConstant =	(char*)	pSimpleAsciiConstantString;
	const char* pAsciiConstantFromVariable =			pSimpleAsciiVariableString;

	printf("\nThis Was Constant before casting:: %s\nThis was Variable before assigning:: %s\n",pAsciiVariableFromConstant,pAsciiConstantFromVariable);
}
void std_string(){
	printf("--------------------------\n # Defining wstring and string from hard coded string and variables\n-----------------------------");

	std::string		stdAsciiString		=		"ascii std::string from hardcoding";
	std::wstring	stdUnicodeString	=	   L"Unicode std::wstring from hardcoding";

	// from std-string to wchar_t*/char*

	const char*		asciiString		= stdAsciiString	.c_str();
	const wchar_t*	unicodeString	= stdUnicodeString	.c_str();
	
	//From wchar_t*/char* to std-string

	std::string		stdAsciiString2		= asciiString;
	std::wstring	stdUnicodeString2	= unicodeString;

	//using std-string in Windows API's :: Method 1 :: by converting them to char*/wchar_t by .c_str()

	printf ( "\nPrinted Ascii String With printf	::%s",stdAsciiString2		.c_str());
	wprintf(L"\nPrinted Unicode String With wprintf ::%s",stdUnicodeString2		.c_str());
	
	//using std-string in Windows API's :: Method 2 :: by providing the stucture memeber's address that is holding the actual char*/wchar_t*, which is first member.
	
	printf(	 "\n directly using std-string in APIs like printf: %s", &stdAsciiString[0]);		// notice that variable is not pointer, so add pointer by '&', then provide first byte.
	wprintf(L"\n directly using std-string in APIs like printf: %s", &stdUnicodeString[0]);		// also notice the [0], which denotes first memeber of this struct.
}
void unicode_ascii_conversion(){
	printf("\n----------------------------\n # char to wchar_t conversion'\n----------------------------");
	char*		InAsciiString			=  "hello,I am AsciiString aka LPSTR, want to be converted into Unicode";
	wchar_t*	InUnicodeString			= L"hellow,I am UnicodeString aka LPWSTR, want to be converted into ascii string";

	char*		outAsciiFromUnicode;
	wchar_t*	outUnicodeFromAscii;


	//1. ascii(aka MultiByte) to unicode(WideCharacter)
		int neededSize = MultiByteToWideChar( CP_UTF8 , 0 , InAsciiString , -1, NULL , 0 );
		outUnicodeFromAscii = new wchar_t[neededSize];
		MultiByteToWideChar( CP_UTF8 , 0 , InAsciiString , -1, outUnicodeFromAscii , neededSize );
		
		wprintf(L"\nString,Converted From Ascii To Unicode: %s",outUnicodeFromAscii);
	
	//2. unicode(aka WideChar) to Ascii(MultiByte)
		int size_needed = WideCharToMultiByte(CP_UTF8, 0,InUnicodeString, (int)wcslen(InUnicodeString), NULL, 0, NULL, NULL);
		outAsciiFromUnicode = new char[size_needed+1]; outAsciiFromUnicode[size_needed] = '\0'; 
		WideCharToMultiByte(CP_UTF8, 0,InUnicodeString, (int)wcslen(InUnicodeString), outAsciiFromUnicode, size_needed, NULL, NULL);
		
		printf("\nString, Converted From Unicode to Ascii: %s",outAsciiFromUnicode);
}

void extra_info(){
	// if your are still don't belive that "char* family" == "LPSTR family" then read this-
	printf("\n----------------------------\n # char*/wchar_t* family and LPSTR family is same things with different names \n----------------------------");
	wchar_t*		unicodeString			= L"I am unicode String";
	const wchar_t*  unicodeConstantString	= L"I am constant Unicode String";
	char*			asciiString				=  "I am simple Ascii String";
	const char*		asciiConstantString		=  "I am simple constant Ascii string";

	LPWSTR	lpwszUnicodeString		= unicodeString;
	LPCWSTR lpwszUnicodeStringg		= unicodeConstantString;
	LPSTR	lpszAscii				= asciiString;
	LPCSTR	lpcszConstantAscii		= asciiConstantString;

	printf(		 "\n LPSTR:  %s \n LPCSTR:  %s",lpszAscii,			lpcszConstantAscii);
	wprintf(	L"\n LPWSTR: %s \n LPCWSTR: %s",lpwszUnicodeString,	lpwszUnicodeStringg);

}
void passByReferenceAndPointer(char *& asciiString, wchar_t *& unicodeString, std::string& stdAsciiString, std::wstring& stdUnicodeString, int& demoInt){
	printf	( "\n Passed Value to asciiString	  :: %s", asciiString			);		asciiString		=  "returned Value to asciiString      By Function";
	wprintf	(L"\n Passed Value to unicodeString   :: %s", unicodeString			);		unicodeString	= L"returned value to unicodeString    By Function";
	printf	( "\n Passed Value to stdAsciiString  :: %s", &stdAsciiString[0]	);		stdAsciiString	=  "returned value to stdAsciiString   By Function";
	wprintf	(L"\n Passed Value to stdUnicodeString:: %s", &stdUnicodeString[0]	);		stdUnicodeString= L"returned value to stdUnicodeString By Function";
	printf  ( "\n Passed Value to integer		  :: %d", demoInt				);		demoInt			= 54321;
}
void functionDemo(){
	printf("\n----------------------------\n # Custum Function Defining and Calling demo.\n----------------------------");
	//defining..
	char*			asciiString			=  "Hello, Im Simple Ascii String";
	wchar_t*		unicodeString		= L"Hellow, Im Unicode String";
	std::string		stdAsciiString		=  "Hello, Im Simple Ascii String, But from std::string";
	std::wstring	stdUnicodeString	= L"Hellow, Im Unicode String, form std::wstring";
	int				demoInt				=  12345;

	//passing to function , function will change their values.
	passByReferenceAndPointer(asciiString,unicodeString,stdAsciiString,stdUnicodeString,demoInt);

	//printing new values assigned by function.
	printf	( "\n Returned Value From Function In asciiString	  :: %s", asciiString			);
	wprintf	(L"\n Returned Value From Function In unicodeString   :: %s", unicodeString			);
	printf	( "\n Returned Value From Function In stdAsciiString  :: %s", &stdAsciiString[0]	);
	wprintf	(L"\n Returned Value From Function In stdUnicodeString:: %s", &stdUnicodeString[0]	);
	printf  ( "\n Returned Value From Function In integer		  :: %d", demoInt				);
}
int main(int argc, wchar_t* argv[])
{
	defineTests();
	std_string();
	unicode_ascii_conversion();
	extra_info();
	functionDemo();

	_getch();return 0;
}

