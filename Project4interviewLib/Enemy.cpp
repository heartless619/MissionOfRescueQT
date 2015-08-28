
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //
#include "Game.h"
#include "globaldef.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    m_positionUpdateCounter = 0;
    //set random y position under the sea
    int random_number = rand() % DEAPTH_OF_SEA + SEA_SURFACE_COORDINATE;
    if( random_number < SCENE_SIZE_HEIGHT ){
        setPos(SCENE_SIZE_WIDTH,random_number);
    }
    else{
        setPos(SCENE_SIZE_WIDTH,random_number - 300);
    }

    setPixmap(QPixmap(":/images/images/enemy.png"));
    setTransformOriginPoint(50,50);

    game->fCounter->ObjectIncrease();

    // create timer to create enemy
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(15);
}

void Enemy::move(){

    setPos(x()-1,y());
    PositionUpdate();

    if (pos().x() < -200){

        game->fCounter->Increase();

        scene()->removeItem(this);
        delete this;
    }
    game->fCounter->Increase();

}

void Enemy::PositionUpdate(){
    if(m_positionUpdateCounter < FRAME_COUNTER_MAX_VALUE)
    {
        m_positionUpdateCounter++;
    }
    else
    {
        // zero it to avoid huge number
        m_positionUpdateCounter = 0;
    }

}

int Enemy::GetPositionChangeCounter()
{
    return m_positionUpdateCounter++;
}

