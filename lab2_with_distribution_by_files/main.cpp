#include <QCoreApplication>
#include<iostream>
#include"methodunit.cpp"
#include"ClassUnit.cpp"
#include"printoperatorunit.h"
#include"unit.cpp"
#include "fabric.cpp"
std::string generateProgram(Fabric* fabric) {
      auto classA = fabric->createClass("myClass");
      auto methodB = fabric->createMethod("testFunc1", "void", 0);
      classA->add(methodB,IClassUnit::PUBLIC);
      auto methodC = fabric->createMethod("testFunc2", "void", IMethodUnit::STATIC);
      classA->add(methodC,IClassUnit::PRIVATE);
      auto methodD = fabric->createMethod("testFunc3", "void", IMethodUnit::VIRTUAL | IMethodUnit::CONST);
      classA->add(methodD,IClassUnit::PUBLIC);
      auto print = fabric->createPrint2("hello world");
      auto methodE = fabric->createMethod("testFunc4", "void", IMethodUnit::VIRTUAL | IMethodUnit::CONST);

      methodE->add(print);
       classA->add(methodE,IClassUnit::PROTECTED);
       // Абстрактной финальной функции не может существовать (JAVA), а в С++ и С# таких определений нет.
       //  auto mth7 = factory->createMethod("M1", "void", IMethodUnit::FINAL | IMethodUnit::ABSTRACT);
       // В JAVA нет VIRTUAL, а в С++ и C# не бывает STATIC и VIRTUAL метода одновременно
       //      auto mth8 = factory->createMethod("M2", "int", IMethodUnit::VIRTUAL | IMethodUnit::STATIC);
       //    auto print3 = factory->createPrintOperator("F1");
       //    auto print4 = factory->createPrintOperator("F2");
       //classA->add(mt7,IClassUnit::PRIVATE_PROTECTED);
       //classA->add(mt8,IClassUnit::PRIVATE);
       // mth7->add(print3);
       //  mth8->add(print4);
       /*
       // Вкладываем класс в класс (создадим еще один)
       auto classB = fabric->createClass("CLASSINSIDE");
       classA->add(classB, IClassUnit::PUBLIC);
       // Вкладываем оператор печати в класс
       classA->add(print,1);
       //Вкладываем класс в метод
       methodE->add(classB);
       methodB->add(methodD); */
       //Вкладываем метод в метод
       //    mth7->add(mth8);
       //Вкладываем класс в оператор печати  // Получаем ошибку определенную в unit
       //    try  { print->add(classB,0); }  catch(const std::runtime_error& e){ std::cout << "Catched an exention std::runtime_error: " << e.what() << std::endl;}
       //Вкладываем оператор печати в оператор печати  // Получаем ошибку определенную в unit
       //print->add(print3);
       return classA->compile();
}


int main(int argc, char *argv[])
{
    CsharpFabric* Csharp = new CsharpFabric;
    CFabric* C = new CFabric;
    JavaFabric* java = new JavaFabric;
    QCoreApplication a(argc, argv);
    std::cout << generateProgram(Csharp) << std::endl;
    delete C;
    delete Csharp;
    delete java;
    return a.exec();
}
