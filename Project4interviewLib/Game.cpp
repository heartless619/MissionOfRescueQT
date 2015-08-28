
#include "Game.h"
#include "Globaldef.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QPainter>

Game::Game(QWidget *parent){


    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1366,768); // make the scene 1366x768
    setBackgroundBrush(QBrush(QImage(":/images/images/background.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1366,768);

    // create the player
    player = new Player();
    player->setPos(400,500); // set the play at the surface of the sea when starts the game
    // make the player controllable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // create the score
    score = new Score();
    scene->addItem(score);

    // create frame counter
    fCounter = new FrameCounter();
    fCounter->setPos(fCounter->x(),fCounter->y()+25);
    scene->addItem(fCounter);


    // spawn enemies : TODO change the enemy coming frequency with level settings
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(EnemySpawnFrequency);

    // calculat the fps and update per second
    QTimer * fpsUpdateTimer = new QTimer();
    QObject::connect(fpsUpdateTimer,SIGNAL(timeout()),player,SLOT(ZeroPositionChangeCounter() ) );
    fpsUpdateTimer->start(1000);  // update every second


    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sounds/background.mp3"));
    music->play();

    show();
}


