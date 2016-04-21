#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include "geometry.h"
#include <QKeyEvent>
#include "admin.h"

//!  Klasa tworząca okno logowania do trybu admina.
/*!
  Aby spróbować się zalogować, należy wpisać hasło i nacisnąć Enter.
  Jeżeli się uda, zmieniony zostanie tryb na "Admin mode".
*/
class AdminLoginDialog : public QDialog
{
    Q_OBJECT
public:
    //! Konstruktor tworzący okno dialogowe.
    /*!
      \param parent Rodzic dla tworzonego okna.
    */
    explicit AdminLoginDialog(QWidget *parent = 0);
signals:
    //! Sygnał emitowany przy zamknięciu okna. Uruchamia z powrotem okno główne.
    void dialogClosed();
private slots:
    void passInputHandle();
private:
    bool isAdmin;
    QWidget *parentWidget;
    QLineEdit *passInput;
    QPushButton *OKButton;
    QHBoxLayout *outerLayout;
    void closeEvent(QCloseEvent *event) {parentWidget->show();
                                         emit dialogClosed();
                                         event->accept();}
};

#endif // ADMINLOGINDIALOG_H
