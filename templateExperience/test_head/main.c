#include "base.h"
#if 0
int changef(struct father *f);
#else
extern int changef(struct father *f);
#endif
int main()
{
    struct father f;
    f.a = 12;
    f.b = 45;
    display(f);
    changef(&f);
    display(f);
    return 0;
}
/*
　　3 问题：extern 函数1

　　常常见extern放在函数的前面成为函数声明的一部分，那么，C语言的关键字extern在函数的声明中起什么作用？

　　答案和分析：

　　假如函数的声明中带有关键字extern，仅仅是暗示这个函数可能在别的源文档里定义，没有其他作用。即下述两个函数声明没有明显的区别
*/