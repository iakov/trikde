#include "startWidget.h"
#include <QKeyEvent>
#include <QCoreApplication>
#include "fileManagerWidget.h"
#include "showNetConfigWidget.h"
#include "showIPAddressWidget.h"

StartWidget::StartWidget(QWidget *parent)
    : BaseWidget(parent)
{
    exitItemTitle = new QString("Exit");

    setWindowState(Qt::WindowFullScreen);

    titleLabel = new QLabel;
    titleLabel->setText("TrikDE");

    menuItems = new QList<QStandardItem *>;
    menuItems->append(new QStandardItem(FileManagerWidget::getTitle()));
    menuItems->append(new QStandardItem(ShowNetConfigWidget::getTitle()));
    menuItems->append(new QStandardItem(ShowIPAddressWidget::getTitle()));
    menuItems->append(new QStandardItem(*exitItemTitle));

    menuModel = new QStandardItemModel;
    menuModel->appendColumn(*menuItems);

    menuView = new QListView;
    menuView->setModel(menuModel);

    layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(menuView);

    setLayout(layout);

    connect(this, SIGNAL(upPressed()), this, SLOT(moveUp()));
    connect(this, SIGNAL(downPressed()), this, SLOT(moveDown()));
    connect(this, SIGNAL(enterPressed()), this, SLOT(launch()));
}

StartWidget::~StartWidget()
{
    delete layout;
    delete menuView;
    delete menuModel;
    delete menuItems;
    delete titleLabel;
    delete exitItemTitle;
}

void StartWidget::moveUp()
{
    QCoreApplication::postEvent(menuView, new QKeyEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier));
}

void StartWidget::moveDown()
{
    QCoreApplication::postEvent(menuView, new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier));
}

void StartWidget::launch()
{
    const QString &currentItemText = menuModel->itemFromIndex(menuView->currentIndex())->text();
    if (currentItemText == FileManagerWidget::getTitle())
    {
        FileManagerWidget *fileManagerWidget = new FileManagerWidget;
        fileManagerWidget->show();
    }
    else if (currentItemText == ShowNetConfigWidget::getTitle())
    {
        ShowNetConfigWidget *showNetConfigWidget = new ShowNetConfigWidget;
        showNetConfigWidget->show();
    }
    else if (currentItemText == ShowIPAddressWidget::getTitle())
    {
        ShowIPAddressWidget *showIPAddressWidget = new ShowIPAddressWidget;
        showIPAddressWidget->show();
    }
    else if (currentItemText == exitItemTitle)
        close();
}
