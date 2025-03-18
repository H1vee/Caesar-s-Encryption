// filehandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include <QFile>

class FileHandler {
public:
    FileHandler();


    QString readFile(const QString& filePath);
    bool writeFile(const QString& filePath, const QString& content);

    QString openFileDialog();
    QString saveFileDialog();
};

#endif // FILEHANDLER_H
