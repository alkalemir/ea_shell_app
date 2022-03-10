#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/ea_command.h"
#include "../include/ea_defines.h"

static struct ea_command commands[] = {
    {"clear", proc_clear},
    {"exit", proc_exit},
    {"pwd", proc_pwd},
    {"cd", proc_cd},
    {"mkdir", proc_mkdir},
    {"tree", proc_tree},
    {NULL, NULL},
};

char ea_pwd[MAX_PWD_SIZE];
char ea_buf[MAX_INPUT_SIZE];
char *ea_args[MAX_ARGS];
int ea_args_idx;

void ea_write_prompt(void)
{
    getcwd(ea_pwd, MAX_PWD_SIZE);
    printf("%c[1m",27); 
    printf("🖥   %s%s%s%s → %s", EA_BLUE, PROMPT, EA_YELLOW, ea_pwd, EA_WHITE);
    
}

void ea_read_line(void)
{
    char *p;
    ea_args_idx = 0;
    
    if ((p = strchr(fgets(ea_buf, sizeof ea_buf, stdin), '\n')) != NULL) 
        *p = '\0';
        
    for (p = strtok(ea_buf, " \t\n"); p; p = strtok(NULL, " \t\n"))
            ea_args[ea_args_idx++] = p;
    
    if (ea_args_idx == 0)
        return;

    int i;
    for (i = 0; commands[i].ea_name; ++i) {
        if (!strcmp(commands[i].ea_name, ea_args[0])) {
            commands[i].ea_proc();
            break;
        }
    }
    
    if (commands[i].ea_name == NULL)
        printf("EA: command not found: %s\n", ea_args[0]);
}