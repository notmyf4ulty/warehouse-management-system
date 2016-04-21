#ifndef ADDCOMPONENTDIALOG_H
#define ADDCOMPONENTDIALOG_H

#include <QObject>
#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSqlQueryModel>
#include <QString>
#include <QDebug>
#include <QLayout>
#include "dbconnector.h"
#include "basketcomponent.h"
#include "geometry.h"
#include <QKeyEvent>


//!  Klasa tworząca okno dodawania nowych komponentów.
/*!
  W oknie dialogowym możliwe jest dodanie trzech rodzajwW komponentów elektronicznych:
  - Rezystora
  - Kondensatora
  - Tranzystora
  <p> Każdy z komponentów posiada odpowiednie dla siebie parametry w zależności od wybranej opcji.
*/
class AddComponentDialog : public QDialog
{
    Q_OBJECT
signals:
    //! Sygnał emitowany przy zamknięciu okna. Uruchamia z powrotem okno główne.
    void dialogClosed();
private slots:
    void addButtonHandle();
    void componentChoiceShowProperties();
public:
    //! Konstruktor tworzący okno dialogowe.
    /*!
      \param parent Rodzic dla tworzonego okna.
    */
    explicit AddComponentDialog(QWidget *parent = 0);

private:
    QWidget *parentWidget;
    QComboBox *componentChoice;

    QLabel *componentLabel;
    QLabel *codeLabel;
    QLabel *valueLabel;
    QLabel *typeLabel;
    QLabel *packageLabel;
    QLabel *packageCaseLabel;
    QLabel *toleranceLabel;
    QLabel *powerLabel;
    QLabel *voltageLabel;
    QLabel *moreInfoLabel;
    QLabel *quantityLabel;

    QLineEdit *componentInput;
    QLineEdit *codeInput;
    QLineEdit *valueInput;
    QLineEdit *typeInput;
    QLineEdit *packageInput;
    QLineEdit *packageCaseInput;
    QLineEdit *toleranceInput;
    QLineEdit *powerInput;
    QLineEdit *voltageInput;
    QLineEdit *moreInfoInput;
    QLineEdit *quantityInput;

    QPushButton *addButton;
    QPushButton *cancelButton;
    QVBoxLayout *outerLayout;
    QHBoxLayout *componentInputLayout;
    QVBoxLayout *inputLayout;
    QVBoxLayout *labelLayout;
    QHBoxLayout *buttonsLayout;
    QSqlQueryModel *model;

    void hideAll();
    void cleanInputs();
    void showDefaultProperties();
    void showResistorProperties();
    void showCapacitorProperties();
    void showTransistorProperties();
    QString addResistor();
    QString addCapacitor();
    QString addTransistor();

    void closeEvent(QCloseEvent *event) {parentWidget->show();
                                         emit dialogClosed();
                                         event->accept();}

};

#endif // ADDELEMENTSCREEN_H
