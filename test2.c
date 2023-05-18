#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 32
#define MESSAGE "helloworld"

int main() {
    int fd;
char s[32]={};
char a[32]={};
s[0]='a';
s[1]='b';
s[2]='c';
    fd = open("/dev/hello", O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        return -1;
    }
  
    printf("Writing to buffer: %s\n", MESSAGE);
    ssize_t ret = write(fd, s,3);
    if (ret < 0) {
        perror("Write error");
    } else {
        printf("Written %zd bytes%ld\n", ret,sizeof(MESSAGE)-1); 
    
    }
  
  
   close(fd);
   printf("%s\n",a);
    return 0;
}