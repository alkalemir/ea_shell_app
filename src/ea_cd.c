#include <unistd.h>
#include <stdio.h>
#include "../include/ea_defines.h"

void proc_cd(void)
{
    if (ea_args_idx == 1) {
        chdir("/");
    } else if (ea_args_idx == 2) {
        if (ea_args[1][0] == '/') {
            chdir(ea_args[1]);
        } else {
            char buf[MAX_PWD_SIZE];
            sprintf(buf, "%s/%s", ea_pwd, ea_args[1]);
            chdir(buf);
        }
    }
}