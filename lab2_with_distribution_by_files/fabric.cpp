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
};

class CsharpFabric : public Fabric {
public: IClassUnit* createClass(std::string name)override
    {
        return new CsharpClassUnit(name);
    }
    IMethodUnit* createMethod(std::string name, std::string vozvr, int Num) override {
        IMethodUnit* CsharpMethodUnitPTR = new CsharpMethodUnit(name,vozvr, Num);
        return CsharpMethodUnitPTR;
    }
    IPrintOperatorUnit*  createPrint2 ( std::string  text)override  {return new CsharpPrintOperatorUnit(text);}
};




#endif // FABRIC_CPP
