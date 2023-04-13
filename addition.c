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


size_t  sizeToMalloc(char *num, size_t *left, size_t *right, int *addZero){
    size_t  index = 0;
    size_t  len = 0;

    (void)right;

    len = ft_strlen(num);
    while(num[index] != '\0' && num[index] == 48)
        index++;
    *left = index;
    if ((num[index] == '\0' || num[index] == '.') && index > 0){
        *left = *left - 1;
        if (num[index] == '\0')
            return len - *left;
    }
    while (num[index] != '\0' && num[index] != '.')
        index++;
    if (num[index] == '\0')
        return len - *left;
    if (index == 0)
        *addZero = *addZero + 1;
    index = len;
    while (num[index - 1] == 48){
        index--;
        *right += 1;
    }
    if (num[index - 1] == '.')
        *right += 1;
    return len + *addZero - *left - *right;
}

char *  cleanNumber(char *num){
    size_t  leftZero = 0;
    size_t  rightZero = 0;
    int     addZero = 0;
    char    *newNum = NULL;
    size_t  len = 0;

    len = sizeToMalloc(num, &leftZero, &rightZero, &addZero);
    newNum = (char *)(malloc(sizeof(char) * (len + 1)));
    if (newNum == NULL)
        return NULL;
    newNum[len] = '\0';
    for (size_t index = 0; index < len; index++){
        if (addZero == 1){
            addZero = -1;
            newNum[index] = 48;
        }
        else{
            newNum[index] = num[leftZero + index + addZero];
        }
    }
    // printf("leftZero = %ld\n", leftZero);
    // printf("rightZero = %ld\n", rightZero);
    // printf("len = %ld\n", len);
    // printf("addZero = %d\n", addZero);
    return newNum;
}

char *  addition(char *num1, char *num2){
    if (num1 == NULL || num2 == NULL)
        return NULL;
    char *nb1clean = NULL;
    char *nb2clean = NULL;

    if (checkIfNumber(num1) == 0 || checkIfNumber(num2) == 0){
        printf("error\n");
        return NULL;
    }
    nb1clean = cleanNumber(num1);
    if (nb1clean == NULL)
        return NULL;
    nb2clean = cleanNumber(num2);
    if (nb2clean == NULL){
        free(nb1clean);
        nb1clean = NULL;
        return NULL;
    }
    printf("nb1clean = %s\n", nb1clean);
    printf("nb2clean = %s\n", nb2clean);

    return nb1clean;
}