#ifndef SCORECHECK
#define SCORECHECK


#include <QObject>
#include "api4testing/game.h"


class ScoreCheck: public QObject{
    Q_OBJECT
public:

    bool ScoreIncrease(Game* aGame);



};

#endif // SCORECHECK

