# Basic bufferover

required software

- python 2.7.x
- Immunity debugger - https://www.immunityinc.com/products/debugger/
- MinGW (gcc) - https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Automated%20Builds/


# First step

Write code

```
#include <stdio.h>

int main() {
char str[50];

printf("Enter your name");
gets(str);
printf("Hello %s\n", str);

return 0;
}
```






