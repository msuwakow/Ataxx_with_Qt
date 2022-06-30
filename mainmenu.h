#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "gamestate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainmenu; }
QT_END_NAMESPACE

class Mainmenu : public QDialog
{
    Q_OBJECT

public:
    Mainmenu(GameState x, QDialog *parent = nullptr);
    ~Mainmenu();


private:
    Ui::mainmenu *ui;
    GameState st;

private slots:
    void on_newGame_clicked();
    void on_saveGame_clicked();
    void on_loadGame_clicked();
    void on_quitGame_clicked();

};
#endif // MAINMENU_H
