#include <stdio.h>

void ea_getopt(int,  char **);
void ea_write_prompt(void);
void ea_read_line(void);

int main(int argc, char *argv[])
{
    if (argc != 1) 
        ea_getopt(argc, argv);

    for (;;) {
        ea_write_prompt();
        ea_read_line();
    }
}