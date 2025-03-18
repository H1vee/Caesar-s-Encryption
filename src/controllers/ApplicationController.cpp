#include "ApplicationController.h"
#include <QDebug>
#include <QUrl>

ApplicationController::ApplicationController(QObject *parent)
    : QObject(parent) {
}

QString ApplicationController::encrypt(const QString& plaintext, const int keyA, const int keyB) {
    return m_cipher.encrypt(plaintext, keyA, keyB);
}

QString ApplicationController::decrypt(const QString& ciphertext,const int keyA,const int keyB) {
    return m_cipher.decrypt(ciphertext, keyA, keyB);
}

void ApplicationController::processOpenFile(const QUrl& fileUrl) {
    const QString filePath = fileUrl.toLocalFile();

    
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    setInputText(content); 
}

void ApplicationController::processSaveFile(const QUrl& fileUrl,const QString& textToSave) {
    const QString filePath = fileUrl.toLocalFile();

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    out << textToSave;  
    file.close();
}
