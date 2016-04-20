#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QApplication *_app, QWidget *parent)
    : QMainWindow(parent)
{
    //this->setGeometry(0,0,500,500);
    app = _app;

    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    componentLabel = new QLabel(tr("Choose component table"));
    componentComboBox = new QComboBox();

    model = &dbConnector::getInstance().getModel();
    view = new QTableView;

    setQuantityLabel = new QLabel(tr("Set Quantity: "));
    setQuantityInput = new QLineEdit();
    setQuantityCommunicateLabel = new QLabel(tr(""));

    addToBasketButton = new QPushButton("Add to basket");
    openBasketButton = new QPushButton("Open basket");

    statusBar = new QStatusBar(this);
    statusBarDbInfoPermanentLabel = new QLabel("Database: ");
    statusBarDbInfoModifableLabel = new QLabel("");

    outerLayout = new QVBoxLayout();
    topLayout = new QHBoxLayout();
    tableLayout = new QVBoxLayout();
    bottomLayout = new QHBoxLayout();
    bottomLeftLayout = new QVBoxLayout();
    bottomLeftTopLayout = new QHBoxLayout();
    statusBarLayout = new QHBoxLayout();

    componentComboBox->addItem(tr("<none>"));
    componentComboBox->addItem(tr("Resistors"));
    componentComboBox->addItem(tr("Capacitors"));
    componentComboBox->addItem(tr("Transistors"));
    connect(componentComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(showComponentsTable()));

    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(view,
            SIGNAL(clicked(const QModelIndex &)),
            this,
            SLOT(onTableClicked(const QModelIndex &)));

    connect(addToBasketButton, SIGNAL(clicked()), this, SLOT(addToBasketButtonHandle()));
    connect(openBasketButton, SIGNAL(clicked()), this, SLOT(openBasketButtonHandle()));

    statusBar->setSizeGripEnabled(false);
    statusBar->addPermanentWidget(statusBarDbInfoPermanentLabel);
    statusBar->addPermanentWidget(statusBarDbInfoModifableLabel,1);

    centralWidget->setLayout(outerLayout);
    outerLayout->addLayout(topLayout);
    outerLayout->addLayout(tableLayout);
    outerLayout->addLayout(bottomLayout);
    outerLayout->addLayout(statusBarLayout);

    topLayout->addWidget(componentLabel);
    topLayout->addWidget(componentComboBox);
    tableLayout->addWidget(view);
    bottomLayout->addLayout(bottomLeftLayout);
    bottomLeftLayout->addLayout(bottomLeftTopLayout);
    bottomLeftTopLayout->addWidget(setQuantityLabel);
    bottomLeftTopLayout->addWidget(setQuantityInput);
    bottomLeftTopLayout->addWidget(setQuantityCommunicateLabel);
    bottomLeftLayout->addWidget(addToBasketButton);
    statusBarLayout->addWidget(statusBar);
    bottomLayout->addWidget(openBasketButton);


    addToBasketButton->setEnabled(false);
    setMenuBar();
    configureDatabase();
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
    model->setQuery(addElementsQuery);
}

void MainWindow::setMenuBar()
{
    fileMenu = this->menuBar()->addMenu(tr("&Database"));
    fileMenu->addAction(tr("&Reset connection"), this, SLOT(configureDatabase()));
    fileMenu->addAction(tr("&Admin mode"), this, SLOT(adminLogin()));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("&Quit"), this, SLOT(quitApp()));

    adminToolsMenu = this->menuBar()->addMenu(tr("&Admin Tools"));
    adminToolsMenu->addAction(tr("&MySQL command line"), this, SLOT(toolsMySQLcmd()));
    adminToolsMenu->addAction(tr("&Add new components"), this, SLOT(addNewComponent()));
    adminToolsMenu->addAction(tr("Import CSV file..."), this, SLOT(importCSV()));
    adminToolsMenu->setEnabled(false);
    //  componentsMenu->addAction(tr("&Delete components"), this, SLOT());
}

QString MainWindow::getTableName()
{
    QString tableName = "";
    switch(componentComboBox->currentIndex())
    {
    case 1:
        tableName = "resistor";
        break;
    case 2:
        tableName = "capacitor";
        break;
    case 3:
        tableName = "transistor";
        break;
    }
    return tableName;
}

void MainWindow::eraseKeyFields()
{
    setQuantityInput->setText("");
    currentTableIndex = 0;
}

void MainWindow::configureDatabase()
{
    if(dbConnector::getInstance().runDatabase())
    {
        statusBarDbInfoModifableLabel->setStyleSheet("QLabel { color : green; }");
        statusBarDbInfoModifableLabel->setText("CONNECTED");
    }
    else
    {
        statusBarDbInfoModifableLabel->setStyleSheet("QLabel { color : red; }");
        statusBarDbInfoModifableLabel->setText("NOT CONNECTED");
    }
}

void MainWindow::quitApp()
{
    app->quit();
}

void MainWindow::onTableClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        currentTableIndex = &index;
        qDebug() << model->index(index.row(),1).data().toString() << endl;
    }
}

void MainWindow::addNewComponent()
{
    AddComponentDialog *dialog = new AddComponentDialog(this);
    dialog->show();
}

void MainWindow::toolsMySQLcmd()
{
    MySQLcmdDialog *dialog = new MySQLcmdDialog(this);
    dialog->show();
}

void MainWindow::addToBasketButtonHandle()
{
    BasketComponent component(
                model->index(currentTableIndex->row(),0).data().toString(),
                getTableName(),
                setQuantityInput->text().toInt()
                );
    Basket::getInstance().addToBasket(component);
}

void MainWindow::openBasketButtonHandle()
{
    BasketDialog *dialog = new BasketDialog(this);
    dialog->show();
}

void MainWindow::showComponentsTable()
{
    addToBasketButton->setEnabled(true);
    eraseKeyFields();

    switch(componentComboBox->currentIndex())
    {
    case 0:
        addToBasketButton->setEnabled(false);
        break;
    case 1:
        model->setQuery("SELECT * FROM resistor;");
        break;
    case 2:
        model->setQuery("SELECT * FROM capacitor;");
        break;
    case 3:
        model->setQuery("SELECT * FROM transistor;");
        break;
    default:
        addToBasketButton->setEnabled(false);
        break;
    }
}

void MainWindow::adminLogin()
{
    AdminLoginDialog *dialog = new AdminLoginDialog(this);
    dialog->show();
}
