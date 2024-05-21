#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include<vector>
#include"unit.h"
#include <memory>
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

#endif // CLASSUNIT_H
