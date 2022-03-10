#include <unistd.h>
#include <stdio.h>
#include "../include/ea_defines.h"

void proc_pwd(void)
{
    getcwd(ea_pwd, MAX_PWD_SIZE);
    printf("%s\n", ea_pwd);
}