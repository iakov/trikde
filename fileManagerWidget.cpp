#include "fileManagerWidget.h"
#include <QCoreApplication>
#include <QKeyEvent>

FileManagerWidget::FileManagerWidget(QWidget *parent) :
    BaseWidget(parent)
{
    setWindowState(Qt::WindowFullScreen);

    currentPathLabel = new QLabel;

    fileSystemModel = new QFileSystemModel;
    fileSystemModel->setRootPath("/");
    fileSystemModel->setFilter(QDir::AllEntries | QDir::System | QDir::NoDot);

    fileSystemView = new QListView;
    fileSystemView->setModel(fileSystemModel);

    layout = new QVBoxLayout;
    layout->addWidget(currentPathLabel);
    layout->addWidget(fileSystemView);
    setLayout(layout);

    connect(this, SIGNAL(upPressed()), this, SLOT(moveUp()));
    connect(this, SIGNAL(downPressed()), this, SLOT(moveDown()));
    connect(this, SIGNAL(enterPressed()), this, SLOT(open()));
    connect(this, SIGNAL(menuPressed()), this, SLOT(close()));

    showCurrentDir();
}

FileManagerWidget::~FileManagerWidget()
{
    delete layout;
    delete fileSystemView;
    delete currentPathLabel;
}

void FileManagerWidget::open()
{
     const QModelIndex &index = fileSystemView->currentIndex();
     if (fileSystemModel->isDir(index))
     {
         QDir::setCurrent(fileSystemModel->filePath(index));
         showCurrentDir();
     }
}

void FileManagerWidget::moveUp()
{
    QCoreApplication::postEvent(fileSystemView, new QKeyEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier));
}

void FileManagerWidget::moveDown()
{
    QCoreApplication::postEvent(fileSystemView, new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier));
}

void FileManagerWidget::showCurrentDir()
{
    currentPathLabel->setText(QDir::currentPath());
    fileSystemView->setRootIndex(fileSystemModel->index(QDir::currentPath()));
}
