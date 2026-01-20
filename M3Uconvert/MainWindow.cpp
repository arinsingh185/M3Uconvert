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
	QStringList filter;

	filter << "*.chd";
	

	dir = QFileDialog::getExistingDirectory(this, tr("Open folder location"),
		"/home",
		QFileDialog::ShowDirsOnly);
	dir.setNameFilters(filter);
	files = dir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

	foreach(QString file, files) {
		ui.fileViewer->addItem(file);
	}
}

void MainWindow::on_Organize_clicked() {

	QStringList newFolders;

	if (files.isEmpty()){
		ui.ErrorBox->setPlainText("Error: No folder selected or folder is empty.");
		return;
	}

	foreach(QString file, files) {
		fileName = file.first(file.indexOf(" ("));
		
		if (dir.mkdir(fileName)) {
			qDebug() << "Directory created";
			newFolders.append(dir.path() + "/" + fileName);
		}
		else {
			qDebug() << "Directory already exists";
		}
		move(dir.absoluteFilePath(file));
		
	}

	

	m3uGeneration(newFolders);

}

void MainWindow::move(QDir filePath) {
	dir.rename(filePath.path(), dir.path() + "/" + fileName + "/" + filePath.dirName());
}

void MainWindow::m3uGeneration(QStringList folders) {
	foreach(QString folder, folders) {
		QDir currDir = folder;
		QStringList roms = currDir.entryList(QDir::Files);
		QFile m3u(folder + "/" + currDir.dirName() + ".m3u");
		if(m3u.open(QFile::WriteOnly | QFile::Truncate)) {
			foreach(QString rom, roms) {
					QTextStream out(&m3u);
					out << rom << "\n";
				}
			}
		}
	}





