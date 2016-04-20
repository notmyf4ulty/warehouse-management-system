#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

template<typename T> void alignCenter(T *widget)
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - widget->width()) / 2;
    int y = (screenGeometry.height() - widget->height()) / 2;
    widget->move(x, y);
}

#endif // GEOMETRY_H
