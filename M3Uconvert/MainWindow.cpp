#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_SelectFolder_clicked() {
    QStringList filter;

    filter << "*.chd";


    dir = QDir(QFileDialog::getExistingDirectory(this, tr("Open folder location"),
        "/home",
        QFileDialog::ShowDirsOnly));
    dir.setNameFilters(filter);
    files = dir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    foreach(QString file, files) {
        ui.fileViewer->addItem(file);
    }
}

void MainWindow::on_Organize_clicked() {
    if (files.isEmpty()) {
        ui.ErrorBox->setPlainText("Error: No folder selected or folder is empty.");
        return;
    }

    QMap<QString, QStringList> gameGroups;

    foreach(QString file, files) {
        if (!file.endsWith(".chd", Qt::CaseInsensitive))
            continue;

        int idx = file.indexOf(" (");
        if (idx == -1)
            continue;

        QString baseName = file.left(idx);
        gameGroups[baseName].append(file);
    }

    m3uGeneration(gameGroups);
}

void MainWindow::m3uGeneration(const QMap<QString, QStringList>& gameGroups) {
    for (auto it = gameGroups.constBegin(); it != gameGroups.constEnd(); ++it) {
        QString gameName = it.key();
        QStringList discs = it.value();

        if (discs.size() < 2)
            continue;

        discs.sort(); 

        QFile m3u(dir.filePath(gameName + ".m3u"));
        if (m3u.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream out(&m3u);
            foreach(const QString & disc, discs) {
                out << disc << "\n";
            }
            m3u.close();
            qDebug() << "Created" << gameName + ".m3u";
        }
        else {
            qDebug() << "Failed to write m3u for" << gameName;
        }
    }
}



