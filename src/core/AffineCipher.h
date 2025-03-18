// affinecipher.h
#ifndef AFFINECIPHER_H
#define AFFINECIPHER_H

#include <QString>
#include <QVector>

class AffineCipher {
public:
    AffineCipher();
    

    QString encrypt(const QString& plaintext, int keyA, int keyB);
    QString decrypt(const QString& ciphertext, int keyA, int keyB);
    

    bool validateKey(int keyA, int keyB, QString& errorMessage);
    
private:

    int modInverse(int a, int m);
    int gcd(int a, int b);

    const int ALPHABET_SIZE = 26;
    const QString ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int charToIndex(QChar c);
    QChar indexToChar(int index);
};

#endif // AFFINECIPHER_H