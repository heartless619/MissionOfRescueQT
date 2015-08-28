#include <QApplication>
#include <QTimer>
#include "api4testing/Game.h"
#include <QDebug>
#include <QElapsedTimer>
#include "framecountercheck.h"
#include "logger.h"
#include "scorecheck.h"

Game * game;


int main(int argc, char *argv[]){

    // use some code to check app launching time
    static qint64 vTime = 0;
    QElapsedTimer et;
    et.start();
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    vTime += et.nsecsElapsed();
    qDebug() << "time elapsed for app launch:" << vTime << "ns";

    //
    //         Logger starts            ////
    //                                  ////
    //                                  ////
    ////////////////////////////////////////
//****************************************************************************
    Logger *logger = new Logger("TestingResult.xml");
    if(!logger->OpenFile())
    {
        qDebug() << "Logging file open FAIL!";
    }

    //         verifying starts here    ////
    //                                  ////
    //                                  ////
    ///////////////////////////////////////
//****************************************************************************
    // Unit Test: counter test
    // test 1: counter increase

    FrameCounterCheck * testCounter = new FrameCounterCheck();

    if( testCounter->FrameCounterIncrease(game) )
    {
        // logging pass result
        qDebug() << "test 1: counter increase PASS!";
        logger->writeFile("test 1: counter increase", "PASS", "none");
    }
    else
    {
        // logging fail result
        logger->writeFile("test 1: counter increase", "FAIL", "none");
        qDebug() << "test 1: counter increase FAIL!";
    }

    // test 2: reset the counter
    if( testCounter->FrameCounterZeroCheck(game) )
    {
        // logging pass result
        logger->writeFile("test 2: reset the counter", "PASS", "none");
        qDebug() << "test 2: reset the counter PASS!";
    }
    else
    {
        // logging fail result
        logger->writeFile("test 2: reset the counter", "FAIL", "none");
        qDebug() << "test 2: reset the counter FAIL!";
    }

    // test 3: decrease the counter
    if( testCounter->FrameCounterDecreaseCheck(game) )
    {
        // logging pass result
        logger->writeFile("test 3: decrease the counter", "PASS", "none");
    }
    else
    {
        // logging fail result
        logger->writeFile("test 3: decrease the counter", "FAIL", "none");

    }


    // test 4: update the counter
    if( testCounter->FrameCounterUpdateCheck(game) )
    {
        // logging pass result
        logger->writeFile("test 4: update the counter", "PASS", "none");

    }
    else
    {
        // logging fail result
        logger->writeFile("test 4: update the counter", "FAIL", "none");

    }
//****************************************************************************
    // Unit Test: counter test
    // test 5: Increase the score
    ScoreCheck *testScore = new ScoreCheck();
    if( testScore->ScoreIncrease(game) )
    {
        // logging pass result
        logger->writeFile("test 5: Increase the score", "PASS", "none");
    }
    else
    {
        // logging fail result
        logger->writeFile("test 5: Increase the score", "FAIL", "none");

    }


//****************************************************************************
    // Unit Test: counter testplayer test


//****************************************************************************
    // Performance test:

    QString path = QCoreApplication::applicationDirPath();
    QDir directory(path);
    directory.cdUp();
    directory.cdUp();
    directory.cd("Project4interview/debug/");
    QString app = directory.filePath("Project4interview.exe");
    qDebug() << "Path = " << directory ;
    qDebug()<< "App = " << app;
    QStringList arguments;

    // Launch process test
    QProcess *myProcess = new QProcess();
    myProcess->start(app, arguments);
    if( myProcess->state() == 2)
    {
        logger->writeFile("test 6: Launch the app", "PASS", "none");
    }
    else
    {
        logger->writeFile("test 6: Launch the app", "FAIL", "Process state is not running");
    }
    qDebug()<<myProcess->errorString();
    qDebug()<<"1st process ->" <<myProcess->state();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Stress launching test
    qDebug()<<"argc = "<< argc;
    if( argc > 2 )  // testApp -stress loop_number
    {
        qDebug()<<"argv[1] = "<< argv[1];
        qDebug()<<"argv[2] = "<< argv[2];
        if( QString(argv[1]) == QString("-stress") )
        {
            qDebug()<<"Enter the loop!";
            int counter = 0;
            for(int i=0; i<atoi(argv[2]); i++)
            {
                counter++;
                QProcess *myProcess2 = new QProcess();
                myProcess2->start(app, arguments);
                qDebug()<< i << "st/nd/th process ->" << myProcess2->state();
                if(myProcess2->state() != 2)
                    break;
            }
            if( counter == atoi(argv[2]) )
            {
                QString s = QString::number(counter);
                QString text = "Succeed launching app " + s + " times!";
                logger->writeFile("Stress test: Launch app multiple times", "PASS", text );
            }
            else
            {
                QString s = QString::number(counter);
                QString text = "Failed at the No." + s + " times launching";
                logger->writeFile("Stress test: Launch app multiple times", "FAIL", text );
            }


        }
    }
//****************************************************************************
    logger->CloseFile();
    return true;
}
