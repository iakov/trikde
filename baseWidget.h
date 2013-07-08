#pragma once

#include <QWidget>
#include <QLayout>

class BaseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseWidget(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);
    
signals:
    void upPressed();
    void downPressed();
    void enterPressed();
};
