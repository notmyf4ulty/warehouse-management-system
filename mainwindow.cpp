#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QApplication *_app, QWidget *parent)
    : QMainWindow(parent)
{
    app = _app;
//    // Create the button, make "this" the parent
//    m_button = new QPushButton("Choose CSV file");
//    // set size and location of the button
//    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
//    // Connect button signal to appropriate slot
//    connect(m_button, SIGNAL (released()), this, SLOT (importCSV()));

    textInput = new QLineEdit(this);
    connect(textInput, SIGNAL (returnPressed()), this, SLOT (handleTextInput()));

//    model = new QSqlQueryModel(this);
//    model->setHeaderData(0, Qt::Horizontal, "Typ");
//    model->setHeaderData(1, Qt::Horizontal, "Wartość");

    model = &(dbConnector::getInstance().getModel());

    view = new QTableView;
    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(view,
            SIGNAL(clicked(const QModelIndex &)),
            this,
            SLOT(onTableClicked(const QModelIndex &)));

    setMenuBar();

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget( centralWidget );
    QGridLayout *layout = new QGridLayout( centralWidget );
    QGridLayout *insideLayout = new QGridLayout();

    layout->addLayout(insideLayout, 0, 0);
//    insideLayout->addWidget(m_button, 0, 0);
    insideLayout->addWidget(textInput, 1, 0);
    layout->addWidget(view, 0, 1);
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

void MainWindow::handleTextInput()
{
//    model->setQuery(textInput->text());
    model->setQuery(textInput->text());
}

void MainWindow::setMenuBar()
{
    fileMenu = this->menuBar()->addMenu(tr("&Database"));
    fileMenu->addAction(tr("Import CSV file..."), this, SLOT(importCSV()));
    fileMenu->addAction(tr("Configure Database"), this, SLOT(configureDatabase()));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("&Quit"), this, SLOT(quitApp()));

    addMenu = this->menuBar()->addMenu((tr("&Add")));
    addMenu->addAction(tr("&Add new elements"), this, SLOT(addNewElements()));

    helpMenu = this->menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(tr("About"), this, SLOT(importCSV()));
    helpMenu->addAction(tr("About Qt"), this, SLOT(importCSV()));
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
