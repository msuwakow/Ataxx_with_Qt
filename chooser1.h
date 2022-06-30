#ifndef CHOOSER1_H
#define CHOOSER1_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class chooser1; }
QT_END_NAMESPACE

class Chooser1 : public QDialog
{
    Q_OBJECT

public:
    Chooser1(int &, QDialog *parent = nullptr);
    ~Chooser1();

private:
    Ui::chooser1 *ui;
    int &ans;

private slots:
    void on_forwards_clicked();
    void on_backwards_clicked();
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
};

#endif // CHOOSER1_H
