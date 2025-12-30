#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{}

void MainWindow::dragEnterEvent(QDragEnterEvent* event) {
	if (event->mimeData()->hasUrls()) {
		event->acceptProposedAction();
	}
}

void MainWindow::dropEvent(QDropEvent* event) {
	int row{ 0 };
	if (event->mimeData()->hasUrls()) {
		foreach(QUrl url, event->mimeData()->urls()) {
			ui.listFileWidget->insertItem(row, url.fileName());
			row++;

		}
	}

}

