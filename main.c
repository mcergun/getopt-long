#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
    int opt;
    int opt_index;  // not going to be used as every long command
                    // has a corresponding short command

    int aflag = 0, bflag = 0, cflag = 0;
    char *cvalue = NULL;

    printf("Hello World!\n");

    const struct option long_options[] =
    {
        {"a-option",    no_argument,        0,  'a'},
        {"b-option",    no_argument,        0,  'b'},
        {"c-option",    required_argument,  0,  'c'},
        {0,             0,                  0,  0}
    };

    while ((opt = getopt_long(argc, argv, "abc:",
            long_options, &opt_index)) != -1) {
        switch(opt)
        {
        case 'a':
            aflag = 1;
            break;
        case 'b':
            bflag = 1;
            break;
        case 'c':
            cflag = 1;
            if(optarg != NULL)
                cvalue = optarg;
            break;
        default:
            break;
        }
    }

    printf("aflag = %d, bflag = %d, cflag = %d optarg = %s\n",
           aflag, bflag, cflag, cvalue);

    return 0;
}
