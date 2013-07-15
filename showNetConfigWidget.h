#pragma once

#include "baseWidget.h"
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>

class ShowNetConfigWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit ShowNetConfigWidget(QWidget *parent = 0);
    ~ShowNetConfigWidget();
    static QString getTitle();

private:
    QLabel *titleLabel;
    QTextEdit *netConfigTextEdit;
    QVBoxLayout *layout;
    void showNetConfig();
    
private slots:
    void moveUp();
    void moveDown();
};
