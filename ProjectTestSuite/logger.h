#ifndef LOGGER
#define LOGGER
#include <QtXml/QtXml>
#include <QtXml/QDomDocument>

const int INDENT = 4;

class Logger
{
public:
    Logger(QString fileName);
    bool OpenFile();
    bool writeFile(QString caseName, QString result, QString shortInfo);
    bool CloseFile();

private:
    QFile* m_file;
    QString m_fileName;
    QDomDocument m_doc;
    QDomElement m_root;
    QDomText m_testCaseName;
    QDomText m_testCaseResult;
    QDomText m_infoText;
};
#endif // LOGGER

