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

open pattern.txt and copy and paste the pattern into your exe
```
!mona pc 100
```

use this as a pattern offset to workout how many junk bites are required
```
!mona po 31634130
```

look for a esp jump command
```
!mona jmp -r esp -m kernel
```
Log data, item 24
 Address=76C9FB75
 Message=  0x76c9fb75 (b+0x0013fb75)  : jmp esp |  {PAGE_EXECUTE_READ} [KERNELBASE.dll] ASLR: True, Rebase: True, SafeSEH: True, OS: True, v10.0.17763.1 (C:\WINDOWS\System32\KERNELBASE.dll)
```


