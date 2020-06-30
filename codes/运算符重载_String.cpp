#include<iostream>
#include<cstring>

using namespace std;

class String {
    private:
        char* str;
    public:
        String(): str(NULL) { }

        const char* c_str() {return str;}

        char* operator=(const char* s);

        // 在class String里添加成员函数
        // String& operator=(const String &s) {
        //     if(str==s.str) return *this; // 确保不会删除自身
        //     if(str) delete [] str;
        //     if(s.str) { //s.str不为NULL才执行拷贝
        //         str = new char[strlen(s.str)+1];
        //         strcpy(str, s.str);
        //     }
        //     else 
        //         str=NULL;
        //     return *this;
        // }

        String(const String &s) {
        if(s.str) {
            str = new char[strlen(s.str) + 1];
            strcpy(str,s.str);
        }
        else 
            str = NULL;
        }

        String& operator=(const String &s) {
            if(this!= &s) {
                String strTemp(s);
                char* pTemp = strTemp.str;
                strTemp.str=str;
                str=pTemp;
            }
            else return *this;
        }


        void show() {
            cout<<str<<endl;
        }

        ~String();
};

char* String::operator=(const char* s) {
    if(str) delete [] str;
    if(s) {
        str=new char[strlen(s)+1];
        strcpy(str, s);
    }
    else {
        str = NULL;
    }
    return str;
}

String::~String() {
    if(str) delete [] str;
}

int main() {
    String S1,S2;
    S1="this";
    S2=S1;
    S2.show();
    return 0;
}