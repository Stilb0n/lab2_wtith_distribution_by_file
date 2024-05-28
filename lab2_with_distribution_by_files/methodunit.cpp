#ifndef MethodUnit_CPP
#define MethodUnit_CPP
#include<iostream>
#include<vector>
#include <memory>
#include"methodunit.h"
MethodUnit::MethodUnit(const std::string & name,
                       const std::string & returnType, Flags
                           flags): m_name(name),
    m_returnType(returnType),
    m_flags(flags) {}
std::string MethodUnit::compile(unsigned int level)const {
    std::string result = generateShift(level);
    if (m_flags & STATIC) {
        result += "static ";
    } else if (m_flags & VIRTUAL) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if (m_flags & CONST) {
        result += " const";
    }
    result += " {\n";
    for (const auto & b: m_body) {
        result += b -> compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}

CsharpMethodUnit::CsharpMethodUnit(std::string  name,
                                   std::string returnType, Flags
                                       flags): m_name(name),
    m_returnType(returnType),
    m_flags(flags) {}
CsharpMethodUnit::~CsharpMethodUnit(){

    for (  auto & elem : m_body)
    {
        delete (elem);
        ++elem;
    }
};

void CsharpMethodUnit::add(Unit * dd , Flags) {
    m_body.push_back(dd);
};
std::string CsharpMethodUnit::compile(unsigned int level) const {        std::string result = generateShift(level);
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
    return result;}

CMethodUnit::CMethodUnit(std::string  name,
                         std::string returnType, Flags
                             flags) : m_name(name),
    m_returnType(returnType),
    m_flags(flags) {}
CMethodUnit::~CMethodUnit(){
    for (  auto & elem : m_body)
    {
        delete (elem);
        ++elem;
    }
}
void CMethodUnit::add(Unit * dd , Flags){
    m_body.push_back(dd);
}
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
JavaMethodUnit::~JavaMethodUnit(){

    for (  auto & elem : m_body)
    {
        delete (elem);
        ++elem;
    }
}
void JavaMethodUnit::add(Unit * dd , Flags){
    m_body.push_back(dd);
}
std::string JavaMethodUnit::compile(unsigned int level) const{
    std::string result = generateShift(level);
    if (m_flags & STATIC) {
        result += "static ";
    } else if (m_flags & FINAL) {
        result += "final ";
    }
    if (m_flags & ABSTRACT)
    {
        result += "abstract ";
    }
    if (m_flags & (VIRTUAL|CONST))
    {throw "wrong modifier";}
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
