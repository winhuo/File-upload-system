#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QKeyEvent>
#include <QMainWindow>
#include<QLabel>
#include "mylabel.h"
#include "magictower.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void showPic();
private:
    MyLabel* label[13][13];
    magicTower *magicT[13][13];
    gamePerson *gameP[7];
    hero* myHero;
    QLabel *label_date;
protected:
    void show_data();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void move(int,int);
};

#endif // MAINWINDOW_H
