#ifndef FRAMECOUNTERCHECK
#define FRAMECOUNTERCHECK

#include <QObject>
#include "api4testing/game.h"


class FrameCounterCheck: public QObject{
    Q_OBJECT
public:
    //FrameCounterCheck();
    bool FrameCounterIncrease(Game* aGame);
    bool FrameCounterZeroCheck(Game* aGame);
    bool FrameCounterDecreaseCheck(Game* aGame);
    bool FrameCounterUpdateCheck(Game* aGame);

};


#endif // FRAMECOUNTERCHECK

