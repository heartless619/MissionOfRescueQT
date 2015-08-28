#include <QApplication>
#include <QTimer>
#include "Game.h"
#include <QDebug>
#include <QElapsedTimer>


Game * game;


int main(int argc, char *argv[]){
    static qint64 vTime = 0;

    QElapsedTimer et;
    et.start();

    QApplication a(argc, argv);

    game = new Game();

    game->show();

    vTime += et.nsecsElapsed();
    qDebug() << "time elapsed for app launch:" << vTime << "ns";


    return a.exec();
}
