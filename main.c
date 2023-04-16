#include "main.h"

int main(int argc, char **argv){
    char *number = NULL;
    if (argc != 3)
        return 0;
    number = addition(argv[1], argv[2]);
    if (number == NULL)
        return (printf("ERROR\n"), 0);
    printf("number = %s\n", number);
    number = (char *)ft_free(number);
    number = soustraction(argv[1], argv[2]);
    if (number == NULL)
        return (printf("ERROR\n"), 0);
    printf("number = %s\n", number);
    number = (char *)ft_free(number);
    return 0;
}