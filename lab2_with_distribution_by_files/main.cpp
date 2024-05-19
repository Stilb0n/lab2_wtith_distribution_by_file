#include <QCoreApplication>
#include<iostream>
#include "unit.cpp"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    std::cout << generateProgram() << std::endl;

    return a.exec();
}
