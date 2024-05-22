#include <QCoreApplication>
#include<iostream>
#include"methodunit.cpp"
//#include"ClassUnit.cpp"
#include"ClassUnit.cpp"
#include"printoperatorunit.h"
#include"unit.cpp"
#include "fabric.h"
std::string generateProgram(Fabric* fabric) {
      IClassUnit* classA = fabric->createClass("keek");
    ClassUnit myClass("MyClass");
    myClass.add(
        std::make_shared < MethodUnit > ("testFunc1", "void", 0),
        ClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared < MethodUnit > ("testFunc2", "void", MethodUnit::STATIC),
        ClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared < MethodUnit > ("testFunc3", "void", MethodUnit::VIRTUAL |
                                                              MethodUnit::CONST),
        ClassUnit::PUBLIC
        );
    auto method = std::make_shared < MethodUnit > ("testFunc4", "void",
                                               MethodUnit::STATIC);
    method -> add(std::make_shared < PrintOperatorUnit > ( "(Hello, world!\n)"));
    myClass.add(method, ClassUnit::PROTECTED);
    return myClass.compile()+classA->compile();
}


int main(int argc, char *argv[])
{
    CsharpFabric* s = new CsharpFabric;
    QCoreApplication a(argc, argv);
    std::cout << generateProgram(s) << std::endl;

    return a.exec();
}
