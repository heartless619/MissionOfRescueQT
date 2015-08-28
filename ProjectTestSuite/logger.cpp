#include "logger.h"

Logger::Logger(QString fileName)
{
    m_fileName = fileName;
    m_root = m_doc.createElement("TestingResult");
    m_doc.appendChild(m_root);
}

bool Logger::OpenFile()
{

    m_file = new QFile();

    m_file->setFileName(m_fileName);
    if (!m_file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
            return false;
    }
    return true;
}

bool Logger::writeFile(QString caseName, QString result, QString shortInfo)
{
    // create element - tag
    QDomElement vTC = m_doc.createElement("TC");
    QDomElement vTitle = m_doc.createElement("Title");
    QDomElement vResult = m_doc.createElement("Result");
    QDomElement vInfo = m_doc.createElement("Info");


    m_testCaseName = m_doc.createTextNode(caseName);
    m_testCaseResult = m_doc.createTextNode(result);
    m_infoText = m_doc.createTextNode(shortInfo);
    /*
    <Testing Result>
        <TC>
            <Title></Title>
            <Result></Result>
            <Info></Info>
        </TC>
    </Testing Result>
    */

    m_root.appendChild(vTC);
    vTC.appendChild(vTitle);
    vTitle.appendChild(m_testCaseName);

    vTC.appendChild(vResult);
    vResult.appendChild(m_testCaseResult);

    vTC.appendChild(vInfo);
    vInfo.appendChild(m_infoText);


    return true;

}

bool Logger::CloseFile()
{
    const int Indent = 4;
    QTextStream out(m_file);
    QDomNode xmlNode = m_doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"ISO-8859-1\"");
    m_doc.insertBefore(xmlNode, m_doc.firstChild());
    m_doc.save(out, Indent);

    return true;
}
