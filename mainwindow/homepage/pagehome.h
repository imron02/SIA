#ifndef PAGEHOME_H
#define PAGEHOME_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class PageHome : public QWidget
{
    Q_OBJECT

public:
    explicit PageHome(QWidget* parent = 0);
    ~PageHome();
};

#endif // PAGEHOME_H
