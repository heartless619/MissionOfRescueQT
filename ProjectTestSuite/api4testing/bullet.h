#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

class Bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
    void PositionUpdate();
    int GetPositionChangeCounter();

public slots:
    void move();
private:
    QMediaPlayer * explosionSound;
    int m_positionUpdateCounter;

};

#endif // BULLET_H

