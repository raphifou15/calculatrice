// description de addition
// prend en paramètre deux nombres et les additionnes.
// si une érreur survient la fonction renvoie NULL.

#include "main.h"

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
    numberAdd = addClean(nb1clean, nb2clean);
    if (numberAdd == NULL)
        return NULL;
    free(nb1clean);
    nb1clean = NULL;
    free(nb2clean);
    nb2clean = NULL;
    return numberAdd;
}