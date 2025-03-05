// 1. define 的宏替换
// 2.去掉注释
// 3. 条件编译
// 4. \ 的字符串
#include <string.h>
#include<stdio.h>
#define N 10
#define printf(...) ' '

int main()
{
    int arr[N];
    // sb os
    //
    //

    char* str = "hello \
     world";
    perror("hello");
    printf("hello");
    return 0;
}