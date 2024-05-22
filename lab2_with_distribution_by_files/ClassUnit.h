#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include<vector>
#include"unit.h"
#include <memory>

class ClassUnit: public Unit {
public: enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static
        const std::vector < std::string > ACCESS_MODIFIERS;
public: explicit ClassUnit(const std::string & name);
    void add(const std::shared_ptr < Unit > & unit, Flags flags);
    std::string compile(unsigned int level = 0) const;
private: std::string m_name;
    using Fields = std::vector < std::shared_ptr < Unit > > ;
    std::vector < Fields > m_fields;
};


class IClassUnit : public Unit { public: virtual void add(Unit* unit, Flags flags) = 0; };



class CsharpClassUnit: public IClassUnit {
public: enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        INTERNAL,
        PROTECTED_INTERNAL
    };
    static const std::vector < std::string > ACCESS_MODIFIERS_NEW;
public: explicit CsharpClassUnit(const std::string & name);
    ~CsharpClassUnit () ;
    void add ( Unit *  method, Flags flags) override;
    std::string  compile(unsigned int level = 0)  const override;
private: std::string m_name;
    using Fields = std::vector < Unit * > ;
    std::vector < Fields > m_fields;
};


#endif // CLASSUNIT_H
