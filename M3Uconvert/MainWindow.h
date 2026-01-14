#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QMainWindow>
#include "ui_m3uconvert.h"
#include <iostream>
#include <qlistwidget.h>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QFileDialog>
#include <QListView>
#include <QDir>



struct fileInfo{

	QString fileName;
	QString fileDir;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 
	
private slots:
	void on_SelectFolder_clicked();

private:
    Ui::M3UconvertClass ui;
    //QListWidget* listFileWidget = new QListWidget();
    //std::vector<fileInfo> files;
    QStringList files;
    QDir dir;
};

#endif
