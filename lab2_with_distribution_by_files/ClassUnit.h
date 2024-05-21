#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include<vector>
#include"unit.h"
#include <memory>

class IClassUnit : public Unit { public: virtual void add(Unit* unit, Flags flags) = 0; };

class ClassUnit: public Unit
{
public:
    ClassUnit();
    explicit ClassUnit(const std::string & name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags);
    std::string compile(unsigned int level = 0);

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};


class CsharpClassUnit: public IClassUnit {
public: enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        INTERNAL,
        PROTECTED_INTERNAL
    };
    static const std::vector < std::string > ACCESS_MODIFIERS;
public: explicit CsharpClassUnit(const std::string & name): m_name(name) {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    ~CsharpClassUnit () {
        for (  auto & elem : m_fields)
        {
            for (  auto & elem2 : elem )
            {
                delete (elem2);
            }
        }
    }
    void add ( Unit *  method, Flags flags) override{
        int AccessModifier = PRIVATE;
        if (flags < ACCESS_MODIFIERS.size()) {
            AccessModifier = flags;
        }
        m_fields[AccessModifier].push_back(method);
    }
    std::string  compile(unsigned int level = 0)  const override{
        std::string result = generateShift(level) + "class " + m_name + " {\n";

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            if (m_fields[i].empty()) {
                continue;
            }

            for (const auto & f: m_fields[i]) {
                result += ACCESS_MODIFIERS[i];
                result += f -> compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
private: std::string m_name;
    using Fields = std::vector < Unit * > ;
    std::vector < Fields > m_fields;
};
const std::vector< std::string > CsharpClassUnit::ACCESS_MODIFIERS = { "public",
                                                                    "protected", "private","private protected","internal","protected internal"};



#endif // CLASSUNIT_H
