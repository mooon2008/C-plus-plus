/*
Abdullah Alajaj
PP4 -consumer
4/30/2017
*/

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR Name[] = TEXT("MyFileMappingObject");

int _tmain()
{
	HANDLE hMapFile;
	LPCTSTR pBuf;
	int i, value;
	int n = 5;
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,   // read/write access
		0,
		BUF_SIZE,
		Name);               // name of mapping object
	DWORD lastError = GetLastError();
	if (hMapFile == NULL)
	{
		_tprintf(TEXT("Could not open file mapping object (%d).\n"),
			GetLastError());
		return 1;
	}

	pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
		FILE_MAP_ALL_ACCESS,  // read/write permission
		0,
		0,
		BUF_SIZE);

	if (pBuf == NULL)
	{
		_tprintf(TEXT("Could not map view of file (%d).\n"),
			GetLastError());

		CloseHandle(hMapFile);

		
		return 1;
	}

	for (i = 1; i <= n; i++)
	{


		CopyMemory((void *)&value, pBuf, sizeof(value));
		pBuf = pBuf + sizeof(value);

		printf("%d\n", value);

	}

	
	system("pause");

	UnmapViewOfFile(pBuf);

	CloseHandle(hMapFile);

	
	return 0;
}