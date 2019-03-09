# Basic bufferover

required software

- python 2.7.x
- Immunity debugger - https://www.immunityinc.com/products/debugger/
- MinGW (gcc) - https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Automated%20Builds/


# First steps

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

Compile

```
gcc -m32 overflow.c -o overflow.exe
```

# Debugger

load immunity and use the folder or file to open and then locate overflow.exe
at the bottom of the screen set a working directory
```
!mona config -set workingfolder c:\mona\%p
```

!mona pc 100

!mona po 31634130

!mona jmp -r esp -m kernel


