#ifndef FABRIC_CPP
#define FABRIC_CPP
#include"methodunit.h"
#include"ClassUnit.h"
#include"printoperatorunit.h"

class Fabric {
public:
    virtual IClassUnit* createClass(std::string name) = 0;
     virtual std::shared_ptr<IMethodUnit> createMethod(std::string name, std::string vozvr, int Num) = 0;
 //   virtual IMethodUnit* createMethod(std::string name, std::string vozvr,int Num) = 0;
    virtual  std::shared_ptr<IPrintOperatorUnit>  createPrint2( std::string text)=0;
    virtual ~Fabric(){};
};

class CsharpFabric : public Fabric {
public:
    IClassUnit* createClass(std::string name)override
    {
        return new CsharpClassUnit(name);
    }
    std::shared_ptr<IMethodUnit> createMethod(std::string name, std::string vozvr, int Num) override {
       // IMethodUnit* CsharpMethodUnitPTR = new CsharpMethodUnit(name,vozvr, Num);
        return std::make_shared<CsharpMethodUnit>(name, vozvr, Num);
    }
     std::shared_ptr<IPrintOperatorUnit>  createPrint2 ( std::string  text)override  {return std::make_shared<CsharpPrintOperatorUnit>(text);}
     ~CsharpFabric(){};
};

class CFabric: public Fabric {

public:
    IClassUnit* createClass(std::string name)override
    {
        return new CClassUnit(name);
    }
    std::shared_ptr<IMethodUnit> createMethod(std::string name, std::string vozvr, int Num) override {
        // IMethodUnit* CsharpMethodUnitPTR = new CsharpMethodUnit(name,vozvr, Num);
        return std::make_shared<CMethodUnit>(name, vozvr, Num);
    }
     std::shared_ptr<IPrintOperatorUnit>  createPrint2 ( std::string  text)override  {return std::make_shared<CPrintOperatorUnit>(text);}
    ~CFabric(){}
};

class JavaFabric: public Fabric {

public: IClassUnit* createClass(std::string name)override{
        return new JavaClassUnit(name);
    }
    std::shared_ptr<IMethodUnit> createMethod(std::string name, std::string vozvr, int Num) override {
        // IMethodUnit* CsharpMethodUnitPTR = new CsharpMethodUnit(name,vozvr, Num);
        return std::make_shared<JavaMethodUnit>(name, vozvr, Num);
    }
    std::shared_ptr<IPrintOperatorUnit>  createPrint2 ( std::string  text)override  { return std::make_shared<JavaPrintOperatorUnit>(text);}
     ~JavaFabric(){};
};


#endif // FABRIC_CPP
