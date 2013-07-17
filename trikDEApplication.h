#pragma once

#include <QApplication>

class TrikDEApplication : public QApplication
{
    Q_OBJECT
public:
    explicit TrikDEApplication(int &argc, char **argv);
    bool notify(QObject *receiver, QEvent *event);
};
