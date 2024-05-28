#ifndef METHODUNIT_H
#define METHODUNIT_H
#include"unit.h"
#include<vector>
class MethodUnit: public Unit {
public: enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public: MethodUnit(const std::string & name,
               const std::string & returnType, Flags
                   flags);
    void add(const std::shared_ptr < Unit > & unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0)const;
private: std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector < std::shared_ptr < Unit > > m_body;
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
                         flags);

    ~CsharpMethodUnit();
    void add( Unit * dd , Flags)override;
    std::string compile(unsigned int level = 0) const override;

    std::string m_name =" ";
    std::string m_returnType = " ";
    Flags m_flags;
    std::vector <  Unit * > m_body;};

class CMethodUnit : public IMethodUnit {

public: CMethodUnit( std::string  name,
                std::string returnType, Flags
                    flags);

    ~CMethodUnit();
    void add( Unit * dd , Flags)override;
    std::string compile(unsigned int level = 0) const override;

    std::string m_name =" ";
    std::string m_returnType = " ";
    Flags m_flags;
    std::vector <  Unit * > m_body;};

class JavaMethodUnit : public IMethodUnit {

public: JavaMethodUnit( std::string  name,
                   std::string returnType, Flags
                       flags);
    ~JavaMethodUnit();
    void add( Unit * dd , Flags)override;
    std::string compile(unsigned int level = 0) const override;

    std::string m_name =" ";
    std::string m_returnType = " ";
    Flags m_flags;
    std::vector <  Unit * > m_body;};

#endif // METHODUNIT_H
