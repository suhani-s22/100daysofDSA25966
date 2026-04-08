//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>

// Recursive function
void reverse(char str[], int index) {
    if (str[index] == '\0')
        return;

    reverse(str, index + 1);   // go forward
    printf("%c", str[index]);  // print while coming back
}

int main() {
    char str[100];

    scanf("%s", str);

    reverse(str, 0);

    return 0;
}