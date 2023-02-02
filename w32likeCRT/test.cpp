#include "w32crt.h"

_Return_MaybeInt_
INT W32LikeCRTProgamMainA(
INT FAR dMainArgCount,
LPCSTR NEAR *lpArgsStr
)
{
	DoNothing();//do nothing
	PrintSomeTextToStdOutA(W32LikeCRTDoNothingAndReturnHelloWordStringA());
	LPSTR sHelloWorldStrBuffer=(LPSTR)MemoryAlloc(
		GetStringLengthA(W32LikeCRTDoNothingAndReturnHelloWordStringA()) + sizeof(CHAR)
	);
	PrintSomeTextToStdOutA("\n");
	DWORD dwHelloWorldStrBufferLength;
	MultiByteToMultiByte(CP_ACP,
		W32LikeCRTDoNothingAndReturnHelloWordStringA(),
		GetStringLengthA(W32LikeCRTDoNothingAndReturnHelloWordStringA()),
		&sHelloWorldStrBuffer,
		&dwHelloWorldStrBufferLength,
		0);
	PrintSomeTextToStdOutA(sHelloWorldStrBuffer);
	PrintSomeTextToStdOutA("\n");
	FreeAllocedMemory(sHelloWorldStrBuffer);
}
