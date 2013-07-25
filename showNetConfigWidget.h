#pragma once

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QList>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QListView>

class ShowNetConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowNetConfigWidget(QWidget *parent = 0);
    ~ShowNetConfigWidget();
    static const QString &getTitle();

private:
    QLabel titleLabel;
    QListView configView;
    QList<QStandardItem *> configItems;
    QStandardItemModel configModel;
    QVBoxLayout layout;
    void generateNetConfigList();
    
protected:
    void keyPressEvent(QKeyEvent *event);
};
