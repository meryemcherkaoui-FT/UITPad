#include "document.h"

Document::Document()
{
    m_fileName = "Untitled";
    m_isModified = false;
}

void Document::setContent(const QString &text)
{
    m_content = text;
    m_isModified = true;
}

QString Document::getContent() const
{
    return m_content;
}

void Document::setFileName(const QString &name)
{
    m_fileName = name;
}

QString Document::getFileName() const
{
    return m_fileName;
}

void Document::setFilePath(const QString &path)
{
    m_filePath = path;
}

QString Document::getFilePath() const
{
    return m_filePath;
}

bool Document::isModified() const
{
    return m_isModified;
}

void Document::setModified(bool modified)
{
    m_isModified = modified;
}
