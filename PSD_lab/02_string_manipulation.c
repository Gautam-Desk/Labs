/**
 * Problem Solving in C (PSD Lab) — String Manipulation Without string.h
 * Topics:
 *   - Custom String Length (my_strlen)
 *   - Custom String Copy (my_strcpy)
 *   - Custom String Concatenation (my_strcat)
 *   - Custom String Comparison (my_strcmp)
 *   - In-Place String Reversal
 *   - Palindrome Checker (Case-insensitive & ignoring spaces)
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

int my_strlen(const char *s) {
    int len = 0;
    while (*s++) len++;
    return len;
}

char *my_strcpy(char *dest, const char *src) {
    char *orig = dest;
    while ((*dest++ = *src++));
    return orig;
}

char *my_strcat(char *dest, const char *src) {
    char *orig = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++));
    return orig;
}

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

void reverse_string(char *s) {
    int len = my_strlen(s);
    int i = 0, j = len - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

bool is_palindrome(const char *s) {
    int i = 0;
    int j = my_strlen(s) - 1;

    while (i < j) {
        while (i < j && !isalnum((unsigned char)s[i])) i++;
        while (i < j && !isalnum((unsigned char)s[j])) j--;

        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(void) {
    printf("========================================================\n");
    printf("   PSD Lab: String Manipulation (Standard Library-Free)\n");
    printf("========================================================\n\n");

    /* 1. Length */
    assert(my_strlen("DataStructures") == 14);
    assert(my_strlen("") == 0);

    /* 2. Copy */
    char buf1[64];
    my_strcpy(buf1, "Antigravity");
    printf("Copied String: %s\n", buf1);
    assert(my_strcmp(buf1, "Antigravity") == 0);

    /* 3. Concat */
    my_strcat(buf1, " Assistant");
    printf("Concatenated String: %s\n", buf1);
    assert(my_strcmp(buf1, "Antigravity Assistant") == 0);

    /* 4. Compare */
    assert(my_strcmp("apple", "apple") == 0);
    assert(my_strcmp("apple", "banana") < 0);
    assert(my_strcmp("banana", "apple") > 0);

    /* 5. In-place Reverse */
    char rev_buf[] = "RACECAR_XYZ";
    reverse_string(rev_buf);
    printf("Reversed: %s\n", rev_buf);
    assert(my_strcmp(rev_buf, "ZYX_RACECAR") == 0);

    /* 6. Palindrome */
    assert(is_palindrome("racecar") == true);
    assert(is_palindrome("A man, a plan, a canal: Panama") == true);
    assert(is_palindrome("hello world") == false);

    printf("\n[PASS] All String Manipulation tests passed successfully!\n");
    return 0;
}
