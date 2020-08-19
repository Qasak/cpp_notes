#include <stdio.h>
class Actress {
public:
    Actress(int h, int w, int a):height(h),weight(w),age(a){};

    virtual void desc() {
        printf("height:%d weight:%d age:%d\n", height, weight, age);
    }

    virtual void name() {
        printf("I'm a actress");
    }

    int height; // 身高
    int weight; // 体重
    int age;    // 年龄（注意，这不是数据库，不必一定存储生日）
};

class Sensei: public Actress {
public:
    Sensei(int h, int w, int a, const char* c):Actress(h, w, a){
        snprintf(cup, sizeof(cup), "%s", c);
    };
    virtual void desc() {
        printf("height:%d weight:%d age:%d cup:%s\n", height, weight, age, cup);
    }
    virtual void name() {
        printf("I'm a sensei");
    }
    char cup[4];

};

int main() {
    Sensei s(168, 50, 20, "36D");
    s.desc();

    Actress* a = &s;
    a->desc();

    Actress& a2 = s;
    a2.desc();
    return 0;
}