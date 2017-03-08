/*
 * Software Engineering homework 2
 * Nikolay Raykov <n.raykov@jacobs-university.de>
*/

#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <iostream>

int main()
{
    QString str = "Hello world !!";

    QFile caFile("output.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }
    QTextStream outStream(&caFile);
    outStream << str;
    caFile.close();
    return 0;
}
