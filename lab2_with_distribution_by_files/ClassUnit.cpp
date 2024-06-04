#ifndef СlassUnit_CPP
#define СlassUnit_CPP
#include "unit.h"
#include<vector>
#include "ClassUnit.h"


CsharpClassUnit::CsharpClassUnit(const std::string & name): m_name(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}


void CsharpClassUnit::add(const std::shared_ptr< Unit >& unit, Flags flags ){
int AccessModifier = IClassUnit::INTERNAL;// по умолчанию internal
    if (flags == IClassUnit::PRIVATE) {
        AccessModifier = IClassUnit::PRIVATE;
    }
    else if (flags == IClassUnit::PROTECTED) {
        AccessModifier = IClassUnit::PROTECTED;
    }
    else if (flags == IClassUnit::PUBLIC) {
        AccessModifier = IClassUnit::PUBLIC;
    }
    else if (flags == IClassUnit::PROTECTED_INTERNAL) {
        AccessModifier = IClassUnit::PROTECTED_INTERNAL;
    }
    else if (flags == IClassUnit::PRIVATE_PROTECTED) {
        AccessModifier = IClassUnit::PRIVATE_PROTECTED;
    }
m_fields[AccessModifier].push_back(unit);
}
std::string CsharpClassUnit::compile(unsigned int level) const{
std::string result = generateShift(level) + "class " + m_name + " {\n";

for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
    if (m_fields[i].empty()) {
        continue;// Пропускаем вывод модификатора доступа, если не было добавлено.
            // ни одной члена-данных/члена-функции с соотвествующим модификатором доступа.
    }

    for (const auto & f: m_fields[i]) {
        result += ACCESS_MODIFIERS[i];
        result += f -> compile(level + 1); // добавляем в result текст член-функции/член-данные c соответствуюзщим отступом
    }
    result += "\n";
}
result += generateShift(level) + "};\n";
return result;
}

CClassUnit::CClassUnit(const std::string & name): m_name(name)
    {
      m_fields.resize(ACCESS_MODIFIERS.size());
    }

void CClassUnit::add(const std::shared_ptr< Unit >& unit, Flags flags ) {
  int AccessModifier = PRIVATE;
  if (flags < ACCESS_MODIFIERS.size()) {
    AccessModifier = flags;
  }
  if (flags >= 3 )
 AccessModifier = PRIVATE;
  m_fields[AccessModifier].push_back(unit);
  /*
        * В условии и последующей строчке с push_back реализовано добавление член-данных и член-функций под определеннным модификатором.
        * Если отказаться от них, то перед каждым член-данным и член-функцией будет писаться модификатор доступа. Это как миниммум не похоже
        * на нормальный код и как максимум вредит читаемости кода.
        */
}
std::string CClassUnit::compile(unsigned int level) const {
  std::string result = generateShift(level) + "class " + m_name + " {\n";

  for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
    if (m_fields[i].empty()) {
        continue;
    }
    result += ACCESS_MODIFIERS[i] + ":\n";
    for (const auto & f: m_fields[i]) {
        result += f -> compile(level + 1);
    }
    result += "\n";
  }
  result += generateShift(level) + "};\n";
  return result;
}
JavaClassUnit::JavaClassUnit(const std::string & name): m_name(name) {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
 void JavaClassUnit::add ( const std::shared_ptr< Unit >& unit, Flags flags ){
        int AccessModifier = PRIVATE; // по умолчанию private
        if (flags < ACCESS_MODIFIERS.size()) {
    AccessModifier = flags;
        }
        if (flags >= 3 )
    AccessModifier = PRIVATE;
        m_fields[AccessModifier].push_back(unit);
}
 std::string  JavaClassUnit::compile(unsigned int level)  const {
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

#endif
