#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QTableView>
#include <QSqlQueryModel>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QList>
#include <QComboBox>
#include <QModelIndex>
#include <QVector>
#include <QStatusBar>
#include "dbconnector.h"
#include "addcomponentdialog.h"
#include "basketdialog.h"
#include "basketcomponent.h"
#include "basket.h"
#include "mysqlcmddialog.h"
#include "adminlogindialog.h"
#include "geometry.h"
#include <QIntValidator>

namespace Ui {
    class MainWindow;
}

//!  Klasa tworząca okno główne aplikacji.
/*!
  Okno posiada określone komponenty:
  1. Menu z dwoma podsekcjami:<br>
  1.1. File - możliwe jest zresetowanie połączenia z bazą danych, włączenie okna logowania do trybu admina
  oraz wyjście z aplikacji.<br>
  1.2. Admin tools - możliwe jest dodanie nowych komponentów, wczytanie pliku CSV oraz wywołanie prostej linii poleceń
  zapytań MySQL.<br>
  2. Ekran główny z rozwijanym menu, za pomocą którego można wybrać odpowiednią tabelę z komponentami. <br>
  3. Panel dodawania komponentów do koszyka. <br>
  4. Pasek statusowy - informuje o połączeniu z bazą danych oraz o włączeniu trybu admina. <br>
  <br>
  Po wybraniu tabeli z komponentami, naciśnięciu któregoś z nich oraz wpisaniu odpowiedniej liczny (z zakresu dostępnęj ilości komponentów)
 możliwe jest użycie przycisku "Add to basket", który doda daną ilość komponentów do koszyka.<br>
 Otworzenie koszyka możliwe jest po naciśnięciu przycisku "Open Basket".<br>
 Tryb admina możliwy jest do odblokowania po wykonaniu instrukcji z paska statusowego.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Konstruktor tworzący okno główne.
    /*!
      \param _app obiekt aplikacji uruchamiającej okno główne.
      \param parent Rodzic dla tworzonego okna.
    */
    explicit MainWindow(QApplication *_app, QWidget *parent = 0);

private slots:
    void importCSV();
    void configureDatabase();
    void quitApp();
    void onTableClicked(const QModelIndex &index);
    void addNewComponent();
    void toolsMySQLcmd();
    void addToBasketButtonHandle();
    void openBasketButtonHandle();
    void showComponentsTable();
    void adminLogin();
    void checkAdmin();
    void onSQLCmdClose();

private:
    QApplication *app;
    QWidget *centralWidget;
    QTableView *view;
    QSqlQueryModel *model;
    const QModelIndex *currentTableIndex;
    Basket *basket;
    QLabel *componentLabel;
    QLabel *setQuantityLabel;
    QLabel *setQuantityCommunicateLabel;
    QLineEdit *setQuantityInput;
    QString addElementsQuery;
    QComboBox *componentComboBox;
    QPushButton *addToBasketButton;
    QPushButton *openBasketButton;
    QMenu *fileMenu;
    QMenu *adminToolsMenu;
    QStatusBar *statusBar;
    QLabel *statusBarDbInfoPermanentLabel;
    QLabel *statusBarDbInfoModifableLabel;
    QLabel *statusBarAdminInfoPermanentLabel;
    QLabel *statusBarAdminInfoModifableLabel;
    QVBoxLayout *outerLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *tableLayout;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *bottomLeftLayout;
    QHBoxLayout *bottomLeftTopLayout;
    QHBoxLayout *statusBarLayout;

    void setMenuBar();
    QString getTableName();
    void eraseKeyFields();
};

#endif // MAINWINDOW_H
