+ touch test
+ vim test : xong ghi Hello
+ file softlink connect to file test. If we delete file test, file test.softlink will show error when we want run it
+ filr hardlink from file test. When we deleted file test. test.hardlink will run and show Hello as normal+ File test.hardlink and file test with the same Inode: run command **stat test.hardlink** and **stat test.softlink** to know the Inode
+ File test.softlink with other Inode id
+ If information in file test change, information in file test.softlink aslo change 
