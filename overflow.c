#include <stdio.h>

int main() {
char str[50];

printf("Enter your name");
gets(str);
printf("Hello %s\n", str);

return 0;
}
