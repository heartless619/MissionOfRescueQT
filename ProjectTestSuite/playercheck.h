#ifndef PLAYERCHECK
#define PLAYERCHECK

#include <QObject>
#include "api4testing/game.h"


class PlayerCheck: public QObject{
    Q_OBJECT
public:

    bool KeyEventCheck(Game* aGame);



};
#endif // PLAYERCHECK

