#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zawodnik.h"
#include <windows.h>
#include <iostream>
#include <QVector>
#include <QFont>
#include <time.h>
#include <cmath>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QDebug>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget_lista->setVisible(false);
    ui->pushButton_wybierz->setVisible(false);
    //ui->pushButton_2->setVisible(false);
    //ui->pushButton_winner->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int i=1;
QVector<Zawodnik> zawodnicy;
bool zawodnikwybrany=false;

void MainWindow::on_pushButton_dodaj_clicked()
{
    if(ui->lineEdit_imie->text().isEmpty() || ui->lineEdit_nazwisko->text().isEmpty() || ui->lineEdit_zespol->text().isEmpty())
    {
    }else
    {
        ui->listWidget_lista->addItem(QString::number(i)+". "+ui->lineEdit_imie->text()+" "+ui->lineEdit_nazwisko->text()+" Zespol: "+ui->lineEdit_zespol->text());
        i++;
        Zawodnik zaw;
        int c;
        double pp;
        c=ui->horizontalSlider->value();
        pp=(c*10)/3;
        zaw.Wczytaj(ui->lineEdit_imie->text(),ui->lineEdit_nazwisko->text(),ui->lineEdit_zespol->text(),c,pp);
        zawodnicy.push_back(zaw);
        ui->listWidget_lista->setVisible(true);
    }
}

int pozycja;

void MainWindow::on_pushButton_wybierz_clicked()
{
    pozycja=ui->listWidget_lista->currentIndex().row();
    if(ui->listWidget_lista->currentItem()->text().isEmpty())
    {


    }else
    {
        zawodnikwybrany=true;
        QFont font = ui->label_zawodnik->font();
        font.setPointSize(18);
        font.setBold(true);
        ui->label_zawodnik->setFont(font);

        QFont font1 = ui->label_czaslot->font();
        font1.setPointSize(18);
        font1.setBold(true);
        ui->label_czaslot->setFont(font);

        QFont font2 = ui->label_punktlot->font();
        font2.setPointSize(18);
        font2.setBold(true);
        ui->label_punktlot->setFont(font);

        //ui->label_czaslot->styleSheet();

        ui->label_zawodnik->setText(zawodnicy.at(pozycja).getImie()+" "+zawodnicy.at(pozycja).getNazwisko());
        ui->label_czaslot->setText("Czas lotu: "+QString::number(zawodnicy.at(pozycja).getCzas()));
        ui->label_punktlot->setText("Punkty: "+QString::number(zawodnicy.at(pozycja).getPunkt()));
        //ui->pushButton_2->setVisible(true);
        //ui->pushButton_winner->setVisible(true);

    }
}


void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    ui->label_czas->setText(QString::number(ui->horizontalSlider->value()));

}


void MainWindow::on_pushButton_clicked()
{
    QString link="http://www.teamusaf3b.com/wp-content/uploads/2010/12/SC4_Vol_F3_Soaring_08.pdf";
    QDesktopServices::openUrl(QUrl(link));

}


void MainWindow::on_listWidget_lista_clicked(const QModelIndex &index)
{
    ui->pushButton_wybierz->setVisible(true);
}



