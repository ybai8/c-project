#include<iostream>
using namespace std;

class JulDate {
private:
    double jday;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int wday;
public:
    JulDate(int year=2000,int month=1,int day=0,int hour=0,int min=00,int sec=00):
    year(year),month(month),day(day),hour(hour),min(min),sec(sec){}
        static JulDate now(){//Get time now
            struct tm *ptr;
            time_t lt;
            lt =time(NULL);
            ptr=localtime(&lt);
            //cout<<ptr->tm_wday;
            return date(ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday,ptr->tm_hour,ptr->tm_min,ptr->tm_sec);
        }
        friend bool g(JulDate a){//leap year or not
            if((a.year%4==0&&a.year%100!=0)||a.year%400==0)
                return 1;
            else
                return 0;
        }

        friend JulDate operator + (JulDate a,int b) {//plus several days
            const int daysinmonth1[12]={31,29,31,30,31,30,31,31,30,31,30,31};
            const int daysinmonth2[12]={31,28,31,30,31,30,31,31,30,31,30,31};

            if(a.month==12&&a.day+b>31)
                return JulDate (a.year+1,1,b-31+a.day,a.hour,a.min,a.sec);
            if(g(a)&&a.month<12&&a.day+b>daysinmonth1[a.month-1])
               return JulDate(a.year,a.month+1,b-daysinmonth1[a.month]+a.day-1,a.hour,a.min,a.sec);
            if(!g(a)&&a.month<12&&a.day+b>daysinmonth2[a.month]-1)
                return JulDate(a.year,a.month+1,b-daysinmonth2[a.month-1]+a.day-1,a.hour,a.min,a.sec);
            else
                return JulDate(a.year,a.month,a.day+b,a.hour,a.min,a.sec);
        }
            friend bool weekday(JulDate d){//If the day is weekend
                 if(d.wday==0||d.wday==6)
                             return 1;//weekend
                        else
                                    return 0;//weekday
            }

         friend string festival(JulDate d){//If the day is holiday
                if(d.month==1&&d.week==1&&d.day>20&&d.day<28)
                    return s="Martin Luther King,Jr.Day No class!";
                if(d.month==2&&d.week==1&&d.day>20&&d.day<28)
                    return s="Presidents' Day No class!";
                if(d.month==5&&a.week==1&&d.day>24&&d.day<=31)
                    return s="Memorial Day No class!";
                if(d.month==7&&d.day==4)
                    return s="Independence Day No class!";
                if(d.month==9&&a.week==1&&d.day>=1&&d.day<7)
                    return s="Labor Day No class!";
                if(d.month==10&&d.week==1&&d.day>13&&d.day<21)
                    return s="Fall Recess No class!";
                if(d.month==11&&d.day==11) 
                    return s="Veterans Day No class!";
                if(d.month==11&&d.week=4&&d.day>=25&&d.day<=30)
                    return s="Thanksgiving  Recess No class!";
            }
    friend makeup{}//If miss up too many class, make up on saturday
    
         };
class file{//read in files with calendar, and write them out
private:
    string s;
    public:
    file(string s):s(s){
        ifstream infile;
        infile.open(s);}



};
//create buttons "Create assignment", "backward one week", "calendar"
//mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//main.cpp
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
