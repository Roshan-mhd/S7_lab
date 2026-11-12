
#include <stdio.h>
#include <string.h>

int main() {
    char exp[100], lhs, operands[50];
    char temp[10];
    int i, t = 1;

    printf("Enter expression (e.g., x=a+c-d): ");
    scanf("%99s", exp);

    lhs = exp[0];
    strcpy(operands, exp + 2);

    for (i = 1; operands[i] != '\0'; i++) {
        if (operands[i] == '+' ||
            operands[i] == '-' ||
            operands[i] == '*' ||
            operands[i] == '/') {

            printf("T%d = %c %c %c\n",
                   t, operands[i - 1],
                   operands[i], operands[i + 1]);

            operands[i + 1] = '0' + t;
            t++;
        }
    }

    printf("%c = T%d\n", lhs, t - 1);

    return 0;
}
