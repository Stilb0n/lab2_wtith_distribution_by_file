#ifndef MethodUnit_CPP
#define MethodUnit_CPP
#include<iostream>
#include<vector>
#include <memory>
#include"methodunit.h"


CsharpMethodUnit::CsharpMethodUnit(std::string  name,
                                   std::string returnType, Flags
                                       flags): m_name(name),
    m_returnType(returnType),
    m_flags(flags) {}
std::string CsharpMethodUnit::compile(unsigned int level) const {  std::string result = generateShift(level);
    if (m_flags & STATIC) {
        result += "static ";
    } else if (m_flags & VIRTUAL) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";

    result += " {\n";
    for (const auto & b: m_body) {
        result += b -> compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;}

CMethodUnit::CMethodUnit(std::string  name,
                         std::string returnType, Flags
                             flags) : m_name(name),
    m_returnType(returnType),
    m_flags(flags) {}
std::string CMethodUnit::compile(unsigned int level) const  {
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
}
JavaMethodUnit::JavaMethodUnit( std::string  name,
               std::string returnType, Flags
                   flags): m_name(name),
        m_returnType(returnType),
        m_flags(flags) {}
std::string JavaMethodUnit::compile(unsigned int level) const{
    std::string result = generateShift(level);
    if( m_flags & ABSTRACT ) { // проверка на наличие бита соответствующему наличию модификатора ABSTRACT
        result += "abstract ";
    } else if( m_flags & STATIC ) { // проверка на наличие бита соответствующему наличию модификатора STATIC
        result += "static ";
    } else if( m_flags & FINAL ) { // проверка на наличие бита соответствующему наличию модификатора STATIC
        result += "final ";
    }
    result += m_returnType + " ";
    result += m_name + "()";

    result += " {\n";
    for (const auto & b: m_body) {
        result += b -> compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}





























#endif
