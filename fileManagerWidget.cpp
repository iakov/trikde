#include "fileManagerWidget.h"
#include <QCoreApplication>
#include <QKeyEvent>

FileManagerWidget::FileManagerWidget(QWidget *parent) :
    BaseWidget(parent)
{
    setWindowState(Qt::WindowFullScreen);

    pathLabel = new QLabel;
    fileList = new QListView;
    layout = new QVBoxLayout;
    layout->addWidget(pathLabel);
    layout->addWidget(fileList);
    setLayout(layout);
    fileSystemModel = new QFileSystemModel;
    fileSystemModel->setRootPath("/");
    fileSystemModel->setFilter(QDir::AllEntries | QDir::System | QDir::NoDot);
    fileList->setModel(fileSystemModel);

    connect(this, SIGNAL(upPressed()), this, SLOT(moveUp()));
    connect(this, SIGNAL(downPressed()), this, SLOT(moveDown()));
    connect(this, SIGNAL(enterPressed()), this, SLOT(open()));
    connect(this, SIGNAL(menuPressed()), this, SLOT(close()));

    printFileList();
}

FileManagerWidget::~FileManagerWidget()
{
    delete layout;
    delete fileList;
    delete pathLabel;
}

void FileManagerWidget::open()
{
     const QModelIndex &index = fileList->currentIndex();
     if (fileSystemModel->isDir(index))
     {
         QDir::setCurrent(fileSystemModel->filePath(index));
         printFileList();
     }
}

void FileManagerWidget::moveUp()
{
    QCoreApplication::postEvent(fileList, new QKeyEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier));
}

void FileManagerWidget::moveDown()
{
    QCoreApplication::postEvent(fileList, new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier));
}

void FileManagerWidget::printFileList()
{
    pathLabel->setText(QDir::currentPath());
    fileList->setRootIndex(fileSystemModel->index(QDir::currentPath()));
}
