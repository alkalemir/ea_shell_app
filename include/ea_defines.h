#ifndef EA_DEFINES_H_
#define EA_DEFINES_H_

#define EA_NORMAL           "\x1B[0m"
#define EA_BLUE             "\x1B[34m"
#define EA_MAGENTA          "\x1B[35m"
#define EA_CYAN             "\x1B[36m"
#define EA_YELLOW           "\x1B[33m"
#define EA_WHITE            "\x1B[37m"
#define EA_GREEN            "\x1B[32m"
#define EA_RED              "\x1B[31m"
#define BOX_UL              0x250C
#define BOX_UR              0x2510
#define BOX_LL              0x2514
#define BOX_LR              0x2518
#define BOX_H               0x2500
#define BOX_V               0x2502
#define PROMPT              "EA# "
#define MAX_INPUT_SIZE      4096
#define MAX_ARGS            16
#define MAX_PWD_SIZE        4096
#define TAB_SIZE            4


extern char ea_pwd[];
extern char ea_buf[];
extern char *ea_args[];
extern int ea_args_idx;


#endif