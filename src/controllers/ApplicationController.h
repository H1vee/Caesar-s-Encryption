// applicationcontroller.h
#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QObject>
#include "../core/AffineCipher.h"
#include "../core/FileHandler.h"

class ApplicationController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString inputText READ inputText WRITE setInputText NOTIFY inputTextChanged)
public:
    explicit ApplicationController(QObject *parent = nullptr);

    QString inputText() const { return m_inputText; }
    void setInputText(const QString &text) {
        if (m_inputText != text) {
            m_inputText = text;
            emit inputTextChanged();
        }
    }
    // QML invokable methods
    Q_INVOKABLE QString encrypt(const QString& plaintext, int keyA, int keyB);
    Q_INVOKABLE QString decrypt(const QString& ciphertext, int keyA, int keyB);
    Q_INVOKABLE void processOpenFile(const QUrl& fileUrl);

private:
    QString m_inputText;
    AffineCipher m_cipher;

public slots:
    void processSaveFile(const QUrl& fileUrl,const QString& textToSave);
signals:
    void inputTextChanged();
};

#endif // APPLICATIONCONTROLLER_H