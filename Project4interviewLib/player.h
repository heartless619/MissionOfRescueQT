#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void PositionUpdate();
    int GetPositionChangeCounter();
public slots:
    void spawn();
    void ZeroPositionChangeCounter();
private:
    QMediaPlayer * bulletsound;
    int m_positionUpdateCounter;

};

#endif // PLAYER_H
