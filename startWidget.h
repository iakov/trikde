#pragma once

#include "baseWidget.h"
#include <QWidget>

class StartWidget : public BaseWidget
{
    Q_OBJECT
    
public:
    StartWidget(QWidget *parent = 0);
    ~StartWidget();
};
