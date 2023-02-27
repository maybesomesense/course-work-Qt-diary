#ifndef NEXTWINDOWSIXTH_H
#define NEXTWINDOWSIXTH_H

#include <QMainWindow>

namespace Ui {
class nextWindowSixth;
}

class nextWindowSixth : public QMainWindow
{
    Q_OBJECT
signals:
    void sixthWindow();
public:
    explicit nextWindowSixth(QWidget *parent = nullptr);
    ~nextWindowSixth();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::nextWindowSixth *ui;
};

#endif // NEXTWINDOWSIXTH_H
