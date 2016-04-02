#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QApplication *_app, QWidget *parent)
    : QMainWindow(parent)
{
    //this->setGeometry(0,0,500,500);
    app = _app;

    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    outerLayout = new QVBoxLayout();
    topLayout = new QVBoxLayout();
    bottomLayout = new QHBoxLayout();

    centralWidget->setLayout(outerLayout);
    outerLayout->addLayout(topLayout);
    outerLayout->addLayout(bottomLayout);

    model = &(dbConnector::getInstance().getModel());
    view = new QTableView;
    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(view,
            SIGNAL(clicked(const QModelIndex &)),
            this,
            SLOT(onTableClicked(const QModelIndex &)));
    topLayout->addWidget(view);

    addToBasketButton = new QPushButton("Add to basket");
    openBasketButton = new QPushButton("Open basket");
    bottomLayout->addWidget(addToBasketButton);
    bottomLayout->addWidget(openBasketButton);

    setMenuBar();


}

void MainWindow::importCSV()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choose CSV file"), "/home/przemek", tr("CSV File (*.csv)"));

    qDebug() << fileName << endl;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "ERROR" << endl;

    int isFirstLine = 0;
    addElementsQuery = "INSERT INTO mojaTabela (";

    while (!file.atEnd()) {
        if(isFirstLine == 2) {
            QString line = file.readLine();
            line.insert(0,"\"");
            line.insert(line.indexOf(","),"\"");
            addElementsQuery += ",(" + line + ")";
        }
        else if(isFirstLine == 1) {
            QString line = file.readLine();
            line.insert(0,"\"");
            line.insert(line.indexOf(","),"\"");
            addElementsQuery +="(" + line + ")";
            isFirstLine++;
        }
        else {
            QString line = file.readLine();
            addElementsQuery += line + ") VALUES " ;
            isFirstLine++;
        }
    }
    addElementsQuery += ";";
    qDebug() << addElementsQuery << endl;
    QString maurycy = "NO ELO";
    qDebug() << maurycy;
//    model->setQuery(addElementsQuery);
    model->setQuery(addElementsQuery);
}

void MainWindow::setMenuBar()
{
    fileMenu = this->menuBar()->addMenu(tr("&Database"));
    fileMenu->addAction(tr("Import CSV file..."), this, SLOT(importCSV()));
    fileMenu->addAction(tr("Configure Database"), this, SLOT(configureDatabase()));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("&Quit"), this, SLOT(quitApp()));

    addMenu = this->menuBar()->addMenu(tr("&Add"));
    addMenu->addAction(tr("&Add new elements"), this, SLOT(addNewElements()));

    toolsMenu = this->menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(tr("&MySQL command line"), this, SLOT(toolsMySQLcmd()));
}

void MainWindow::configureDatabase()
{
    dbConnector::getInstance().runDatabase();
//    model->setQuery("SELECT * FROM mojaTabela;");
}

void MainWindow::quitApp()
{
    app->quit();
}

void MainWindow::onTableClicked(const QModelIndex &index)
{
    if (index.isValid()) {

//        QString cellText = index.data().toString();
        qDebug() << model->index(index.row(),1).data().toString() << endl;
    }
}

void MainWindow::addNewElements()
{
    AddElementDialog *dialog = new AddElementDialog(this);
    dialog->show();
}

void MainWindow::toolsMySQLcmd()
{
    MySQLcmdDialog *dialog = new MySQLcmdDialog(this);
    dialog->show();
}

void MainWindow::addToBasketButtonHandle()
{

}

void MainWindow::openBasketButtonHandle()
{

}
