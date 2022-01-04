#include "demo_view.h"
#include "ui_demo_view.h"

demo_view::demo_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::demo_view)
{
    ui->setupUi(this);
}

demo_view::~demo_view()
{
    delete ui;
}

void demo_view::set_tree(genealogy *g)
{
    ui->genealogy_view->clear();
    if(g[0].root==nullptr)
    {
        return;
    }
    QTreeWidgetItem *root_obj=new QTreeWidgetItem(QStringList()<<QString(g->root[0].name.c_str()));
    ui->genealogy_view->addTopLevelItem(root_obj);
    if(g[0].root->child!=nullptr)
    {
        build_tree(g->root[0].child,root_obj);
    }
}

void demo_view::build_tree(person *p, QTreeWidgetItem *father_node)
{
    QTreeWidgetItem *now=new QTreeWidgetItem(QStringList()<<QString(p[0].name.c_str()));
    father_node->addChild(now);
    if(p[0].broorsis!=nullptr)
    {
        build_tree(p[0].broorsis,father_node);
    }
    if(p[0].child!=nullptr)
    {
        build_tree(p[0].child,now);
    }
    return;
}
