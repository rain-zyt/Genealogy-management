#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <iostream>
#include <QDebug>

#include "demo_add.h"
#include "genealogy.h"
#include "demo_search.h"
#include "person_version.h"
#include "demo_del.h"
#include "demo_view.h"
#include "demo_change.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    demo_add *window_add=new demo_add(this);
    demo_del *window_del=new demo_del(this);
    demo_change *window_change=new demo_change(this);
    demo_search *window_search=new demo_search(this);
    person_version *window_search_result=new person_version(this);
    demo_view *window_view=new demo_view(this);
    genealogy *g1=new genealogy();

private slots:


    void on_exit_button_clicked();
    void getdata(QString name,QString father,QString spous,QDate birth1,QDate death1,bool sex1,bool is_dead);
    void on_add_clicked();
    void get_delete(QString name4);
    void get_search(QString name2);

    void on_delete_2_clicked();
    void on_search_clicked();


    void on_total_clicked();

    void on_show_clicked();

    void on_change_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
