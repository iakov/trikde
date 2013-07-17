#include "showIPAddressWidget.h"
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QAbstractSocket>
#include <QKeyEvent>

ShowIPAddressWidget::ShowIPAddressWidget(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowState(Qt::WindowFullScreen);

    addressLabel = new QLabel;
    addressLabel->setText(getAddress());
    addressLabel->setAlignment(Qt::AlignCenter);

    layout = new QHBoxLayout;
    layout->addWidget(addressLabel);
    setLayout(layout);
}

ShowIPAddressWidget::~ShowIPAddressWidget()
{
    delete layout;
    delete addressLabel;
}

QString ShowIPAddressWidget::getTitle()
{
    return QString("Show IP address");
}


QString ShowIPAddressWidget::getAddress()
{
    QString addressString;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
        {
            addressString = address.toString();
            break;
        }
    }
    return addressString;
}

void ShowIPAddressWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Meta: case Qt::Key_Enter:
        {
            close();
            break;
        }
        default:
        {
            QWidget::keyPressEvent(event);
            break;
        }
    }
}
