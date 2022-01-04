#include "person_version.h"
#include "ui_person_version.h"

person_version::person_version(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::person_version)
{
    ui->setupUi(this);
}

person_version::~person_version()
{
    delete ui;
}

void person_version::on_pushButton_clicked()
{
    this->hide();
}

void person_version::set_result(person *result)
{
    QString name=QString(result[0].name.c_str());
    ui->name_box->setText(name);
    person *father=result[0].father;
    if(father!=nullptr)
    {
        QString fathername=QString(father[0].name.c_str());
        ui->father_box->setText(fathername);
    }
    else
    {
        ui->father_box->setText("无相关信息");
    }
    QString birthday=QString(result[0].birthday.c_str());
    ui->birthday_box->setText(birthday);
    QString deathday=QString(result[0].deathday.c_str());
    ui->deathday_box->setText(deathday);
    QString spousname=QString(result[0].spous.c_str());
    ui->spous_box->setText(spousname);
    if(!result[0].sex)
    {
        ui->sex_box->setText("男");
    }
    else
    {
        ui->sex_box->setText("女");
    }
}
