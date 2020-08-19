#include <stdio.h>
// 写法一
// typedef struct Actress {
//     int height; // 身高
//     int weight; // 体重
//     int age;    // 年龄（注意，这不是数据库，不必一定存储生日）

//     void (*desc)(struct Actress*);
// } Actress;

// // obj中各个字段的值不一定被初始化过，通常还会在类内定义一个类似构造函数的函数指针，这里简化
// void profile(Actress* obj) {
//     printf("height:%d weight:%d age:%d\n", obj->height, obj->weight, obj->age);
// }

// C语言的项目中你很少会看到这种写法，
// 主要原因就是函数指针是有空间成本的，
// 这样写的话每个实例化的对象中都会有一个指针大小（比如8字节）的空间占用，
// 如果实例化N个对象，每个对象有M个成员函数，那么就要占用N*M*8的内存。



// 写法二


typedef struct Actress {
    int height; // 身高
    int weight; // 体重
    int age;    // 年龄（注意，这不是数据库，不必一定存储生日）

} Actress;

void desc(Actress* obj) {
    printf("height:%d weight:%d age:%d\n", obj->height, obj->weight, obj->age);
}

int main() {
    Actress a;
    a.height = 168;
    a.weight = 50;
    a.age = 20;

    desc(&a);
    return 0;
}

// Redis中AE相关的代码实现，便是如此。

