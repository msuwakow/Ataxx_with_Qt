#ifndef PAINTER_H
#define PAINTER_H

#include "gamestate.h"
#include <QPushButton>
#include <QGraphicsView>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class painter; }
QT_END_NAMESPACE

class Painter : public QDialog
{
    Q_OBJECT

public:
    Painter(QDialog *parent = nullptr);
    ~Painter();
    std::pair<int, int> query(GameState x);
    void paint(GameState x);

private:
    Ui::painter *ui;
    int y, x;
//    QPushButton black[7][7], white[7][7], spaceCloser[7][7], spaceFarther[7][7];
//    QGraphicsView blackOpposite[7][7], whiteOpposite[7][7], blackWithdraw[7][7],
//                whiteWithdraw[7][7];

private slots:
    void reset(GameState x);
    void on_regret_clicked();
    void on_quit_clicked();
};

#endif // PAINTER_H
