#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buffer[80];
    char msg[] = "Gary Clarck when my train";
    fd = open("test.txt"), 0_RDWR);
    printf("fd = %d", fd);
    if(fd != -1)
    {
        printf("\n text opende with read write access\n");
        write(fd, msg, sizeof(msg));
        lseek(fd,0,SEEK_SET);
        read(fd, buffer, sizeof(msg));
        printf("\n %s tktbat fel file \n, buffer");
        close (fd);
    }
  return 0;
}