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
public: virtual   std::string compile(unsigned int level = 0) const=0;
};

class CsharpPrintOperatorUnit : public IPrintOperatorUnit {
public:

    explicit CsharpPrintOperatorUnit(const std::string &text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

class CPrintOperatorUnit : public IPrintOperatorUnit {
public:

    explicit CPrintOperatorUnit(const std::string &text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

class JavaPrintOperatorUnit : public IPrintOperatorUnit {
public:

    explicit JavaPrintOperatorUnit(const std::string &text);
    std::string compile(unsigned int level = 0) const override;


private:
    std::string m_text;
};




#endif // PRINTOPERATORUNIT_H
