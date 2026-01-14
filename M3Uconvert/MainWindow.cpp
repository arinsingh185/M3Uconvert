#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MainWindow::~MainWindow()
{}

void MainWindow::on_SelectFolder_clicked() {
	dir = QFileDialog::getExistingDirectory(this, tr("Open folder location"),
		"/home",
		QFileDialog::ShowDirsOnly);
	
	files = dir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

	foreach(QString file, files) {
		ui.fileViewer->addItem(file);
	}
}



