#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "unit.h"
class PrintOperatorUnit: public Unit
{
public:
    explicit PrintOperatorUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const;
private: std::string m_text;
};

class IPrintOperatorUnit : public Unit {
    //public: virtual   std::string createPrint( )=0;
public: virtual   std::string compile(unsigned int level = 0) const=0;
};

class CsharpPrintOperatorUnit : public IPrintOperatorUnit {
public:

    explicit CsharpPrintOperatorUnit(const std::string &text);
    //   void add(Unit * dd , Flags)override {std::cout<<"YaEstGroot";}
    std::string compile(unsigned int level = 0) const override;
    // std::string generateShift(unsigned int level) const override {    return "Compiled code: " + m_text;}


private:
    std::string m_text;
};

class CPrintOperatorUnit : public IPrintOperatorUnit {
public:

    explicit CPrintOperatorUnit(const std::string &text);
    //   void add(Unit * dd , Flags)override {std::cout<<"YaEstGroot";}
    std::string compile(unsigned int level = 0) const override;
    // std::string generateShift(unsigned int level) const override {    return "Compiled code: " + m_text;}


private:
    std::string m_text;
};




#endif // PRINTOPERATORUNIT_H
