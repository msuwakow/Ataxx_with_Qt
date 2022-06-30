#ifndef NOPAINTER_H
#define NOPAINTER_H

#include <QDialog>
#include <QGraphicsView>
#include "gamestate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class nopainter; }
QT_END_NAMESPACE


class Nopainter : public QDialog
{
    Q_OBJECT

public:
    Nopainter(GameState &x, QDialog *parent = nullptr);
    ~Nopainter();
    void paint(GameState &x);
    std::pair<int, int> ScanPos1();
    std::pair<int, int> ScanPos2();

private:
    Ui::nopainter *ui;
    QGraphicsView black[7][7], white[7][7];

private slots:

};

#endif // NOPAINTER_H

