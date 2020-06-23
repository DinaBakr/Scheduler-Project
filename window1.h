#ifndef WINDOW1_H
#define WINDOW1_H

#include <QDialog>
#include<QLabel>
#include <QtWidgets/QMainWindow>
#include <QMainWindow>
#include<vector>
using namespace std;

namespace Ui {
class window1;
}

class window1 : public QDialog
{
    Q_OBJECT

public:
    explicit window1(QString required_data,QString brust,QString arrival,QString quan,QString priority,QString type_sch,QWidget *parent = nullptr);
    ~window1();
    void setRequired_data(QString value);
    void set_brust(QString value);
    void set_arrival(QString value);
    void set_quan(QString value);
    void set_priority(QString value);
    void set_type_sch(QString value);

private slots:


private:
    Ui::window1 *ui;
    vector<QLabel*> labelss;
    vector<QLabel*> numb;
    QString required_data;
    QString brust;
    QString arrival;
    QString quan;
    QString priority;
    QString type_sch;

};

#endif // WINDOW1_H
