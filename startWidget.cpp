#include "startWidget.h"
#include <QKeyEvent>
#include <QCoreApplication>

StartWidget::StartWidget(QWidget *parent)
    : BaseWidget(parent)
{
    setWindowState(Qt::WindowFullScreen);

    titleLabel = new QLabel;
    titleLabel->setText("TrikDE");

    menuItems = new QList<QStandardItem *>;
    menuItems->append(new QStandardItem("Item 1"));
    menuItems->append(new QStandardItem("Item 2"));
    menuItems->append(new QStandardItem("Item 3"));
    menuItems->append(new QStandardItem("Exit"));


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
    if (currentItemText == "Exit")
        close();
}
