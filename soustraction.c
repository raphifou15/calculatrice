#include "main.h"

char *  soustractionNext(char *num1, char *num2, int neg){
    // printf("num1 = %s\n", num1);
    // printf("num2 = %s\n", num2);
    // printf("neg = %d\n", neg);

    char    *str = NULL;
    char    *num = NULL;
    size_t  lenNb1 = 0;
    size_t  lenNb2 = 0;
    size_t  ap1 = 0;
    size_t  ap2 = 0;
    char    c = 0;
    char    hold = 0; 

    (void)c;
    lenNb1 = ft_strlenAP(num1, &ap1);
    lenNb2 = ft_strlenAP(num2, &ap2);
    while (ap1 > 0 || ap2 > 0){
        if (ap1 > ap2){
            c = num1[lenNb1 - 1];
            ap1--;
            lenNb1--;
        }
        else if (ap2 > ap1){
            if (num2[lenNb2 - 1] != '.'){
                c = (58 - num2[lenNb2 -1]) + 48 + hold;
                hold = 1;
            }else
                c = '.';
            ap2--;
            lenNb2--;
        }
        else if(ap1 == ap2){
            if (num1[lenNb1 - 1] != '.'){
                if (num1[lenNb1 - 1] >= (num2[lenNb2 - 1] + hold)){
                    c = (num1[lenNb1 - 1] - (num2[lenNb2 - 1] + hold)) + 48;
                    hold = 0;
                    }else{
                    c = ((10 + num1[lenNb1 - 1]) - (num2[lenNb2 - 1] + hold)) + 48;
                    hold = 1;
                }
            }
            else
                c = '.';
            ap1--;
            ap2--;
            lenNb1--;
            lenNb2--;
        }
        str = num;
        num = ft_joinCharBefore(str, c);
        str = ft_free(str);
        if (num == NULL)
            return NULL;
        // printf("num = %s\n", num);
    }
    while (lenNb1 > 0 || lenNb2 > 0){
        if (lenNb1 > 0 && lenNb2 > 0){
            if (num1[lenNb1 - 1] >= (num2[lenNb2 - 1] + hold)){
                c = (num1[lenNb1 - 1] - (num2[lenNb2 - 1] + hold)) + 48;
                hold = 0;
            }else{
                c = ((10 + num1[lenNb1 - 1]) - (num2[lenNb2 - 1] + hold)) + 48;
                hold = 1;
            }
            (lenNb1 > 0) ? lenNb1-- : 0;
            (lenNb2 > 0) ? lenNb2-- : 0;
        }else{
            c = num1[lenNb1 - 1] - hold;
            (lenNb1 > 0) ? lenNb1-- : 0;
            hold = 0;
        }
        str = num;
        num = ft_joinCharBefore(str, c);
        str = ft_free(str);
        if (num == NULL)
            return NULL;
        // printf("num = %s\n", num);
    }
    str = num;
    num = cleanNumber(str);
    ft_free(str);
    if (num == NULL)
        return NULL;
    if (neg == -1){
        str = num;
        num = ft_joinCharBefore(str, '-');
        str = ft_free(str);
        if (num == NULL)
            return NULL;
    }
    return num;
}

char *  soustraction(char *num1, char *num2){
    char *nb1clean = NULL;
    char *nb2clean = NULL;
    char *numberSous = NULL;

    if (num1 == NULL || num2 == NULL)
        return NULL;
    if (checkIfNumber(num1) == 0 || checkIfNumber(num2) == 0)
        return NULL;
    nb1clean = cleanNumber(num1);
    if (nb1clean == NULL)
        return NULL;
    nb2clean = cleanNumber(num2);
    if (nb2clean == NULL){
        nb1clean = (char *)ft_free(nb1clean);
        return NULL;
    }
    numberSous = (bigestNumber(nb1clean, nb2clean) == 1) ?
        soustractionNext(nb1clean, nb2clean, 1) : soustractionNext(nb2clean, nb1clean, -1);
    nb1clean = ft_free(nb1clean);
    nb2clean = ft_free(nb2clean);
    return numberSous;
}