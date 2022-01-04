#ifndef DEMO_VIEW_H
#define DEMO_VIEW_H

#include <QDialog>
#include "person.h"
#include <QStandardItemModel>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringLiteral>
#include "genealogy.h"

namespace Ui {
class demo_view;
}

class demo_view : public QDialog
{
    Q_OBJECT

public:
    explicit demo_view(QWidget *parent = nullptr);
    void set_tree(genealogy *g);
    void build_tree(person *p,QTreeWidgetItem *father_node);
    ~demo_view();

private:
    Ui::demo_view *ui;
};

#endif // DEMO_VIEW_H
