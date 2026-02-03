#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main() {
    char sourceFileName[256];
    char destinationFileName[256];
    int sourceFile, destinationFile;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    
    printf("Enter the source file name: ");
    scanf("%255s", sourceFileName);
    printf("Enter the destination file name: ");
    scanf("%255s", destinationFileName);
    
    sourceFile = open(sourceFileName, O_RDONLY);
    
    destinationFile = open(destinationFileName, O_WRONLY | O_CREAT | O_EXCL, 0666);
    

    // Copy data from source to destination
    while ((bytes_read = read(sourceFile, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(destinationFile, buffer, bytes_read);
    }

    // Close files
    close(sourceFile);
    close(destinationFile);

    printf("File copied successfully!\n");
    return 0;
}

