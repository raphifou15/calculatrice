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

size_t  ft_strlenAP(char *str, size_t *ap){
    size_t  i = 0;
    while (str[i] != '\0' && str[i] != '.')
        i++;
    while (str[i] != '\0'){
        *ap = *ap + 1;
        i++;
    }
    return i;
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

char * ft_joinCharBefore(char *str, char c){
    char *num = NULL;
    size_t  len = 0;

    if (str == NULL){
        num = (char *)malloc(sizeof(char) * 2);
        if (num == NULL)
            return NULL;
        num[0] = c;
        num[1] = '\0';
        return num;
    }
    len = ft_strlen(str);
    num = (char *)(malloc(sizeof(char) * (len + 2)));
    if (num == NULL){
        return NULL;
    }
    for (size_t i = 0; i < len + 1; i++){
        if (i == 0)
            num[i] = c;
        else
            num[i] = str[i - 1];
    }
    num[len + 1] = '\0';
    return num;
}

char *  addClean(char *nb1, char *nb2){
    char *str = NULL;  
    char *num = NULL;
    char *cleanNum = NULL;
    size_t  lenNb1 = 0;
    size_t  lenNb2 = 0;
    size_t  ap1 = 0;
    size_t  ap2 = 0;
    char    c = 0;
    char    val = 0;

    lenNb1 = ft_strlenAP(nb1, &ap1);
    lenNb2 = ft_strlenAP(nb2, &ap2);
    // printf("lenNb1 = %ld\n", lenNb1);
    // printf("lenNb2 = %ld\n", lenNb2);
    // printf("ap1 = %ld\n", ap1);
    // printf("ap2 = %ld\n", ap2);
    while (ap1 > 0 || ap2 > 0){
        if (ap1 > ap2){
            c = (nb1[lenNb1 - 1]);
            lenNb1--;
            ap1--;
        }
        else if (ap2 > ap1){
            c = (nb2[lenNb2 - 1]);
            lenNb2--;
            ap2--;
        }
        else if (ap1 == ap2){
            if (ap1 != 1){
                c = ((nb1[lenNb1 - 1] - 48) + (nb2[lenNb2 - 1] - 48) + val);
                val = c / 10;
                c = (c % 10) + 48;
            }else{
                c = '.';
            }
            ap1--;
            ap2--;
            lenNb1--;
            lenNb2--;
        }
        str = num;
        num = ft_joinCharBefore(str, c);
        if (str != NULL){
            free(str);
            str = NULL;
        }
        if (num == NULL)
            return NULL;
    }
    while (lenNb1 > 0 || lenNb2 > 0){
        if (lenNb1 > 0 && lenNb2 > 0){
            c = ((nb1[lenNb1 - 1] - 48) + (nb2[lenNb2 - 1] - 48) + val);
            val = c / 10;
            c = (c % 10) + 48;
        }else if (lenNb1 > 0){
            c = ((nb1[lenNb1 - 1] - 48) + val);
            val = c / 10;
            c = (c % 10) + 48;
        }else if (lenNb2 > 0){
            c = ((nb2[lenNb2 - 1] - 48) + val);
            val = c / 10;
            c = (c % 10) + 48;
        }
        lenNb1--;
        lenNb2--;
        str = num;
        num = ft_joinCharBefore(str, c);
        if (str != NULL){
            free(str);
            str = NULL;
        }
        if (num == NULL)
            return NULL;
    }
    cleanNum = cleanNumber(num);
    free(num);
    num = NULL;
    return cleanNum;
}   

char *  addition(char *num1, char *num2){
    char *nb1clean = NULL;
    char *nb2clean = NULL;
    char *numberAdd = NULL;

    if (num1 == NULL || num2 == NULL)
        return NULL;
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
    // printf("nb1clean = %s\n", nb1clean);
    // printf("nb2clean = %s\n", nb2clean);
    numberAdd = addClean(nb1clean, nb2clean);
    if (numberAdd == NULL)
        return NULL;

    free(nb1clean);
    nb1clean = NULL;
    free(nb2clean);
    nb2clean = NULL;
    // printf("numberAdd = %s\n", numberAdd);
    return numberAdd;
}