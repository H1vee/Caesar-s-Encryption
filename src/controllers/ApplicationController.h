// applicationcontroller.h
#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QObject>
#include "../core/AffineCipher.h"
#include "../core/FileHandler.h"

class ApplicationController : public QObject {
    Q_OBJECT

public:
    explicit ApplicationController(QObject *parent = nullptr);

    // QML invokable methods
    Q_INVOKABLE QString encrypt(const QString& plaintext, int keyA, int keyB);
    Q_INVOKABLE QString decrypt(const QString& ciphertext, int keyA, int keyB);
    Q_INVOKABLE QString openFile();
    Q_INVOKABLE bool saveEncryptedFile();
    Q_INVOKABLE bool setCurrentText(const QString& text);
    Q_INVOKABLE QString getCurrentText();

private:
    AffineCipher m_cipher;
    FileHandler m_fileHandler;
    QString m_currentText;
    QString m_currentFilePath;
};

#endif // APPLICATIONCONTROLLER_H