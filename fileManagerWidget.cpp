#include "fileManagerWidget.h"
#include <QCoreApplication>
#include <QKeyEvent>
#include <QProcess>

FileManagerWidget::FileManagerWidget(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowState(Qt::WindowFullScreen);

    fileSystemModel.setRootPath("/");
    fileSystemModel.setFilter(QDir::AllEntries | QDir::System | QDir::NoDot);

    fileSystemView.setModel(&fileSystemModel);

    layout.addWidget(&currentPathLabel);
    layout.addWidget(&fileSystemView);
    setLayout(&layout);

    showCurrentDir();
}

FileManagerWidget::~FileManagerWidget()
{
}

QString FileManagerWidget::getTitle()
{
    return QString("File Manager");
}

void FileManagerWidget::open()
{
     const QModelIndex &index = fileSystemView.currentIndex();
     if (fileSystemModel.isDir(index))
     {
         QDir::setCurrent(fileSystemModel.filePath(index));
         showCurrentDir();
     }
     else
         QProcess::execute(fileSystemModel.filePath(index));
}

void FileManagerWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Meta:
        {
            close();
            break;
        }
        case Qt::Key_Enter:
        {
            open();
            break;
        }
        default:
        {
            QWidget::keyPressEvent(event);
            break;
        }
    }
}

void FileManagerWidget::showCurrentDir()
{
    currentPathLabel.setText(QDir::currentPath());
    fileSystemView.setRootIndex(fileSystemModel.index(QDir::currentPath()));
}
