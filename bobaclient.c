#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helpOutput() {
        printf("%s\n", "");
        printf("%s\n", "A simple and lightweight client for bobashare.");
        printf("%s\n", "All credits to bobashare at https://bbaovanc.com/");
        printf("%s\n", "");
        printf("%s\n", "All commands will be ran with the structure of 'bobaclient [flag] [flag] [flag] filename.xyz'");
        printf("%s\n", "The first flag here is always required, the second flag is optional for things such as randomized filename.");
        printf("%s\n", "The maximum amount of flags possible is three.");
        printf("%s\n", "");
        printf("%s\n", "Valid Flags:");
        printf("%s\n", "");
        printf("%s\n", "- 'h' to display this help message.");
        printf("%s\n", "- 'u' to upload the specified file to bobashare and return the URL.");
        printf("%s\n", "- 'u r' to upload the specified file with a randomized name to bobashare and return the URL.");
        printf("%s\n", "- 'u z' in the parent directory of the one you would like to upload to upload all files in the specified directory as a .zip file to bobashare and return the URL.");
        printf("%s\n", "- 'u z r' directorytoupload/' in the parent directory of the one you would like to upload to upload all files in the specified directory as a .zip file with a randomized name to bobashare and return the URL.");
        printf("%s\n", "");
        printf("%s\n", "Example command: bobaclient u filename.xyz");
        printf("%s\n", "Example command: bobaclient u z filename.xyz");       
        printf("%s\n", "");
        exit(0);
}

int main(int argc, char **argv) {

    if (argc < 2 || argc > 6) {
        helpOutput();
    }

    char arg1 = *argv[1];

    switch (arg1) {
        case 'u': {
            if (argc < 4) {

                char uploadCommand[512];
                char filename[512];

                strncpy(filename, argv[2], sizeof(filename));
                snprintf(uploadCommand, sizeof(uploadCommand), "curl -T %s https://share.boba.best/upload/", filename);
                printf("%s\n", "Uploading to bobashare...");
                system(uploadCommand);

            } else if (argc < 5) {

                if (*argv[2] == 'r') {
                    char uploadCommand[512];
                    char filename[512];

                    strncpy(filename, argv[3], sizeof(filename));
                    snprintf(uploadCommand, sizeof(uploadCommand), "curl -H \"Linx-randomize: yes\" -T %s https://share.boba.best/upload/", filename);
                    printf("%s\n", "Uploading to bobashare with randomized filename...");
                    system(uploadCommand);

                } else if (*argv[2] == 'z') {

                    char uploadCommand[512];
                    char filename[512] = "filename.zip";
                    char directoryName[512];

                    strncpy(directoryName, argv[3], sizeof(directoryName));
                    snprintf(uploadCommand, sizeof(uploadCommand), "zip -r filename.zip %s && curl -T %s https://share.boba.best/upload/", directoryName, filename);
                    printf("%s\n", "Uploading directory as zip...");
                    system(uploadCommand);
                    snprintf(uploadCommand, sizeof(uploadCommand), "rm %s", filename);
                    system(uploadCommand);

                }
            } else if (argc < 6 && *argv[2] == 'z' && *argv[3] == 'r') {
                
                char uploadCommand[512];
                char filename[512] = "filename.zip";
                char directoryName[512];

                strncpy(directoryName, argv[4], sizeof(directoryName));
                snprintf(uploadCommand, sizeof(uploadCommand), "zip -r filename.zip %s && curl -H \"Linx-randomize:yes\" -T %s https://share.boba.best/upload/", directoryName, filename);
                printf("%s\n", "Uploading directory as zip with randomized filename...");
                system(uploadCommand);
                snprintf(uploadCommand, sizeof(uploadCommand), "rm %s", filename);
                system(uploadCommand);

            } else {
                helpOutput();
            }
            break;
        }
        case 'h': {
            helpOutput();
            break;
        }
    }
    return 0;
}