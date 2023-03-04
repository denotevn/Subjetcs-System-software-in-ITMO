+ **[fork vs Exec](https://www.geeksforgeeks.org/difference-fork-exec/)**
### Fork()
   + When a process makes the fork system call, a new process is created which is a clone of the calling process. The code, data and the stack of the new process is copied from the calling process.
   + Tiến trình mới được tạo ra được gọi là tiến trình con, trong khi tiến trình gọi được gọi là tiến trình cha.
   + Giá trị trả về của fork trong tiến trình con là 0, trong khi đó, trong tiến trình cha, id tiến trình của tiến trình con được trả về. Thật vậy, hai quy trình sử dụng sự **khác biệt này để tìm ra liệu chúng là cha mẹ hay con cái.**
   + Trong Linux, có một lệnh gọi hệ thống execve và có sáu hàm có tên bắt đầu bằng exec và là giao diện người dùng của lệnh gọi hệ thống execve.
### Difference between fork and exec
  + Sự khác biệt chính là trong trường hợp fork, một tiến trình con mới được tạo ra, là một bản sao của tiến trình cha.
  + Khi một quá trình thực thi exec, không có quá trình mới nào được tạo. Quá trình gọi được ghi đè bởi chương trình có tên tệp được chuyển làm đối số đầu tiên.
  + Trong hầu hết các trường hợp, lệnh gọi hệ thống fork được theo sau bởi lệnh gọi exec trong quy trình con mới được tạo.
  + Một quy trình thực hiện lệnh gọi hệ thống fork, lệnh gọi này sẽ tạo ra một quy trình con mới. 
  + Vì vậy, fork và exec chủ yếu được sử dụng cùng nhau. Không có fork, exec được sử dụng hạn chế. Và, không có exec, fork hầu như không được sử dụng.

> More information fork() and exec **[Here](https://www.softprayog.in/programming/creating-processes-with-fork-and-exec-in-linux)**

## **[Share memory](https://viblo.asia/p/giao-tiep-giua-cac-tien-trinh-trong-linux-phan-2-su-dung-share-memory-va-message-queue-djeZ1yyYZWz)**