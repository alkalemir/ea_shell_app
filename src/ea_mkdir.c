#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include "../include/ea_defines.h"

void proc_mkdir(void)
{
    int retval; 

    if (ea_args_idx == 1) {
        printf("At least you should specify 2 parameteres.\n");
        return;
    } else {
        for (int i = 1; i < ea_args_idx; ++i) {
            retval = mkdir(ea_args[i], S_IRUSR|S_IWUSR|S_IXUSR|
                            S_IRGRP|S_IXGRP|
                            S_IROTH| S_IXOTH);

            if (retval != 0)
                printf("mkdir : %s\n", strerror(errno));
            
        }
    }
}