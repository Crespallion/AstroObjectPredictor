#include "plwindow.h"
#include "ui_plwindow.h"


PLWindow::PLWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PLWindow)
{
    ui->setupUi(this);
    this->setFixedSize(470,357); this->move(500,0);
    ui->textBrowser->setFontPointSize(15); ui->textBrowser->setFontUnderline(true);
}

PLWindow::~PLWindow()
{
    delete ui;
}

void PLWindow::RSSetter(int ar[]){
    for (int i = 0; i < 14; ++i) risessets[i] = ar[i];
}

void PLWindow::TextSetter(int r, int s){
    ui->textBrowser_2->setText("Rise is in " + QString::number(r) + 'h');
    ui->textBrowser_4->setText("Set is in " + QString::number(s) + 'h');
    if (r > s) s += 24;
    r = (s+r)/2;
    if (r > 23) r = 23;
    ui->textBrowser_3->setText("Best time for watching is " + QString::number(r) + 'h');
}

void PLWindow::on_pushButton_clicked()
{
    ui->textBrowser->setText("Mercury");
    TextSetter(risessets[0], risessets[7]);
}


void PLWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->setText("Venus");
    TextSetter(risessets[1], risessets[8]);
}

void PLWindow::on_pushButton_6_clicked()
{
    ui->textBrowser->setText("Mars");
    TextSetter(risessets[2], risessets[9]);
}

void PLWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->setText("Jupiter");
    TextSetter(risessets[3], risessets[10]);
}

void PLWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->setText("Saturn");
    TextSetter(risessets[4], risessets[11]);
}

void PLWindow::on_pushButton_7_clicked()
{
    ui->textBrowser->setText("Uranus");
    TextSetter(risessets[5], risessets[12]);
}

void PLWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->setText("Neptune");
    TextSetter(risessets[6], risessets[13]);
}

void PLWindow::on_pushButton_8_clicked()
{
    ui->textBrowser->setFontPointSize(9);TextSetter(-1,25);
    ui->textBrowser->setText("Probably, you're really bad astronomer!");
    ui->textBrowser->setFontPointSize(15);
}
