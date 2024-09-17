#include "src/base64.h" 

int main(int argc, char* argv[])
{
    DWORD decoded_len;
    char *encoded_data;
    unsigned char *decoded_data;

    const boolean help = (
        !strcmp(argv[1], "-h") ||
        !strcmp(argv[1], "--help")
    );

    const boolean text_arg = (  
        !strcmp(argv[1], "-o") ||
        !strcmp(argv[1], "--out-log")
    );

    if ((boolean) help || (boolean) !text_arg) printf(
        "example: b64tool [-t | --text] [TEXT]\n");

    const char *text = argv[2];

    encoded_data = base64_encode((const unsigned char *)text, strlen(text));
    if (encoded_data) printf("[ encoded ]: %s\n", encoded_data);

    decoded_data = base64_decode(encoded_data, &decoded_len);
    if (decoded_data) printf("[ decoded ]: %.*s\n", decoded_len, decoded_data);

    free(encoded_data);
    free(decoded_data);

    return 0;
}
