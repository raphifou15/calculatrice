#ifndef CALC
# define CALC

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647

char *  addition(char *num1, char *num2);
char *  soustraction(char *num1, char *num2);

// tools //
size_t  ft_strlen(char *str);
size_t  ft_strlenAP(char *str, size_t *ap);
size_t  ft_strlenBPAP(char *nb1, size_t *ap, size_t *bp);
int     checkIfNumber(char *number);
char *  cleanNumber(char *num);
char *  ft_joinCharBefore(char *str, char c);
void *  ft_free(void *elem);
int     bigestNumber(char *num1, char *num2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_strcmp(const char *s1, const char *s2);
#endif