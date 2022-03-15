#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <wchar.h>
#include <getopt.h>
#include "../include/ea_defines.h"

static int a_flag = 0;

void walk_dir(const char *path, int level)
{
    DIR *dir;
    struct dirent *ent;
    struct stat finfo;

    if ((dir = opendir(path)) == NULL)
        return;
    if (chdir(path) == -1)
        return;

    while ((ent = readdir(dir)) != NULL) {
        
        if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
            continue;

        if (lstat(ent->d_name, &finfo) == -1)
            continue;

        if ((ent->d_name[0] == '.') && !a_flag)
            continue;
        else if (S_ISDIR(finfo.st_mode))
            printf("%s%*s%s%s\n", EA_GREEN, level * TAB_SIZE * 2, "", ent->d_name, EA_WHITE);
        else 
            printf("%*s%s\n", level * TAB_SIZE, "", ent->d_name);

        if (S_ISDIR(finfo.st_mode)) {
            walk_dir(ent->d_name, level + 1);

            if (chdir("..") == -1)
                break;
        }
    }
    closedir(dir);
}

void proc_tree(void)
{
    int opt;

    while ((opt = getopt(ea_args_idx, ea_args, "a")) != -1)
        switch (opt) {
            case 'a':
                a_flag = 1;
                break;
        }

    if (ea_args_idx == 1)
        walk_dir(ea_pwd, 0);
    else if (a_flag && (ea_args_idx == 2))
        walk_dir(ea_pwd, 0);
    else 
        walk_dir(ea_args[1], 0);
}