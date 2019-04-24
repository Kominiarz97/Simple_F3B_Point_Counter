#ifndef ZAWODNIK_H
#define ZAWODNIK_H
#include <QString>
class Zawodnik
{
public:
    Zawodnik();
    void Wczytaj(QString i,QString n,QString z,int c,double pp);

    QString getImie() const;
    QString getNazwisko()  const;
    QString getZespol() const;
    int getCzas() const;
    double getPunkt() const;


private:
    int czas;
    double punkty;
    QString imie;
    QString nazwisko;
    QString zespol;

};

#endif // ZAWODNIK_H
