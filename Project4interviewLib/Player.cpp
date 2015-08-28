
#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "globaldef.h"
extern Game * game; // access the items from game

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/sounds/bullet.mp3"));

    setPixmap(QPixmap(":/images/images/player.png"));

    m_positionUpdateCounter = 0;
}

void Player::keyPressEvent(QKeyEvent *event){
    // The user could move the player 4 directions with arrow keys
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        {
        setPos(x()-10,y());
        PositionUpdate();

        }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + PLAYER_SIZE_WIDTH < SCENE_SIZE_WIDTH)
        {
            setPos(x()+10,y());
            PositionUpdate();
        }

    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > SCENE_SIZE_HEIGHT*0.41)  // Sea surface position
        {
        setPos(x(),y()-10);
        PositionUpdate();
        }
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() < SCENE_SIZE_HEIGHT - PLAYER_SIZE_HEIGHT*2)
        {
        setPos(x(),y()+10);
        PositionUpdate();
        }
    }
    else if (event->key() == Qt::Key_Plus){
        // add more enemies quickly
        if( EnemySpawnFrequency > 500)
        {
            EnemySpawnFrequency -=500;  // shorten the time for generating enemy
        }
        qDebug() << "Key_Plus pressed, frequency = " << EnemySpawnFrequency;
        spawn();
    }
    else if (event->key() == Qt::Key_Minus){
        // add more enemies slowly
        if( EnemySpawnFrequency < 5000)
        {
            EnemySpawnFrequency +=500;  // enlarge the time span for generating enemy
        }

        qDebug() << "Key_Minus pressed, frequency = " << EnemySpawnFrequency;
    }
    // shoot with the space key
    else if (event->key() == Qt::Key_Space){
        // create a missile
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+45,y()+15);
        scene()->addItem(bullet);

        // play sound when launch a missile
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }
}

void Player::spawn(){

    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::PositionUpdate(){

    m_positionUpdateCounter++;
    game->fCounter->Increase();

}

int Player::GetPositionChangeCounter()
{
    return m_positionUpdateCounter++;
}

void Player::ZeroPositionChangeCounter(){
    m_positionUpdateCounter = 0;
    game->fCounter->ZeroCounter();
}
