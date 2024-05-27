#ifndef FABRIC_CPP
#define FABRIC_CPP
#include"methodunit.h"
#include"ClassUnit.h"
#include"printoperatorunit.h"

class Fabric {
public:
    virtual IClassUnit* createClass(std::string name) = 0;
    virtual IMethodUnit* createMethod(std::string name, std::string vozvr,int Num) = 0;
    virtual IPrintOperatorUnit* createPrint2( std::string text)=0;
    virtual ~Fabric(){};
};

class CsharpFabric : public Fabric {
public:
    IClassUnit* createClass(std::string name)override
    {
        return new CsharpClassUnit(name);
    }
    IMethodUnit* createMethod(std::string name, std::string vozvr, int Num) override {
        IMethodUnit* CsharpMethodUnitPTR = new CsharpMethodUnit(name,vozvr, Num);
        return CsharpMethodUnitPTR;
    }
    IPrintOperatorUnit*  createPrint2 ( std::string  text)override  {return new CsharpPrintOperatorUnit(text);}

};

class CFabric: public Fabric {

public:
    IClassUnit* createClass(std::string name)override
    {
        return new CClassUnit(name);
    }
    IMethodUnit* createMethod(std::string name, std::string vozvr, int Num) override
    {
        IMethodUnit* CMethodUnitPTR = new CMethodUnit(name,vozvr, Num);
        return CMethodUnitPTR;
    }
    IPrintOperatorUnit*  createPrint2 ( std::string  text)override  {return new CPrintOperatorUnit(text);}
    ~CFabric(){}
};


#endif // FABRIC_CPP
