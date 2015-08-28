#include <QDebug>
#include "framecountercheck.h"


bool FrameCounterCheck::FrameCounterIncrease(Game* aGame)
{
    //Get current counter
    int vCurrentCounter = aGame->fCounter->GetFrameCounter();
    //increase the counter
    aGame->fCounter->Increase();
    int vCounterAfterIncrease = aGame->fCounter->GetFrameCounter();

    if( vCounterAfterIncrease == vCurrentCounter+1)
    {
        return true;
    }
    qDebug() << "Counter value before being increased:" << vCurrentCounter;
    qDebug() << "Counter value after being increased:" << vCounterAfterIncrease;
    return false;
}

bool FrameCounterCheck::FrameCounterZeroCheck(Game* aGame)
{
    // Zero the counter
    aGame->fCounter->ZeroCounter();
    int vCounterAfterSet = aGame->fCounter->GetFrameCounter();
    if( vCounterAfterSet == 0)
    {
    return true;
    }
    qDebug() << "Counter value after being reset:" << vCounterAfterSet;
    return false;
}

bool FrameCounterCheck::FrameCounterDecreaseCheck(Game* aGame)
{
    //Get current counter
    int vCurrentCounter = aGame->fCounter->GetFrameCounter();
    //increase the counter
    aGame->fCounter->ObjectDecrease();
    int vCounterAfterDecrease = aGame->fCounter->GetFrameCounter();

    if( vCounterAfterDecrease == vCurrentCounter-1)
    {
        return true;
    }
    qDebug() << "Counter value before being decreased:" << vCurrentCounter;
    qDebug() << "Counter value after being decreased:" << vCounterAfterDecrease;
    return false;

}

bool FrameCounterCheck::FrameCounterUpdateCheck(Game* aGame)
{
    // Zero the counter
    //aGame->fCounter->Increase();
    //aGame->fCounter->UpdateFps();
    int vCounterAfterSet = aGame->fCounter->GetFrameCounter();
    if( vCounterAfterSet == 0)
    {
    return true;
    }
    qDebug() << "Counter value after being reset:" << vCounterAfterSet;
    return false;
}
