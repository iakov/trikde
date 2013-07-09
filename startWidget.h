#pragma once

#include "baseWidget.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QList>

class StartWidget : public BaseWidget
{
    Q_OBJECT
    
public:
    StartWidget(QWidget *parent = 0);
    ~StartWidget();

private:
    QVBoxLayout *layout;
    QLabel *titleLabel;
    QListView *menuView;
    QStandardItemModel *menuModel;
    QList<QStandardItem *> *menuItems;

private slots:
    void moveUp();
    void moveDown();
    void launch();
};
