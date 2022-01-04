#ifndef DEMO_SEARCH_H
#define DEMO_SEARCH_H

#include <QDialog>
#include <QRegExpValidator>

namespace Ui {
class demo_search;
}

class demo_search : public QDialog
{
    Q_OBJECT

public:
    explicit demo_search(QWidget *parent = nullptr);
    ~demo_search();

private slots:
    void on_cancel_clicked();
    void on_yes_clicked();

signals:
    void send_search(QString search_name);

private:
    Ui::demo_search *ui;
};

#endif // DEMO_SEARCH_H
