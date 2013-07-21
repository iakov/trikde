#pragma once

#include <QLabel>
#include <QHBoxLayout>
#include <QString>

class ShowIPAddressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowIPAddressWidget(QWidget *parent = 0);
    ~ShowIPAddressWidget();
    static QString getTitle();
    
private:
    QLabel addressLabel;
    QHBoxLayout layout;
    QString getAddress();

protected:
    void keyPressEvent(QKeyEvent *event);
};
