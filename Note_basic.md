# Các thuật ngữ cơ bản
  + PID: Mỗi tiến trình có một định danh PID (Process Identify) duy nhất trong toàn bộ hệ thống vào thời điểm tiến trình đang chạy
  + PPID: Mỗi tiến trình đều có một tiến trình cha (parent process) với định danh là PPID (Parent process identify). Các tiến trình con (child process) thường được start bởi tiến trình cha (parent process). Một parents process có thể có nhiều child process nhưng một child process chỉ có một parents process.
  + init: Init process là tiến trình đầu tiên được khởi động sau khi bạn lựa chọn hệ điều hành trong boot loader. Trong cây tiến trình, init process là tiến trình cha của các tiến trình khác. Init process có đặc điểm sau: + PID = 1 + Không thể kill init process
  + kill: Khi một tiến trình dừng chạy, tiến trình đó sẽ chết. Khi bạn muốn muốn 1 tiến trình chết, bạn sẽ phải kill nó đi.
  + daemon process: Một daemon process là một tiến trình chạy nền (background). Các tiến trình này được bắt đầu khi khởi động hệ thống và sẽ tiếp tục được chạy mãi.
  + zombie: Zombie thực chất là một phần còn sót lại của một tiến trình đã ngừng hoạt động nhưng chưa được xử lý sạch. Và, đúng vậy, zombie nghĩa là thây ma tức là tiến trình đó đã chết và bạn không thể “kill” nó thêm 1 lần nữa. Những chương trình sau khi thoát để lại tiến trình Zombie thì điều đó đồng nghĩa với việc chương trình đó được lập trình không tốt.
## **Quản lý tiến trình trong linux cơ bản**
  + Biến $$ sẽ giữ ID tiến trình hiện tại của bạn và $ PPID chứa PID chính.
  ```
  tuandinh@ngoctuan:~$ echo $$ $PPID
  10016 9998
  ```
  + pidof: Với lệnh pidopf, bạn có thể tìm kiếm tất cả các process id theo tên.
  ```
  ```
  + Parent and child: Các tiến trình có mối quan hệ cha-con. Mọi tiến trình đều có tiến trình cha (parent process). Khi bắt đầu một bash mới, bạn có thể sử dụng echo để xác minh rằng pid trước đó có phải là ppid của shell mới. Tiến trình con từ phía trên bây giờ là tiến trình cha.
  + fork và exec: Một tiến trình bắt đầu một tiến trình khác theo hai giai đoạn. Đầu tiên, tiến trình tạo ra một nhánh (fork) của chính nó, sao y hệt.  Sau đó, tiến trình được phân nhánh thực hiện một trình thực thi (exec) để thay thế tiến trình được phân nhánh bằng tiến trình con.
  + ps: Một trong những công cụ phổ biến nhất trên Linux để xem các tiến trình là ps. 
+ More information this **[Link](https://viblo.asia/p/basic-process-management-quan-ly-tien-trinh-trong-unixlinux-co-ban-LzD5der0KjY)**
