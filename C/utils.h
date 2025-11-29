#ifndef UTILS_H //this file contains the declarations of the functions that are available for other programs to use.
#define UTILS_H

#include <stddef.h> //for type 'size_t'

void strToLower(char *s);
void trimString(char *str);
void flushInputBuffer()