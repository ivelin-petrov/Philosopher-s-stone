#include "formula.h"

Formula::Formula(const Equation equation_elements, const std::string _element)
    : Equation(equation_elements), end_element(_element) {}

Formula::Formula(const Formula& other) : Equation(other), end_element(other.end_element) {}

Formula& Formula::operator = (const Formula& other)
{
    if(this != &other)
    {
        Equation::operator=(other);
        end_element = other.end_element;
    }
    return *this;
}

Formula::~Formula() {}

std::string Formula::get_end_element() const { return end_element; }

void Formula::set_element(const std::string& _element) { end_element = _element; }

bool Formula::correct_formula()
{
    int counter = 0;
    size_t size = elements.size();

    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < size; ++j)
        {
            if(i != j){

                if(Element::element1_can_react_with_element2(*ElementFactory::make_element(elements[i]), 
                                                             *ElementFactory::make_element(elements[j])) == 1)
                {
                    ++counter;
                }
            }
        }
    }

    return (counter == (size * (size - 1)));
}

// Example: Stone + Metal + Gold = PS
// Example: /Fire
Formula Formula::from_string_to_Formula(const std::string string)
{
    Formula formula;

    if(string[0] == '/')
    {
        formula.add_equation_element(string);

        return formula;
    }

    int i = 0;
    int saver = 0;
    while(string[i] != '=')
    {
        if(string[i] == ' ')
        {
            std::string substring = string.substr(saver, i - saver);
            formula.add_equation_element(substring);
        }
        else if(string[i] == '+')
        {
            saver = i + 2;
            ++i;
        }
        ++i;
    }
    std::string end_string = string.substr(i + 2);
    formula.set_element(end_string);

    return formula;
}

void Formula::print_formula()
{
    for(size_t i = 0; i < elements.size() - 1; ++i)
    {
        std::cout << elements[i] << " + ";
    }
    std::cout << elements[elements.size() - 1] << " ";
    std::cout << "= " << end_element << std::endl;

}

bool Formula::operator == (const Formula& other)
{
    return ((this->end_element == other.end_element) && (this->elements == other.elements) );  
}