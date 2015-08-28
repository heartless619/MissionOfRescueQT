
#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include "globaldef.h"

extern Game * game; // wrap up everything

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    m_positionUpdateCounter = 0;

    setPixmap(QPixmap(":/images/images/bullet.png"));
    explosionSound = new QMediaPlayer();
    explosionSound->setMedia(QUrl("qrc:/sounds/sounds/explosion.mp3"));
    game->fCounter->ObjectIncrease();

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(10);
}

void Bullet::move(){
    game->fCounter->Increase();

    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            // play explosion sound
            if (explosionSound->state() == QMediaPlayer::PlayingState){
                explosionSound->setPosition(0);
            }
            else if (explosionSound->state() == QMediaPlayer::StoppedState){
                explosionSound->play();
            }

            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // really delete them
            delete colliding_items[i];
            delete this;
            // remove object counter
            game->fCounter->ObjectDecrease();  // remove bullet
            game->fCounter->ObjectDecrease();   // remove the enemy which is hit

            return;
        }

    }

    // bullet move
    setPos(x()+5,y());
    // delete bullet when it is out of the screen
    if (pos().x() > SCENE_SIZE_WIDTH + PLAYER_SIZE_WIDTH){
        scene()->removeItem(this);
        delete this;
    }
    PositionUpdate();

}



void Bullet::PositionUpdate(){
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

int Bullet::GetPositionChangeCounter()
{
    return m_positionUpdateCounter++;
}
