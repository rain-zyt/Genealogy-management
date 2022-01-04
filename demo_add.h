#ifndef DEMO_ADD_H
#define DEMO_ADD_H
#include"gene.h"
#include <QWidget>
#include <QMessageBox>
#include <QDate>
#include <QDialog>
#include <QDebug>

namespace Ui {
class demo_add;
}

class demo_add : public QDialog
{
    Q_OBJECT

public:
    explicit demo_add(QWidget *parent = nullptr);
    ~demo_add();



private slots:

    void on_cancel_button_clicked();

    void on_male_clicked();

    void on_female_clicked();


    void on_yes_button_pressed();

signals:
     void send_date(QString name,QString father,QString spous,QDate birth_day,QDate death_day,bool sexs,bool is_dead);

private:
    Ui::demo_add *ui;
    bool sex;
};

#endif // DEMO_ADD_H
