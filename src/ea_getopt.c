#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "../include/ea_defines.h"
#include "../include/ea_command.h"




void ea_getopt(int argc,  char *argv[])
{
    int c;
    struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
    };

    c = getopt_long(argc, argv, "hv", long_options, NULL);

    switch (c) {
        case 'h': {
            if (argc != 2) {
                printf("\x1B[31m""  Wrong number of arguments.\n");
                exit(EXIT_FAILURE);
            }
            proc_clear();
            printf("%c[1m\n\n\t\t\t      %s 🖥    Emir Alkal Shell   🖥\n\n", 27, EA_YELLOW);
            setlocale(LC_CTYPE, "");
            
            wprintf(L"\t%lc", BOX_UL);

            for (int i = 0; i < 70; ++i)
                wprintf(L"%lc", BOX_H);
            
            wprintf(L"%lc\n\n", BOX_UR);

            printf("\n\t\t%s✔%s\t--version or -v for version.\n", EA_RED, EA_WHITE);


            printf("\t\t%s✔%s\t--help or -h for help.\n", EA_RED, EA_WHITE);
            printf("\t\t%s✔%s\tclear command for clear console output.\n", EA_RED, EA_WHITE);

            printf("\t\t%s✔%s\tpwd command for print current working directory.\n", EA_RED, EA_WHITE);
            printf("\t\t%s✔%s\tcd command for change current working directory.\n\t\t\t(You can use absolute path (with start /) \n\t\t\tor you can use relative path.)\n", EA_RED, EA_WHITE);
            printf("\t\t%s✔%s\tmkdir command for create single or multiple directory.\n", EA_RED, EA_WHITE);
            printf("\t\t%s✔%s\texit command for terminating shell.\n\n\n%s", EA_RED, EA_WHITE, EA_YELLOW);

            wprintf(L"\t%lc", BOX_LL);

            for (int i = 0; i < 70; ++i)
                wprintf(L"%lc", BOX_H);
            
            wprintf(L"%lc\n", BOX_LR);
            exit(EXIT_SUCCESS);
            break;
        }
        case 'v': {
            if (argc != 2) {
                printf("%s\n  Wrong number of arguments.\n\n", EA_RED);
                exit(EXIT_FAILURE);
            }

            printf("%s\n  ea_shell v1.0\n  Written by Emir Alkal\n\n", EA_RED);
            exit(EXIT_SUCCESS);
            break;
        } 
    }
}
