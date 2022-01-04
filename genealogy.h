/*
家谱类，用于构建家谱，只存储总人数、家谱根节点地址
可以实现增加成员、删除成员、返回成员的功能
可以在打开程序时读文件构建家谱，退出时保存文件供下次使用
*/
#ifndef GENEALOGY_H
#define GENEALOGY_H
#include"person.h"
#include<iostream>
#include<fstream>
#include"tree_find.h"
using namespace std;
class genealogy{
private:
    int personnum;//总人数，int类型
    tree_find tree;//用于搜索的类对象
public:
    person* root;//根节点（祖宗）对应的地址
    genealogy();//构造函数，没有参数返回值
    void addperson(string this_name,string father_name,bool male_or_female,string birthday,string deathday,string spous);//增加一个人员函数，参数是string了日行的名字、父亲名字、生日、忌日、配偶名字，无返回值
    int showpersonnum();//显示人员数量函数，无参数，返回当前人员数量
    void readfile();//读文件函数，无参数返回值
    person* search(string name);//搜索家庭成员函数，参数是名字，返回对应的person变量地址，若不存在则返回空
    void writefile(person* now);//写文件函数，参数是当前person变量指针，无返回值
    bool deleteperson(string name);//删除成员函数，参数是人名，返回删除是否成功的布尔变量值
    void destroy(person* now);//递归释放内存的函数，无返回值，参数是当前person变量的地址
    ~genealogy();//析构函数，默认无参数
};

#endif // GENEALOGY_H
