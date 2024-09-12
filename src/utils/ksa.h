/**
 * 
 *  KSA (Key Scheduling Algorithm)
 * 
*/
#include <stdlib.h>

#include "mod.h"

int* KSA(char* key, int key_length)
{
    int* S = (int*) malloc(sizeof(int) * MOD);

    for (int i = 0; i < MOD; i++) { S[i] = i; }

    int j = 0; 
    for (int i = 0; i < MOD; i++) {
        j = (j + S[i] + key[i % key_length]) % MOD;

        int temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    return S;
}
