#include "main.h"


// calculate the lenght of a sring;
// returns the number of bytes in the string pointed to by str.
size_t  ft_strlen(char *str){
    size_t index = 0;

    while(str[index] != '\0')
        index++;
    return index;
}
// calculate the lenght of a string special for number.
// ap will be the number bytes after point '.' included.
// returns the number of bytes in the string pointed to by str.
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

size_t  ft_strlenBPAP(char *str, size_t *ap, size_t *bp){
    size_t  i = 0;
    while (str[i] != '\0' && str[i] != '.'){
        *bp = *bp + 1;
        i++;
    }
    while (str[i] != '\0'){
        *ap = *ap + 1;
        i++;
    }
    return i;
}

// check if the string is a number.
// 0 is not a number.
// 1 is a number.
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

// cleanNumber clean the number
// takeoff number of 0 from left to right.
// takeoff number of 0 from right to left if is a decimal number
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
    return newNum;
}


// join a char to a string
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

// free an elem and put the elem to NULL and return elem;
void *  ft_free(void *elem){
    if (elem != NULL){
        free(elem);
        elem = NULL;
    }
    return elem;
}

int ft_strncmp(const char *s1, const char *s2, size_t n){
    size_t  i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && n > i)
        i++;
    return (s1[i] - s2[i]);
}

int ft_strcmp(const char *s1, const char *s2){
    size_t i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int bigestNumber(char *num1, char *num2){
    size_t  ap1 = 0;
    size_t  ap2 = 0;
    size_t  bp1 = 0;
    size_t  bp2 = 0;
    int     res = 0;
    
    
    ft_strlenBPAP(num1, &ap1, &bp1);
    ft_strlenBPAP(num2, &ap2, &bp2);
    if (bp1 > bp2)
        return 1;
    else if(bp2 > bp1)
        return 2;
    else if (bp1 == bp2 && ap1 > 0 && ap2 == 0)
        return 1;
    else if (bp1 == bp2 && ap2 > 0 && ap1 == 0)
        return 2;
    res = ft_strncmp(num1, num2, ap1);
    if (res > 0)
        return 1;
    else if (res < 0)
        return 2;
    res = ft_strcmp(num1 + ap1, num2 + ap2);
    if (res >= 0)
        return 1;
    return 2;
}