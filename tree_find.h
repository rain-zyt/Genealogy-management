#ifndef TREE_FIND_H
#define TREE_FIND_H
#include "person.h"
#include <vector>

struct node{
    person* this_person;
    string name;
};

class tree_find
{
public:
    tree_find();
    void treeadd(person* person_new);
    person* search(string name);
    void treedelete(person*);
    void GetNext(vector<int>& next, const string& p);
    int KMP(const string& s, const string& p);
private:
        person* a[10000];
        string b[10000];
        bool c[10000];
        int total;
};

#endif // TREE_FIND_H
