#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QList>
#include <QString>

class StartWidget : public QWidget
{
    Q_OBJECT
    
public:
    StartWidget(QWidget *parent = 0);
    ~StartWidget();

private:
    QString exitItemTitle;
    QVBoxLayout layout;
    QLabel titleLabel;
    QListView menuView;
    QStandardItemModel menuModel;
    QList<QStandardItem *> menuItems;

    void launch();

protected:
    void keyPressEvent(QKeyEvent *event);
};
