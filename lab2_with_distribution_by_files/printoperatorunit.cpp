#include "printoperatorunit.h"

std::string PrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}

PrintOperatorUnit::PrintOperatorUnit(const std::string& text) : m_text(text) {}

CsharpPrintOperatorUnit::CsharpPrintOperatorUnit(const std::string &text) : m_text(text) {}

std::string CsharpPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift( level ) + "Console.WriteLine(\"" + m_text + "\");\n";
}

CPrintOperatorUnit::CPrintOperatorUnit(const std::string &text) : m_text(text) {}
std::string CPrintOperatorUnit::compile(unsigned int level) const  {
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
