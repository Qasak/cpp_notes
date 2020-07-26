## 派生

+ 写法：

  ```c++
  class 派生类名: public 基类名
  {
  
  };
  ```

+ 内存空间：

  + 基类对象体积，在假设派生类对象自己的成员变量的体积，基类对象的存储位置位于派生类对象新增的成员变量前

  + ```c++
    class CBasse
    {
        int v1, v2;
    };
    
    class CDerived:public CBase
    {
    	int v3;    
    };
    ```

    ![img](https://github.com/Qasak/cpp_notes/blob/master/3.%E7%BB%A7%E6%89%BF%E5%92%8C%E6%B4%BE%E7%94%9F/%E6%B4%BE%E7%94%9F%E7%B1%BB%E7%9A%84%E5%86%85%E5%AD%98%E7%A9%BA%E9%97%B4.png)

+ eg:学籍管理系统

  ```c++
  #include <iostream>
  #include <string>
  using namespace std;
  class CStudent {
  	private:
      	string name;
      	string id;
      	char gender;
      	int age;
      public:
      	void PrintInfo();
      	void SetInfo(const string & name_, const string & id_, int age_, char gender_);
      	string GetName() { return name; }
  };
  
  ```

  ```c++
  class CUndergraduateStudent:public CStudent
  {
      private:
      	string department;
      public:
      	void QualifiedForBaoyan() {
              cout <<"qualified for baoyan"<<endl;
          }
      	void PrintInfo() {
              CStudent::PrintInfo();
              cout<<"Department:"<<department<<endl;
          }
      	void SetInfo(const string & name_, const string & id_, int age_, char gender_, const string & department_) {
              CStudent::SetInfo(name_, id_, age_, gender_);
              department=department_;
          }
  };
  ```

  + 覆盖：派生类对基类的修改，不是重载
    可在覆盖的成员函数里调用基类的同名成员函数

## 派生