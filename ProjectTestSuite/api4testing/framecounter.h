#ifndef FRAMECOUNTER_H
#define FRAMECOUNTER_H

#include <QGraphicsTextItem>


class FrameCounter: public QGraphicsTextItem{

public:
    FrameCounter(QGraphicsItem * parent=0);
    void ObjectDecrease();
    void ObjectIncrease();
    int GetFrameCounter();
    void Increase();
    void ZeroCounter();
public slots:
    void UpdateFps();
private:
    int frameCounter;
    int m_objectNum;
};

#endif FRAMECOUNTER_H

