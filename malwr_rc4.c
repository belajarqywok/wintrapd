/**
 * 
 *  Main
 * 
*/
#include <stdio.h>
#include <stdlib.h>

#include "src/enc_dec.h"
#include "src/logging.h"

typedef unsigned char bool;

int main (int argc, char* argv[])
{
    /**
     * 
     *  Examples :
     *      main -f plain.txt -k secret123 -o cipher.txt encrypt
     *      main --file plain.txt --key secret123 --output cipher.txt encrypt
     * 
     *      main -f cipher.txt -k secret123 -o plain.txt decrypt
     *      main --file cipher.txt --key secret123 --output plain.txt decrypt
     * 
     *      main -d cipher.txt -k secret123 encrypt
     *      main --directory --key secret123 encrypt
     * 
     *      main -d /dirx -k secret123 decrypt
     *      main --directory /dirx --key secret123 decrypt
     * 
    */

    /**
     *  Plainfile And Cipherfile Option
     *  Option: [-f | --file]
    */   
    const bool file_opt = (  
        !strcmp(argv[1], "-f") ||
        !strcmp(argv[1], "--file")
    );

    /**
     *  Directory Option
     *  Option: [-d | --directory]
    */
    const bool directory_opt = (
        !strcmp(argv[1], "-d") ||
        !strcmp(argv[1], "--directory")
    );

    /**
     *  Key Option
     *  Option: [-k | --key]
    */
    const bool key_opt = (
        !strcmp(argv[3], "-k") ||
        !strcmp(argv[3], "--key")
    );

    /**
     *  Output File Option
     *  Option: [-o | --output]
    */
    const bool output_opt = (
        !strcmp(argv[5], "-o") ||
        !strcmp(argv[5], "--output")
    );

    /**
     *  Encrypt And Decrypt FIle Condition
     *  Option: [encrypt | decrypt]
    */
    if ((bool) file_opt && key_opt && output_opt) {
        if ((bool) !strcmp(argv[7], "encrypt")) encrypt(argv);
        
        else if ((bool) !strcmp(argv[7], "decrypt")) decrypt(argv);

    /**
     *  Encrypt And Decrypt Directory Condition
     *  Option: [encrypt | decrypt]
    */
    } else if ((bool) directory_opt && key_opt) {
        if ((bool) !strcmp(argv[5], "encrypt")) encrypt_dir(argv);
        
        else if ((bool) !strcmp(argv[5], "decrypt")) decrypt_dir(argv);

    } else help_log();

    return 0;    
}
