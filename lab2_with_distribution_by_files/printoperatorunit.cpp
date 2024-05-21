#include "printoperatorunit.h"

std::string PrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}

PrintOperatorUnit::PrintOperatorUnit(const std::string& text) : m_text(text) {}
