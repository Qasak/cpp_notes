
#include <stdio.h>
#include <string>
using std::string;

class Actress {
public:
    Actress(int h, int w, int a):height(h),weight(w),age(a){};

    void desc() {
        printf("height:%d weight:%d age:%d\n", height, weight, age);
    }

    int height; // 身高
    int weight; // 体重
    int age;    // 年龄（注意，这不是数据库，不必一定存储生日）
};

class Sensei: public Actress {
public:
    Sensei(int h, int w, int a, string c):Actress(h, w, a),cup(c){};
    virtual void desc() {
        printf("height:%d weight:%d age:%d cup:%s\n", height, weight, age, cup.c_str());
    }
    string cup;

};

int main() {
    Sensei s(168, 50, 20, "36D");

    Actress* a = &s;
    a->desc();

    Actress& a2 = s;
    a2.desc();
    return 0;
}