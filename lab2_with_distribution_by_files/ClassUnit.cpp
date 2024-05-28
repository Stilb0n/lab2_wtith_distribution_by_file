#ifndef СlassUnit_CPP
#define СlassUnit_CPP
#include "unit.h"
#include<vector>
#include "ClassUnit.h"

const std::vector< std::string > JavaClassUnit::ACCESS_MODIFIERS = { "public",
                                                                  "protected", "private"};


const std::vector < std::string > ClassUnit::ACCESS_MODIFIERS = {
    "public",
    "protected",
    "private"
};

const std::vector< std::string > CClassUnit::ACCESS_MODIFIERSC = { "public",
                                                                "protected", "private"};

const std::vector< std::string > CsharpClassUnit::ACCESS_MODIFIERS_NEW = { "public",
                                                                        "protected", "private","private protected","internal","protected internal"};


ClassUnit::ClassUnit(const std::string & name): m_name(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}
void ClassUnit::add(const std::shared_ptr < Unit > & unit, Flags flags){

    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}
 std::string ClassUnit::compile(unsigned int level) const{
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



CsharpClassUnit::CsharpClassUnit(const std::string & name): m_name(name) {
    m_fields.resize(ACCESS_MODIFIERS_NEW.size());
}

CsharpClassUnit::~CsharpClassUnit() {
    for (  auto & elem : m_fields)
{
    for (  auto & elem2 : elem )
    {
        delete (elem2);
    }
}
}
void CsharpClassUnit::add(Unit *  method, Flags flags){
int AccessModifier = PRIVATE;
if (flags < ACCESS_MODIFIERS_NEW.size()) {
    AccessModifier = flags;
}
m_fields[AccessModifier].push_back(method);
}
std::string CsharpClassUnit::compile(unsigned int level) const{
std::string result = generateShift(level) + "class " + m_name + " {\n";

for (size_t i = 0; i < ACCESS_MODIFIERS_NEW.size(); ++i) {
    if (m_fields[i].empty()) {
        continue;
    }

    for (const auto & f: m_fields[i]) {
        result += ACCESS_MODIFIERS_NEW[i];
        result += f -> compile(level + 1);
    }
    result += "\n";
}
result += generateShift(level) + "};\n";
return result;
}

CClassUnit::CClassUnit(const std::string & name): m_name(name)
    {
      m_fields.resize(ACCESS_MODIFIERSC.size());
    }
    CClassUnit::~CClassUnit()
{      for (  auto & elem : m_fields)
  {
    for (  auto & elem2 : elem )
    {
        delete (elem2);
    }
  }
}

void CClassUnit::add(Unit* method, Flags flags) {
  int AccessModifier = PRIVATE;
  if (flags < ACCESS_MODIFIERSC.size()) {
    AccessModifier = flags;
  }
  if (flags >= 3 )
  {throw "wrong modifier";}
  m_fields[AccessModifier].push_back(method);
}
std::string CClassUnit::compile(unsigned int level) const {
  std::string result = generateShift(level) + "class " + m_name + " {\n";

  for (size_t i = 0; i < ACCESS_MODIFIERSC.size(); ++i) {
    if (m_fields[i].empty()) {
        continue;
    }
    result += ACCESS_MODIFIERSC[i] + ":\n";
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
JavaClassUnit::~JavaClassUnit(){
        for (  auto & elem : m_fields)
        {
    for (  auto & elem2 : elem )
    {
        delete (elem2);
    }
        }
}
 void JavaClassUnit::add ( Unit *  method, Flags flags){
        int AccessModifier = PRIVATE;
        if (flags < ACCESS_MODIFIERS.size()) {
    AccessModifier = flags;
        }
        if (flags >= 3 )
        {throw "wrong modifier";}
        m_fields[AccessModifier].push_back(method);
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
