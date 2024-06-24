#include "kernel/types.h"
#include "user/user.h"

int main(void)
{
    char *str = hello();
    printf("%s\n", str);
    exit(0);
}