#pragma once

#include "baseWidget.h"
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>

class ShowNetConfigWidget : public QWidget
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
    
protected:
    void keyPressEvent(QKeyEvent *event);
};
