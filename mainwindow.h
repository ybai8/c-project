/*Author:Yang Bai

  Header file of class "MainWindow",define the function we need,
  like create,delete,edit...




*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"createassignmentcontroller.h"

#include <QMainWindow>
#include<QHash>

namespace Ui {
class MainWindow;
}
class QListWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(createassignmentcontroller *controller,QWidget *parent = 0);
    ~MainWindow();
public slots:
    void createEntry();
    void deleteEntry();
    void editEntry();
    void saveEntry();
    void discardEntry();
    void resetEntry();
private:
    Ui::MainWindow *ui;
    createassignmentcontroller *m_controller;
    QHash<QListWidgetItem*,createassignmententry*>m_entryMap;
    void setupConnections();

};

#endif // MAINWINDOW_H
