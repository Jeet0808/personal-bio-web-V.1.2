#include <stdio.h>
#include <string.h>

int main() {
    char s[30] = "jeet";
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    printf("%s", s);
    return 0;
}
