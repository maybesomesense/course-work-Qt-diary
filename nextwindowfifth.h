#ifndef NEXTWINDOWFIFTH_H
#define NEXTWINDOWFIFTH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class nextWindowFifth; }
QT_END_NAMESPACE

class nextWindowFifth : public QMainWindow
{
    Q_OBJECT
signals:
    void fifthWindow();
public:
    nextWindowFifth(QWidget *parent = nullptr);
    ~nextWindowFifth();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::nextWindowFifth *ui;
};
#endif // NEXTWINDOWFIFTH_H
