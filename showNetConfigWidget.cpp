#include "showNetConfigWidget.h"
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QCoreApplication>
#include <QKeyEvent>

ShowNetConfigWidget::ShowNetConfigWidget(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowState(Qt::WindowFullScreen);

    titleLabel = new QLabel;
    titleLabel->setText("Network Configuration");

    netConfigTextEdit = new QTextEdit;
    netConfigTextEdit->setReadOnly(true);

    layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(netConfigTextEdit);
    setLayout(layout);

    showNetConfig();
}

ShowNetConfigWidget::~ShowNetConfigWidget()
{
    delete layout;
    delete netConfigTextEdit;
    delete titleLabel;
}

QString ShowNetConfigWidget::getTitle()
{
    return QString("Show network configuration");
}

void ShowNetConfigWidget::showNetConfig()
{
    foreach (const QNetworkInterface &interface, QNetworkInterface::allInterfaces())
    {
        netConfigTextEdit->append(interface.name());
        foreach (const QNetworkAddressEntry &entry, interface.addressEntries())
        {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol)
            {
                netConfigTextEdit->append(QString("IP address: ") + entry.ip().toString());
                netConfigTextEdit->append(QString("Netmask: ") + entry.netmask().toString());
            }
        }
        netConfigTextEdit->append(QString("Hardware address: ") + interface.hardwareAddress());
        netConfigTextEdit->append(QString("\n"));
    }
}

void ShowNetConfigWidget::keyPressEvent(QKeyEvent *event)
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
