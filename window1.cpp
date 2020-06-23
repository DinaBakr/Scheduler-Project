#include "window1.h"
#include "ui_window1.h"
#include "mainwindow.h"
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
#include<QPixmap>
#include<QMessageBox>


using namespace  std;
typedef struct proccess
{
    QString pro_id;
    float at, bt, pr, ct, ta, wt;


} process2;
struct psjf
{
       float bt,at,wt,st,tt,cbt;
       int pid;
};
int min(int at[],int n);
int max(int at[],int n);
float minn(float at[],int n);


/*pirority non*/
bool compare2(process2 a, process2 b);
bool compare(process2 a, process2 b);
float avgWT(int n, vector<process2>pro);
int avgWT_index_P(int n, vector<process2>pro);
float* avgWT_drawgantt(int n, vector<process2>pro);
QString* avgWT_namesdrawgantt(int n, vector<process2>pro);

/************/


/**FCFS DUMM**/


float avgWTT(int n, vector<process2>pro);
float* avgWT_gantt(int n, vector<process2>pro);
int avgWTT_mm(int n, vector<process2>pro);
QString* avgWT_id(int n, vector<process2>pro);

/*************/


/**SJF NON PREEM****/




typedef struct procsjfnon
{
    QString pro_id;
    float at, bt, ct, ta, wt;


}pnsjf;


bool compare2sjfnon(pnsjf a,pnsjf b);
bool comparesjfnon(pnsjf a,pnsjf b);
float avgWT_nonsjf(int n, vector<pnsjf>pro);
int avgWT_nonsjfmm(int n, vector<pnsjf>pro);
float* avgWT_flogh(int n, vector<pnsjf>pro);
QString* avgWT_flogh_gh(int n, vector<pnsjf>pro);

/*******************************/


/*********RR******/

float roundRobin(int p[],int a[],int b[],int n,int pn);
int print_array(vector<int>n,int t);
vector<int> round_Robin(int p[],int a[],int b[],int n,int pn);
int* roundRobinwaiting(int p[],int a[],int b[],int n,int pn) ;
int round_Robin_max(int p[],int a[],int b[],int n,int pn);

int round_Robin_number(int p[],int a[],int b[],int n,int pn);


/************************/


/***SJF PREEM**/

struct procsjfpreeem
{
       float bt,at,wt,st,tt,cbt;
       int pid;
};

int get(procsjfpreeem proc[],int t,int n);
vector<int> bta3et_seq(procsjfpreeem proc[],int p[],int n,int nop);
vector<float> bta3et_elarqaam (procsjfpreeem proc[],int p[],int n,int nop);
float bta3_elwa2t(procsjfpreeem proc[],int p[],int n,int nop);
int iscomplite(procsjfpreeem proc[],int n);
int index_sjfpreem(procsjfpreeem proc[],int p[],int n,int nop);
/**********************************/

bool isNumber(string s);
int charCheck(string input_char ,int n) ;

/********prior preem***/
struct procpirpreem
{
       float bt,at,wt,st,tt,cbt;
       int pr,pid;
};
int get_prior(procpirpreem proc[],int t,int n);
vector<float> ana_elarqam(procpirpreem proc[],int p[],int n,int nop);
float ana_elavwt(procpirpreem proc[],int p[],int n,int nop);
int arefinish(procpirpreem proc[],int n);
vector<int> ana_elseq(procpirpreem proc[],int p[],int n,int nop);
bool IsNumericDigit(const string strr);



/*******RR New****/
typedef struct process_RB
{
    QString pro_id;
    float st, ct, at, bt, ta, wt;


}process;
bool compare_at(process_RB a, process_RB b);
int avgWT_RB_INDEX(int n, int quantum, vector<process_RB>pro);
vector<QString> avgWT_RB_PID(int n, int quantum, vector<process_RB>pro);
vector<float> avgWT_RB_VEFLO(int n, int quantum, vector<process_RB>pro);
float avgWT_RB(int n, int quantum, vector<process_RB>pro);

window1::window1(QString required_data,QString brust,QString arrival,QString quan,QString priority,QString type_sch,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window1)
{
    ui->setupUi(this);
    QPixmap pix(":/image/pic_sc.png");
    ui->label_pic->setPixmap(pix.scaled(181,211,Qt::KeepAspectRatio));
    //ui->label_2->setText(required_data);
    //string w=required_data.toStdString();
    string b=brust.toStdString();
    string a=arrival.toStdString();
    //string q=quan.toStdString();
    string p=priority.toStdString();
    string type_of_sch=type_sch.toStdString();
    int x=required_data.toInt();
    int q=quan.toInt();
   //process* proc=new process[x];
    string q_test= quan.toStdString();
    proccess* proc=new proccess[x];
    int flag =0;





    if(type_of_sch=="FCFS"){


            vector<float>bursttime;
            vector<float>arrivaltime;


            vector<string> burst_time_str;
            vector<string> arrival_time_str;
            stringstream ss(b);

            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                burst_time_str.push_back(substr);
            }

            stringstream aa(a);

            while (aa.good()) {
                string substr;
                getline(aa, substr, ',');
                arrival_time_str.push_back(substr);
            }



            for (int m = 0; m<x; m++) {
                bursttime.push_back(atof(burst_time_str[m].c_str()));
                arrivaltime.push_back(atof(arrival_time_str[m].c_str()));
            }


for(int jp=0;jp<x;jp++)
{
//bool IsNumericDigit(const string strr)
    if((IsNumericDigit(burst_time_str[jp]) == 0 || IsNumericDigit(arrival_time_str[jp] )==0 || p.length() !=0 ||q_test.length() !=0))
        {
         QMessageBox:: warning(this,"Warning","Invaild inputs please check your inputs");
         break;
       }
    else if(   IsNumericDigit(burst_time_str[jp] )==true || IsNumericDigit(arrival_time_str[jp] )==true)
    {
        break;
    }
}
            vector<process2>pro;
            pro.clear();
            process2 mypoint;
            for (int i = 0; i<x; i++)
            {

                //mypoint.pro_id = "  P" + to_string(i + 1);
                mypoint.pro_id= "P" +QString::fromStdString(to_string(i + 1));
                mypoint.at = arrivaltime[i];
                mypoint.bt = bursttime[i];
                pro.push_back(mypoint);
            }

            sort(pro.begin(), pro.end(), compare);
            //cout << "avg time is " << avgWT(n, pro);
            int num_index=avgWTT_mm(x,pro);
            cout<<num_index;
            for (int i=0;i<=num_index;i++)
               {  if(i==num_index)
                   {
                       labelss.push_back(new QLabel(" ",this));
                       labelss[i]->setMinimumWidth(1000);
                       labelss[i]->setAutoFillBackground(true);
                       ui->horizontalLayout->addWidget(labelss[i]);
                       ui->horizontalLayout->setSpacing(0);
                   }
                   else
                   {
                   QString* arr=avgWT_id(x, pro);
                   QString temp=QString("%1").arg(arr[i]);
                   labelss.push_back(new QLabel(temp,this));
                    QPalette color1,color2;
                    color1.setColor(QPalette::Window,Qt::blue);
                    color2.setColor(QPalette::Window,Qt::white);
                    labelss[i]->setMinimumWidth(1000);
                    labelss[i]->setAutoFillBackground(true);

                    if(flag==0)
                    {
                        labelss[i]->setPalette(color1);
                        flag=1;
                    }

                    else if(flag==1)
                    {
                        labelss[i]->setPalette(color2);
                        flag=0;

                    }


                    ui->horizontalLayout->addWidget(labelss[i]);
                    ui->horizontalLayout->setSpacing(0);

                    }



               }
                float d= avgWTT(x,pro);
                float *kj=avgWT_gantt(x,pro);
                 //ui->label_2->setNum(d);

                QString t_p=QString ("%1 msec").arg(d);
                  ui->label_2->setText(t_p);
                 for (int y=0;y<num_index+1;y++)//for drawing
                 {
                     if(y==0)
                     {
                        // float jk=minn(arrivaltime,x)
                         numb.push_back(new QLabel(QString::number(0),this));
                         numb[y]->setMinimumWidth(1000);
                         numb[y]->setAutoFillBackground(true);
                         ui->horizontalLayout_2->addWidget(numb[y]);
                         ui->horizontalLayout_2->setSpacing(0);

                     }

            else{
                      numb.push_back(new QLabel(QString::number(kj[y-1]),this));
                      numb[y]->setMinimumWidth(1000);
                      numb[y]->setAutoFillBackground(true);
                      ui->horizontalLayout_2->addWidget(numb[y]);
                      ui->horizontalLayout_2->setSpacing(0);
            }
                 }




    }


    /*  PRIORITY NON PREEMPTIVE DONNNNNNNNE*/

    else if(type_of_sch=="Priority Non Preemptive")
    {
        vector<float>bursttime;
        vector<float>arrivaltime;
        vector<float>priority;

        vector<string> burst_time_str;
        vector<string> arrival_time_str;
        vector<string>priority_str;

        stringstream ss(b);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            burst_time_str.push_back(substr);
        }

        stringstream aa(a);

        while (aa.good()) {
            string substr;
            getline(aa, substr, ',');
            arrival_time_str.push_back(substr);
        }

        stringstream pp(p);

        while (pp.good()) {
            string substr;
            getline(pp, substr, ',');
            priority_str.push_back(substr);
        }

        for (int m = 0; m<x; m++) {
            bursttime.push_back(atof(burst_time_str[m].c_str()));
        }

        for (int m = 0; m<x; m++) {
            arrivaltime.push_back(atof(arrival_time_str[m].c_str()));
        }

        for (int m = 0; m<x; m++) {
            priority.push_back(atof(priority_str[m].c_str()));
        }


        for(int jp=0;jp<x;jp++)
        {
        //bool IsNumericDigit(const string strr)
            if((IsNumericDigit(burst_time_str[jp]) == 0 || IsNumericDigit(arrival_time_str[jp] )==0 || p.length() ==0 ||q_test.length() !=0))
                {
                 QMessageBox:: warning(this,"Warning","Invaild inputs please check your inputs");
                 break;
               }
            else if(   IsNumericDigit(burst_time_str[jp] )==true || IsNumericDigit(arrival_time_str[jp] )==true)
            {
                break;
            }
        }




        vector<process2>pro;
        pro.clear();
        process2 mypoint;
        for (int i = 0; i<x; i++)
        {

            mypoint.pro_id= "P" +QString::fromStdString(to_string(i + 1));
            mypoint.at = arrivaltime[i];
            mypoint.bt = bursttime[i];
            mypoint.pr = priority[i];
            pro.push_back(mypoint);
        }

        sort(pro.begin(), pro.end(), compare);

       int f=avgWT_index_P(x,pro);

   for (int i=0;i<=f;i++)
   {  if(i==f)
       {
           labelss.push_back(new QLabel(" ",this));
           labelss[i]->setMinimumWidth(1000);
           labelss[i]->setAutoFillBackground(true);
           ui->horizontalLayout->addWidget(labelss[i]);
           ui->horizontalLayout->setSpacing(0);
       }
       else
       {
       QString* arr=avgWT_namesdrawgantt(x, pro);
       QString temp=QString("%1").arg(arr[i]);
       labelss.push_back(new QLabel(temp,this));
        QPalette color1,color2;
        color1.setColor(QPalette::Window,Qt::blue);
        color2.setColor(QPalette::Window,Qt::white);
        labelss[i]->setMinimumWidth(1000);
        labelss[i]->setAutoFillBackground(true);

        if(flag==0)
        {
            labelss[i]->setPalette(color1);
            flag=1;
        }

        else if(flag==1)
        {
            labelss[i]->setPalette(color2);
            flag=0;

        }


        ui->horizontalLayout->addWidget(labelss[i]);
        ui->horizontalLayout->setSpacing(0);

        }



   }
    float d= avgWT(x,pro);
    float *kj=avgWT_drawgantt(x,pro);
     //ui->label_2->setNum(d);

    QString t_p=QString ("%1 msec").arg(d);
      ui->label_2->setText(t_p);
     for (int y=0;y<f+1;y++)//for drawing
     {
         if(y==0)
         {
            // float jk=minn(arrivaltime,x)
             numb.push_back(new QLabel(QString::number(0),this));
             numb[y]->setMinimumWidth(1000);
             numb[y]->setAutoFillBackground(true);
             ui->horizontalLayout_2->addWidget(numb[y]);
             ui->horizontalLayout_2->setSpacing(0);

         }

else{
          numb.push_back(new QLabel(QString::number(kj[y-1]),this));
          numb[y]->setMinimumWidth(1000);
          numb[y]->setAutoFillBackground(true);
          ui->horizontalLayout_2->addWidget(numb[y]);
          ui->horizontalLayout_2->setSpacing(0);
}
     }


    }



/*       A5RHAAAAAAAAAAAAAAAAAAAAAAAAA      :D */

    else if(type_of_sch=="SJF Non Preemptive")
    {

//        int n, i;
//        cin >> n;
//        string b_t; //burst_time
//        cin >> b_t;
//        string a_t; // arrival time
//        cin >> a_t;


        vector<float>bursttime;
        vector<float>arrivaltime;
        vector<float>priority;

        vector<string> burst_time_str;
        vector<string> arrival_time_str;
        vector<string>priority_str;

        stringstream ss(b);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            burst_time_str.push_back(substr);
        }

        stringstream aa(a);

        while (aa.good()) {
            string substr;
            getline(aa, substr, ',');
            arrival_time_str.push_back(substr);
        }


        for (int m = 0; m<x; m++) {
            bursttime.push_back(atof(burst_time_str[m].c_str()));
        }

        for (int m = 0; m<x; m++) {
            arrivaltime.push_back(atof(arrival_time_str[m].c_str()));
        }
        for(int jp=0;jp<x;jp++)
        {
        //bool IsNumericDigit(const string strr)
            if((IsNumericDigit(burst_time_str[jp]) == 0 || IsNumericDigit(arrival_time_str[jp] )==0 || p.length() !=0 ||q_test.length() !=0))
                {
                 QMessageBox:: warning(this,"Warning","Invaild inputs please check your inputs");
                 break;
               }
            else if(   IsNumericDigit(burst_time_str[jp] )==true || IsNumericDigit(arrival_time_str[jp] )==true)
            {
                break;
            }
        }
        vector<pnsjf>pro;
        pro.clear();
        pnsjf mypoint;
        for (int i = 0; i<x; i++)
        {

           // mypoint.pro_id = "  P" + to_string(i + 1);
            mypoint.pro_id= "   P" +QString::fromStdString(to_string(i + 1));
            mypoint.at = arrivaltime[i];
            mypoint.bt = bursttime[i];
            pro.push_back(mypoint);
        }

        sort(pro.begin(), pro.end(), comparesjfnon);
        //cout << "avg time is " << avgWT(n, pro);
        int num_index=avgWT_nonsjfmm(x,pro);
        cout<<num_index;
        for (int i=0;i<=num_index;i++)
           {  if(i==num_index)
               {
                   labelss.push_back(new QLabel(" ",this));
                   labelss[i]->setMinimumWidth(1000);
                   labelss[i]->setAutoFillBackground(true);
                   ui->horizontalLayout->addWidget(labelss[i]);
                   ui->horizontalLayout->setSpacing(0);
               }
               else
               {
               QString* arr=avgWT_flogh_gh(x, pro);
               QString temp=QString("%1").arg(arr[i]);
               labelss.push_back(new QLabel(temp,this));
                QPalette color1,color2;
                color1.setColor(QPalette::Window,Qt::blue);
                color2.setColor(QPalette::Window,Qt::white);
                labelss[i]->setMinimumWidth(1000);
                labelss[i]->setAutoFillBackground(true);

                if(flag==0)
                {
                    labelss[i]->setPalette(color1);
                    flag=1;
                }

                else if(flag==1)
                {
                    labelss[i]->setPalette(color2);
                    flag=0;

                }


                ui->horizontalLayout->addWidget(labelss[i]);
                ui->horizontalLayout->setSpacing(0);

                }



           }
            float d= avgWT_nonsjf(x,pro);
            float *kj=avgWT_flogh(x,pro);
             //ui->label_2->setNum(d);

            QString t_p=QString ("%1 msec").arg(d);
              ui->label_2->setText(t_p);
             for (int y=0;y<num_index+1;y++)//for drawing
             {
                 if(y==0)
                 {
                    // float jk=minn(arrivaltime,x)
                     numb.push_back(new QLabel(QString::number(0),this));
                     numb[y]->setMinimumWidth(1000);
                     numb[y]->setAutoFillBackground(true);
                     ui->horizontalLayout_2->addWidget(numb[y]);
                     ui->horizontalLayout_2->setSpacing(0);

                 }

        else{
                  numb.push_back(new QLabel(QString::number(kj[y-1]),this));
                  numb[y]->setMinimumWidth(1000);
                  numb[y]->setAutoFillBackground(true);
                  ui->horizontalLayout_2->addWidget(numb[y]);
                  ui->horizontalLayout_2->setSpacing(0);
        }
             }

}
//    else if(type_of_sch=="Round Robin")
//    {


//         int *burst_time ;
//        burst_time = new int [x];
//           int *arrival_time ;
//        arrival_time = new int [x];

//             int *proc ;
//             proc = new int [x];

//            vector<string> burst_time_str;
//            vector<string> arrival_time_str;


//        stringstream ss(b);

//         while (ss.good()) {
//            string substr;
//            getline(ss, substr, ',');
//            burst_time_str.push_back(substr);
//        }

//         stringstream aa(a);

//         while (aa.good()) {
//            string substr;
//            getline(aa, substr, ',');
//            arrival_time_str.push_back(substr);
//        }

//       for(int m=0;m<x;m++){
//        burst_time[m]=atoi(burst_time_str[m].c_str());

//        }

//        for(int m=0;m<x;m++){
//        arrival_time[m]=atoi(arrival_time_str[m].c_str());
//        }

//         for(int m=0;m<x;m++){
//             proc[m]=m+1;
//         }
//        cout<< roundRobin(proc,arrival_time,burst_time,q,x);
//        for(int jp=0;jp<x;jp++)
//        {
//        //bool IsNumericDigit(const string strr)
//            if((IsNumericDigit(burst_time_str[jp]) == 0 || IsNumericDigit(arrival_time_str[jp] )==0 || p.length() !=0 ||q_test.length() ==0))
//                {
//                 QMessageBox:: warning(this,"Warning","Invaild inputs please check your inputs");
//                 break;
//               }
//            else if(   IsNumericDigit(burst_time_str[jp] )==true || IsNumericDigit(arrival_time_str[jp] )==true)
//            {
//                break;
//            }
//        }

//    int numbb=round_Robin_number(proc,arrival_time,burst_time,q,x);
//        for (int i=0;i<=numbb;i++)
//        {
//            if(i==numbb)
//            {
//                labelss.push_back(new QLabel(" ",this));
//                labelss[i]->setMinimumWidth(1000);
//                labelss[i]->setAutoFillBackground(true);
//                ui->horizontalLayout->addWidget(labelss[i]);
//                ui->horizontalLayout->setSpacing(0);
//            }

//            else
//            {

//              vector<int> pp =round_Robin(proc,arrival_time,burst_time,q,x);
//            labelss.push_back(new QLabel("P"+QString::number(pp[i]),this));
//             QPalette color1,color2;
//             color1.setColor(QPalette::Window,Qt::blue);
//             color2.setColor(QPalette::Window,Qt::white);
//             labelss[i]->setMinimumWidth(1000);
//             labelss[i]->setAutoFillBackground(true);


//             if(flag==0)
//             {
//                 labelss[i]->setPalette(color1);
//                 flag=1;
//             }

//             else if(flag==1)
//             {
//                 labelss[i]->setPalette(color2);
//                 flag=0;

//             }


//             ui->horizontalLayout->addWidget(labelss[i]);
//             ui->horizontalLayout->setSpacing(0);

//             }



//        }
//         float d= roundRobin( proc,arrival_time,burst_time,q,x);
//          int* kj=roundRobinwaiting(proc,arrival_time,burst_time,q,x);
//          QString t_p=QString ("%1 msec").arg(d);
//        ui->label_2->setText(t_p);
//        // float d=findWaitingTime(x,  burst_time,arrival_time);
//          //ui->label_2->setNum(d);

//          for (int y=0;y<numbb+1;y++)//for drawing
//          {
//              if(y==0)
//              {
//                  int b=min(arrival_time,x);
//                  numb.push_back(new QLabel(QString::number(b),this));
//                  numb[y]->setMinimumWidth(1000);
//                  numb[y]->setAutoFillBackground(true);
//                  ui->horizontalLayout_2->addWidget(numb[y]);
//                  ui->horizontalLayout_2->setSpacing(0);
//              }
//              else if(y==numbb)
//              {
//                  int l=round_Robin_max(proc,arrival_time,burst_time,q,x);
//                  numb.push_back(new QLabel(QString::number(l),this));
//                  numb[y]->setMinimumWidth(1000);
//                  numb[y]->setAutoFillBackground(true);
//                  ui->horizontalLayout_2->addWidget(numb[y]);
//                  ui->horizontalLayout_2->setSpacing(0);
//              }
//              else
//              {

//               numb.push_back(new QLabel(" ",this));
//               numb[y]->setMinimumWidth(1000);
//               numb[y]->setAutoFillBackground(true);
//               ui->horizontalLayout_2->addWidget(numb[y]);
//               ui->horizontalLayout_2->setSpacing(0);
//              }
//          }
//    }
    else if(type_of_sch=="SJF Preemptive")
    {
         //  int n;
            /*
            vector<int> seq;
            vector<float> gant_chart_nums;*/
            int i;
            int aba,t=0;
    //        cin >> n ;
    //        string bt; //burst_time
    //        cin >> bt;
    //        string at; // arrival time
    //        cin >>at;

             float *burst_time ;
            burst_time = new float [x];
              float *arrival_time ;
            arrival_time = new float [x];

                 vector<string> burst_time_str;
                 vector<string> arrival_time_str;
               stringstream ss(b);

            while (ss.good()) {
               string substr;
               getline(ss, substr, ',');
               burst_time_str.push_back(substr);
           }

            stringstream aa(a);

            while (aa.good()) {
               string substr;
               getline(aa, substr, ',');
               arrival_time_str.push_back(substr);
           }

       for(int m=0;m<x;m++){
           burst_time[m]=atof(burst_time_str[m].c_str());
           }

           for(int m=0;m<x;m++){
           arrival_time[m]=atof(arrival_time_str[m].c_str());
           }
           int sum =0;
           for (int i=0;i<x;i++)
           {
               sum = sum+burst_time[i];
           }
           for(int jp=0;jp<x;jp++)
           {
           //bool IsNumericDigit(const string strr)
               if((IsNumericDigit(burst_time_str[jp]) == 0 || IsNumericDigit(arrival_time_str[jp] )==0 || p.length() !=0 ||q_test.length() !=0))
                   {
                    QMessageBox:: warning(this,"Warning","Invaild inputs please check your inputs");
                    break;
                  }
               else if(   IsNumericDigit(burst_time_str[jp] )==true || IsNumericDigit(arrival_time_str[jp] )==true)
               {
                   break;
               }
           }
          procsjfpreeem *prosjfpre_1;
          prosjfpre_1 = new procsjfpreeem [x];
           for(int i=0;i<x;i++)
           {
               prosjfpre_1[i].pid=i+1;
               prosjfpre_1[i].at=arrival_time[i];
               prosjfpre_1[i].bt=burst_time[i];
               prosjfpre_1[i].cbt=burst_time[i];
               prosjfpre_1[i].st=0;
               prosjfpre_1[i].tt=burst_time[i];
               prosjfpre_1[i].wt=0;
           }

              int p[100];
              //float avgwt=0,avgtt=0;
              i=0;
              while(1)
              {
                     if(iscomplite(prosjfpre_1,x))
                            break;
                     aba=get(prosjfpre_1,t,x);
                     p[i]=aba;
                     prosjfpre_1[aba].bt-=1;
                     if(prosjfpre_1[aba].bt==0)
                            prosjfpre_1[aba].st=1;
                     t=t+1;
                     i++;

              }

                  vector<int> zefttt;
              zefttt=bta3et_seq(prosjfpre_1,p,i,x);


                    for (auto itxx = zefttt.begin(); itxx != zefttt.end(); ++itxx)
                       cout << " " << *itxx;


                       vector<float> helwww;
              helwww=bta3et_elarqaam(prosjfpre_1,p,i,x);


                    for (auto itx = helwww.begin(); itx != helwww.end(); ++itx)
                       cout << " " << *itx;



                       //float xe;
                       //xe=bta3_elwa2t(prosjfpre_1,p,i,x);
                      //cout<<xe;
//vector <int> torp=bta3et_seq(prosjfpre_1,p,i,x);
int hko=zefttt.size();
           // int hko=index_sjfpreem(prosjfpre_1,p,i,x);
            //int hko=hk/2;
           // cout<<endl<<hko<<"TO VIEW";
                       for (int i=0;i<=hko;i++)
                          {  if(i==hko)
                              {
                                  labelss.push_back(new QLabel(" ",this));
                                  labelss[i]->setMinimumWidth(1000);
                                  labelss[i]->setAutoFillBackground(true);
                                  ui->horizontalLayout->addWidget(labelss[i]);
                                  ui->horizontalLayout->setSpacing(0);
                              }
                              else
                              {
                               vector <int> nhj=bta3et_seq(prosjfpre_1,p,i,x);
                              //QString* arr=avgWT_flogh_gh(x, pro);
                             // QString temp=QString("%1").arg(arr[i]);
                              labelss.push_back(new QLabel("P"+QString::number(nhj[i]),this));
                               QPalette color1,color2;
                               color1.setColor(QPalette::Window,Qt::blue);
                               color2.setColor(QPalette::Window,Qt::white);
                               labelss[i]->setMinimumWidth(1000);
                               labelss[i]->setAutoFillBackground(true);

                               if(flag==0)
                               {
                                   labelss[i]->setPalette(color1);
                                   flag=1;
                               }

                               else if(flag==1)
                               {
                                   labelss[i]->setPalette(color2);
                                   flag=0;

                               }


                               ui->horizontalLayout->addWidget(labelss[i]);
                               ui->horizontalLayout->setSpacing(0);

                               }



                          }
                           float d= bta3_elwa2t(prosjfpre_1,p,i,x);
                           vector<float> kj=bta3et_elarqaam(prosjfpre_1,p,i,x);
                            ui->label_2->setNum(d);

                           QString t_p=QString ("%1 msec").arg(d);
                             ui->label_2->setText(t_p);
                            for (int y=0;y<hko+1;y++)//for drawing
                            {
                                if(y==0)
                                {
                                   float jk=minn(arrival_time,x);
                                    numb.push_back(new QLabel(QString::number(jk),this));
                                    numb[y]->setMinimumWidth(1000);
                                    numb[y]->setAutoFillBackground(true);
                                    ui->horizontalLayout_2->addWidget(numb[y]);
                                    ui->horizontalLayout_2->setSpacing(0);

                                }
                      else{
                                 numb.push_back(new QLabel(QString::number(kj[y-1]),this));
                                 numb[y]->setMinimumWidth(1000);
                                 numb[y]->setAutoFillBackground(true);
                                 ui->horizontalLayout_2->addWidget(numb[y]);
                                 ui->horizontalLayout_2->setSpacing(0);
                       }
                          }



                            delete [] arrival_time;
                            delete [] burst_time;
                            delete [] prosjfpre_1;

        }

    else if(type_of_sch=="Priority Preemptive")
    {
    //    int n;
        int i,abq,t=0;
//        cin >> n ;
//        string bt; //burst_time
//        cin >> bt;
//        string at; // arrival time
//        cin >>at;
//        string pri;// priority
//        cin >> pri;

         float *burst_time ;
        burst_time = new float [x];
          float *arrival_time ;
        arrival_time = new float [x];
           float *priority ;
        priority = new float [x];

             vector<string> burst_time_str;
             vector<string> arrival_time_str;
             vector<string> priority_str;
           stringstream ss(b);

        while (ss.good()) {
           string substr;
           getline(ss, substr, ',');
           burst_time_str.push_back(substr);
       }

        stringstream aa(a);

        while (aa.good()) {
           string substr;
           getline(aa, substr, ',');
           arrival_time_str.push_back(substr);
       }


        stringstream kk(p);

        while (kk.good()) {
           string substr;
           getline(kk, substr, ',');
           priority_str.push_back(substr);
       }

       for(int m=0;m<x;m++){
       burst_time[m]=atof(burst_time_str[m].c_str());
       }

       for(int m=0;m<x;m++){
       arrival_time[m]=atof(arrival_time_str[m].c_str());
       }

       for(int m=0;m<x;m++){
       priority[m]=atof(priority_str[m].c_str());
       }

       for(int jp=0;jp<x;jp++)
       {
       //bool IsNumericDigit(const string strr)
           if((IsNumericDigit(burst_time_str[jp]) == 0 || IsNumericDigit(arrival_time_str[jp] )==0 || p.length() ==0 ||q_test.length() !=0))
               {
                QMessageBox:: warning(this,"Warning","Invaild inputs please check your inputs");
                break;
              }
           else if(   IsNumericDigit(burst_time_str[jp] )==true || IsNumericDigit(arrival_time_str[jp] )==true)
           {
               break;
           }
       }
       procpirpreem*proc=new procpirpreem[x];

       //vector<procpirpreem> proc;
       //procpirpreem the_proc ;
       //int lenghthh = proc.size();
       for(int i=0;i<x;i++)
       {
           proc[i].pid=i+1;
           proc[i].at=arrival_time[i];
           proc[i].bt=burst_time[i];
           proc[i].cbt=burst_time[i];
           proc[i].st=0;
           proc[i].tt=burst_time[i];
           proc[i].wt=0;
           proc[i].pr=priority[i];

       }

          int p[100];
          float avgwt=0,avgtt=0;
          i=0;
          while(1)
          {
                 if(arefinish(proc,x))
                        break;
                 abq=get_prior(proc,t,x);
                 p[i]=abq;
                 proc[abq].bt-=1;
                 if(proc[abq].bt==0)
                        proc[abq].st=1;
                 t=t+1;
                 i++;
          }
          //gantt_chart(proc,p,i,n);
          vector<int> gogo=ana_elseq(proc,p,i,x);
            for (auto itxx = gogo.begin(); itxx != gogo.end(); ++itxx)
                   cout << " " << *itxx;
                   cout << endl;
                   vector<float> soso=ana_elarqam(proc,p,i,x);
            for (auto itx =soso.begin(); itx != soso.end(); ++itx)
                   cout << " " << *itx;
                   cout << endl ;
                   float hohoz;
                   hohoz=ana_elavwt(proc,p,i,x);
                   int hkoo=gogo.size();

                                          for (int i=0;i<=hkoo;i++)
                                             {  if(i==hkoo)
                                                 {
                                                     labelss.push_back(new QLabel(" ",this));
                                                     labelss[i]->setMinimumWidth(1000);
                                                     labelss[i]->setAutoFillBackground(true);
                                                     ui->horizontalLayout->addWidget(labelss[i]);
                                                     ui->horizontalLayout->setSpacing(0);
                                                 }
                                                 else
                                                 {
                                              //    vector <int> nhjj=ana_elseq(proc,p,i,x);
                                                 //QString* arr=avgWT_flogh_gh(x, pro);
                                                // QString temp=QString("%1").arg(arr[i]);
                                                 labelss.push_back(new QLabel("P"+QString::number(gogo[i]),this));
                                                  QPalette color1,color2;
                                                  color1.setColor(QPalette::Window,Qt::blue);
                                                  color2.setColor(QPalette::Window,Qt::white);
                                                  labelss[i]->setMinimumWidth(1000);
                                                  labelss[i]->setAutoFillBackground(true);

                                                  if(flag==0)
                                                  {
                                                      labelss[i]->setPalette(color1);
                                                      flag=1;
                                                  }

                                                  else if(flag==1)
                                                  {
                                                      labelss[i]->setPalette(color2);
                                                      flag=0;

                                                  }


                                                  ui->horizontalLayout->addWidget(labelss[i]);
                                                  ui->horizontalLayout->setSpacing(0);

                                                  }



                                             }
                                             // float d= ana_elavwt(proc,p,i,x);
                                              //vector<float> kjj=ana_elarqam(proc,p,i,x);
                                              // ui->label_2->setNum(hohoz);

                                              QString t_p=QString ("%1 msec").arg(hohoz);
                                                ui->label_2->setText(t_p);
                                               for (int y=0;y<hkoo+1;y++)//for drawing
                                               {
                                                   if(y==0)
                                                   {
                                                      float jk=minn(arrival_time,x);
                                                       numb.push_back(new QLabel(QString::number(jk),this));
                                                       numb[y]->setMinimumWidth(1000);
                                                       numb[y]->setAutoFillBackground(true);
                                                       ui->horizontalLayout_2->addWidget(numb[y]);
                                                       ui->horizontalLayout_2->setSpacing(0);

                                                   }
                                         else{
                                                    numb.push_back(new QLabel(QString::number(soso[y-1]),this));
                                                    numb[y]->setMinimumWidth(1000);
                                                    numb[y]->setAutoFillBackground(true);
                                                    ui->horizontalLayout_2->addWidget(numb[y]);
                                                    ui->horizontalLayout_2->setSpacing(0);
                                          }
                                             }




    }

else if(type_of_sch=="Round Robin")
    {




            vector<float>bursttime;
            vector<float>arrivaltime;


            vector<string> burst_time_str;
            vector<string> arrival_time_str;

            stringstream ss(b);

            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                burst_time_str.push_back(substr);
            }

            stringstream aa(a);

            while (aa.good()) {
                string substr;
                getline(aa, substr, ',');
                arrival_time_str.push_back(substr);
            }


            for (int m = 0; m<x; m++) {
                bursttime.push_back(atof(burst_time_str[m].c_str()));
            }

            for (int m = 0; m<x; m++) {
                arrivaltime.push_back(atof(arrival_time_str[m].c_str()));
            }

            for(int jp=0;jp<x;jp++)
            {
            //bool IsNumericDigit(const string strr)
                if((IsNumericDigit(burst_time_str[jp]) == 0 || IsNumericDigit(arrival_time_str[jp] )==0 || p.length() !=0 ||q_test.length() ==0))
                    {
                     QMessageBox:: warning(this,"Warning","Invaild inputs please check your inputs");
                     break;
                   }
                else if(   IsNumericDigit(burst_time_str[jp] )==true || IsNumericDigit(arrival_time_str[jp] )==true)
                {
                    break;
                }
            }


            vector<process_RB>pro;
            pro.clear();
            process_RB mypoint;
            for (int i = 0; i<x; i++)
            {

               // mypoint.pro_id = "  P" + to_string(i + 1);
                mypoint.pro_id= "P" +QString::fromStdString(to_string(i + 1));
                mypoint.at = arrivaltime[i];
                mypoint.bt = bursttime[i];
                pro.push_back(mypoint);
            }

            sort(pro.begin(), pro.end(), compare_at);


     //cout << "avg time is " << avgWT_RB(x, q, pro);

            //cout<<num_index;
            int num_index=avgWT_RB_INDEX(x,q,pro);
            for (int i=0;i<=num_index;i++)
               {  if(i==num_index)
                   {
                       labelss.push_back(new QLabel(" ",this));
                       labelss[i]->setMinimumWidth(1000);
                       labelss[i]->setAutoFillBackground(true);
                       ui->horizontalLayout->addWidget(labelss[i]);
                       ui->horizontalLayout->setSpacing(0);
                   }
                   else
                   {
                  vector<QString> arr=avgWT_RB_PID(x,q,pro);
                   QString temp=QString("%1").arg(arr[i]);
                   labelss.push_back(new QLabel(temp,this));
                    QPalette color1,color2;
                    color1.setColor(QPalette::Window,Qt::blue);
                    color2.setColor(QPalette::Window,Qt::white);
                    labelss[i]->setMinimumWidth(1000);
                    labelss[i]->setAutoFillBackground(true);

                    if(flag==0)
                    {
                        labelss[i]->setPalette(color1);
                        flag=1;
                    }

                    else if(flag==1)
                    {
                        labelss[i]->setPalette(color2);
                        flag=0;

                    }


                    ui->horizontalLayout->addWidget(labelss[i]);
                    ui->horizontalLayout->setSpacing(0);

                    }



               }
                float d= avgWT_RB(x,q,pro);
                vector<float> kj=avgWT_RB_VEFLO(x,q,pro);
                 //ui->label_2->setNum(d);

                QString t_p=QString ("%1 msec").arg(d);
                  ui->label_2->setText(t_p);
                 for (int y=0;y<num_index+1;y++)//for drawing
                 {
                     if(y==0)
                     {
                        // float jk=minn(arrivaltime,x)
                         numb.push_back(new QLabel(QString::number(0),this));
                         numb[y]->setMinimumWidth(1000);
                         numb[y]->setAutoFillBackground(true);
                         ui->horizontalLayout_2->addWidget(numb[y]);
                         ui->horizontalLayout_2->setSpacing(0);

                     }

            else{
                      numb.push_back(new QLabel(QString::number(kj[y-1]),this));
                      numb[y]->setMinimumWidth(1000);
                      numb[y]->setAutoFillBackground(true);
                      ui->horizontalLayout_2->addWidget(numb[y]);
                      ui->horizontalLayout_2->setSpacing(0);
            }
                 }









    }







}


window1::~window1()
{
    delete ui;
}

void window1::setRequired_data(QString value)
{
    required_data = value;
}

void window1::set_brust(QString value)
{
    brust=value;
}

void window1::set_arrival(QString value)
{
    arrival=value;
}

void window1::set_quan(QString value)
{
    quan=value;
}

void window1::set_priority(QString value)
{
    priority =value;
}

void window1::set_type_sch(QString value)
{
    type_sch=value;
}

