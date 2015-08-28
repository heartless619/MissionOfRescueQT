
#include "FrameCounter.h"
#include <QFont>

FrameCounter::FrameCounter(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize
    frameCounter = 0;
    m_objectNum = 1;  // at the beginning, the player exists

    // draw the text
    setPlainText(QString("FPS: ") + QString::number(frameCounter));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void FrameCounter::ObjectDecrease(){
    if(m_objectNum > 0)
        m_objectNum--;
    //setPlainText(QString("FPS: ") + QString::number(frameCounter));
}

void FrameCounter::ObjectIncrease(){
    m_objectNum++;
    //setPlainText(QString("FPS: ") + QString::number(frameCounter));
}

void FrameCounter::UpdateFps(){
    ZeroCounter();
    //setPlainText(QString("FPS: ") + QString::number(frameCounter));

}

void FrameCounter::Increase(){
    frameCounter++;
    //setPlainText(QString("FPS: ") + QString::number(frameCounter));

}

int FrameCounter::GetFrameCounter(){
    return frameCounter;
}

void FrameCounter::ZeroCounter(){

    int tmpFps = int(frameCounter/m_objectNum);
    setPlainText(QString("FPS: ") + QString::number(tmpFps));
    frameCounter = 0;

}
