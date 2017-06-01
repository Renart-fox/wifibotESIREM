#ifndef NETWORKINGOPT_H
#define NETWORKINGOPT_H

class NETWORKINGOPT
{
public:
    static quint16 crc16(QByteArray buffer) {

        quint16 crc = 0xFFFF;
        quint16 polynome = 0xA001;
        unsigned int parity = 0;
        unsigned int cptBit;
        unsigned int cptOct;

        for (cptOct = 1; cptOct < 7; cptOct++){

            crc ^= (unsigned char) buffer.at(cptOct);

            for (cptBit = 0; cptBit <= 7 ; cptBit++){

                parity = crc;
                crc >>= 1;

                if (parity % 2 == true) crc ^= polynome;
            }
        }

        return crc;
    }
};

#endif // NETWORKINGOPT_H
