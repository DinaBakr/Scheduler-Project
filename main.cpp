#include "mainwindow.h"
#include<iostream>
#include<vector>
#include<string>
//#include <bits/stdc++.h>
#include <algorithm>
#include<cstdlib>
#include<stdio.h>
#include <cctype>
#include<cstring>
#include<queue>
#include <QApplication>

using namespace std;
vector<int> seq;
int size1 = seq.size();
vector<float> gant_chart_nums;
int size2 = gant_chart_nums.size();



//struct process
//{
//    float at,bt;
//    int pno;
//};
//extern int nn;
bool isNumber(string s)
{

    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false )
            return false;


    return true;
}
bool IsNumericDigit(const string strr)
{
    int count = 0;
    //srting C;
    for (int i = 0; i<strr.length(); i++)
    {
        if ((strr[i] >= '0' && strr[i] <= '9') || (strr[i] == '.'))
        {count++;}

    }

    if (count == strr.length())	return true;

    else return 0;
}
int charCheck(string input_char ,int n)
{
    // CHECKING FOR ALPHABET
    int flag;
    for(int i=0;i<n;i++)
    {
    if ((input_char[i] >= 65 && input_char[i] <= 90)
        || (input_char [i]>= 97 && input_char[i] <= 122))
        {
           // cout << " NO ";
        flag=0;
        break;
        }

    // CHECKING FOR DIGITS
    else if (input_char[i] >= 48 && input_char[i] <= 57)
      { // cout << " Yes ";
        flag=1;
    }
    else if(input_char[i]=='.')
    {
        //cout<<"YES";
        flag=1;
    }
    // OTHERWISE SPECIAL CHARACTER

    }
 return flag;
 }
int min(int at[],int n)
{
    int min=at[0];
    for(int i=1;i<n;i++)
    {
        if(at[i]<min)
        {
            min=at[i];
        }
    }
    return min;
}
float minn(float at[],int n)
{
    float min=at[0];
    for(int i=1;i<n;i++)
    {
        if(at[i]<min)
        {
            min=at[i];
        }
    }
    return min;
}
float minn_vec(vector<string> at,int n)
{
    string min=at.front();
    for(int i=1;i<n;i++)
    {
        if(at[i]<min)
        {
            min=at[i];
        }
    }

    return stof(min);
}
int max(int at[],int n)
{
    int max=at[0];
    for(int i=1;i<n;i++)
    {
        if(at[i]>max)
        {
            max=at[i];
        }
    }
    return max;
}

/*****PRIORITY NON PREM NEWWW****/
typedef struct proccess
{
    QString pro_id;
    float at, bt, pr, ct, ta, wt;


} process2;
bool compare(process2 a, process2 b)
{
    if(a.at==b.at)
    {
        return a.pr<b.pr;
    }
    else
    {
    return a.at<b.at;
}
}
bool compare2(process2 a, process2 b)
{
    return a.pr<b.pr;
}
float avgWT(int n, vector<process2>pro)
{
    process2 dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "";
        dumy.at = 0;
        dumy.bt = pro[0].at;
        dumy.pr = 0;
        pro.insert(pro.begin(), dumy);
        //m++;
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }



    int i = 1;
    int j;


    int m = pro.size();


    while (i<m)
    {

        for (j = i; j<pro.size(); j++)
        {
            if (pro[j].at>pro[i - 1].ct)
                break;
        }

        sort(pro.begin() + i, pro.begin() + i + (j - i), compare2);


        if (pro[i].at>pro[i - 1].ct) {
            process2 dummy;
            dummy.pro_id = "";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;
            dummy.pr = 0;
            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

        float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }


    //cout<<"P_no\tarr_time\tbur_time\tCompl_time\tWait_Time\tPriority"<<endl;


    for (i = 0; i<pro.size(); i++)
    {
        //desplaying all the values
        //cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
          //  << "\t" << "wt " << pro[i].wt << "\t" << "pr " << pro[i].pr;
       // cout << endl;
    }


    avg_wt = total_wt / (float)n;
    return avg_wt;

}
int avgWT_index_P(int n, vector<process2>pro)
{
    process2 dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "";
        dumy.at = 0;
        dumy.bt = pro[0].at;
        dumy.pr = 0;
        pro.insert(pro.begin(), dumy);
        //m++;
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }



    int i = 1;
    int j;


    int m = pro.size();


    while (i<m)
    {

        for (j = i; j<pro.size(); j++)
        {
            if (pro[j].at>pro[i - 1].ct)
                break;
        }

        sort(pro.begin() + i, pro.begin() + i + (j - i), compare2);


        if (pro[i].at>pro[i - 1].ct) {
            process2 dummy;
            dummy.pro_id = "";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;
            dummy.pr = 0;
            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

        float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }


    //cout<<"P_no\tarr_time\tbur_time\tCompl_time\tWait_Time\tPriority"<<endl;


    //for (i = 0; i<pro.size(); i++)
  //  {
//        //desplaying all the values
//        cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
//            << "\t" << "wt " << pro[i].wt << "\t" << "pr " << pro[i].pr;
//        cout << endl;
  //  }


    avg_wt = total_wt / (float)pro.size();
    return m;

}
float* avgWT_drawgantt(int n, vector<process2>pro)
{
    process2 dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "";
        dumy.at = 0;
        dumy.bt = pro[0].at;
        dumy.pr = 0;
        pro.insert(pro.begin(), dumy);
        //m++;
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }



    int i = 1;
    int j;


    int m = pro.size();


    while (i<m)
    {

        for (j = i; j<pro.size(); j++)
        {
            if (pro[j].at>pro[i - 1].ct)
                break;
        }

        sort(pro.begin() + i, pro.begin() + i + (j - i), compare2);


        if (pro[i].at>pro[i - 1].ct) {
            process2 dummy;
            dummy.pro_id = "";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;
            dummy.pr = 0;
            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

        float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }


    //cout<<"P_no\tarr_time\tbur_time\tCompl_time\tWait_Time\tPriority"<<endl;
    float *num= new float [m];
    for (i = 0; i<pro.size(); i++)
    {
        num[i]=pro[i].ct;
    }

    for (i = 0; i<pro.size(); i++)
    {
//        //desplaying all the values
//        cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
//            << "\t" << "wt " << pro[i].wt << "\t" << "pr " << pro[i].pr;
//        cout << endl;
//        //return pro[i].ct;
    }


    avg_wt = total_wt / (float)pro.size();
    return num;

}

QString* avgWT_namesdrawgantt(int n, vector<process2>pro)
{
    process2 dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "";
        dumy.at = 0;
        dumy.bt = pro[0].at;
        dumy.pr = 0;
        pro.insert(pro.begin(), dumy);
        //m++;
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }



    int i = 1;
    int j;


    int m = pro.size();


    while (i<m)
    {

        for (j = i; j<pro.size(); j++)
        {
            if (pro[j].at>pro[i - 1].ct)
                break;
        }

        sort(pro.begin() + i, pro.begin() + i + (j - i), compare2);


        if (pro[i].at>pro[i - 1].ct) {
            process2 dummy;
            dummy.pro_id = "";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;
            dummy.pr = 0;
            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

        float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }


    //cout<<"P_no\tarr_time\tbur_time\tCompl_time\tWait_Time\tPriority"<<endl;
    QString *num= new QString [m];
    for (i = 0; i<pro.size(); i++)
    {
        num[i]=pro[i].pro_id;
    }

    for (i = 0; i<pro.size(); i++)
    {
        //desplaying all the values
//        cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
//            << "\t" << "wt " << pro[i].wt << "\t" << "pr " << pro[i].pr;
//        cout << endl;
        //return pro[i].ct;
    }


    avg_wt = total_wt / (float)pro.size();
    return num;

}

/*FCFS NEWWW*/
//bool comp(process a,process b)
//{

//    return a.at<b.at;
//}

float avgWTT(int n, vector<process2>pro)
{
    process2 dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "  Gap";
        dumy.at = 0;
        dumy.bt = pro[0].at;

        pro.insert(pro.begin(), dumy);

        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }



    int i = 1;
    int j;


    int m = pro.size(); // return number of labels


    while (i<m)
    {



        if (pro[i].at>pro[i - 1].ct) {
            process2 dummy;
            dummy.pro_id = "  Gap";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;

            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt; // numbers on gantt chart
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

        float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }



    avg_wt = total_wt / (float)n;
    return avg_wt;

}
int avgWTT_mm(int n, vector<process2>pro)
{
    process2 dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "  Gap";
        dumy.at = 0;
        dumy.bt = pro[0].at;

        pro.insert(pro.begin(), dumy);

        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }



    int i = 1;
    int j;


    int m = pro.size(); // return number of labels


    while (i<m)
    {



        if (pro[i].at>pro[i - 1].ct) {
            process2 dummy;
            dummy.pro_id = "  Gap";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;

            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt; // numbers on gantt chart
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

        float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }



    avg_wt = total_wt / (float)pro.size();
return m;

}
float* avgWT_gantt(int n, vector<process2>pro)
{
    process2 dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "  Gap";
        dumy.at = 0;
        dumy.bt = pro[0].at;

        pro.insert(pro.begin(), dumy);

        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }



    int i = 1;
    int j;


    int m = pro.size(); // return number of labels


    while (i<m)
    {



        if (pro[i].at>pro[i - 1].ct) {
            process2 dummy;
            dummy.pro_id = "  Gap";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;

            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt; // numbers on gantt chart
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

        float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }


float *new_com=new float[m];


    for (i = 0; i<pro.size(); i++)
    {
//		//desplaying all the values
//		cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
//			<< "\t" << "wt " << pro[i].wt ;
//		cout << endl;
        new_com[i]=pro[i].ct ;
    }


    avg_wt = total_wt / (float)pro.size();
    return new_com;

}
QString* avgWT_id(int n, vector<process2>pro)
{
    process2 dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "  Gap";
        dumy.at = 0;
        dumy.bt = pro[0].at;

        pro.insert(pro.begin(), dumy);

        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
        }



    int i = 1;
    int j;


    int m = pro.size(); // return number of labels


    while (i<m)
    {



        if (pro[i].at>pro[i - 1].ct) {
            process2 dummy;
            dummy.pro_id = "  Gap";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;

            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt; // numbers on gantt chart
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

        float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }



QString *num_id= new QString[m];
    for (i = 0; i<pro.size(); i++)
    {
    num_id[i]=pro[i].pro_id;
    }


    avg_wt = total_wt / (float)pro.size();
    return num_id;

}

/*SJF NON*/
typedef struct procsjfnon
{
    QString pro_id;
    float at, bt, ct, ta, wt;


}pnsjf;

bool comparesjfnon(pnsjf a, pnsjf b)

{
    if (a.at == b.at)
    {
        return a.bt<b.bt;
    }
    else
        return a.at<b.at;
}

bool compare2sjfnon(pnsjf a, pnsjf b)
{
    return a.bt<b.bt;
}
float avgWT_nonsjf(int n, vector<pnsjf>pro)
{
    pnsjf dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "  Gap";
        dumy.at = 0;
        dumy.bt = pro[0].at;
        pro.insert(pro.begin(), dumy);
        //m++;
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
    }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
    }



    int i = 1;
    int j;


    int m = pro.size();


    while (i<m)
    {

        for (j = i; j<pro.size(); j++)
        {
            if (pro[j].at>pro[i - 1].ct)
                break;
        }

        sort(pro.begin() + i, pro.begin() + i + (j - i), compare2sjfnon);


        if (pro[i].at>pro[i - 1].ct) {
            pnsjf dummy;
            dummy.pro_id = "  Gap";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;
            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

    float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }




    for (i = 0; i<pro.size(); i++)
//    {
//        //desplaying all the values
//        //cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
//            //<< "\t" << "wt " << pro[i].wt;
//       // cout << endl;
//    }


    avg_wt = total_wt / (float)n;
    return avg_wt;

}
int avgWT_nonsjfmm(int n, vector<pnsjf>pro)
{
    pnsjf dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "  Gap";
        dumy.at = 0;
        dumy.bt = pro[0].at;
        pro.insert(pro.begin(), dumy);
        //m++;
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
    }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
    }



    int i = 1;
    int j;


    int m = pro.size();


    while (i<m)
    {

        for (j = i; j<pro.size(); j++)
        {
            if (pro[j].at>pro[i - 1].ct)
                break;
        }

        sort(pro.begin() + i, pro.begin() + i + (j - i), compare2sjfnon);


        if (pro[i].at>pro[i - 1].ct) {
            pnsjf dummy;
            dummy.pro_id = "  Gap";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;
            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

    float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }




//	for (i = 0; i<pro.size(); i++)
//	{
//		//desplaying all the values
//		//cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
//			//<< "\t" << "wt " << pro[i].wt;
//		cout << endl;
//	}


    avg_wt = total_wt / (float)n;
    return m;

}
float* avgWT_flogh(int n, vector<pnsjf>pro)
{
    pnsjf dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "  Gap";
        dumy.at = 0;
        dumy.bt = pro[0].at;
        pro.insert(pro.begin(), dumy);
        //m++;
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
    }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
    }



    int i = 1;
    int j;


    int m = pro.size();


    while (i<m)
    {

        for (j = i; j<pro.size(); j++)
        {
            if (pro[j].at>pro[i - 1].ct)
                break;
        }

        sort(pro.begin() + i, pro.begin() + i + (j - i), compare2sjfnon);


        if (pro[i].at>pro[i - 1].ct) {
            pnsjf dummy;
            dummy.pro_id = "  Gap";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;
            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

    float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }




    float *new_com=new float[m];


        for (i = 0; i<pro.size(); i++)
        {
    //		//desplaying all the values
    //		cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
    //			<< "\t" << "wt " << pro[i].wt ;
    //		cout << endl;
            new_com[i]=pro[i].ct ;
        }


    avg_wt = total_wt / (float)n;
    return new_com;

}
QString* avgWT_flogh_gh(int n, vector<pnsjf>pro)
{
    pnsjf dumy;
    if (pro[0].at > 0) {

        dumy.pro_id = "  Gap";
        dumy.at = 0;
        dumy.bt = pro[0].at;
        pro.insert(pro.begin(), dumy);
        //m++;
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
    }
    else {
        pro[0].ct = pro[0].bt + pro[0].at;
        pro[0].ta = pro[0].ct - pro[0].at;
        pro[0].wt = pro[0].ta - pro[0].bt;
    }



    int i = 1;
    int j;


    int m = pro.size();


    while (i<m)
    {

        for (j = i; j<pro.size(); j++)
        {
            if (pro[j].at>pro[i - 1].ct)
                break;
        }

        sort(pro.begin() + i, pro.begin() + i + (j - i), compare2sjfnon);


        if (pro[i].at>pro[i - 1].ct) {
            pnsjf dummy;
            dummy.pro_id = "  Gap";
            dummy.at = pro[i - 1].ct;
            dummy.bt = pro[i].at - pro[i - 1].ct;
            pro.insert(pro.begin() + i, dummy);
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
            m++;
        }
        else if (m != i + 1) {
            pro[i].ct = pro[i - 1].ct + pro[i].bt;
            pro[i].ta = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].ta - pro[i].bt;
            i++;
        }
        else { break; }

    }

    pro[i].ct = pro[i - 1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

    float avg_wt, total_wt = 0;

    for (int k = 0; k<pro.size(); k++)
    {
        total_wt = total_wt + pro[k].wt;
    }




    QString *num= new QString [m];
    for (i = 0; i<pro.size(); i++)
    {
        num[i]=pro[i].pro_id;
    }

    for (i = 0; i<pro.size(); i++)
    {
        //desplaying all the values
//        cout << "P_no " << pro[i].pro_id << "\t" << "at " << pro[i].at << "\t" << "bt " << pro[i].bt << "\t" << "ct " << pro[i].ct << "\t"
//            << "\t" << "wt " << pro[i].wt << "\t" << "pr " << pro[i].pr;
//        cout << endl;
        //return pro[i].ct;
    }


    avg_wt = total_wt / (float)pro.size();
    return num;

}




/*RR*/float roundRobin(int p[],int a[],int b[],int n,int pn)
{
    // result of average times
    int res = 0;
    int resc = 0;

    // for sequence storage
   vector<int>seq;

    // copy the burst array and arrival array
    // for not effecting the actual array
   int *res_b ;
res_b = new int [pn];
 int *res_a ;
res_a = new int [pn];

    for (int i = 0; i < pn; i++)
    {
        res_b[i] = b[i];
        res_a[i] = a[i];
    }

    // critical time of system
    int t = 0;

      int *w ;
w = new int [pn];
 int *comp ;
comp = new int [pn];

    while (true)
    {
        bool flag = true;
        for (int i = 0; i < pn; i++)
        {

            // these condition for if
            // arrival is not on zero

            // check that if there come before qtime
            if (res_a[i] <= t)
            {
                if (res_a[i] <= n)
                {
                    if (res_b[i] > 0)
                    {
                        flag = false;
                        if (res_b[i] > n)
                        {

                            // make decrease the b time
                            t = t + n;
                            res_b[i] = res_b[i] - n;
                            res_a[i] = res_a[i] + n;
                             seq.push_back(p[i]);
                        }
                        else
                        {

                            // for last time
                            t = t + res_b[i];

                            // store comp time
                            comp[i] = t - a[i];

                            // store wait time
                            w[i] = t - b[i] - a[i];
                            res_b[i] = 0;

                            // add sequence
                             seq.push_back(p[i]);
                        }
                    }
                }
                else if (res_a[i] > n)
                {

                    // is any have less arrival time
                    // the coming process then execute them
                    for (int j = 0; j < pn; j++)
                    {

                        // compare
                        if (res_a[j] < res_a[i])
                        {
                            if (res_b[j] > 0)
                            {
                                flag = false;
                                if (res_b[j] > n)
                                {
                                    t = t + n;
                                    res_b[j] = res_b[j] - n;
                                    res_a[j] = res_a[j] + n;
                                     seq.push_back(p[j]);
                                }
                                else
                                {
                                    t = t + res_b[j];
                                    comp[j] = t - a[j];
                                    w[j] = t - b[j] - a[j];
                                    res_b[j] = 0;
                                     seq.push_back(p[j]);
                                }
                            }
                        }
                    }

                    // now the previous porcess according to
                    // ith is process
                    if (res_b[i] > 0)
                    {
                        flag = false;

                        // Check for greaters
                        if (res_b[i] > n)
                        {
                            t = t + n;
                            res_b[i] = res_b[i] - n;
                            res_a[i] = res_a[i] + n;
                             seq.push_back(p[i]);
                        }
                        else
                        {
                            t = t + res_b[i];
                            comp[i] = t - a[i];
                            w[i] = t - b[i] - a[i];
                            res_b[i] = 0;
                             seq.push_back(p[i]);
                        }
                    }
                }
            }

            // if no process is come on thse critical
            else if (res_a[i] > t)
            {
                t++;
                i--;
            }
        }

        // for exit the while loop
        if (flag)
        {
            break;
        }
    }

cout<<"name    ctime   wtime "<<endl;
    for(int i =0; i<pn;i++)
    {
        cout<<"p"<<p[i]<<"    "<<comp[i]<<"   "<<w[i]<<endl;

        res =res+w[i];
        resc=resc+comp[i];
    }
     float avw=float(res)/float(pn);

    int length=seq.size();
    for(int i =0; i<length;i++)
{
    cout<<seq[i]<<" -> ";
}
cout<<endl;

   //print_array(seq,length);
return avw;




}

int* roundRobinwaiting(int p[],int a[],int b[],int n,int pn)
{
    // result of average times
    int res = 0;
    int resc = 0;

    // for sequence storage
   vector<int>seq;

    // copy the burst array and arrival array
    // for not effecting the actual array
   int *res_b ;
res_b = new int [pn];
 int *res_a ;
res_a = new int [pn];

    for (int i = 0; i < pn; i++)
    {
        res_b[i] = b[i];
        res_a[i] = a[i];
    }

    // critical time of system
    int t = 0;

      int *w ;
w = new int [pn];
 int *comp ;
comp = new int [pn];

    while (true)
    {
        bool flag = true;
        for (int i = 0; i < pn; i++)
        {

            // these condition for if
            // arrival is not on zero

            // check that if there come before qtime
            if (res_a[i] <= t)
            {
                if (res_a[i] <= n)
                {
                    if (res_b[i] > 0)
                    {
                        flag = false;
                        if (res_b[i] > n)
                        {

                            // make decrease the b time
                            t = t + n;
                            res_b[i] = res_b[i] - n;
                            res_a[i] = res_a[i] + n;
                             seq.push_back(p[i]);
                        }
                        else
                        {

                            // for last time
                            t = t + res_b[i];

                            // store comp time
                            comp[i] = t - a[i];

                            // store wait time
                            w[i] = t - b[i] - a[i];
                            res_b[i] = 0;

                            // add sequence
                             seq.push_back(p[i]);
                        }
                    }
                }
                else if (res_a[i] > n)
                {

                    // is any have less arrival time
                    // the coming process then execute them
                    for (int j = 0; j < pn; j++)
                    {

                        // compare
                        if (res_a[j] < res_a[i])
                        {
                            if (res_b[j] > 0)
                            {
                                flag = false;
                                if (res_b[j] > n)
                                {
                                    t = t + n;
                                    res_b[j] = res_b[j] - n;
                                    res_a[j] = res_a[j] + n;
                                     seq.push_back(p[j]);
                                }
                                else
                                {
                                    t = t + res_b[j];
                                    comp[j] = t - a[j];
                                    w[j] = t - b[j] - a[j];
                                    res_b[j] = 0;
                                     seq.push_back(p[j]);
                                }
                            }
                        }
                    }

                    // now the previous porcess according to
                    // ith is process
                    if (res_b[i] > 0)
                    {
                        flag = false;

                        // Check for greaters
                        if (res_b[i] > n)
                        {
                            t = t + n;
                            res_b[i] = res_b[i] - n;
                            res_a[i] = res_a[i] + n;
                             seq.push_back(p[i]);
                        }
                        else
                        {
                            t = t + res_b[i];
                            comp[i] = t - a[i];
                            w[i] = t - b[i] - a[i];
                            res_b[i] = 0;
                             seq.push_back(p[i]);
                        }
                    }
                }
            }

            // if no process is come on thse critical
            else if (res_a[i] > t)
            {
                t++;
                i--;
            }
        }

        // for exit the while loop
        if (flag)
        {
            break;
        }
    }

cout<<"name    ctime   wtime "<<endl;
    for(int i =0; i<pn;i++)
    {
        cout<<"p"<<p[i]<<"    "<<comp[i]<<"   "<<w[i]<<endl;

        res =res+w[i];
        resc=resc+comp[i];
    }
     float avw=float(res)/float(pn);

    int length=seq.size();
    for(int i =0; i<length;i++)
{
    cout<<seq[i]<<" -> ";
}
cout<<endl;

   //print_array(seq,length);
return w;




}
vector<int> round_Robin(int p[],int a[],int b[],int n,int pn)
    {
        // result of average times
        int res = 0;
        int resc = 0;

        // for sequence storage
       vector<int>seq;

        // copy the burst array and arrival array
        // for not effecting the actual array
       int *res_b ;
    res_b = new int [pn];
     int *res_a ;
    res_a = new int [pn];

        for (int i = 0; i < pn; i++)
        {
            res_b[i] = b[i];
            res_a[i] = a[i];
        }

        // critical time of system
        int t = 0;

          int *w ;
    w = new int [pn];
     int *comp ;
    comp = new int [pn];

        while (true)
        {
            bool flag = true;
            for (int i = 0; i < pn; i++)
            {

                // these condition for if
                // arrival is not on zero

                // check that if there come before qtime
                if (res_a[i] <= t)
                {
                    if (res_a[i] <= n)
                    {
                        if (res_b[i] > 0)
                        {
                            flag = false;
                            if (res_b[i] > n)
                            {

                                // make decrease the b time
                                t = t + n;
                                res_b[i] = res_b[i] - n;
                                res_a[i] = res_a[i] + n;
                                 seq.push_back(p[i]);
                            }
                            else
                            {

                                // for last time
                                t = t + res_b[i];

                                // store comp time
                                comp[i] = t - a[i];

                                // store wait time
                                w[i] = t - b[i] - a[i];
                                res_b[i] = 0;

                                // add sequence
                                 seq.push_back(p[i]);
                            }
                        }
                    }
                    else if (res_a[i] > n)
                    {

                        // is any have less arrival time
                        // the coming process then execute them
                        for (int j = 0; j < pn; j++)
                        {

                            // compare
                            if (res_a[j] < res_a[i])
                            {
                                if (res_b[j] > 0)
                                {
                                    flag = false;
                                    if (res_b[j] > n)
                                    {
                                        t = t + n;
                                        res_b[j] = res_b[j] - n;
                                        res_a[j] = res_a[j] + n;
                                         seq.push_back(p[j]);
                                    }
                                    else
                                    {
                                        t = t + res_b[j];
                                        comp[j] = t - a[j];
                                        w[j] = t - b[j] - a[j];
                                        res_b[j] = 0;
                                         seq.push_back(p[j]);
                                    }
                                }
                            }
                        }

                        // now the previous porcess according to
                        // ith is process
                        if (res_b[i] > 0)
                        {
                            flag = false;

                            // Check for greaters
                            if (res_b[i] > n)
                            {
                                t = t + n;
                                res_b[i] = res_b[i] - n;
                                res_a[i] = res_a[i] + n;
                                 seq.push_back(p[i]);
                            }
                            else
                            {
                                t = t + res_b[i];
                                comp[i] = t - a[i];
                                w[i] = t - b[i] - a[i];
                                res_b[i] = 0;
                                 seq.push_back(p[i]);
                            }
                        }
                    }
                }

                // if no process is come on thse critical
                else if (res_a[i] > t)
                {
                    t++;
                    i--;
                }
            }

            // for exit the while loop
            if (flag)
            {
                break;
            }
        }

 cout<<"name    ctime   wtime "<<endl;
        for(int i =0; i<pn;i++)
        {
            cout<<"p"<<p[i]<<"    "<<comp[i]<<"   "<<w[i]<<endl;

            res =res+w[i];
            resc=resc+comp[i];
        }
         float avw=float(res)/float(pn);

        int length=seq.size();
        for(int i =0; i<length;i++)
    {
        cout<<seq[i]<<" -> ";
    }
    cout<<endl;

       //print_array(seq,length);
    return seq;




}

int round_Robin_max(int p[],int a[],int b[],int n,int pn)
    {
        // result of average times
        int res = 0;
        int resc = 0;

        // for sequence storage
       vector<int>seq;

        // copy the burst array and arrival array
        // for not effecting the actual array
       int *res_b ;
    res_b = new int [pn];
     int *res_a ;
    res_a = new int [pn];

        for (int i = 0; i < pn; i++)
        {
            res_b[i] = b[i];
            res_a[i] = a[i];
        }

        // critical time of system
        int t = 0;

          int *w ;
    w = new int [pn];
     int *comp ;
    comp = new int [pn];

        while (true)
        {
            bool flag = true;
            for (int i = 0; i < pn; i++)
            {

                // these condition for if
                // arrival is not on zero

                // check that if there come before qtime
                if (res_a[i] <= t)
                {
                    if (res_a[i] <= n)
                    {
                        if (res_b[i] > 0)
                        {
                            flag = false;
                            if (res_b[i] > n)
                            {

                                // make decrease the b time
                                t = t + n;
                                res_b[i] = res_b[i] - n;
                                res_a[i] = res_a[i] + n;
                                 seq.push_back(p[i]);
                            }
                            else
                            {

                                // for last time
                                t = t + res_b[i];

                                // store comp time
                                comp[i] = t - a[i];

                                // store wait time
                                w[i] = t - b[i] - a[i];
                                res_b[i] = 0;

                                // add sequence
                                 seq.push_back(p[i]);
                            }
                        }
                    }
                    else if (res_a[i] > n)
                    {

                        // is any have less arrival time
                        // the coming process then execute them
                        for (int j = 0; j < pn; j++)
                        {

                            // compare
                            if (res_a[j] < res_a[i])
                            {
                                if (res_b[j] > 0)
                                {
                                    flag = false;
                                    if (res_b[j] > n)
                                    {
                                        t = t + n;
                                        res_b[j] = res_b[j] - n;
                                        res_a[j] = res_a[j] + n;
                                         seq.push_back(p[j]);
                                    }
                                    else
                                    {
                                        t = t + res_b[j];
                                        comp[j] = t - a[j];
                                        w[j] = t - b[j] - a[j];
                                        res_b[j] = 0;
                                         seq.push_back(p[j]);
                                    }
                                }
                            }
                        }

                        // now the previous porcess according to
                        // ith is process
                        if (res_b[i] > 0)
                        {
                            flag = false;

                            // Check for greaters
                            if (res_b[i] > n)
                            {
                                t = t + n;
                                res_b[i] = res_b[i] - n;
                                res_a[i] = res_a[i] + n;
                                 seq.push_back(p[i]);
                            }
                            else
                            {
                                t = t + res_b[i];
                                comp[i] = t - a[i];
                                w[i] = t - b[i] - a[i];
                                res_b[i] = 0;
                                 seq.push_back(p[i]);
                            }
                        }
                    }
                }

                // if no process is come on thse critical
                else if (res_a[i] > t)
                {
                    t++;
                    i--;
                }
            }

            // for exit the while loop
            if (flag)
            {
                break;
            }
        }

 cout<<"name    ctime   wtime "<<endl;
        for(int i =0; i<pn;i++)
        {
            cout<<"p"<<p[i]<<"    "<<comp[i]<<"   "<<w[i]<<endl;

            res =res+w[i];
            resc=resc+comp[i];
        }
         float avw=float(res)/float(pn);

        int length=seq.size();
//        for(int i =0; i<length;i++)
//    {
//        cout<<seq[i]<<" -> ";
//    }
//    cout<<endl;

//       print_array(seq,length);
       int m=max(comp,pn);


    return m ;




}

int round_Robin_number(int p[],int a[],int b[],int n,int pn)
    {
        // result of average times
        int res = 0;
        int resc = 0;

        // for sequence storage
       vector<int>seq;

        // copy the burst array and arrival array
        // for not effecting the actual array
       int *res_b ;
    res_b = new int [pn];
     int *res_a ;
    res_a = new int [pn];

        for (int i = 0; i < pn; i++)
        {
            res_b[i] = b[i];
            res_a[i] = a[i];
        }

        // critical time of system
        int t = 0;

          int *w ;
    w = new int [pn];
     int *comp ;
    comp = new int [pn];

        while (true)
        {
            bool flag = true;
            for (int i = 0; i < pn; i++)
            {

                // these condition for if
                // arrival is not on zero

                // check that if there come before qtime
                if (res_a[i] <= t)
                {
                    if (res_a[i] <= n)
                    {
                        if (res_b[i] > 0)
                        {
                            flag = false;
                            if (res_b[i] > n)
                            {

                                // make decrease the b time
                                t = t + n;
                                res_b[i] = res_b[i] - n;
                                res_a[i] = res_a[i] + n;
                                 seq.push_back(p[i]);
                            }
                            else
                            {

                                // for last time
                                t = t + res_b[i];

                                // store comp time
                                comp[i] = t - a[i];

                                // store wait time
                                w[i] = t - b[i] - a[i];
                                res_b[i] = 0;

                                // add sequence
                                 seq.push_back(p[i]);
                            }
                        }
                    }
                    else if (res_a[i] > n)
                    {

                        // is any have less arrival time
                        // the coming process then execute them
                        for (int j = 0; j < pn; j++)
                        {

                            // compare
                            if (res_a[j] < res_a[i])
                            {
                                if (res_b[j] > 0)
                                {
                                    flag = false;
                                    if (res_b[j] > n)
                                    {
                                        t = t + n;
                                        res_b[j] = res_b[j] - n;
                                        res_a[j] = res_a[j] + n;
                                         seq.push_back(p[j]);
                                    }
                                    else
                                    {
                                        t = t + res_b[j];
                                        comp[j] = t - a[j];
                                        w[j] = t - b[j] - a[j];
                                        res_b[j] = 0;
                                         seq.push_back(p[j]);
                                    }
                                }
                            }
                        }

                        // now the previous porcess according to
                        // ith is process
                        if (res_b[i] > 0)
                        {
                            flag = false;

                            // Check for greaters
                            if (res_b[i] > n)
                            {
                                t = t + n;
                                res_b[i] = res_b[i] - n;
                                res_a[i] = res_a[i] + n;
                                 seq.push_back(p[i]);
                            }
                            else
                            {
                                t = t + res_b[i];
                                comp[i] = t - a[i];
                                w[i] = t - b[i] - a[i];
                                res_b[i] = 0;
                                 seq.push_back(p[i]);
                            }
                        }
                    }
                }

                // if no process is come on thse critical
                else if (res_a[i] > t)
                {
                    t++;
                    i--;
                }
            }

            // for exit the while loop
            if (flag)
            {
                break;
            }
        }

 cout<<"name    ctime   wtime "<<endl;
        for(int i =0; i<pn;i++)
        {
            cout<<"p"<<p[i]<<"    "<<comp[i]<<"   "<<w[i]<<endl;

            res =res+w[i];
            resc=resc+comp[i];
        }
         float avw=float(res)/float(pn);

        int length=seq.size();
//        for(int i =0; i<length;i++)
//    {
//        cout<<seq[i]<<" -> ";
//    }
//    cout<<endl;

//       print_array(seq,length);
       int m=max(comp,pn);


    return length ;




}

/***SJF PREEM**/

struct procsjfpreeem
{
       float bt,at,wt,st,tt,cbt;
       int pid;
};

int get(procsjfpreeem proc[],int t,int n)
{
       float imin,min=9999;
       int i;
       for(i=0;i<n;i++)
       {
              if(proc[i].at<=t&&proc[i].st==0)
                     if(min>proc[i].bt)
                     {
                           min=proc[i].bt;
                           imin=i;
                     }
       }
       return imin;
}
//vector<int> seq;
//int size1 = seq.size();
int index_sjfpreem(procsjfpreeem proc[],int p[],int n,int nop)
{
//    vector<int> seq_1;
//    int size1 = seq_1.size();
    int i;
       float a[100],s=0;
       float avgtt=0,avgwt=0;
       vector<int> the_array;
       //the_array=new int [n];


        vector<float> gant_chart_nums;
       //cout <<"*****\n";
       //cout << "GANTT CHART\n";
       //cout << "0";
       for(i=0;i<n-1;i++)
       {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }
              s++;
             // cout << " ->" <<proc[p[i]].pid <<  "<-" << s;
             //the_array[i]=proc[p[i]].pid;
              seq.push_back(proc[p[i]].pid);
              //gant_chart_nums.push_back(s);
              proc[p[i]].wt=s-proc[p[i]].at-proc[p[i]].tt;
}

return seq.size();
}
vector<int> bta3et_seq(procsjfpreeem proc[],int p[],int n,int nop)
{
       int i;
       float a[100],s=0;
       float avgtt=0,avgwt=0;
       vector<int> the_array;
       //the_array=new int [n];


        vector<float> gant_chart_nums;
       //cout <<"*****\n";
       //cout << "GANTT CHART\n";
       //cout << "0";
       for(i=0;i<n-1;i++)
       {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }
              s++;
             // cout << " ->" <<proc[p[i]].pid <<  "<-" << s;
             //the_array[i]=proc[p[i]].pid;
              seq.push_back(proc[p[i]].pid);
              //gant_chart_nums.push_back(s);
              proc[p[i]].wt=s-proc[p[i]].at-proc[p[i]].tt;
}


return seq;
}
//vector<float> gant_chart_nums;
//int size2 = gant_chart_nums.size();


vector<float> bta3et_elarqaam (procsjfpreeem proc[],int p[],int n,int nop)
{
       int i;
       float a[100],s=0;
       float avgtt=0,avgwt=0;
       vector<int> the_array;
       //the_array=new int [n];
        //cout <<"*****\n";
      // cout << "GANTT CHART\n";
       //cout << "0";
       for(i=0;i<n-1;i++)
       {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }
              s++;
             // cout << " ->" <<proc[p[i]].pid <<  "<-" << s;
//              seq.push_back(proc[p[i]].pid);
              gant_chart_nums.push_back(s);
              proc[p[i]].wt=s-proc[p[i]].at-proc[p[i]].tt;
}

       return gant_chart_nums;
}

float bta3_elwa2t(procsjfpreeem proc[],int p[],int n,int nop)
{
       int i;
       float a[100],s=0;
       float avgtt=0,avgwt=0;
       //vector<int>seq;
       //vector<float> gant_chart_nums;
       cout <<"*****\n";
       cout << "GANTT CHART\n";
       //cout << "0";
       for(i=0;i<n-1;i++)
       {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }

              s++;
              proc[p[i]].wt=s-proc[p[i]].at-proc[p[i]].tt;
       }

    for(i=0;i<nop;i++)
       {
              proc[i].tt+=proc[i].wt;
              avgwt+=proc[i].wt;
              avgtt+=proc[i].tt;
       }
       //cout << "\n*******\n";
       //cout << "Pro\tArTi\tBuTi\tTaTi\tWtTi\n";
       //cout << "*****\n";
       for(i=0;i<nop;i++)
       {
cout << proc[i].pid<< "\t" << proc[i].at << "\t" << proc[i].cbt << "\t" << proc[i].tt<< "\t"  << proc[i].wt << "\n" ;
       }
       //cout << "*****\n";
       avgwt = avgwt/(float)nop;
       avgtt = avgtt/nop;
       cout << "Average Waiting Time :" << avgwt;
//       cout << "Average Turnaround Time : " << avgtt;
        return avgwt;
}



int iscomplite(procsjfpreeem proc[],int n)
{
       int i;
       for(i=0;i<n;i++)
              if(proc[i].st==0)
                     return 0;
       return 1;
}


/*******PRIOR PREEM*********/

struct procpirpreem
{
       float bt,at,wt,st,tt,cbt;
       int pr,pid;
};


int get_prior(procpirpreem proc[],int t,int n)
{
       int imin,min=9999,i;
       for(i=0;i<n;i++)
       {
              if(proc[i].at<=t&&proc[i].st==0)
                     if(min>proc[i].pr)
                     {
                           min=proc[i].pr;
                           imin=i;
                     }
                    //  else if(min==proc[i].pr)
                    //  { int smalll =99999;
                    //      if(smalll>proc[i].pid)
                    //      {
                    //          smalll=proc[i].pid;
                    //          imin=i;
                    //      }
                    //  }
       }
       return imin;
}


vector<int>seq_2;
vector<int> ana_elseq(procpirpreem proc[],int p[],int n,int nop)
{
      int i,a[100],s=0;
      float avgtt=0,avgwt=0;
      vector<float> gant_chart_nums_2;
      //cout <<"*************\n";
      //cout << "GANTT CHART\n";
      //cout << "0";
      for(i=0;i<n-1;i++)
      {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }

              s++;
        //      cout << " ->" <<proc[p[i]].pid <<  "<-" << s;
              seq_2.push_back(proc[p[i]].pid);
          //    gant_chart_nums_2.push_back(s);
              proc[p[i]].wt=s-proc[p[i]].at-proc[p[i]].tt;
      }
return seq_2 ;
}





vector<float> gant_chart_nums_2;
vector<float> ana_elarqam(procpirpreem proc[],int p[],int n,int nop)
{
      int i,a[100],s=0;
      float avgtt=0,avgwt=0;
      //cout <<"*************\n";
      //cout << "GANTT CHART\n";
      //cout << "0";
      for(i=0;i<n-1;i++)
      {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }

              s++;
        //      cout << " ->" <<proc[p[i]].pid <<  "<-" << s;
              //seq_2.push_back(proc[p[i]].pid);
              gant_chart_nums_2.push_back(s);
              proc[p[i]].wt=s-proc[p[i]].at-proc[p[i]].tt;
      }
return gant_chart_nums_2 ;
}


float ana_elavwt(procpirpreem proc[],int p[],int n,int nop)
{
      int i,a[100],s=0;
      float avgtt=0,avvgwtt=0;
      //vector<int>seq_2;
      //vector<float> gant_chart_nums_2;
      //cout <<"*************\n";
      //cout << "GANTT CHART\n";
      //cout << "0";
      for(i=0;i<n-1;i++)
      {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }

              s++;
              //cout << " ->" <<proc[p[i]].pid <<  "<-" << s;
              //seq_2.push_back(proc[p[i]].pid);
              //gant_chart_nums_2.push_back(s);
              proc[p[i]].wt=s-proc[p[i]].at-proc[p[i]].tt;
      }

    for(i=0;i<nop;i++)
      {
              proc[i].tt+=proc[i].wt;
              avvgwtt+=proc[i].wt;
              avgtt+=proc[i].tt;
      }
      //cout << "\n***************\n";
      //cout << "Pro\tArTi\tBuTi\tTaTi\tWtTi\n";
      //cout << "*************\n";
      for(i=0;i<nop;i++)
      {
cout << proc[i].pid<< "\t" << proc[i].at << "\t" << proc[i].cbt << "\t" << proc[i].tt<< "\t"  << proc[i].wt << "\n" ;
      }
      //cout << "*************\n";
      avvgwtt = avvgwtt/(float)nop;
      avgtt = avgtt/nop;
      cout << "Average Waiting Time :" << avvgwtt;
      cout << "Average Turnaround Time : " << avgtt;
      cout << endl;
        /*int size1 = seq_2.size();

      for(int i=0;i<size1;i++)
      {
          cout << seq_2[i]<< " ";
      }
      cout << endl ;
        int size2 = seq_2.size();

              for(int i=0;i<size2;i++)
      {
          cout << gant_chart_nums_2[i]<< " ";
      }*/
        return avvgwtt;
}

int arefinish(procpirpreem proc[],int n)
{
       int i;
       for(i=0;i<n;i++)
              if(proc[i].st==0)
                     return 0;
       return 1;
}
/*******RR NEW***********/
typedef struct process_RB
{
    QString pro_id;
    float st, ct, at, bt, ta, wt;


}process;



bool compare_at(process_RB a, process_RB b)

{

    return a.at<b.at;
}


float avgWT_RB(int n, int quantum, vector<process_RB>pro)
{
    queue<process_RB> qready;
    queue<process_RB> qexc;
    process_RB temp;
    int d_count = 0, i = 0, clk = 0, qt_clk = 0, count = 0, b = pro.size(), flag = 0;
    while (count<n || !(qready.empty()) || i<n)
    {
        if (count < n)
        {
            if (pro[count].at == 0) {
                qready.push(pro[count]);
                count++;
            }

            else if (clk == 0 && qready.empty() && count == 0)
            {
                process_RB dummy;
                dummy.pro_id = "  Gap";
                dummy.wt = 0;
                dummy.at = 0;
                dummy.st = 0;
                dummy.bt = pro[count].at;
                dummy.ct = pro[count].at;
                qexc.push(dummy);
                qt_clk += pro[count].at;
                d_count++;
            }
        }
        /*

        if (count<n)
        {
        if (pro[count].at == clk) {
        qready.push(pro[count]);
        count++;
        }
        }
        */
        while (true) {
            if (count<n)
            {
                if (pro[count].at == clk) {
                    qready.push(pro[count]);
                    count++;
                }
                else { break; }
            }
            else { break; }
        }

        if (flag == 1 && qt_clk == clk)
        {
            qready.push(temp);
            flag = 0;
        }

        if (qready.empty() && i<n&&clk != 0)
        {
            process_RB dummy;
            dummy.pro_id = "   Gap";
            dummy.wt = 0;
            dummy.at = clk;
            dummy.st = qt_clk;
            dummy.bt = pro[count].at - dummy.st;
            if (dummy.bt >= quantum) {
                dummy.bt = quantum;
                dummy.ct = dummy.st + quantum;
                qexc.push(dummy);
                qt_clk += quantum;

            }
            else {
                qexc.push(dummy);
                qt_clk += dummy.bt;
                dummy.ct = dummy.st + dummy.bt;
            }
            d_count++;
        }


        if (qready.empty() == 0 && qt_clk == clk)
        {
            temp = qready.front();
            if (temp.bt <= quantum)
            {
                temp.st = clk;
                temp.ct = temp.st + temp.bt;
                temp.wt = -temp.at + temp.st;
                qexc.push(temp);
                qready.pop();
                qt_clk += temp.bt;
                i++;
            }
            else
            {
                temp.st = clk;
                temp.ct = temp.st + quantum;
                temp.wt = -temp.at + temp.st;
                qexc.push(temp);
                qready.pop();
                qt_clk += quantum;
                flag = 1;
                temp.at = temp.ct;
                temp.bt -= quantum;
            }
        }

        clk++;

    }
    float avgwt = 0, wt = 0;
    int m = qexc.size(); // size of gantt chart
    vector<float>compprint(m); //printing completion time
    vector<QString>PID(m); // printing name of process on gantt chart
    for (i = 0; i<m; i++)
    {
        process_RB temp2 = qexc.front();
        float temp3 = temp2.wt;
        compprint[i] = temp2.ct;
        PID[i] = temp2.pro_id;
        //desplaying all the values
       // cout << "P_no " << temp2.pro_id << "\t" << "at " << temp2.at << "\t" << "bt " << temp2.bt << "\t" << "ct " << temp2.ct << "\t"
        //    << "wt " << temp2.wt << "\t" << "st " << temp2.st;
        cout << endl;
        wt += temp3;
        qexc.pop();


    }
    //cout<<endl<<compprint<<" ";
    cout << m << endl;
    avgwt = wt / (float)(n);
    return avgwt;
}
vector<float> avgWT_RB_VEFLO(int n, int quantum, vector<process_RB>pro)
{
    queue<process_RB> qready;
    queue<process_RB> qexc;
    process_RB temp;
    int d_count = 0, i = 0, clk = 0, qt_clk = 0, count = 0, b = pro.size(), flag = 0;
    while (count<n || !(qready.empty()) || i<n)
    {
        if (count < n)
        {
            if (pro[count].at == 0) {
                qready.push(pro[count]);
                count++;
            }

            else if (clk == 0 && qready.empty() && count == 0)
            {
                process_RB dummy;
                dummy.pro_id = "  Gap";
                dummy.wt = 0;
                dummy.at = 0;
                dummy.st = 0;
                dummy.bt = pro[count].at;
                dummy.ct = pro[count].at;
                qexc.push(dummy);
                qt_clk += pro[count].at;
                d_count++;
            }
        }
        /*

        if (count<n)
        {
        if (pro[count].at == clk) {
        qready.push(pro[count]);
        count++;
        }
        }
        */
        while (true) {
            if (count<n)
            {
                if (pro[count].at == clk) {
                    qready.push(pro[count]);
                    count++;
                }
                else { break; }
            }
            else { break; }
        }

        if (flag == 1 && qt_clk == clk)
        {
            qready.push(temp);
            flag = 0;
        }

        if (qready.empty() && i<n&&clk != 0)
        {
            process_RB dummy;
            dummy.pro_id = "   Gap";
            dummy.wt = 0;
            dummy.at = clk;
            dummy.st = qt_clk;
            dummy.bt = pro[count].at - dummy.st;
            if (dummy.bt >= quantum) {
                dummy.bt = quantum;
                dummy.ct = dummy.st + quantum;
                qexc.push(dummy);
                qt_clk += quantum;

            }
            else {
                qexc.push(dummy);
                qt_clk += dummy.bt;
                dummy.ct = dummy.st + dummy.bt;
            }
            d_count++;
        }


        if (qready.empty() == 0 && qt_clk == clk)
        {
            temp = qready.front();
            if (temp.bt <= quantum)
            {
                temp.st = clk;
                temp.ct = temp.st + temp.bt;
                temp.wt = -temp.at + temp.st;
                qexc.push(temp);
                qready.pop();
                qt_clk += temp.bt;
                i++;
            }
            else
            {
                temp.st = clk;
                temp.ct = temp.st + quantum;
                temp.wt = -temp.at + temp.st;
                qexc.push(temp);
                qready.pop();
                qt_clk += quantum;
                flag = 1;
                temp.at = temp.ct;
                temp.bt -= quantum;
            }
        }

        clk++;

    }
    float avgwt = 0, wt = 0;
    int m = qexc.size(); // size of gantt chart
    vector<float>compprint(m); //printing completion time
    vector<QString>PID(m); // printing name of process on gantt chart
    for (i = 0; i<m; i++)
    {
        process_RB temp2 = qexc.front();
        float temp3 = temp2.wt;
        compprint[i] = temp2.ct;
        PID[i] = temp2.pro_id;
        //desplaying all the values
//        cout << "P_no " << temp2.pro_id << "\t" << "at " << temp2.at << "\t" << "bt " << temp2.bt << "\t" << "ct " << temp2.ct << "\t"
//            << "wt " << temp2.wt << "\t" << "st " << temp2.st;
//        cout << endl;
        wt += temp3;
        qexc.pop();


    }
    //cout<<endl<<compprint<<" ";
    cout << m << endl;
    avgwt = wt / (float)(n);
    return compprint ;
}
vector<QString> avgWT_RB_PID(int n, int quantum, vector<process_RB>pro)
{
    queue<process_RB> qready;
    queue<process_RB> qexc;
    process_RB temp;
    int d_count = 0, i = 0, clk = 0, qt_clk = 0, count = 0, b = pro.size(), flag = 0;
    while (count<n || !(qready.empty()) || i<n)
    {
        if (count < n)
        {
            if (pro[count].at == 0) {
                qready.push(pro[count]);
                count++;
            }

            else if (clk == 0 && qready.empty() && count == 0)
            {
                process_RB dummy;
                dummy.pro_id = "  Gap";
                dummy.wt = 0;
                dummy.at = 0;
                dummy.st = 0;
                dummy.bt = pro[count].at;
                dummy.ct = pro[count].at;
                qexc.push(dummy);
                qt_clk += pro[count].at;
                d_count++;
            }
        }
        /*

        if (count<n)
        {
        if (pro[count].at == clk) {
        qready.push(pro[count]);
        count++;
        }
        }
        */
        while (true) {
            if (count<n)
            {
                if (pro[count].at == clk) {
                    qready.push(pro[count]);
                    count++;
                }
                else { break; }
            }
            else { break; }
        }

        if (flag == 1 && qt_clk == clk)
        {
            qready.push(temp);
            flag = 0;
        }

        if (qready.empty() && i<n&&clk != 0)
        {
            process_RB dummy;
            dummy.pro_id = "   Gap";
            dummy.wt = 0;
            dummy.at = clk;
            dummy.st = qt_clk;
            dummy.bt = pro[count].at - dummy.st;
            if (dummy.bt >= quantum) {
                dummy.bt = quantum;
                dummy.ct = dummy.st + quantum;
                qexc.push(dummy);
                qt_clk += quantum;

            }
            else {
                qexc.push(dummy);
                qt_clk += dummy.bt;
                dummy.ct = dummy.st + dummy.bt;
            }
            d_count++;
        }


        if (qready.empty() == 0 && qt_clk == clk)
        {
            temp = qready.front();
            if (temp.bt <= quantum)
            {
                temp.st = clk;
                temp.ct = temp.st + temp.bt;
                temp.wt = -temp.at + temp.st;
                qexc.push(temp);
                qready.pop();
                qt_clk += temp.bt;
                i++;
            }
            else
            {
                temp.st = clk;
                temp.ct = temp.st + quantum;
                temp.wt = -temp.at + temp.st;
                qexc.push(temp);
                qready.pop();
                qt_clk += quantum;
                flag = 1;
                temp.at = temp.ct;
                temp.bt -= quantum;
            }
        }

        clk++;

    }
    float avgwt = 0, wt = 0;
    int m = qexc.size(); // size of gantt chart
    vector<float>compprint(m); //printing completion time
    vector<QString>PID(m); // printing name of process on gantt chart
    for (i = 0; i<m; i++)
    {
        process_RB temp2 = qexc.front();
        float temp3 = temp2.wt;
        compprint[i] = temp2.ct;
        PID[i] = temp2.pro_id;
        //desplaying all the values
        //cout << "P_no " << temp2.pro_id << "\t" << "at " << temp2.at << "\t" << "bt " << temp2.bt << "\t" << "ct " << temp2.ct << "\t"
        //    << "wt " << temp2.wt << "\t" << "st " << temp2.st;
        //cout << endl;
        wt += temp3;
        qexc.pop();


    }
    //cout<<endl<<compprint<<" ";
    cout << m << endl;
    avgwt = wt / (float)(n);
    return PID ;
}

int avgWT_RB_INDEX(int n, int quantum, vector<process_RB>pro)
{
    queue<process_RB> qready;
    queue<process_RB> qexc;
    process_RB temp;
    int d_count = 0, i = 0, clk = 0, qt_clk = 0, count = 0, b = pro.size(), flag = 0;
    while (count<n || !(qready.empty()) || i<n)
    {
        if (count < n)
        {
            if (pro[count].at == 0) {
                qready.push(pro[count]);
                count++;
            }

            else if (clk == 0 && qready.empty() && count == 0)
            {
                process_RB dummy;
                dummy.pro_id = "  Gap";
                dummy.wt = 0;
                dummy.at = 0;
                dummy.st = 0;
                dummy.bt = pro[count].at;
                dummy.ct = pro[count].at;
                qexc.push(dummy);
                qt_clk += pro[count].at;
                d_count++;
            }
        }
        /*

        if (count<n)
        {
        if (pro[count].at == clk) {
        qready.push(pro[count]);
        count++;
        }
        }
        */
        while (true) {
            if (count<n)
            {
                if (pro[count].at == clk) {
                    qready.push(pro[count]);
                    count++;
                }
                else { break; }
            }
            else { break; }
        }

        if (flag == 1 && qt_clk == clk)
        {
            qready.push(temp);
            flag = 0;
        }

        if (qready.empty() && i<n&&clk != 0)
        {
            process_RB dummy;
            dummy.pro_id = "   Gap";
            dummy.wt = 0;
            dummy.at = clk;
            dummy.st = qt_clk;
            dummy.bt = pro[count].at - dummy.st;
            if (dummy.bt >= quantum) {
                dummy.bt = quantum;
                dummy.ct = dummy.st + quantum;
                qexc.push(dummy);
                qt_clk += quantum;

            }
            else {
                qexc.push(dummy);
                qt_clk += dummy.bt;
                dummy.ct = dummy.st + dummy.bt;
            }
            d_count++;
        }


        if (qready.empty() == 0 && qt_clk == clk)
        {
            temp = qready.front();
            if (temp.bt <= quantum)
            {
                temp.st = clk;
                temp.ct = temp.st + temp.bt;
                temp.wt = -temp.at + temp.st;
                qexc.push(temp);
                qready.pop();
                qt_clk += temp.bt;
                i++;
            }
            else
            {
                temp.st = clk;
                temp.ct = temp.st + quantum;
                temp.wt = -temp.at + temp.st;
                qexc.push(temp);
                qready.pop();
                qt_clk += quantum;
                flag = 1;
                temp.at = temp.ct;
                temp.bt -= quantum;
            }
        }

        clk++;

    }
    float avgwt = 0, wt = 0;
    int m = qexc.size(); // size of gantt chart
    vector<float>compprint(m); //printing completion time
    vector<QString>PID(m); // printing name of process on gantt chart
    for (i = 0; i<m; i++)
    {
        process_RB temp2 = qexc.front();
        float temp3 = temp2.wt;
        compprint[i] = temp2.ct;
        PID[i] = temp2.pro_id;
        //desplaying all the values
        //cout << "P_no " << temp2.pro_id << "\t" << "at " << temp2.at << "\t" << "bt " << temp2.bt << "\t" << "ct " << temp2.ct << "\t"
          //  << "wt " << temp2.wt << "\t" << "st " << temp2.st;
        //cout << endl;
        wt += temp3;
        qexc.pop();


    }
    //cout<<endl<<compprint<<" ";
    cout << m << endl;
    avgwt = wt / (float)(n);
    return m ;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
