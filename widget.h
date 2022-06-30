#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWizardPage>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void on_aboutButton_clicked();
    void on_quitButton_clicked();
    void on_rulesButton_clicked();
    void on_leaderBoardButton_clicked();
    void on_signupButton_clicked();
    void on_loginButton_clicked();

private:
    QWizardPage *createPage1();

};
#endif // WIDGET_H
