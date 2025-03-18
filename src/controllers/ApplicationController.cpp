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

bool ApplicationController::saveEncryptedFile() {
    if (m_currentText.isEmpty()) {
        return false;
    }

    QString filePath = m_fileHandler.saveFileDialog();
    if (filePath.isEmpty()) {
        return false; // User canceled
    }

    return m_fileHandler.writeFile(filePath, m_currentText);
}

bool ApplicationController::setCurrentText(const QString& text) {
    m_currentText = text;
    return true;
}

QString ApplicationController::getCurrentText() {
    return m_currentText;
}