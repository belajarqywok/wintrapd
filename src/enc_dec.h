/**
 * 
 * 
 *  Encryption
 *  
 * 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#include "logic.h"
#include "file_io.h"

/**
 * 
 *  Encryption Method
 * 
*/
void encrypt (char* argv[])
{
    char* plainfile = read_plainfile(argv[2]);
    int plainfile_length = strlen(plainfile);

    char* key = argv[4];
    int key_length = strlen(key);

    char* result_file = argv[6];

    int* logic_xor = enc_logic(
        key,
        key_length,

        plainfile,
        plainfile_length
    );

    char hex[] = "hex";

    write_file(
        logic_xor, plainfile_length,
        result_file, *hex
    );

    free(logic_xor);
    free(plainfile);

    printf("Status: Encryption Success!!!.\n\n");
}


/**
 * 
 *  Encryption Directory Method
 * 
*/
void encrypt_dir (char* argv[])
{
    struct list_file_struct fileList = list_files(argv[2]);

    for (int i = 0; i < fileList.count; ++i) {
        char* plainfile = read_plainfile(fileList.files[i]);
        int plainfile_length = strlen(plainfile);

        char* key = argv[4];
        int key_length = strlen(key);

        char* result_file = fileList.files[i];

        int* logic_xor = enc_logic(
            key,
            key_length,

            plainfile,
            plainfile_length
        );

        char hex[] = "hex";

        write_file(
            logic_xor, plainfile_length,
            result_file, *hex
        );

        free(logic_xor);
        free(plainfile);

        printf("Status: Encryption Success!!!.\n\n");
        free(fileList.files[i]);
    }
}

/**
 * 
 *  Decryption File Method
 * 
*/
void decrypt (char* argv[])
{
    struct read_cipherfile_struct cipherfile = read_cipherfile(argv[2]);

    char *key = argv[4];
    int key_length = strlen(key);

    char *result_file = argv[6];

    int* logic_xor = dec_logic(
        key,
        key_length,

        cipherfile.hexs,
        cipherfile.hexs_length
    );

    char text[] = "text";

    write_file(
        logic_xor, cipherfile.hexs_length,
        result_file, *text
    );

    free(logic_xor);

    printf("Status: Decryption Success!!!.\n\n");    
}

/**
 * 
 *  Decryption Directory Method
 * 
*/
void decrypt_dir (char* argv[])
{
    struct list_file_struct fileList = list_files(argv[2]);

    for (int i = 0; i < fileList.count; ++i) {
        struct read_cipherfile_struct cipherfile = read_cipherfile(fileList.files[i]);

        char *key = argv[4];
        int key_length = strlen(key);

        char *result_file = fileList.files[i];

        int* logic_xor = dec_logic(
            key,
            key_length,

            cipherfile.hexs,
            cipherfile.hexs_length
        );

        char text[] = "text";

        write_file(
            logic_xor, cipherfile.hexs_length,
            result_file, *text
        );

        free(logic_xor);

        printf("Status: Decryption Success!!!.\n\n");  
        free(fileList.files[i]);
    }
}
