#include "baseWidget.h"

BaseWidget::BaseWidget(QWidget *parent) :
    QWidget(parent)
{
}

void BaseWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_F2:
        {
            emit menuPressed();
            break;
        }
        case Qt::Key_F4:
        {
            emit downPressed();
            break;
        }
        case Qt::Key_F5:
        {
            emit upPressed();
            break;
        }
        case Qt::Key_F6:
        {
            emit enterPressed();
            break;
        }
        default:
        {
            QWidget::keyPressEvent(event);
            break;
        }
    }
}
