#include <QCoreApplication>
#include<iostream>
#include"methodunit.cpp"

#include"ClassUnit.cpp"
#include"printoperatorunit.h"
#include"unit.cpp"
#include "fabric.cpp"
std::string generateProgram(Fabric* fabric) { //mod
    //new
      IClassUnit* classA = fabric->createClass("keek");
      IMethodUnit* methodB = fabric->createMethod("testFunc1NEW", "void", 0);
      IPrintOperatorUnit* printA = fabric->createPrint2("fa123");
      classA->add(methodB,0); // line 12

      IMethodUnit* methodC = fabric->createMethod("testFunc3NEW", "void",IMethodUnit::FINAL|IMethodUnit::STATIC);
      classA->add(methodC,0);

      IMethodUnit* methodD = fabric->createMethod("testFunc2", "void", 1);
      classA->add(methodD,1);

      auto methodNEW = fabric->createMethod("testFunc4", "void", 1);
      IPrintOperatorUnit* PrintOperatorA = printA;
      methodNEW->add( PrintOperatorA,1);
      classA->add(methodNEW,2);

   //old
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
    //old


    return myClass.compile()+classA->compile(); //mod
}


int main(int argc, char *argv[])
{
    CsharpFabric* Csharp = new CsharpFabric;
    CFabric* C = new CFabric;
    JavaFabric* java = new JavaFabric;
    QCoreApplication a(argc, argv);
    std::cout << generateProgram(java) << std::endl;
    delete C;
    delete Csharp;
    delete java;
    return a.exec();
}
