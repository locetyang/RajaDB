
#if !defined(AFX_AGENTSERVER_H__F4B2DCF8_D77A_426D_8C68_DE978C3113E8__INCLUDED_)
#define AFX_AGENTSERVER_H__F4B2DCF8_D77A_426D_8C68_DE978C3113E8__INCLUDED_
//dbdeamon setting for win10
#ifndef WINVER
#define _WIN32_WINNT 0x0A00
#endif
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000




#pragma warning(disable: 4996)

#include <afx.h>
//#include <windows.h>
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <ole2.h>
#include <initguid.h>

//Libraries
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "../Library/HSEL.lib")

#if !defined(_DLLEXPORT_)

// If _DLLEXPORT_ is NOT defined then the default is to import.
#if defined(__cplusplus)
#define DLLENTRY extern "C" __declspec(dllimport)
#else
#define DLLENTRY extern __declspec(dllimport)
#endif
#define STDENTRY DLLENTRY HRESULT WINAPI
#define STDENTRY_(type) DLLENTRY type WINAPI

// Here is the list of server APIs offered by the DLL (using the
// appropriate entry API declaration macros just #defined above).

//STDENTRY DllRegisterServer(void);

//STDENTRY DllUnregisterServer(void);

#else  // _DLLEXPORT_

// Else if _DLLEXPORT_ is indeed defined then we've been told to export.
#if defined(__cplusplus)
#define DLLENTRY extern "C" __declspec(dllexport)
#else
#define DLLENTRY __declspec(dllexport)
#endif
#define STDENTRY DLLENTRY HRESULT WINAPI
#define STDENTRY_(type) DLLENTRY type WINAPI
#endif // _DLLEXPORT_

#pragma warning(disable:4786)
#include <map>
#include <vector>
using namespace std;

#define GUID_SIZE 128
#define MAX_STRING_LENGTH 256
typedef void**	PPVOID;

#define BUFF_BUG_CHECKS // Finito 26/08/07 enable buff bug checking. Checks if tiem difference 
						// is 12 hours an takes  away 12 hours so that server time is kept at the proper time

#define MY_STRING	"Daryl is childish"//"Thank you all" // CSD-040120-
#include "LocalizingMgr.h"//021007 lsw
#define COMMENT /##/

#endif // !defined(AFX_AGENTSERVER_H__F4B2DCF8_D77A_426D_8C68_DE978C3113E8__INCLUDED_)
