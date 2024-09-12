/**
 * 
 *  Logging
 * 
*/

#include <stdio.h>
#include <string.h>


void help_log()
{
    printf("stream cipher tool\n");
    printf("Follow @otw.mastah & @qywok_exploiter_357\n\n");
    printf("Usage :\n");
    printf("  [ Encryption ]\n");
    printf("  main -f <SECRET FILE> -k <PRIVATE KEY> -o <OUTPUT FILE> encrypt\n");
    printf("  main --file <SECRET FILE> --key <PRIVATE KEY> --output <OUTPUT FILE> encrypt\n\n");
    printf("  [ Decryption ]\n");
    printf("  main -f <CIPHER FILE> -k <PRIVATE KEY> -o <OUTPUT FILE> decrypt\n");
    printf("  main --file <CIPHER FILE> --key <PRIVATE KEY> --output <OUTPUT FILE> decrypt\n\n");
    printf("Options :\n");
    printf("  [    -f    |  --file   ]   secret file or cipher file (example: -f your_file | --file your_file)\n");
    printf("  [    -k    |  --key    ]   private key (example: -k secret | --key secret)\n");
    printf("  [    -o    |  --output ]   secret file or cipher file (example: -o out_file | --output out_file)\n");
    printf("  [  encrypt |  decrypt  ]   secret file or cipher file (example: encrypt | decrypt)\n\n");
}