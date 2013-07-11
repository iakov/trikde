#include "showIPAddressWidget.h"
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QAbstractSocket>

ShowIPAddressWidget::ShowIPAddressWidget(QWidget *parent) :
    BaseWidget(parent)
{
    setWindowState(Qt::WindowFullScreen);

    addressLabel = new QLabel;
    addressLabel->setText(getAddress());
    addressLabel->setAlignment(Qt::AlignCenter);

    layout = new QHBoxLayout;
    layout->addWidget(addressLabel);
    setLayout(layout);

    connect(this, SIGNAL(menuPressed()), this, SLOT(close()));
    connect(this, SIGNAL(enterPressed()), this, SLOT(close()));
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
