#include "string.h"

void *memchr(const void *str, int c, size_t n) {
  if (str == NULL) return NULL;
  unsigned char *byte = (unsigned char *)str;
  unsigned char *result = NULL;

  for (size_t i = 0; i < n; i++) {
    if (byte[i] == (unsigned char)c) {
      result = byte + i;
      break;
    }
  }
  return result;
}

int memcmp(const void *str1, const void *str2, size_t n) {
  if (str1 == NULL || str2 == NULL) {
    perror("Erorr. str1 or str2 eq NULL");
  }
  int res = 0;
  while (n--) {
    if (*(unsigned char *)str1 != *(unsigned char *)str2) {
      res = *(unsigned char *)str1 - *(unsigned char *)str2;
      break;
    }
    str1 = (void *)((unsigned char *)str1 + 1);
    str2 = (void *)((unsigned char *)str2 + 1);
  }

  return res;
}

void *memcpy(void *dest, const void *src, size_t n) {
  if (dest == NULL || src == NULL) return NULL;
  char *d = (char *)dest;  // приведение типа
  const char *s = (const char *)src;

  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}

void *memset(void *str, int c, size_t n) {
  if (str == NULL) return NULL;
  for (size_t i = 0; i < n; ++i) {
    ((char *)str)[i] = (char)c;  //приведение типа из блока символов в один
  }
  return str;
}

char *strncat(char *dest, const char *src, size_t n) {
  if (dest == NULL || src == NULL) return NULL;
  size_t dest_len = strlen(dest);
  size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}

char *strchr(const char *str, int c) {
  if (str == NULL) return NULL;
  char *result = NULL;
  int len = strlen(str) + 1;

  for (int i = 0; i < len; i++) {
    if (str[i] == c) {  // standart strings works on tests: str[i] == (char)c;
      result = (char *)(str + i);
      break;
    }
  }
  return result;
}

int strncmp(const char *str1, const char *str2, size_t n) {
  if (str1 == NULL || str2 == NULL) {
    perror("Erorr. str1 or str2 eq NULL");
  }
  int res = 0;
  while (n--) {
    if (*str1 != *str2) {
      res = *(unsigned char *)str1 - *(unsigned char *)str2;
      break;
    }

    str1++;
    str2++;
  }
  return res;
}

char *strncpy(char *dest, const char *src, size_t n) {
  if (dest == NULL || src == NULL) return NULL;

  size_t src_len = strlen(src);
  if (n > src_len) n = src_len + 1;

  for (size_t i = 0; i < n; i++) dest[i] = src[i];

  return dest;
}

size_t strcspn(const char *str1, const char *str2) {
  if (str1 == NULL || str2 == NULL) return 0;
  size_t len = 0;
  while (str1[len] != '\0' && strchr(str2, str1[len]) == NULL) {
    len++;
  }
  return len;
}

size_t strlen(const char *str) {
  if (str == NULL) return 0;
  size_t len = 0;
  for (; str[len] != '\0'; len++)
    ;
  return len;
}

char *strpbrk(const char *str1, const char *str2) {
  if (str1 == NULL || str2 == NULL) return NULL;

  size_t str1_len = strlen(str1);
  size_t str2_len = strlen(str2);
  if (str1_len < 1 || str2_len < 1) return NULL;

  int flag = 0;
  size_t i = 0;
  for (; i < str1_len && flag == 0; i++)
    for (size_t j = 0; j < str2_len && flag == 0; j++)
      if (str1[i] == str2[j]) flag = 1;

  char *result = NULL;
  if (flag == 1) result = (char *)(str1 + i - 1);

  return result;
}

char *strrchr(const char *str, int c) {
  if (str == NULL) return NULL;
  char *result = NULL;
  int len = strlen(str) + 1;

  for (int i = len; i >= 0; i--) {
    if (str[i] == c) {  // standart strings works on tests: str[i] == (char)c;
      result = (char *)(str + i);
      break;
    }
  }
  return result;
}

char *strstr(const char *haystack, const char *needle) {
  if (haystack == NULL || needle == NULL) return NULL;
  char *result = NULL;

  if (*needle == '\0') {
    result = (char *)haystack;

  } else {
    for (char *h = (char *)haystack; *h != '\0'; h++) {
      char *start_h = h;
      char *n = (char *)needle;

      while (*h == *n && *h != '\0' && *n != '\0') {
        h++;
        n++;
      }

      if (*n == '\0') {
        result = start_h;
        break;
      }
      h = start_h;
    }
  }
  return result;
}

// if delim == "", returns all the rest part of the str
char *strtok(char *str, const char *delim) {
  static char *p_str = NULL;
  if ((str == NULL && p_str == NULL) || delim == NULL)
    return NULL;

  size_t str_len = 0;
  if (str != NULL) p_str = str;
  str_len = strlen(p_str);

  static char *res = NULL;
  if (str_len > 0) {
    size_t delim_len = strlen(delim);
    if (delim_len < 1)
      res = p_str;
    else {
      size_t res_len = strcspn(p_str, delim);
      while (res_len == 0 && str_len > 0) {
        p_str++;
        str_len--;
        res_len = strcspn(p_str, delim);
      }
      res = res_len > 0 ? p_str : NULL;
      if (res_len < str_len - 1 && res_len != 0)
        p_str = p_str + res_len + 1;
      else
        p_str = NULL;
      if (res != NULL) res[res_len] = '\0';
    }
  }
  return res;
}

// Part 5. C# functions
void *to_upper(const char *str) {
  if (str == NULL) return NULL;
  int len = strlen(str);
  char *result = malloc(len + 1);
  if (result != NULL) {
    strncpy(result, str, len);
    result[len] = '\0';

    for (int i = 0; i < len; i++) {
      if (result[i] >= 'a' && result[i] <= 'z') {
        result[i] -= 32;
      }
    }
  }
  return result;
}

void *to_lower(const char *str) {
  if (str == NULL) return NULL;
  int len = strlen(str);
  char *result = malloc(len + 1);
  if (result != NULL) {
    strncpy(result, str, len);
    result[len] = '\0';
    for (int i = 0; i < len; i++) {
      if (result[i] >= 'A' && result[i] <= 'Z') {
        result[i] += 32;
      }
    }
  }
  return result;
}

void *insert(const char *src, const char *str, size_t start_index) {
  if (src == NULL || str == NULL || start_index > strlen(src))
    return NULL;

  size_t src_len = strlen(src);
  size_t str_len = strlen(str);
  size_t new_len = src_len + str_len;

  // Создаем новую строку, достаточную для хранения результата
  char *result = (char *)malloc(new_len + 1);  // +1 для завершающего нуля

  if (result != NULL) {
    // Копируем часть исходной строки до позиции вставки
    strncpy(result, src, start_index);
    result[start_index] = '\0';
    // Добавляем вставляемую строку
    strncat(result, str, str_len);
    // Добавляем оставшуюся часть исходной строки после позиции вставки
    strncat(result, src + start_index, src_len - start_index);
  } else
    result = NULL;  // Не удалось выделить память

  return result;
}

void *trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) return NULL;

  const char *start = src;
  const char *end = start + strlen(start);
  while (*start != '\0' && strchr(trim_chars, *start) != NULL) start++;

  while (end >= start && strchr(trim_chars, *end) != NULL) end--;

  size_t len = (size_t)(end - start) + 1;
  char *result = (char *)malloc((len + 1) * sizeof(char));
  if (result != NULL) {
    strncpy(result, start, len);
    result[len] = '\0';
  }

  return result;
}

// %[ширина][длина]спецификатор
int sscanf(const char *str, const char *format, ...) {
  if (str == NULL || format == NULL) return 0;
  va_list args = {0};
  va_start(args, format);

  while (*format != '\0') {
    int clean_strlen = strcspn(format, "%");
    format = format + clean_strlen;

    // parse flags of the current specifier

    // parse current specifier
    if (*format != '\0') format = parse_spec(str, &format, &args);
  }
  va_end(args);
  return strlen(str);
  ;
}

const char *parse_spec(const char *str, const char **format, va_list *args) {
  if (str == NULL || format == NULL) return NULL;
  switch (**format) {
    case ('c'):
      char c = va_arg(*args, int);
      c = c;
      break;
    case ('d'):
      break;
    default:  // wrong specifier
      break;
  }
  (*format)++;
  return *format;
}
