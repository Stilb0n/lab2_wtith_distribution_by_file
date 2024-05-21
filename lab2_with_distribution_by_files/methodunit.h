#ifndef METHODUNIT_H
#define METHODUNIT_H
#include"unit.h"
#include<vector>
class MethodUnit
{
public:
    MethodUnit();
};

class IMethodUnit : public Unit {
public: enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };
public:
    std::string static name;
    std::string vozvr;
    int Num = 0;

};

class CsharpMethodUnit : public IMethodUnit {

public: CsharpMethodUnit( std::string  name,
                     std::string returnType, Flags
                         flags): m_name(name),
        m_returnType(returnType),
        m_flags(flags) {}

    ~CsharpMethodUnit(){

        for (  auto & elem : m_body)
        {
            delete (elem);
            ++elem;
        }
    };
    void add( Unit * dd , Flags)override {
        m_body.push_back(dd);
    };
    std::string compile(unsigned int level = 0) const override{
        std::string result = generateShift(level);
        if (m_flags & STATIC) {
            result += "static ";
        } else if (m_flags & VIRTUAL) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if (m_flags & CONST)
        {
            result += " const";
        }
        result += " {\n";
        for (const auto & b: m_body) {
            result += b -> compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    };

    std::string m_name =" ";
    std::string m_returnType = " ";
    Flags m_flags;
    std::vector <  Unit * > m_body;};


#endif // METHODUNIT_H
