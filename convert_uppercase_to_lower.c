#include <stdio.h>
#include <string.h>

int main() {
    int n;
    puts("enter n");
    scanf("%d", &n); // Fix: Missing comma after "%d"
    char s[n];
    printf("Enter FULL NAME IN uppercase letters: ");
    scanf("%s",s);
    int len = strlen(s); // Fix: Calculate the length after reading the string

    // Convert the first 4 characters to lowercase
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }

    printf("Converted name: %s", s);
    return 0;
}
