#include "equation.h"

Equation::Equation(const std::vector<std::string> _elements) : elements(_elements) {}

Equation::Equation(const Equation& other) : elements(other.elements) {}

Equation& Equation::operator = (const Equation& other)
{
    if(this != &other)
    {
        elements = other.elements;
    }
    return *this;
}

Equation::~Equation() {}

std::vector<std::string> Equation::get_elements() const { return elements; }

void Equation::add_equation_element(const std::string& element)
{
    elements.push_back(element);
}