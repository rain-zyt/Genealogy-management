/*
家谱类，用于构建家谱，只存储总人数、家谱根节点地址
可以实现增加成员、删除成员、返回成员的功能
可以在打开程序时读文件构建家谱，退出时保存文件供下次使用
*/
#include "genealogy.h"
genealogy::genealogy()//构造函数，没有参数返回值
{
    root=nullptr;//新创建的家谱中没有成员，根节点置空
    personnum=0;//人数为0
    readfile();//读文件创建家谱
    deleteperson("");
}
person* genealogy::search(string name)//搜索家庭成员函数，参数是名字，返回对应的person变量地址，若不存在则返回空
{
    return tree.search(name);//返回
}
void genealogy::addperson(string this_name,string father_name,bool male_or_female,string birthday,string deathday,string spous)//增加一个人员函数，参数是string了日行的名字、父亲名字、生日、忌日、配偶名字，无返回值
{
    if(this_name=="")
    {
        return;
    }
    person *temp=new person[1];//动态分配内存来存储人员信息
    temp[0].name=this_name;//将名字信息放入当前动态分配的空间
    temp[0].spous=spous;//访入配偶信息
    temp[0].birthday=birthday;//放入生日信息
    temp[0].deathday=deathday;//放入死亡日期
    temp[0].sex=male_or_female;//放入性别信息
    temp[0].childrennum=0;//孩子数量置零
    temp[0].broorsis=nullptr;//兄弟姐妹节点置空
    temp[0].child=nullptr;//孩子节点置空
    if(personnum==0)//若家谱中当前没有成员
    {
        root=temp;//根节点指向当前空间
        temp[0].father=nullptr;//当前节点没有父节点，将其置空
    }
    else//否则有成员
    {
        person *temp_person;//创建临时person指针
        temp_person=tree.search(father_name);//查找父亲指针
        temp[0].father=temp_person;//将找到的父亲指针放入当前人的父节点里
        if(temp_person==nullptr)//家谱中未找到其父亲
        {
            cout<<"not family"<<endl;//不是家谱成员
            return;//返回，不添加到家谱里
        }
        temp_person[0].childrennum+=1;//有父亲则父亲的孩子数量+1
        if(temp_person[0].child!=nullptr)//如果父亲的孩子节点已经有数据了
        {
            temp_person=temp_person[0].child;//先将父亲的孩子节点放入temp——person
            while(temp_person[0].broorsis!=nullptr)//循环遍历至最后一个兄弟姐妹节点
            {
                temp_person=temp_person[0].broorsis;
            }
            temp_person[0].broorsis=temp;//将最后一个兄弟姐妹的兄弟姐妹置当前节点地址
        }
        else//若父亲的孩子节点没有数据
        {
            temp_person[0].child=temp;//将父亲的孩子节点置当前节点地址
        }
    }
    personnum++;//总人数增加1
    cout<<"p++"<<endl;
    tree.treeadd(temp);//将这个人添加进查找类里
}
int genealogy::showpersonnum()//显示人员数量函数，无参数，返回当前人员数量
{
    return personnum;//返回人数
}
void genealogy::readfile()//读文件函数，无参数返回值
{
    string name,father,birthday,deathday,spous,sex;//定义临时字符串用于读取姓名、父亲、生日、忌日、配偶姓名
    bool male_or_female;//布尔变量，读取性别信息
    ifstream file_pointer("C:/Users/Public/personlist.txt");//输入流打开对应文件
    if(!file_pointer.is_open())//如果打开失败
    {
        file_pointer.close();//关闭文件指针
        return;//直接返回
    }
    while(true)//打开成功则循环读取人员信息
    {
        file_pointer.clear();//先清空文件指针状态
        getline(file_pointer,name);//按行读入名字信息
        getline(file_pointer,father);//读入父亲信息
        getline(file_pointer,birthday);//读入生日信息
        getline(file_pointer,deathday);//读入死亡日期信息
        getline(file_pointer,spous);//读取配偶信息
        getline(file_pointer,sex);//读取性别信息
        if(sex=="0")//如果性别是false写的字符0
        {
            male_or_female=false;//性别为男
        }
        else//性别是true对应的字符1
        {
            male_or_female=true;//性别为女
        }
        addperson(name,father,male_or_female,birthday,deathday,spous);//添加当前人员进内存
        if(file_pointer.eof())//文件空则跳出
        {
            break;
        }
        cout<<name<<endl;//测试用
    }
    file_pointer.close();//关闭文件指针
    return;//返回
}
void genealogy::writefile(person* now)//写文件函数，参数是当前person变量指针，无返回值
{
    if(now==nullptr)//如果要写的人指针为空
    {
        return;//则直接返回
    }
    cout<<now[0].name<<endl;//测试用
    ofstream filepointer("C:/Users/Public/personlist.txt",ios_base::app);//追加写入文件
    person *temp;//生成临时person指针
    filepointer<<now[0].name<<endl;//将名字写入文件并换行
    if(now[0].father!=nullptr)//若父亲节点不为空
    {
        temp=now[0].father;//temp存放当前父亲节点
        filepointer<<temp[0].name<<endl;//将父亲姓名写入文件
    }
    else//若父亲指针是空（即当前节点是根节点）
    {
        filepointer<<"none"<<endl;//用none代替父亲姓名写入文件
    }
    filepointer<<now[0].birthday<<endl;//写入生日
    filepointer<<now[0].deathday<<endl;//写入死亡日期
    filepointer<<now[0].spous<<endl;//写入配偶姓名
    filepointer<<now[0].sex<<endl;//写入性别
    filepointer.close();//关闭文件指针
    if(now[0].broorsis!=nullptr)//若兄弟节点不为空
    {
        writefile(now[0].broorsis);//则写入兄弟节点
    }
    if(now[0].child!=nullptr)//若孩子节点不为空
    {
        writefile(now[0].child);//则写入孩子节点
    }
    return;//返回
}
bool genealogy::deleteperson(string name)//删除成员函数，参数是人名，返回删除是否成功的布尔变量值
{
    person *person_to_be_deleted;//定义临时person指针变量用于存放要删除的成员对应地址
    person_to_be_deleted=tree.search(name);//搜索成员姓名并将其对应的指针赋给person_to_be_deleted变量
    if(person_to_be_deleted==nullptr)//如果没有找到要删除的人
    {
        return false;//返回false表示没有找到
    }
    person *temp_person;//定义临时person类型指针
    if(person_to_be_deleted!=root)//如果要删除的人不是根节点
    {
        temp_person=person_to_be_deleted[0].father;//先找到其父节点
        temp_person[0].childrennum--;//父节点孩子减一
        if(temp_person[0].child==person_to_be_deleted)//如果父节点的孩子指针指向要删除的人
        {
            temp_person[0].child=person_to_be_deleted[0].broorsis;//将父亲节点的孩子节点变为要删除的人的兄弟节点保证链表完整
        }
        else//父节点的孩子指针不指向要删除的人
        {
            temp_person=temp_person[0].child;//先将父亲的孩子节点赋给临时person变量
            while(temp_person[0].broorsis!=person_to_be_deleted)//循环遍历链表至要删除的人上一个节点
            {
                temp_person=temp_person[0].broorsis;
            }
            temp_person[0].broorsis=person_to_be_deleted[0].broorsis;//将要删除的人从链表里删除
        }
    }
    else//要删除根节点
    {
        root=nullptr;//根节点置空
    }
    tree.treedelete(person_to_be_deleted);//将要删除的人从查找类里删除
    cout<<person_to_be_deleted[0].name<<" "<<"deleted1"<<endl;//测试用
    if(person_to_be_deleted[0].child!=nullptr)//如果要删除的人有孩子
    {
        destroy(person_to_be_deleted[0].child);//删除相关人员
    }
    delete [] person_to_be_deleted;//释放要删除的人对应内存
    personnum--;//家谱中减少一个人
    return true;//返回删除成功信息
}
void genealogy::destroy(person *now)//递归释放内存并删除成员的函数，无返回值，参数是当前person变量的地址
{
    if(now==nullptr)//若要删除一个不存在的节点
    {
        return;//则直接返回
    }
    if(now[0].broorsis!=nullptr)//若有兄弟节点
    {
        cout<<"t1"<<endl;//测试用
        destroy(now[0].broorsis);//递归删除兄弟
    }
    if(now[0].child!=nullptr)//若有孩子节点
    {
        cout<<"t2"<<endl;//测试用
        destroy(now[0].child);//递归删除孩子
    }
    tree.treedelete(now);//从查找类中删除当前成员
    delete [] now;//是发放当前成员对应的地址
    personnum--;//成员人数减一
    cout<<"deleted"<<endl;//测试用
    return;//返回
}
genealogy::~genealogy()
{
    if(root!=nullptr)//家谱中有成员
    {
        ofstream f("C:/Users/Public/personlist.txt");//若不存在存储家谱文件则创建
        f.close();
        writefile(root);//从根节点开始写入家谱
        destroy(root);//递归删除所有人
    }
    else//家谱中没有成员
    {
        remove("C:/Users/Public/personlist.txt");//直接删除家谱文件
    }
}
