#include "FileHandler.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

FileHandler::FileHandler() {
}

QString FileHandler::readFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "Error: Could not open file for reading";
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    return content;
}

bool FileHandler::writeFile(const QString& filePath, const QString& content) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out << content;
    file.close();

    return true;
}

QString FileHandler::openFileDialog() {
    return QFileDialog::getOpenFileName(nullptr, "Open Text File", "", "Text Files (*.txt);;All Files (*)");
}

QString FileHandler::saveFileDialog() {
    return QFileDialog::getSaveFileName(nullptr, "Save Text File", "", "Text Files (*.txt);;All Files (*)");
}