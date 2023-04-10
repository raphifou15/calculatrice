#include "main.h"

int main(int argc, char **argv){
    char *number = NULL;
    if (argc != 3)
        return 0;
    number = addition(argv[1], argv[2]);
    printf("number = %s\n", number);
    free(number);
    return 0;
}

