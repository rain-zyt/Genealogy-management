                #include "demo_del.h"
#include "ui_demo_del.h"


QString name_1;

demo_del::demo_del(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::demo_del)
{
    ui->setupUi(this);
    QRegExp regx("[\u4e00-\u9fa5]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit);
    ui->lineEdit->setValidator(validator);



    connect(ui->ok,SIGNAL(clicked()),this,SLOT(push_ok()),Qt::UniqueConnection);
}

demo_del::~demo_del()
{
    delete ui;
}

void demo_del::push_ok()
{
    emit send_del(ui->lineEdit->text());
    this->hide();
    ui->lineEdit->clear();
    //name_1=ui->lineEdit->text();
}




void demo_del::on_pushButton_clicked()
{
    this->hide();
    ui->lineEdit->clear();
}

