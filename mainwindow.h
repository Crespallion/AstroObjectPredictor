#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBitArray>
#include <QString>
#include "plwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_WeatherW_clicked();
    void on_CalculateDataW_clicked();
    void on_ToPlanetsW_clicked();

private:
    Ui::MainWindow *ui;
    PLWindow *listW;
    bool IW = false;
    QBitArray mer, ven, mar, jup, sat, ura, nep,
    merh, venh, marh, juph, sath, urah, neph;
    QString qcity;
    int risessets[14];

    void PlanetListOutput(QBitArray a, QBitArray b, QBitArray c, QBitArray d,
                                      QBitArray e, QBitArray f, QBitArray g);
};

#endif // MAINWINDOW_H
