#ifndef EQUATION_H_
#define EQUATION_H_

#include "elements.h"

class Equation
{
  protected:
    std::vector<std::string> elements;
  public:
    Equation(const std::vector<std::string> _elements = {});
    Equation(const Equation& other);
    Equation& operator = (const Equation& other);
    ~Equation();

    std::vector<std::string> get_elements() const;

    void add_equation_element(const std::string& element);
};

#endif // EQUATION_H_