#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <libgen.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

#include "lexer.h"

#define CAPACITY 8192

void creat_filepath(char *filepath, char *dirname, char *filename) {
    sprintf(filepath, "%s/%s", dirname, filename);
}

bool file_ext_validate(char *filepath, const char *ext) {
    char *filename = basename(filepath);
    size_t filename_len = strlen(filename);
    size_t ext_len = strlen(ext);

    return filename_len > ext_len
        && !strcasecmp(&filename[filename_len - ext_len], ext);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("Usage: cflow <dirname>\n");
        return EXIT_FAILURE;
    }

    DIR *dir = opendir(argv[1]);
    if (!dir) {
        perror("diropen");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (file_ext_validate(entry->d_name, ".h") || file_ext_validate(entry->d_name, ".c")) {
            char filepath[PATH_MAX];
            creat_filepath(filepath, argv[1], entry->d_name);
            FILE *file = fopen(filepath, "r");
            if (!file) {
                perror("fopen");
                return EXIT_FAILURE;
            }
            lexer(file);
            fclose(file);
        }
    }

    closedir(dir);

    return EXIT_SUCCESS;
}