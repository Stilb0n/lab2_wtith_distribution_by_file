#include<iostream>
#include <memory>
#include <vector>
#include"unit.h"



 void Unit::add(const std::shared_ptr < Unit > & , Flags) {
        throw std::runtime_error("Not supported");
    }

    std::string Unit::generateShift(unsigned int level) const {
        static
            const auto DEFAULT_SHIFT = " ";
        std::string result;
        for (unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }


class PrintOperatorUnit: public Unit {
public: explicit PrintOperatorUnit(const std::string & text): m_text(text) {}
    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
private: std::string m_text;
};


