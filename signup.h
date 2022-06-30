#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class Signup : public QDialog
{
    Q_OBJECT

public:
    Signup(QDialog *parent = nullptr);
    ~Signup();

private:
    Ui::Form *ui;
    QWidget *last;

private slots:
    void on_forwards_clicked();
    void on_backwards_clicked();
};

#endif // SIGNUP_H
