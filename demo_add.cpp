#include "demo_add.h"
#include "ui_demo_add.h"

demo_add::demo_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::demo_add)
{
    ui->setupUi(this);
    QRegExp regx("[\u4e00-\u9fa5]+$");
    QValidator *validator = new QRegExpValidator(regx, this);
    ui->name->setValidator(validator);
    ui->father->setValidator(validator);
    ui->spous->setValidator(validator);
    ui->male->setChecked(true);
}

demo_add::~demo_add()
{
    delete ui;
}


void demo_add::on_cancel_button_clicked()
{
    this->hide();
    ui->name->clear();
    ui->father->clear();
    ui->spous->clear();
    ui->male->setChecked(true);
    ui->checkBox->setChecked(false);
}


void demo_add::on_male_clicked()
{
    if(ui->male->isChecked())
    {
        ui->female->setChecked(false);
    }
    else
    {
        ui->female->setChecked(true);
    }
}

void demo_add::on_female_clicked()
{
    if(ui->female->isChecked())
    {
        ui->male->setChecked(false);
    }
    else
    {
        ui->male->setChecked(true);
    }
}



void demo_add::on_yes_button_pressed()
{
    if(ui->male->isChecked())
    {
        sex=0;
    }
    else if(ui->female->isChecked())
    {
        sex=1;
    }
    else {
       QMessageBox::warning(NULL,"error","please check a sex",QMessageBox::Ok);
    }
    bool dead;
    if(ui->checkBox->isChecked())
    {
        dead=1;
    }
    else
    {
        dead=0;
    }
    emit send_date(ui->name->text(),ui->father->text(),ui->spous->text(),ui->birth->date(),ui->death->date(),sex,dead);
    this->hide();
    ui->name->clear();
    ui->father->clear();
    ui->spous->clear();
    ui->male->setChecked(true);
    ui->checkBox->setChecked(false);
}
