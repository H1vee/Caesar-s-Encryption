#include "ApplicationController.h"
#include <QDebug>

ApplicationController::ApplicationController(QObject *parent)
    : QObject(parent) {
}

QString ApplicationController::encrypt(const QString& plaintext, int keyA, int keyB) {
    return m_cipher.encrypt(plaintext, keyA, keyB);
}

QString ApplicationController::decrypt(const QString& ciphertext, int keyA, int keyB) {
    return m_cipher.decrypt(ciphertext, keyA, keyB);
}

QString ApplicationController::openFile() {
    QString filePath = m_fileHandler.openFileDialog();
    if (filePath.isEmpty()) {
        return "";
    }

    m_currentFilePath = filePath;
    m_currentText = m_fileHandler.readFile(filePath);
    return m_currentText;
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