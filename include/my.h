/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** task02
*/

#ifndef LIB_H_
    #define LIB_H_
    #include "op.h"
    #include "robot_f.h"
    #define OK 0
    #define ERR -1
    #define KO 84
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <string.h>

int my_putchar(char c);
void my_put_errchar(char c);
int my_putstr(char const *str);
int my_put_errstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_strcat(char *dest, char const *src);
int my_getnbr(char const *str);
char *my_strtok(char *str, char const *delimiter);
char *my_strstr(char const *str, char const *needle);
int my_arraylen(char **array);
char *my_int_to_base(unsigned long nbr, int base);
int bin_to_dec(const char *binary);
unsigned int my_htonl(int valeur);
unsigned short my_htons(unsigned short valeur);

#endif /* LIB_H_ */
