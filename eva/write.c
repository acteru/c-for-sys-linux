#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * argc = argument counter
 * argv = argument vector
 */

int main(int argc, char **argv) {                               // int main method
  mode_t mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH;        // set permissions to rw-rw-r--
  ssize_t size;                                                 // function ssize_t with size param
  int filedec;                                                  // integer for file descriptor
  char *string;                                                 // char declaration
  umask(0);                                                     // set permissions for umask

  if(argc < 2) {                                                // check the second input
    fprintf(stderr, "Usage: %s filename file-input\n", *argv);  // int fprintf(FILE *stream, const char *format, ...)
    return EXIT_FAILURE;
  }
  if(argc < 3) {                                                // check the third input
    string = "there are no arguments\n"; 
  }
  else {
    string  = argv[2];                                          // save thrid input into char-var
  }
  size = strlen(string);                                        // get the stringlenght and save it in size
  filedec = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, mode); // string is added at the end of the file O_APPEND

  if(filedec == -1) {                                           // check if file is open
    perror("failure while opening the file");
    return EXIT_FAILURE; 
  }
  if(write(filedec, string, size) != size)                      // check if written
    perror("failure while writing the file");
    return EXIT_SUCCESS;
}
