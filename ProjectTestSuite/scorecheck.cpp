#include <QDebug>
#include "scorecheck.h"


bool ScoreCheck::ScoreIncrease(Game* aGame)
{
    //Get current score
    int vCurrentScore = aGame->score->getScore();
    //increase the score
    aGame->score->increase();
    int vScoreAfterIncrease = aGame->score->getScore();

    if( vCurrentScore != vScoreAfterIncrease)
    {
        return true;
    }
    qDebug() << "Score value before and after being increased:" << vScoreAfterIncrease;

    return false;
}


