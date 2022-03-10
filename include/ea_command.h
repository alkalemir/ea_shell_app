#ifndef EA_COMMANDS_H_
#define EA_COMMANDS_H_

struct ea_command {
    char *ea_name;
    void (*ea_proc)(void);
};

void proc_exit(void);
void proc_clear(void);
void proc_pwd(void);
void proc_cd(void);
void proc_mkdir(void);
void proc_tree(void);

#endif