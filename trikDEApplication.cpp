#include "trikDEApplication.h"
#include <QKeyEvent>

TrikDEApplication::TrikDEApplication(int &argc, char **argv) :
    QApplication(argc, argv)
{
}

bool TrikDEApplication::notify(QObject *receiver, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(event);
        switch (keyEvent->key())
        {
            case Qt::Key_F2:
            {
                return QApplication::notify(receiver, new QKeyEvent(QEvent::KeyPress, Qt::Key_Meta, Qt::NoModifier));
            }
            case Qt::Key_F3:
            {
                return QApplication::notify(receiver, new QKeyEvent(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier));
            }
            case Qt::Key_F4:
            {
                return QApplication::notify(receiver, new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier));
            }
            case Qt::Key_F5:
            {
                return QApplication::notify(receiver, new QKeyEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier));
            }
            case Qt::Key_F6:
            {
                return QApplication::notify(receiver, new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));
            }
            case Qt::Key_F7:
            {
                return QApplication::notify(receiver, new QKeyEvent(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier));
            }
            default:
            {
                return QApplication::notify(receiver, event);
            }
        }
    }
    else
        return QApplication::notify(receiver, event);
}
