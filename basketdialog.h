#ifndef BASKETDIALOG_H
#define BASKETDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include "basketcomponent.h"
#include "basket.h"
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QDebug>
#include <QLayout>
#include "geometry.h"
#include <QWidget>
#include <QKeyEvent>

//!  Klasa tworząca okno "dodawania nowych komponentów.."koszyka zakupów"
/*!
  Wypisane są tu komponenty, które aktualnie znajdują się w koszyku.
*/
class BasketDialog : public QDialog
{
    Q_OBJECT
public:
    //! Konstruktor tworzący okno dialogowe.
    /*!
      \param parent Rodzic dla tworzonego okna.
    */
    explicit BasketDialog(QWidget *parent = 0);

signals:
    //! Sygnał emitowany przy zamknięciu okna. Uruchamia z powrotem okno główne.
    void dialogClosed();
private slots:
    void proceedOrderButtonHandle();
    void clearOrderButtonHanle();
private:
    QWidget *parentWidget;
    QPushButton *proceedOrderButton;
    QPushButton *clearOrderButton;
    QPushButton *cancelButton;
    QVBoxLayout *outerLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *topLeftLayout;
    QVBoxLayout *topRightLayout;
    QHBoxLayout *bottomLayout;

    QStringList *basketComponentsList;
    QStringListModel *basketComponentsModel;
    QListView *basketComponentsView;

    void closeEvent(QCloseEvent *event) {parentWidget->show();
                                         emit dialogClosed();
                                         event->accept();}
};

#endif // BASKETDIALOG_H
