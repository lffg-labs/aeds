#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_upper_with_acc(char *str, int len, int acc) {
    if (len <= 0) {
        return acc;
    }
    int is_upper = isupper(str[len - 1]) != 0;
    return count_upper_with_acc(str, len - 1, acc + is_upper);
}

int count_upper(char *str, int len) {
    return count_upper_with_acc(str, len, 0);
}

char *read_string(char *buf, int cap, int *len) {
    char *str = fgets(buf, cap, stdin);
    if (str == NULL) {
        return NULL;
    }

    int orig_len  = strcspn(str, "\r\n");
    str[orig_len] = 0;  // Remove trailing new line.
    *len          = orig_len;

    return str;
}

int main() {
    char buf[2048];
    int len = 0;
    while (read_string(buf, 2048, &len) != NULL) {
        if (strcmp(buf, "FIM") == 0) {
            break;
        }
        printf("%d\n", count_upper(buf, len));
    }
}
