// LooderTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#pragma warning(disable:4996)


int wmain(int argc,TCHAR *argv[])
{
    if (argc != 2)
    {
        printf(("\nUsage: %s <dir name>\n"), argv[0]);
    }
    WIN32_FIND_DATA ffd;
    LARGE_INTEGER filesize;
    TCHAR szDir[MAX_PATH];
    size_t length_of_arg;
    HANDLE hFind;
    DWORD dwError = 0;
    WIN32_FIND_DATA FindData;
    std::vector<std::wstring> pathList;


        cout << "FindFirstFile/FindNextFile demo.\n" << endl;

        // Find the first file
        TCHAR dataPath[260];
        wcscpy(dataPath, argv[1]);
        hFind = FindFirstFile(dataPath, &FindData);
        std::wstring ws(FindData.cFileName);
        wcout << ws << endl;
        // Look for more

        while (FindNextFile(hFind, &FindData))
        {
            cout << FindData.cFileName << endl;
            pathList.push_back(std::wstring(FindData.cFileName));
        }

        // Close the file handle

        FindClose(hFind);
        std::copy(pathList.begin(),pathList.end(),std::ostream_iterator<std::wstring, wchar_t>(std::wcout, L"\n"));
        return 0;
    }
