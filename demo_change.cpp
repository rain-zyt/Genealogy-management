#include "demo_change.h"
#include "ui_demo_change.h"

demo_change::demo_change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::demo_change)
{
    ui->setupUi(this);
    QRegExp regx("[\u4e00-\u9fa5]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit);
    ui->lineEdit->setValidator(validator);
}

demo_change::~demo_change()
{
    delete ui;
}

void demo_change::on_pushButton_clicked()
{
    if(s==nullptr)
    {
        cout<<"error"<<endl;
        return;
    }
    string temp_name=ui->lineEdit->text().toStdString();//g1->search(name4.toStdString())
    temp_person=s->search(temp_name);
    if(temp_person!=nullptr)
    {
    temp_person[0].deathday=ui->dateEdit->date().toString().toStdString();
    }
    else
    {
    QMessageBox::information(nullptr,"注意","查无此人",QMessageBox::Ok,QMessageBox::Ok);
    }
    ui->lineEdit->clear();
    this->hide();
}


void demo_change::on_pushButton_2_clicked()
{

    ui->lineEdit->clear();
    this->hide();
}

void demo_change::getperson(genealogy *n)
{
    s=n;
    cout<<"get successfully"<<endl;
}
