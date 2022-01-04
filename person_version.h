#ifndef PERSON_VERSION_H
#define PERSON_VERSION_H
#include "person.h"
#include<fstream>

#include <QDialog>

namespace Ui {
class person_version;
}

class person_version : public QDialog
{
    Q_OBJECT

public:
    explicit person_version(QWidget *parent = nullptr);
    ~person_version();
    void set_result(person* result);

private slots:
    void on_pushButton_clicked();

private:
    Ui::person_version *ui;

};

#endif // PERSON_VERSION_H
