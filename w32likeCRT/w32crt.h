
#if defined(_WIN32) && !defined(WIN32CRT_MEAN_AND_MEAN)
#include <Windows.h>
#endif
#ifndef _MINWINDEF_
#define _MINWINDEF_
#ifndef BASETYPES
#define BASETYPES
	typedef unsigned long ULONG;
	typedef ULONG* PULONG;
	typedef unsigned short USHORT;
	typedef USHORT* PUSHORT;
	typedef unsigned char UCHAR;
	typedef UCHAR* PUCHAR;
	typedef char* PSZ;
	typedef void* HANDLE;
#endif  /* !BASETYPES */
#define MAX_PATH          260
#define far
#define near
#define FAR                 far
#define NEAR                near
#ifndef CONST
#define CONST               const
#endif
	typedef unsigned long       DWORD;
	typedef int                 BOOL;
	typedef unsigned char       BYTE;
	typedef unsigned short      WORD;
	typedef float               FLOAT;
	typedef FLOAT* PFLOAT;
	typedef BOOL near* PBOOL;
	typedef BOOL far* LPBOOL;
	typedef BYTE near* PBYTE;
	typedef BYTE far* LPBYTE;
	typedef int near* PINT;
	typedef int far* LPINT;
	typedef WORD near* PWORD;
	typedef WORD far* LPWORD;
	typedef long far* LPLONG;
	typedef DWORD near* PDWORD;
	typedef DWORD far* LPDWORD;
	typedef void far* LPVOID;
	typedef CONST void far* LPCVOID;
	typedef int                 INT;
	typedef unsigned int        UINT;
	typedef unsigned int* PUINT;
	typedef wchar_t WCHAR;
	typedef char CHAR;
	typedef WCHAR *PWCHAR;
	typedef CHAR *PCHAR;
	typedef CONST CHAR *LPCSTR;
	typedef CONST WCHAR* LPCWSTR;
#define VOID void
#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))
	typedef HANDLE NEAR* SPHANDLE;
	typedef HANDLE FAR* LPHANDLE;
	typedef HANDLE              HGLOBAL;
	typedef HANDLE              HLOCAL;
	typedef HANDLE              GLOBALHANDLE;
	typedef HANDLE              LOCALHANDLE;
#endif

#ifndef _INC_WIN32CRT
#define _INC_WIN32CRT
#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once//微软这家伙加了头文件保护符还加这个（笑）
#endif
#include <stdio.h>
#include <errno.h>


typedef unsigned int UINT;
typedef void *_____HANDLE;
typedef _____HANDLE _W32_LIKE_HANDLE;
typedef _W32_LIKE_HANDLE WLPVOID,*WLPHANDLE,
** WLPPHANDLE,*** WLPPPHANDLE,
********** WLPPPPPPPPPPHANDLE;
typedef PWCHAR *PPWCH;
typedef PCHAR *PPCH;

#define _W32_CRTAPI __stdcall

#define _Return_MaybeInt_
#define _Return_MaybeReturn_
#define _Return_MaybeVoid_


_Return_MaybeVoid_
VOID
_W32_CRTAPI
DoNothing(
VOID
)
{
	;//do nothing
}

_Return_MaybeInt_
INT
_W32_CRTAPI
GetLastErrno(
VOID
)
{
	return errno;
}

_Return_MaybeVoid_
VOID
_W32_CRTAPI
SetLastErrno(
	INT 
	dErrCode)
{
	errno = dErrCode;
}

_Return_MaybeReturn_
LPCSTR
_W32_CRTAPI
W32LikeCRTDoNothingAndReturnHelloWordStringA(
VOID
)
{
	return "Hello Word";
}


LPCWSTR
_W32_CRTAPI
W32LikeCRTDoNothingAndReturnHelloWordStringW(
VOID
)
{
	DoNothing();
	return L"Hello Word";
}


_Return_MaybeReturn_
LPVOID
_W32_CRTAPI
MemoryAlloc(
DWORD far dwMemoryAllocSize
)
{
	return malloc(dwMemoryAllocSize);
}

_Return_MaybeReturn_
DWORD
_W32_CRTAPI
MultiByteToMultiByte(
UINT udCodePage,
LPCSTR lpMultiByteStr,
DWORD dwInputMultiByteStrLength,
LPSTR *lpMultiByteStrOut,
LPDWORD lpOutStrLength,
DWORD dwThisArgIsUnused
)
{
	if (lpOutStrLength == NULL)
	{
		SetLastErrno(EINVAL);
		return dwInputMultiByteStrLength;
	}
	for (DWORD i = 0; i < dwInputMultiByteStrLength; i++)
	{
		(*lpMultiByteStrOut)[i] = lpMultiByteStr[i];
	}
	(*lpMultiByteStrOut)[dwInputMultiByteStrLength] = '\0';
	return 0;
}

_Return_MaybeReturn_
DWORD
_W32_CRTAPI
WideCharToWideChar(
UINT udCodePage,
LPCWSTR lpWideCharStr,
DWORD dwInputWideCharStrLength,
LPWSTR* lpWideCharStrOut,
LPDWORD lpOutStrLength,
DWORD dwThisArgIsUnused
)
{
	if (lpOutStrLength == NULL)
	{
		SetLastErrno(EINVAL);
		return dwInputWideCharStrLength;
	}
	for (DWORD i = 0; i < dwInputWideCharStrLength; i++)
	{
		(*lpWideCharStrOut)[i] = lpWideCharStr[i];
	}
	(*lpWideCharStrOut)[dwInputWideCharStrLength] = L'\0';
	return 0;
}


_Return_MaybeInt_
INT
_W32_CRTAPI
PrintSomeTextToStdOutA(
LPCSTR lpOutputStr
)
{
	return printf(lpOutputStr);
}


_Return_MaybeInt_
INT
_W32_CRTAPI
PrintSomeTextToStdOutW(
	LPCWSTR lpOutputStr
)
{
	return wprintf(lpOutputStr);
}

#ifdef _MSC_VER
#pragma warning(disable:6269)
#endif

_Return_MaybeVoid_
VOID
_W32_CRTAPI
CauseCNullptrException(
VOID
)
{
	*(LPDWORD)NULL;
}

#define W32LikeCRTProgamMainA main

_Return_MaybeReturn_
DWORD
_W32_CRTAPI
GetStringLengthA(
LPCSTR lpStr
)
{
	return (DWORD)strlen(lpStr);
}

_Return_MaybeReturn_
DWORD
_W32_CRTAPI
GetStringLengthW(
	LPCWSTR lpStr
)
{
	return (DWORD)wcslen(lpStr);
}

_Return_MaybeVoid_
VOID
_W32_CRTAPI
FreeAllocedMemory(
LPVOID lpMemoryPtr
)
{
	free(lpMemoryPtr);
}

#ifndef CP_ACP
#define CP_ACP 0
#endif
#ifndef CP_UTF8
#define CP_UTF8 65001
#endif

#endif
