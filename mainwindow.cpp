#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<sstream>
#include<window1.h>
//#include <bits/stdc++.h>
#include <algorithm>
#include<cstdlib>
#include<stdio.h>
#include <cctype>
#include<cstring>
#include<QtCore>
#include<QString>
#include<QtGui>
#include<QMessageBox>
#include<QLineEdit>
#include<string>
#include<iostream>
#include <QtWidgets/QMainWindow>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("FCFS");//done
    ui->comboBox->addItem("SJF Preemptive");//done
    ui->comboBox->addItem("SJF Non Preemptive"); //done

    ui->comboBox->addItem("Priority Non Preemptive");//done
    ui->comboBox->addItem("Priority Preemptive");

    ui->comboBox->addItem("Round Robin");//done

}

MainWindow::~MainWindow()
{
    delete ui;
}

float findWaitingTime( int n,int bt[], int at[]);
void MainWindow::on_pushButton_clicked()
{
    QString number_pro=ui->no_processes->text();
    string w=number_pro.toStdString();
    int x=number_pro.toInt();
    QString brustt=ui->burst_time->text();
    QString arrivall=ui->arrival_time->text();
    QString quantum=ui->quantum_time->text();
    QString priority=ui->priorityy->text();
    QString type_sch=ui->comboBox->currentText();


    window1 *form=new window1(ui->no_processes->text(),brustt,arrivall,quantum,priority,type_sch);
    form->show();




}
