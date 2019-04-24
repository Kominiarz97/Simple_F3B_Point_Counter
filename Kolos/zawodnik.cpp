#include "zawodnik.h"
#include <QString>
Zawodnik::Zawodnik()
{

}

void Zawodnik::Wczytaj(QString i,QString n,QString z,int c,double pp)
{
    imie=i;
    nazwisko=n;
    zespol=z;
    czas=c;
    punkty=pp;
}



QString Zawodnik::getImie() const
{
    return this->imie;
}

QString Zawodnik::getNazwisko() const
{
    return nazwisko;
}
QString Zawodnik::getZespol() const
{
    return zespol;
}
 int Zawodnik::getCzas() const
 {
     return czas;
 }
 double Zawodnik::getPunkt() const
 {
     return punkty;
 }



