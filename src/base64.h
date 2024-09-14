#include <windows.h>
#include <stdio.h>

// B64 encoding
char *base64_encode(const unsigned char *data, DWORD data_len)
{
    DWORD encoded_len = 0;
    char *encoded_data = NULL;

    if (!CryptBinaryToStringA(data, data_len, CRYPT_STRING_BASE64 | CRYPT_STRING_NOCRLF, NULL, &encoded_len)) 
    {
        printf("Error getting encoded length: %lu\n", GetLastError());
        return NULL;
    }

    encoded_data = (char *)malloc(encoded_len * sizeof(char));
    if (!encoded_data)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    if (!CryptBinaryToStringA(data, data_len, CRYPT_STRING_BASE64 | CRYPT_STRING_NOCRLF, encoded_data, &encoded_len))
    {
        printf("Error encoding data: %lu\n", GetLastError());
        free(encoded_data);
        return NULL;
    }

    return encoded_data;
}

// B64 decoding
unsigned char *base64_decode(const char *encoded_data, DWORD *decoded_len)
{
    unsigned char *decoded_data = NULL;

    if (!CryptStringToBinaryA(encoded_data, 0, CRYPT_STRING_BASE64, NULL, decoded_len, NULL, NULL))
    {
        printf("Error getting decoded length: %lu\n", GetLastError());
        return NULL;
    }

    decoded_data = (unsigned char *)malloc(*decoded_len);
    if (!decoded_data)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    if (!CryptStringToBinaryA(encoded_data, 0, CRYPT_STRING_BASE64, decoded_data, decoded_len, NULL, NULL))
    {
        printf("Error decoding data: %lu\n", GetLastError());
        free(decoded_data);
        return NULL;
    }

    return decoded_data;
}