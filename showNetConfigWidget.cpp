#include "showNetConfigWidget.h"
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QScrollBar>

ShowNetConfigWidget::ShowNetConfigWidget(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowState(Qt::WindowFullScreen);

    titleLabel.setText("Network Configuration");

    generateNetConfigList();
    configModel.appendColumn(configItems);

    configView.setModel(&configModel);

    layout.addWidget(&titleLabel);
    layout.addWidget(&configView);
    setLayout(&layout);
}

ShowNetConfigWidget::~ShowNetConfigWidget()
{
}

QString ShowNetConfigWidget::getTitle()
{
    return QString("Show network configuration");
}

void ShowNetConfigWidget::generateNetConfigList()
{
    foreach (const QNetworkInterface &interface, QNetworkInterface::allInterfaces())
    {
        configItems.append(new QStandardItem(interface.name()));
        foreach (const QNetworkAddressEntry &entry, interface.addressEntries())
        {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol)
            {
                configItems.append(new QStandardItem(QString("IP address: ") + entry.ip().toString()));
                configItems.append(new QStandardItem(QString("Netmask: ") + entry.netmask().toString()));
            }
        }
        configItems.append(new QStandardItem(QString("Hardware address: ") + interface.hardwareAddress()));
        configItems.append(new QStandardItem(QString()));
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
