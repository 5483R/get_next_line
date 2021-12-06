#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int i = open ("test.txt", O_RDWR);
    char *p;
    int f;
   read(i, p, 30);
    printf("%s",p);
}