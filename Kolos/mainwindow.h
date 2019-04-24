#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_dodaj_clicked();

    void on_pushButton_wybierz_clicked();

    void on_pushButton_clicked();


    void on_horizontalSlider_actionTriggered(int action);

    void on_pushButton_czas_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_lista_activated(const QModelIndex &index);

    void on_listWidget_lista_clicked(const QModelIndex &index);

    void on_pushButton_winner_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
