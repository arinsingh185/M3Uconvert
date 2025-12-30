#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QMainWindow>
#include "ui_m3uconvert.h"
#include <iostream>
#include <qlistwidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	
private slots:
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* event);

private:
    Ui::M3UconvertClass ui;
    //QListWidget* listFileWidget = new QListWidget();

};

#endif
