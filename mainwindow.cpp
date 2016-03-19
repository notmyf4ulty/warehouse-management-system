#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // Create the button, make "this" the parent
    m_button = new QPushButton("My Button");//, this);
    // set size and location of the button
    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    // Connect button signal to appropriate slot
    connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));

    model = new QSqlQueryModel(this);
    model->setQuery("SELECT first_name, last_name FROM actor;");
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Salary");

    view = new QTableView;
    view->setModel(model);

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget( centralWidget );
    QGridLayout *layout = new QGridLayout( centralWidget );

    layout->addWidget(m_button);
    layout->addWidget(view);
    //    setCentralWidget(view);
}

void MainWindow::handleButton()
{
    // change the text
    m_button->setText("Example");
    // resize button
    m_button->resize(100,100);
}
