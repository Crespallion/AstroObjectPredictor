#ifndef PLWINDOW_H
#define PLWINDOW_H

#include <QWidget>

namespace Ui {
class PLWindow;
}

class PLWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PLWindow(QWidget *parent = 0);
    void RSSetter(int ar[]);
    ~PLWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::PLWindow *ui;
    bool IW;
    int risessets[14];
    QString name;
    void TextSetter(int r, int s);
};


#endif // PLWINDOW_H
