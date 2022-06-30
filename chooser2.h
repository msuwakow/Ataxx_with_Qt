#ifndef CHOOSER2_H
#define CHOOSER2_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class chooser2; }
QT_END_NAMESPACE

class Chooser2 : public QDialog
{
    Q_OBJECT

public:
    Chooser2(int &, QDialog *parent = nullptr);
    ~Chooser2();

private:
    Ui::chooser2 *ui;
    int &ans;

private slots:
    void on_forwards_clicked();
    void on_backwards_clicked();
    void on_b1_clicked();
    void on_b2_clicked();
};

#endif // CHOOSER2_H
