/* create a new file with permissions and dont if it exists on linux*/
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {                           // int main method
  mode_t mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH;    // set permissions to rw-rw-r--
  const char *new_file;                                     // new file var
  int filedec;                                              // integer for file descriptor
  umask(0);                                                 // set permissions for umask

  if(argv[1] == NULL) {
    fprintf(stderr, "Usage: %s file to create\n", *argv);   // define the usage output
    return EXIT_FAILURE;
  }
  new_file = argv[1];                                       // catch the firt argument (filename)

  filedec = open(new_file, O_WRONLY|O_EXCL|O_CREAT, mode);  // file descriptor (new_file open-method, modevar)

  if(filedec == -1) {                                       // deal with opening failure
    perror("failure while opening the file ");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
