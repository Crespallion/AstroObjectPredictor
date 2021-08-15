#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpfunctions.h"

#include <QDate>
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,357);
    this->move(0,0);
    ui->WeatherW->setEnabled(false); ui->ToPlanetsW->setEnabled(false);
    listW = new PLWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PlanetListOutput(QBitArray a, QBitArray b, QBitArray c, QBitArray d,
                                  QBitArray e, QBitArray f, QBitArray g){
    QString planetlist = "You can see ";
    if (isOne(a)) planetlist += "Mercury, ";
    if (isOne(b)) planetlist += "Venus, ";
    if (isOne(c)) planetlist += "Mars, ";
    if (isOne(d)) planetlist += "Jupiter, ";
    if (isOne(e)) planetlist += "Saturn, ";
    if (isOne(f)) planetlist += "Uranus, ";
    if (isOne(g)) planetlist += "Neptune, ";
    if (planetlist == "You can see "){
        ui->VisiblePlanetsW->setText("You can see nothing :c");
    }
    else {
    planetlist.chop(2);
    ui->VisiblePlanetsW->setText(planetlist);}
}

void MainWindow::on_WeatherW_clicked()
{
    IW = !IW;
    if (IW){
        ui->WeatherW->setText("Consider weather");
        PlanetListOutput(merh, venh, marh, juph, sath, urah, neph);
    }
    else {
        ui->WeatherW->setText("Ignore weather");
        PlanetListOutput(mer, ven, mar, jup, sat, ura, nep);
    }
}

void MainWindow::on_CalculateDataW_clicked()
{
    try {
    ui->CalculateDataW->setEnabled(false);
    ui->CalculateDataW->setText("Calculating...");
    QString latit, longit, country, city;
    QString inthesky, intheskyUrl;
    QString getip, wunderground;

    getip = GetCode("http://getip.ru");
    getip.remove(0, getip.indexOf("val\"><p>")+8);
    getip.remove(getip.indexOf('<'), getip.size()-1);

    GeoLite2PP::DB db("GeoLite2-City.mmdb");

    std::string sinfo = db.lookup(getip.toStdString());
    std::string scity, scountry, slat, slon;
    sinfo = sinfo.substr(sinfo.find("\"en\"")+8,
                         sinfo.length()-sinfo.find("\"en\"")-8);
    scity = sinfo.substr(0, (sinfo.find('\"')));
    sinfo = sinfo.substr(sinfo.find("\"iso_code\"")+14,
                         sinfo.length()-sinfo.find("\"iso_code\"")-14);
    scountry = sinfo.substr(0, (sinfo.find('\"')));
    sinfo = sinfo.substr(sinfo.find("\"latitude\"")+13,
                         sinfo.length()-sinfo.find("\"latitude\"")-13);
    slat = sinfo.substr(0, (sinfo.find('.'))+3);
    sinfo = sinfo.substr(sinfo.find("\"longitude\"")+14,
                         sinfo.length()-sinfo.find("\"longitude\"")-14);
    slon = sinfo.substr(0, (sinfo.find('.'))+3);
    qcity = QString::fromStdString(scity);
    QString qcountry = QString::fromStdString(scountry);
    QString qlat = QString::fromStdString(slat);
    QString qlon = QString::fromStdString(slon);

    intheskyUrl = "https://in-the-sky.org/data/planets.php?latitude=";
    intheskyUrl += qlat; intheskyUrl += "&longitude=";
    intheskyUrl += qlon; intheskyUrl += "&timezone=%2B00%3A00";
    inthesky = GetCode(intheskyUrl);

    inthesky.remove(0,inthesky.indexOf("Mercury"));
    inthesky.remove(0,inthesky.indexOf("risesetinfo"));
    risessets[0] = inthesky.mid(inthesky.indexOf("Rise")+13,2).toInt();
    risessets[7] = inthesky.mid(inthesky.indexOf("Set")+12,2).toInt();
    merh = PlanetHours(risessets[0], risessets[7]);

    inthesky.remove(0,inthesky.indexOf("Venus"));
    inthesky.remove(0,inthesky.indexOf("risesetinfo"));
    risessets[1] = inthesky.mid(inthesky.indexOf("Rise")+13,2).toInt();
    risessets[8] = inthesky.mid(inthesky.indexOf("Set")+12,2).toInt();
    venh = PlanetHours(risessets[1], risessets[8]);

    inthesky.remove(0,inthesky.indexOf("Mars"));
    inthesky.remove(0,inthesky.indexOf("risesetinfo"));
    risessets[2] = inthesky.mid(inthesky.indexOf("Rise")+13,2).toInt();
    risessets[9] = inthesky.mid(inthesky.indexOf("Set")+12,2).toInt();
    marh = PlanetHours(risessets[2], risessets[9]);

    inthesky.remove(0,inthesky.indexOf("Jupiter"));
    inthesky.remove(0,inthesky.indexOf("risesetinfo"));
    risessets[3] = inthesky.mid(inthesky.indexOf("Rise")+13,2).toInt();
    risessets[10] = inthesky.mid(inthesky.indexOf("Set")+12,2).toInt();
    juph = PlanetHours(risessets[3], risessets[10]);

    inthesky.remove(0,inthesky.indexOf("Saturn"));
    inthesky.remove(0,inthesky.indexOf("risesetinfo"));
    risessets[4] = inthesky.mid(inthesky.indexOf("Rise")+13,2).toInt();
    risessets[11] = inthesky.mid(inthesky.indexOf("Set")+12,2).toInt();
    sath = PlanetHours(risessets[4], risessets[11]);

    inthesky.remove(0,inthesky.indexOf("Uranus"));
    inthesky.remove(0,inthesky.indexOf("risesetinfo"));
    risessets[5] = inthesky.mid(inthesky.indexOf("Rise")+13,2).toInt();
    risessets[12] = inthesky.mid(inthesky.indexOf("Set")+12,2).toInt();
    urah = PlanetHours(risessets[5], risessets[12]);

    inthesky.remove(0,inthesky.indexOf("Neptune"));
    inthesky.remove(0,inthesky.indexOf("risesetinfo"));
    risessets[6] = inthesky.mid(inthesky.indexOf("Rise")+13,2).toInt();
    risessets[13] = inthesky.mid(inthesky.indexOf("Set")+12,2).toInt();
    neph = PlanetHours(risessets[6], risessets[13]);

    QTime ctime = QTime::currentTime(); int hours = 23 - ctime.hour();
    QDate cdate = QDate::currentDate(); QString date;
    cdate = cdate.addDays(1);
    date = cdate.toString("yyyy-MM-dd");

    wunderground = GetCode("https://www.wunderground.com/hourly/"
                           + qcountry +'/' + qcity + "/date/" + date);
    wunderground.remove(0,wunderground.
                        indexOf("{&q;value&q;:{&q;cloudCover&q;:")+32);
    wunderground.remove(200,wunderground.size()-1);
    QBitArray clearsky(24);
    for (int i = 0; i < 24; ++i){
        clearsky[i] = wunderground.split(",")[i+hours].toInt() < 50;
    }

    mer = merh & clearsky;
    ven = venh & clearsky;
    mar = marh & clearsky;
    jup = juph & clearsky;
    sat = sath & clearsky;
    ura = urah & clearsky;
    nep = neph & clearsky;

    ui->WeatherW->setText("Ignore weather");
    PlanetListOutput(mer, ven, mar, jup, sat, ura, nep);
    QString apqcity = "Your city is " + qcity;
    ui->CityW->setFont(QFont ("Estrangelo Edessa", 15));
    ui->CityW->setText(apqcity);
    ui->CalculateDataW->setText("Recalculate");
    ui->WeatherW->setEnabled(true);
    ui->ToPlanetsW->setEnabled(true);ui->CalculateDataW->setEnabled(true);
    listW->RSSetter(risessets);

    //
    } catch(const std::system_error& e) {
    ui->CalculateDataW->setText("FAILED");
    QMessageBox msgBox;
    msgBox.setText("Application can't find database \"GeoLite2-City.\
mmdb\".\n If you haven't it, download it from \
    http://dev.maxmind.com/geoip/geoip2/geolite2/#Downloads \
    \nGeoLite2-City.mmdb should be in the program directory." );
    msgBox.exec();
    abort();
    }
    catch(...) {
    ui->CalculateDataW->setText("FAILED");
    QMessageBox msgBox;
    msgBox.setText("Application can't connect to servers!");
    msgBox.exec();
    abort();
    }

    //
}

void MainWindow::on_ToPlanetsW_clicked()
{
    listW->show();
}
