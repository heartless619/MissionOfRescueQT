#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "FrameCounter.h"



class Game: public QGraphicsView{

public:
    Game(QWidget * parent=0);

    int GetFps();
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    FrameCounter * fCounter;

    int drawForeground();
    int m_fps;
public slots:
    void UpdateFps();




};

#endif // GAME_H

