#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NULL ((void*)0)

typedef long unsigned size_t;

void* memchr(const void* str, int c, size_t n);
int memcmp(const void* str1, const void* str2, size_t n);
void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* str, int c, size_t n);
char* strncat(char* dest, const char* src, size_t n);
char* strchr(const char* str, int c);
int strncmp(const char* str1, const char* str2, size_t n);
char* strncpy(char* dest, const char* src, size_t n);
size_t strcspn(const char* str1, const char* str2);
char* strerror(int errnum);
size_t strlen(const char* str);
char* strpbrk(const char* str1, const char* str2);
char* strrchr(const char* str, int c);
char* strstr(const char* haystack, const char* needle);
char* strtok(char* str, const char* delim);

int sprintf(char* str, const char* format, ...);

int sscanf(const char* str, const char* format, ...);
const char* parse_spec(const char* str, const char** format, va_list* args);

// Part 5. Дополнительно. Реализация С# функций обработки строк
// Возвращает копию строки (str) в верхнем регистре. В случае возвращает NULL.
void* to_upper(const char* str);
void* to_lower(const char* str);
void* insert(const char* src, const char* str, size_t start_index);
void* trim(const char* src, const char* trim_chars);
