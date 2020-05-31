#ifndef FORMULA_H_
#define FORMULA_H_

#include "equation.h"

class Formula : public Equation 
{                   // Equation equation = std::vector<std::string> elements;
  private:
    std::string end_element;

  public:
    Formula(const Equation equation_elements = {}, const std::string _element = "unknown");
    Formula(const Formula& other);
    Formula& operator = (const Formula& other);
    ~Formula();
    
    void print_formula();
    std::string get_end_element() const;
    void set_element(const std::string& _element);

    bool operator == (const Formula& other);
    bool correct_formula();

    static Formula from_string_to_Formula(const std::string string);

};

#endif // FORMULA_H_