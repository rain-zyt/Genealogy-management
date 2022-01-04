#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QString name_1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    window_add->setWindowTitle("添加新成员");
    window_del->setWindowTitle("删除成员");
    window_search->setWindowTitle("查找成员");
    window_view->setWindowTitle("家谱显示");
    window_change->setWindowTitle("家族成员修改");
    //setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);


    connect(window_add,SIGNAL(send_date(QString,QString,QString,QDate,QDate,bool,bool)),this,SLOT(getdata(QString,QString,QString,QDate,QDate,bool,bool)),Qt::UniqueConnection);
    connect(window_del,SIGNAL(send_del(QString)),this,SLOT(get_delete(QString)));
    connect(window_search,SIGNAL(send_search(QString)),this,SLOT(get_search(QString)));
    connect(ui->change,SIGNAL(clicked()),window_change,SLOT(show()));
   }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_button_clicked()
{
    g1->~genealogy();
    this->close();
}

void MainWindow::getdata(QString name,QString father,QString spous,QDate birth1,QDate death1,bool sex1,bool is_dead){
    if(is_dead==0)
    {
    g1->addperson(name.toStdString(),father.toStdString(),sex1,birth1.toString().toStdString(),death1.toString().toStdString(),spous.toStdString());
    }
    else
    {
        g1->addperson(name.toStdString(),father.toStdString(),sex1,birth1.toString().toStdString(),"~",spous.toStdString());
    }
}


void MainWindow::on_add_clicked()
{

   window_add->show();
}

void MainWindow::on_delete_2_clicked()
{
    window_del->show();
}

void MainWindow::get_delete(QString name4)
{
    person* temp=g1->search(name4.toStdString());
    if(temp==nullptr)
    {
        QMessageBox::warning(NULL,"错误","查无此人",QMessageBox::Ok,QMessageBox::Ok);
    }
    g1->deleteperson(name4.toStdString());
}

void MainWindow::on_search_clicked()
{
    window_search->show();
}

void MainWindow::get_search(QString name2)
{
    person* temp;
    temp=g1->search(name2.toStdString());
    if(temp==nullptr)
    {
        QMessageBox::warning(nullptr,"","查无此人",QMessageBox::Ok,QMessageBox::Ok);
    }
    else
    {
        window_search_result->set_result(temp);
        window_search_result->show();
    }
}

void MainWindow::on_total_clicked()
{
    QString number=QString::number(g1->showpersonnum());
    QString alert_message="总人数：";
    alert_message+=number;
    alert_message+="人";
    QMessageBox::information(nullptr,"目前家族人数         ",number+"人",QMessageBox::Ok,QMessageBox::Ok);
}

void MainWindow::on_show_clicked()
{
    if(g1->showpersonnum()==0)
    {
        QMessageBox::warning(nullptr,"警告","家谱中没有成员",QMessageBox::Ok,QMessageBox::Ok);
        return;
    }
    window_view->set_tree(g1);
    window_view->show();
}



void MainWindow::on_change_clicked()
{

    window_change->getperson(g1);
    cout<<"below get operate"<<endl;
    window_change->show();
}

