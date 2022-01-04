#include "demo_search.h"
#include "ui_demo_search.h"

demo_search::demo_search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::demo_search)
{
    ui->setupUi(this);
    QRegExp regx("[\u4e00-\u9fa5]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->name_box);
    ui->name_box->setValidator(validator);
}

demo_search::~demo_search()
{
    delete ui;
}

void demo_search::on_cancel_clicked()
{
    ui->name_box->clear();
    this->hide();
}

void demo_search::on_yes_clicked()
{
    emit send_search(ui->name_box->text());
    ui->name_box->clear();
    this->hide();
}
