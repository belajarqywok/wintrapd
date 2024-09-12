/**
 * 
 * 
 *  File I/O
 * 
 * 
*/
#include <stdio.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_PATH_LENGTH 1024

/*
 *  Open File
*/
FILE* _fileops(char* filename, char* permission)
{
    FILE* file;
    file = fopen(filename, permission);

    return file;
}

/**
 * 
 *  Write File Method
 * 
*/
void write_file(int* result_text, int length_result_text, char* output_file, char type)
{
    FILE* file = _fileops(output_file, "w");

    char hex[] = "hex";
    char text[] = "text";

    if (type == *hex) {
        for (int i = 0; i < length_result_text; i++) {
            fprintf(file, "%x ", result_text[i]);
        }

    } else if (type == *text) {
        for (int i = 0; i < length_result_text; i++) {
            fprintf(file, "%c", result_text[i]);
        } 
    }

    fclose(file);
}

/**
 * 
 *  Read Plainfile Method
 * 
*/
char* read_plainfile(char* input_file)
{
    char* buffer;
    long file_size;
    size_t result;

    FILE* file = _fileops(input_file, "r");
    fseek(file, 0, SEEK_END);  

    file_size = ftell(file); 
    rewind(file);

    buffer = (char*) malloc(file_size * sizeof(char));  
    result = fread(buffer, 1, file_size, file);

    fclose(file);

    return buffer;
}

/**
 * 
 *  Read Hexfile Method
 * 
*/
struct read_cipherfile_struct
{
    int* hexs;
    int hexs_length;
};

struct read_cipherfile_struct read_cipherfile(char* input_file)
{
    char hex_char;
    char hex_char_next;

    long file_size;

    FILE* file = _fileops(input_file, "r");

    fseek(file, 0, SEEK_END);  
    file_size = ftell(file); 

    rewind(file);

    struct read_cipherfile_struct* HX;
    HX = (struct read_cipherfile_struct*) 
        malloc(sizeof(struct read_cipherfile_struct));

    int F_HEX_i = 0;
    int* F_HEX = (int*) malloc(sizeof(int) * file_size);

    while(1) { 
        hex_char = fgetc(file);

        char hex_char_allo[2] = {hex_char, '\0'}; 
        char forbidden_char[] = " ";

        if(hex_char != *forbidden_char && hex_char != EOF) {  
            char hexstring[] = "0x";
            hex_char_next = fgetc(file);

            if(hex_char_next != *forbidden_char && hex_char_next != EOF) {
                char hex_char_next_allo[2] = {hex_char_next, '\0'};

                strcat(hexstring, hex_char_allo);
                strcat(hexstring, hex_char_next_allo);

            } else strcat(hexstring, hex_char_allo);
            
            int hexnumber = (int) strtol(hexstring, NULL, 0);

            F_HEX[F_HEX_i] = hexnumber;
            F_HEX_i += 1;

        } else if (hex_char == EOF) break;

        else continue;
    }

    fclose(file); 
    HX -> hexs = F_HEX;
    HX -> hexs_length = F_HEX_i;

    return *HX;
}


/**
 * 
 *  Read Directory FIles Method
 * 
*/
struct list_file_struct {
    char* files[MAX_FILES];
    int count;
};

struct list_file_struct list_files(const char *path) {
    struct list_file_struct fileList;
    fileList.count = 0;

    DIR *dp = opendir(path);
    if (dp == NULL) {
        perror("opendir");
        fileList.count = -1;
        return fileList;
    }

    struct dirent *entry;
    while ((entry = readdir(dp))) {
        char fullPath[MAX_PATH_LENGTH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        struct stat path_stat;
        stat(fullPath, &path_stat);

        if (S_ISDIR(path_stat.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            fileList.files[fileList.count] = strdup(fullPath);
            fileList.count++;

            struct list_file_struct subDirList = list_files(fullPath);
            for (int i = 0; i < subDirList.count; ++i) {
                fileList.files[fileList.count] = strdup(subDirList.files[i]);
                fileList.count++;
            }
        } else {
            fileList.files[fileList.count] = strdup(fullPath);
            fileList.count++;
        }

        if (fileList.count >= MAX_FILES) {
            fprintf(stderr, "Too many files, increase MAX_FILES\n");
            break;
        }
    }

    closedir(dp);
    return fileList;
}
