#include <stdio.h>
int main(void) {
    unsigned x = 0xDEADBEEF;
    unsigned char *p = (unsigned char *)&x;
    printf("%X", *p);
    return 0;
}