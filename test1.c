#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 32

int main() {
    int fd;
    char buffer[BUFFER_SIZE]={};

    fd = open("/dev/hello",O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        return -1;
    }

    printf("Reading from buffer:\n");
  {
        ssize_t ret = read(fd, buffer, 2);
        
        printf("Read %zd bytes: %s\n", ret, buffer);
    }
    
    close(fd);
    return 0;
}