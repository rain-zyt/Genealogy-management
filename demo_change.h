#ifndef DEMO_CHANGE_H
#define DEMO_CHANGE_H

#include <QDialog>
#include <QRegExpValidator>
#include "genealogy.h"
#include <QDate>
#include <QMessageBox>

namespace Ui {
class demo_change;
}

class demo_change : public QDialog
{
    Q_OBJECT

public:
    explicit demo_change(QWidget *parent = nullptr);
    ~demo_change();

    void getperson(genealogy *n);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::demo_change *ui;
    genealogy* s;
    person* temp_person;
};

#endif // DEMO_CHANGE_H
