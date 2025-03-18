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
    // Convert QUrl to local file path
    const QString filePath = fileUrl.toLocalFile();

    // Read the file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle error
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Process the content and update your UI
    // For example, if you have a Q_PROPERTY for text content:
    setInputText(content);  // Assuming you have this method
}

void ApplicationController::processSaveFile(const QUrl& fileUrl,const QString& textToSave) {
    // Convert QUrl to local file path
    const QString filePath = fileUrl.toLocalFile();

    // Write the file
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Handle error
        return;
    }

    QTextStream out(&file);
    out << textToSave;  // Write the passed text to the file
    file.close();
}
