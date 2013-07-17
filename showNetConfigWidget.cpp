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

    titleLabel = new QLabel;
    titleLabel->setText("Network Configuration");

    configItems = new QList<QStandardItem *>;
    configModel = new QStandardItemModel;
    configView = new QListView;
    showNetConfig();
    configModel->appendColumn(*configItems);

    configView->setModel(configModel);

    layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(configView);
    setLayout(layout);

}

ShowNetConfigWidget::~ShowNetConfigWidget()
{
    delete layout;
    delete configItems;
    delete configModel;
    delete configView;
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
        configItems->append(new QStandardItem(interface.name()));
        foreach (const QNetworkAddressEntry &entry, interface.addressEntries())
        {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol)
            {
                configItems->append(new QStandardItem(QString("IP address: ") + entry.ip().toString()));
                configItems->append(new QStandardItem(QString("Netmask: ") + entry.netmask().toString()));
            }
        }
        configItems->append(new QStandardItem(QString("Hardware address: ") + interface.hardwareAddress()));
        configItems->append(new QStandardItem(QString("\n")));
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
