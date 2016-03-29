#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // Create the button, make "this" the parent
    m_button = new QPushButton("Choose CSV file");
    // set size and location of the button
    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    // Connect button signal to appropriate slot
    connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));

    textInput = new QLineEdit(this);
    connect(textInput, SIGNAL (returnPressed()), this, SLOT (handleTextInput()));

    model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM actor;");//first_name, last_name FROM actor;");
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Salary");

    view = new QTableView;
    view->setModel(model);

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget( centralWidget );
    QGridLayout *layout = new QGridLayout( centralWidget );
    QGridLayout *insideLayout = new QGridLayout();

    layout->addLayout(insideLayout, 0, 0);
    insideLayout->addWidget(m_button, 0, 0);
    insideLayout->addWidget(textInput, 1, 0);
    layout->addWidget(view, 0, 1);
}

void MainWindow::handleButton()
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
//            line.insert(0,"\"");
//            line.insert(line.indexOf(","),"\"");
//            line.insert(line.indexOf(",")+1,"\"");
//            line.insert(line.indexOf(*(line.end()-1)),"\"");
            addElementsQuery += line + ") VALUES " ;
            isFirstLine++;
        }
    }
    addElementsQuery += ";";
    qDebug() << addElementsQuery << endl;
    QString maurycy = "NO ELO";
    qDebug() << maurycy;
    model->setQuery(addElementsQuery);
}

void MainWindow::handleTextInput()
{
    model->setQuery(textInput->text());
}
