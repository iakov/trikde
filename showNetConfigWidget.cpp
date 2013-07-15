#include "showNetConfigWidget.h"
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QCoreApplication>
#include <QKeyEvent>

ShowNetConfigWidget::ShowNetConfigWidget(QWidget *parent) :
    BaseWidget(parent)
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

    connect(this, SIGNAL(upPressed()), this, SLOT(moveUp()));
    connect(this, SIGNAL(downPressed()), this, SLOT(moveDown()));
    connect(this, SIGNAL(menuPressed()), this, SLOT(close()));
    connect(this, SIGNAL(enterPressed()), this, SLOT(close()));

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

void ShowNetConfigWidget::moveUp()
{
    QCoreApplication::postEvent(netConfigTextEdit, new QKeyEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier));
}

void ShowNetConfigWidget::moveDown()
{
    QCoreApplication::postEvent(netConfigTextEdit, new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier));
}
