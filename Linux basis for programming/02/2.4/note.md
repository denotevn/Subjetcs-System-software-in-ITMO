+  strace - trace system calls and signals
+ for information here **[link](https://man7.org/linux/man-pages/man1/strace.1.html)**
+ The pwd Linux command prints the current working directory path, starting from the root ( / ).

+ Hệ thống tệp Proc (procfs) là hệ thống tệp ảo được tạo khi hệ thống khởi động và bị giải thể khi tắt hệ thống.
+ Nó chứa thông tin hữu ích về các tiến trình hiện đang chạy, nó được coi là trung tâm điều khiển và thông tin cho kernel.
+ Hệ thống tệp proc cũng cung cấp phương tiện giao tiếp giữa không gian kernel và không gian người dùng.
+ **[Link Proc](https://www.geeksforgeeks.org/proc-file-system-linux/)**

+ Ex1 
```
tuandinh@ngoctuan:~/Desktop/Linux_programming_tutorial/02/2.4$ cat main.c
#include <stdio.h>

int main()
{
  char name[100];
  printf("What is your name? __");
  gets(name);
  return printf("Hello %s\n", name);
}

tuandinh@ngoctuan:~/Desktop/Linux_programming_tutorial/02/2.4$ strace -o trace.txt -e trace=read,write ./a.out
What is your name? __Tuan
Hello Tuan
tuandinh@ngoctuan:~/Desktop/Linux_programming_tutorial/02/2.4$ egrep "^(read|write)" trace.txt | wc -l
4
tuandinh@ngoctuan:~/Desktop/Linux_programming_tutorial/02/2.4$ 

```
+ Ex2: /proc/3471
