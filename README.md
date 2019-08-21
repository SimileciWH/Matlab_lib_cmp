# Matlab_lib_cmp
Use c program to rewrite Matlab library function.

1.  MATLAB中有很多函数的重构，但是C语言实现函数的重构，需要提供传入的参数的个数，因此所有关于此的MATLAB的重构的函数，在这里通过可变参数的方式实现，但是会新增第一个参数为count，以传递传入参数的个数。比如：

   ```c
   MATLAB: rand() -----> C: rand(count, ...) example: rand(0);
   MATLAB: rand(5)-----> C: rand(count, ...) example: rand(1, 5);
   ```

   

2. 关于函数的全局变量的定义与使用和一些宏，全部放在 ==include/global==文件中。

