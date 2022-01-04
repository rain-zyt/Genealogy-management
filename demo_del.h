#ifndef DEMO_DEL_H
#define DEMO_DEL_H

#include <QDialog>
#include <QDebug>
#include <QRegExpValidator>

namespace Ui {
class demo_del;
}


class demo_del : public QDialog
{
    Q_OBJECT

public:
    explicit demo_del(QWidget *parent = nullptr);
    ~demo_del();
signals:
    void send_del(QString name3);
private slots:
    void push_ok();

    void on_pushButton_clicked();

private:
    Ui::demo_del *ui;
};

#endif // DEMO_DEL_H
