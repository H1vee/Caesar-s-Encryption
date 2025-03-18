// affinecipher.cpp
#include "AffineCipher.h"
#include <QDebug>

AffineCipher::AffineCipher() {
}

QString AffineCipher::encrypt(const QString& plaintext, int keyA, int keyB) {
    QString result;
    QString errorMessage;

    if (!validateKey(keyA, keyB, errorMessage)) {
        return "Error: " + errorMessage;
    }

    for (const QChar& c : plaintext) {
        if (!ALPHABET.contains(c.toUpper())) {
            result.append(c);
            continue;
        }

        bool isLower = c.isLower();
        int index = charToIndex(c.toUpper());
        int newIndex = (keyA * index + keyB) % ALPHABET_SIZE;
        QChar encryptedChar = indexToChar(newIndex);

        result.append(isLower ? encryptedChar.toLower() : encryptedChar);
    }

    return result;
}

QString AffineCipher::decrypt(const QString& ciphertext, int keyA, int keyB) {
    QString result;
    QString errorMessage;

    if (!validateKey(keyA, keyB, errorMessage)) {
        return "Error: " + errorMessage;
    }

    int keyAInverse = modInverse(keyA, ALPHABET_SIZE);

    for (const QChar& c : ciphertext) {
        if (!ALPHABET.contains(c.toUpper())) {
            result.append(c);
            continue;
        }

        bool isLower = c.isLower();
        int index = charToIndex(c.toUpper());
        int newIndex = (keyAInverse * (index - keyB + ALPHABET_SIZE)) % ALPHABET_SIZE;
        QChar decryptedChar = indexToChar(newIndex);

        result.append(isLower ? decryptedChar.toLower() : decryptedChar);
    }

    return result;
}

bool AffineCipher::validateKey(int keyA, int keyB, QString& errorMessage) {
    if (keyA <= 0) {
        errorMessage = "Key A must be positive";
        return false;
    }

    if (keyB < 0 || keyB >= ALPHABET_SIZE) {
        errorMessage = "Key B must be between 0 and " + QString::number(ALPHABET_SIZE-1);
        return false;
    }

    if (gcd(keyA, ALPHABET_SIZE) != 1) {
        errorMessage = "Key A must be coprime with " + QString::number(ALPHABET_SIZE);
        return false;
    }

    return true;
}

int AffineCipher::modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

int AffineCipher::gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int AffineCipher::charToIndex(QChar c) {
    return ALPHABET.indexOf(c.toUpper());
}

QChar AffineCipher::indexToChar(int index) {
    return ALPHABET.at(index);
}
