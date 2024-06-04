#ifndef METHODUNIT_H
#define METHODUNIT_H
#include"unit.h"
#include<vector>


class IMethodUnit : public Unit {
public: enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };

public:
  void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override {
        m_body.push_back( unit );
    }
    std::string static name;
    std::string vozvr;
    int Num = 0;
   std::vector<std::shared_ptr<Unit>> m_body;
};

class CsharpMethodUnit : public IMethodUnit {

public: CsharpMethodUnit( std::string  name,
                     std::string returnType, Flags
                         flags);

    std::string compile(unsigned int level = 0) const override;

    std::string m_name =" ";
    std::string m_returnType = " ";
    Flags m_flags;
   };

class CMethodUnit : public IMethodUnit {

public: CMethodUnit( std::string  name,
                std::string returnType, Flags
                    flags);

    std::string compile(unsigned int level = 0) const override;

    std::string m_name =" ";
    std::string m_returnType = " ";
    Flags m_flags;

};

class JavaMethodUnit : public IMethodUnit {

public: JavaMethodUnit( std::string  name,
                   std::string returnType, Flags
                       flags);
    std::string compile(unsigned int level = 0) const override;

    std::string m_name =" ";
    std::string m_returnType = " ";
    Flags m_flags;

};

#endif // METHODUNIT_H
