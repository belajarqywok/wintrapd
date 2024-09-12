/**
 * 
 *  RC4 (Ron's Code / Rivest's Cipher)
 * 
*/
#include <stdlib.h>

#include "ksa.h"
#include "prng.h"

int* RC4(char* key, int key_length, int plaintext_length)
{
    int* ksa_result  = KSA(key, key_length);

    int* prng_result = PRNG(ksa_result, plaintext_length);
 
    free(ksa_result);
    
    return prng_result;
}
