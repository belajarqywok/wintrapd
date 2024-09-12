/**
 * 
 *  PRNG (Pseudorandom Number Generator)
 * 
*/
#include <stdlib.h>

#include "mod.h"

int* PRNG(int* ksa_result, int plaintext_length)
{
    int j = 0;
    int x = 0;

    int* K = (int*) malloc(sizeof(int) * plaintext_length);

    for (int i = 0; i < plaintext_length; i++) { 
        x = (x + 1) % MOD;
        j = (j + ksa_result[x]) % MOD;

        int temp = ksa_result[x];
        ksa_result[x] = ksa_result[j];
        ksa_result[j] = temp;

        K[i] = ksa_result[(ksa_result[x] + ksa_result[j]) % MOD];
    }

    return K;
}
