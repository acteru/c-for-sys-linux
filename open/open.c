/* create a new file with permissions and don't if it exists on linux*/
#include <sys/stat.h>  // needed for mode_t permissions
#include <sys/types.h> // ssize_t used for a count for bytes or an error indication
#include <fcntl.h>     // file control options like O_CREAT oder O_SYNC
#include <stdio.h>     // input output options
#include <stdlib.h>    // converts file types
#include <unistd.h>    // system call wrapper function (read, write, close)

int main(int argc, char **argv) {                           // int main method
  mode_t mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH;    // set permissions to rw-rw-r--
  const char *new_file;                                     // new file var
  int filedec;                                              // integer for file descriptor
  umask(0);                                                 // set permissions for umask

  if(argv[1] == NULL) {
    fprintf(stderr, "Usage: %s filename\n", *argv);   // define the usage output
    return EXIT_FAILURE;
  }
  new_file = argv[1];                                       // catch the first argument (filename)

  filedec = open(new_file, O_WRONLY|O_EXCL|O_CREAT, mode);  // file descriptor (new_file open-method, mode var)

  if(filedec == -1) {                                       // deal with opening failure
    perror("failure while opening the file ");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
