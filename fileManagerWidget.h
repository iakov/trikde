#pragma once

#include <QVBoxLayout>
#include <QLabel>
#include <QListView>
#include <QFileSystemModel>
#include <QString>

class FileManagerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileManagerWidget(QWidget *parent = 0);
    ~FileManagerWidget();
    static const QString &getTitle();
    
private:
    QVBoxLayout layout;
    QLabel currentPathLabel;
    QListView fileSystemView;
    QFileSystemModel fileSystemModel;

    void showCurrentDir();
    void open();

protected:
    void keyPressEvent(QKeyEvent *event);
};
