# 如何在Linux中运行cpp文件

使用指南：

1. 在终端中输入vim file_name.cpp
2. 键入i进入输入模式，然后编写cpp文件
3. 先按esc键退出输入模式，然后按shift+：键进入命令模式，输入wq，保存并推出
4. 编译cpp文件： g++ file_name.cpp
5. 运行文件：./a.out即可运行
6. 使用命令echo $?查看返回给操作系统的值

当然在第4步若使用了如下的命令就会产生些许差别

4. 编译cpp文件：g++ -o execute_file_name file_name.cpp 这段命令的作用就是将最终的可执行文件指定为没有后缀名的文件;
除此之外还可以加入参数：-std=c++0x来打开C++11标准的支持
5. 然后使用命令：./execute_file_name  来执行当前目录下的可执行文件