#include "main.h"

char *  soustractionNext(char *num1, char *num2, int neg){
    (void)num1;
    (void)num2;
    (void)neg;
    return NULL;
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
    numberSous = (bigestNumber(num1, num2) == 1) ?
        soustractionNext(num1, num2, 1) : soustractionNext(num2, num1, -1);
    nb1clean = ft_free(nb1clean);
    nb2clean = ft_free(nb2clean);
    return numberSous;
}