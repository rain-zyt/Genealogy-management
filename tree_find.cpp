#include "tree_find.h"

tree_find::tree_find()
{
    total=0;
}

void tree_find::treeadd(person *person_new){
    a[total]=person_new;
    b[total]=person_new[0].name;
    c[total]=true;
    total++;
}

person* tree_find::search(string name){
    for(int i=0;i<total;i++)
    {
        if(KMP(b[i],name)==0&&c[i]==1)
        {
            return a[i];
        }
    }
    return nullptr;
}

void tree_find::treedelete(person *person_fw){
   for(int i=0;i<total;i++)
   {
       if(a[i]==person_fw)
       {
           c[i]=false;
       }
   }
   return;
}

//求next数组的过程
void tree_find::GetNext(vector<int>& next, const string& p)
{
    next[0] = 0;//next数组初始化
    for (int i = 1, j = 0; i < p.size(); ++i)//i是表示后缀尾，j表示前缀尾以及i之前最长相等前后缀长度
    {
        while (j && p[i] != p[j])//当i和j不匹配时，j向前跳转，当j已经跳转到开头时，不再跳转，防止死循环
        {
            j = next[j - 1];
        }
        if (p[i] == p[j]) j++;
        next[i] = j;//下标为i的字符之前的最长相等前后缀的长度
    }

}
//KMP算法实现过程
int tree_find::KMP(const string& s, const string& p)
{
    if(s==""||p=="")
    {
        return -1;
    }
    vector<int> next(p.size(), 0);//初始化next数组
    GetNext(next, p);
    for (int i = 0, j = 0; i < s.size(); ++i)
    {
        while (j && s[i] != p[j])
        {
            j = next[j - 1];
        }
        if (s[i] == p[j]) j++;
        if (j == p.size()) return i - p.size() + 1;//下标从1开始的话，return 后面加一，GetNext里的next数组里的for循环i初始化为2
    }
    return -1;
}
