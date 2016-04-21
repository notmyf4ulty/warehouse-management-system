#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

//!  Szablon centrujący okna.
/*!
  Funkcja przyjmuje obiekt posiadający funkcje zwracające szerokość i wysokość,
  a następnie po wykonaniu prostych obliczeń centruje go na ekranie.
*/
template<typename T> void alignCenter(T *widget)
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - widget->width()) / 2;
    int y = (screenGeometry.height() - widget->height()) / 2;
    widget->move(x, y);
}

#endif // GEOMETRY_H
