#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QMainWindow>
#include "ui_m3uconvert.h"
#include <iostream>
#include <qlistwidget.h>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QListView>
#include <QDir>
#include <QTextStream>
#include <QMap>



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();


private slots:
	void on_SelectFolder_clicked();
	void on_Organize_clicked();

private:
	void m3uGeneration(const QMap<QString, QStringList>& gameGroups);

	Ui::M3UconvertClass ui;
	QStringList files;
	QDir dir;


};

#endif