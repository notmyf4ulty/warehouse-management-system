#ifndef MYSQLCMDDIALOG_H
#define MYSQLCMDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSqlQueryModel>
#include "dbconnector.h"
#include <QHBoxLayout>
#include <QLayout>
#include "geometry.h"
#include <QKeyEvent>
#include <QRect>
#include <QString>

//!  Klasa tworząca okno linii poleceń MySQL.
/*!
  Możliwe jest wykonywanie wszystkich komend MySQL. Odpowiednio wyświetlane będą wyniki na oknie głównym.
  Podczas korzystania z linii poleceń wszystkie inne funkcje programu są zablokowane, a po jej wyłączeniu
  program wraca do poprzedniej postaci.<br>
  UWAGA! Należy być bardzo ostrożnym - za pomocą linii poleceń można zniszczyć tabele, usunąć komponenty, itp.
*/
class MySQLcmdDialog : public QDialog
{
    Q_OBJECT
public:
    //! Konstruktor tworzący okno dialogowe.
    /*!
      \param parent Rodzic dla tworzonego okna.
    */
    explicit MySQLcmdDialog(QWidget *parent = 0);

signals:
    //! Sygnał emitowany przy zamknięciu okna. Uruchamia z powrotem okno główne.
    void dialogClosed();

private slots:
    void promptHandle();

private:
    QString oldQuery;
    QWidget *parentWidget;
    QLineEdit *prompt;
    QSqlQueryModel *model;
    QHBoxLayout *outerLayout;
    void closeEvent(QCloseEvent *event) {model->setQuery(oldQuery);
                                         emit dialogClosed();
                                         event->accept();}
};

#endif // MYSQLCMDDIALOG_H
