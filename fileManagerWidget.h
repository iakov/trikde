#pragma once

#include "baseWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QListView>
#include <QFileSystemModel>

class FileManagerWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit FileManagerWidget(QWidget *parent = 0);
    ~FileManagerWidget();
    
private:
    QVBoxLayout *layout;
    QLabel *currentPathLabel;
    QListView *fileSystemView;
    QFileSystemModel *fileSystemModel;

    void showCurrentDir();

private slots:
    void open();
    void moveUp();
    void moveDown();
};
