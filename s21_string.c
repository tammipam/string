#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++) {
    }
    return len;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char *p = str;
    for (int i = 0; i < (int)n; i++) {
        if (*p++ == (unsigned char)c) {
            return (void *)(p - 1);
        }
    }
    return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *str_k1, *str_k2;
    str_k1 = str1;
    str_k2 = str2;
    int res = 0;
    while (n != 0) {
        if ((res = *str_k1 - *str_k2) != 0)
            break;
        n--;
        ++str_k1;
        ++str_k2;
    }
    return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *tmp = dest;
    const char *s = src;
    while (n--) {
        *tmp++ = *s++;
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    if (dest < src) {
        char *s = (char *)src;
        char *d = (char *)dest;
        for (unsigned int i = 0; i < n; i++) {
            *(d + i) = *(s + i);
        }
    } else {
        char *s = (char *)src + n;
        char *d = (char *)dest + n;
        for (int i = n - 1; i >= 0; i--) {
            *--d = *--s;
        }
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *p = str;
    for (int i = 0; i < (int)n; i++) {
        *(p + i) = (unsigned char)c;
    }
    return p;
}

char *s21_strcat(char *dest, const char *src) {
    char *temp = dest;
    while (*dest) {
        dest++;
    }
    while ((*dest++ = *src++) != '\0') {
    }
    return temp;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *temp = dest;
    while (*dest)
        while (*dest)
            while (*dest)
                dest++;
    while ((*dest++ = *src++) != 0) {
        if (--n == 0) {
            *dest = '\0';
            break;
        }
    }
    return temp;
}

char *s21_strchr(const char *str, int c) {
    while (*str != (char)c) {
        if (*str++ == '\0') {
            return 0;
        }
    }
    return (char *)str;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++, str2++;
    }
    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    while (n-- - 1 && *str1 && *str1 == *str2) {
        str1++, str2++;
    }
    return (*str1 - *str2);
}

char *s21_strcpy(char *dest, const char *src) {
    char *tmp = dest;
    while ((*dest++ = *src++) != 0) {
    }
    return tmp;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    char *temp = dest;
    int ttp = 0;
    while (((*dest++ = *src++) != '\0') && ttp++ < ((int)n)-1) {
    }
    return temp;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t count = 0;
    while (*str1 && !s21_strchr(str2, *str1++)) {
        count++;
    }
    return count;
}

char *s21_strerror(int errnum) {
    static char *str[] = ERRORS;
    int max;
    char error[4096] = {'\0'};
    char stt[10];
    static char strr[4096] = {'\0'};
    for (int i = 0; i < 4096; i++) strr[i] = '\0';
#if defined(__APPLE__) && defined(__MACH__)
    max = 106;
#else
    max = 133;
#endif
    if (errnum > max || errnum < 0) {
        s21_itoa(errnum, stt);
        s21_strcpy(error, "Unknown error: ");
        s21_strncat(error, stt, s21_strlen(error));
    } else {
        s21_strcat(error, str[errnum]);
    }
    s21_strcat(strr, error);
    return strr;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    int flag = 0;
    char *res = S21_NULL;
    while (*str1 != '\0' && !flag) {
        for (int i = 0; i < (int)s21_strlen(str2); i++) {
            if (*str1 == *(str2 + i)) {
                flag = 1;
                res = (char *)str1;
            }
        }
        str1++;
    }
    return res;
}

char *s21_strrchr(const char *str, int c) {
    const char *ptr, *found;
    c = (unsigned char) c;

    if (c == '\0')
        return s21_strchr (str, '\0');
    found = S21_NULL;
    while ((ptr = s21_strchr(str, c)) != S21_NULL) {
        found = ptr;
        str = ptr + 1;
    }
    return (char *) found;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t spn = 0;
    while (*str1 && s21_strchr(str2, *str1++)) {
        spn++;
    }
    return spn;
}

char *s21_strstr(const char *haystack, const char *needle) {
    s21_size_t lens1, lens2;
    lens2 = s21_strlen(needle);
    if (!lens2) {
        return (char *)haystack;
    }
    lens1 = s21_strlen(haystack);
    while (lens1 >= lens2) {
        lens1--;
        if (!s21_memcmp(haystack, needle, lens2)) {
            return (char *)haystack;
        }
        haystack++;
    }
    return S21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
    static char *buffer;
    char *token = S21_NULL;
    if (str) {
        buffer = str;
        while (*buffer && s21_strchr(delim, *buffer)) {
            *buffer++ = '\0';
        }
    }
    if (buffer && *buffer) {
        str = buffer;
        while (*buffer && !s21_strchr(delim, *buffer)) {
            ++buffer;
        }
        while (*buffer && s21_strchr(delim, *buffer)) {
            *buffer++ = '\0';
        }
        token = str;
    }
    return token;
}

void s21_itoa(int m, char *str) {
    if (m < 0) {
        m = abs(m);
        int power = 0, j = 0;
        j = m;
        for (power = 1; j >= 10; j /= 10)
            power = power * 10;
        *str++ = '-';
        for (; power > 0; power /= 10) {
            *str++ = '0' + m / power;
            m %= power;
        }
        *str = '\0';

    } else {
        int power = 0, j = 0;
        j = m;
        for (power = 1; j >= 10; j /= 10)
            power *= 10;

        for (; power > 0; power /= 10) {
            *str++ = '0' + m / power;
            m %= power;
        }
        *str = '\0';
    }
}

void *s21_to_upper(const char *str) {
    char *dst = S21_NULL;
    s21_size_t lenght = s21_strlen(str) + 1;
    dst = calloc((s21_strlen(str) + 1), sizeof(char));

    if (dst != S21_NULL) {
        s21_strcpy(dst, str);
        for (s21_size_t i = 0; i < lenght; i++) {
            if (dst[i] >= 97 && dst[i] <= 122) {
                dst[i] = (char) (dst[i] - 32);
            }
        }
    }

    return (void *)dst;
}

void *s21_to_lower(const char *str) {
    char *dst = S21_NULL;
    s21_size_t lenght = s21_strlen(str) + 1;
    dst = calloc((s21_strlen(str) + 1), sizeof(char));

    if (dst != S21_NULL) {
        s21_strcpy(dst, str);
        for (s21_size_t i = 0; i < lenght; i++) {
            if (dst[i] >= 65 && dst[i] <= 90) {
                dst[i] = (char) (dst[i] + 32);
            }
        }
    }

    return (void *)dst;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *pointer = S21_NULL;

    if (src != S21_NULL && str != S21_NULL) {
        s21_size_t src_length = s21_strlen(src);
        s21_size_t str_length = s21_strlen(str);
        s21_size_t memory_size = src_length + str_length + 1;

        if (start_index <= src_length) {
            pointer = calloc(memory_size, sizeof(char));

            if (pointer != S21_NULL) {
                for (s21_size_t i = 0; i < start_index; i++) {
                    pointer[i] = src[i];
                }

                for (s21_size_t i = 0; i < str_length; i++) {
                    pointer[i + start_index] = str[i];
                }

                for (s21_size_t i = 0; i < src_length - start_index; i++) {
                    pointer[i + start_index + str_length] =
                        src[i + start_index];
                }

                pointer[memory_size - 1] = '\0';
            }
        }
    }

    return pointer;
}

void *s21_trim(const char *src, const char *trim_char) {
    char *pointer = S21_NULL;

    if (src != S21_NULL) {
        s21_size_t length = s21_strlen(src);

        if (trim_char == S21_NULL) {
            trim_char = " ";
        }

        s21_size_t begin_trim_num = s21_strspn(src, trim_char);
        s21_size_t end_trim_num = s21_trim_strspn_reverse(src, trim_char);

        if (length != begin_trim_num) {
            pointer = calloc(length - begin_trim_num - end_trim_num + 1, sizeof(char));
        } else {
            pointer = calloc(1, sizeof(char));
        }

        if (pointer != S21_NULL) {
            if (length != begin_trim_num) {
                for (s21_size_t i = 0;
                     i < length - begin_trim_num - end_trim_num; i++) {
                    pointer[i] = src[i + begin_trim_num];
                }

                pointer[length - begin_trim_num - end_trim_num] = '\0';
            } else {
                pointer[0] = '\0';
            }
        }
    }

    return pointer;
}

s21_size_t s21_trim_strspn_reverse(const char *str1, const char *str2) {
    s21_size_t str1len = s21_strlen(str1);
    s21_size_t str2len = s21_strlen(str2);
    int is_continue = 0;
    int res = 0;

    for (int i = (int) str1len - 1; i > -1 && is_continue == 0; i--) {
        int inner_res = 0;

        for (s21_size_t j = 0; j < str2len && inner_res == 0; j++) {
            if (str1[i] == str2[j]) {
                inner_res++;
            }
        }

        if (inner_res == 0) {
            is_continue++;
            res--;
        }

        res++;
    }

    return res;
}
