// description de addition
// prend en paramètre deux nombres et les additionnes.
// si une érreur survient la fonction renvoie NULL.

#include "main.h"

size_t  ft_strlen(char *str){
    size_t index = 0;

    while(str[index] != '\0')
        index++;
    return index;
}

int     checkIfNumber(char *number){
    int     point = 0;
    size_t  index = 0;

    while (number[index] != '\0'){
        if (index > INT_MAX)
            return 0;
        if ((number[index] < 48 || number[index] > 57) && number[index] != '.')
            return 0;
        if (number[index] == '.'){
            point++;
            if (point >= 2)
                return 0;
        }
        index++;
    }
    if (index == 1 && point == 1)
        return 0;
    return 1;
}

char *  cleanNumber(char *num){
    char    *newNum = NULL;
    size_t  len = 0;
    (void)newNum;
    (void)len;
    (void)num;
    return NULL;
}

char *  addition(char *num1, char *num2){
    if (num1 == NULL && num2 == NULL)
        return NULL;
    char *nb1clean = NULL;
    // char *nb2clean = NULL;

    if (checkIfNumber(num1) == 0 || checkIfNumber(num2) == 0){
        printf("error\n");
    }

    nb1clean = cleanNumber(num1);

    printf("nb1clean = %s\n", nb1clean);

    return NULL;
}