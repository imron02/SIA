/*
|-------------------------------------------------------------------------------
| Name:        home.h
| Author:      Imron Rosdiana
| Modified by:
| Created:     2014-12-08
| Copyright:   (C) Copyright 2014, Imron Rosdiana
| Licence:     GPL (General Public License) V.3
*/

#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class PageHome : public QWidget {
  Q_OBJECT

 public:
  explicit PageHome(QWidget* parent = 0);
  ~PageHome();
};

#endif  // HOME_H
