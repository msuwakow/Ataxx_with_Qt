#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "gamestate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

namespace lastSucceedLogin {
    extern GameState last;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QDialog *parent = nullptr);
    ~Login();

private:
    Ui::login *ui;
    QWidget *last;

private slots:
    void on_forwards_clicked();
    void on_backwards_clicked();
};

#endif // LOGIN_H
