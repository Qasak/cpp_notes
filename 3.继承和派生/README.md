## 继承

定义：在定义一个新的类B时，如果该类与某个已有的类A相似(指的是B拥有A的全部特点)，那就可以把A作为一个基类，而把B作为基类的一个派生类(也称子类)  

eg:

![img](https://github.com/Qasak/cpp_notes/blob/master/3.%E7%BB%A7%E6%89%BF%E5%92%8C%E6%B4%BE%E7%94%9F/%E9%9C%80%E8%A6%81%E7%BB%A7%E6%89%BF%E6%9C%BA%E5%88%B6%E7%9A%84%E4%BE%8B%E5%AD%90.png)



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
  void CStudent::PrintInfo()
  {
      cout << "Name:" << name << endl;
      cout << "ID:" << id << endl;
      cout << "Age:" << age << endl;
      cout << "Gender:" << gender << endl;
  }
  void CStudent::SetInfo( const string & name_,const string & id_, int age_,char gender_ )
  {
      name = name_;
      id = id_;
      age = age_;
      gender = gender_;
  }
  
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

+ 派生类是通过对基类进行修改和扩充得到的。在派生类中，可以扩充新的成员变量和成员函数。  

+ 派生类一经定义后，可以独立使用，不依赖于基类。  

+ 派生类拥有基类的全部成员函数和成员变量，不论是private、 protected、 public 。
  + 在派生类的各个成员函数中，不能访问基类中的private成员。  