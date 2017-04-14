// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConsoleApplication1.h"


#include <windows.h>
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

DWORD WINAPI myThread(LPVOID lpParameter)
{
	unsigned int& myCounter = *((unsigned int*)lpParameter);
	while (myCounter < 0xFFFFFFFF) ++myCounter;
	return 0;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.


			unsigned int myCounter = 0;
			DWORD myThreadID;
					
			HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);

			char myChar = ' ';
			while (myChar != 'q') {
				cout << myCounter << endl;
				myChar = getchar();
			}
			
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}


