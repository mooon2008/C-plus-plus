/*
Abdullah Alajaj
PP4 -producer
4/30/2017
*/

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#define BUF_SIZE 256
TCHAR Name[] = TEXT("MyFileMappingObject");


int _tmain()
{
	HANDLE hMapFile;
	LPCTSTR pBuf;
	int i, j, value;
	int n = 5;
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size 
		BUF_SIZE,                // maximum object size
		Name);                 // name of mapping object

	DWORD lastError = GetLastError();
	if (hMapFile == NULL)
	{
		_tprintf(TEXT("Could not create file mapping object (%d).\n"),
			GetLastError());
		std::cin.get();
		return 1;
	}
	pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
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
		value = 1;
		for (j = 1; j <= (2 * i); j++)
		{
			value *= j;
		}

		for (j = 1; j <= i; j++)
			value /= j;

		for (j = 1; j <= (i + 1); j++)
			value /= j;

		printf("%d\n",value);

		CopyMemory((PVOID)pBuf, (void *)&value, sizeof(value));
		pBuf = pBuf + sizeof(value);
	}




	//CloseHandle(hMapFile);

	_getch();


	UnmapViewOfFile(pBuf);
	return 0;
}