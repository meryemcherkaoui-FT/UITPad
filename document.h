#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>

class Document
{
public:
    Document();

    // Méthodes pour gérer le fichier
    void setContent(const QString &text);
    QString getContent() const;

    void setFileName(const QString &name);
    QString getFileName() const;

    void setFilePath(const QString &path);
    QString getFilePath() const;

    bool isModified() const;
    void setModified(bool modified);

private:
    QString m_content;   // Le texte du fichier
    QString m_fileName;  // Nom (ex: main.cpp)
    QString m_filePath;  // Chemin complet
    bool m_isModified;   // Est-ce qu'on a changé le texte sans sauvegarder ?
};

#endif // DOCUMENT_H
