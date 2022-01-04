/*
定义person结构体来存储人的信息
存储结构适合二叉树的构建
其中包含人名，配偶名，生日，死亡日期，性别（0是男性，1是女性），父节点指针，子节点指针，兄弟节点指针
*/
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
using namespace std;
struct person{
    string name;
    string spous;
    string birthday;
    string deathday;
    int childrennum;
    bool sex;
    person* father;
    person* child;
    person* broorsis;
};
#endif // PERSON_H
