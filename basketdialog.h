#ifndef BASKETDIALOG_H
#define BASKETDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include "component.h"
#include "basket.h"
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QDebug>

class BasketDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BasketDialog(QWidget *parent = 0);

signals:

public slots:

private:
    QPushButton *proceedOrderButton;
    QPushButton *cancelButton;
    QVBoxLayout *outerLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *topLeftLayout;
    QVBoxLayout *topRightLayout;
    QHBoxLayout *bottomLayout;
};

#endif // BASKETDIALOG_H
