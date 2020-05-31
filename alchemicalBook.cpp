#include "alchemicalBook.h"

AlchemicalBook::AlchemicalBook(const std::vector<Formula> _formulas) : formulas(_formulas) {}

AlchemicalBook::AlchemicalBook(const AlchemicalBook& other) : formulas(other.formulas) {}

AlchemicalBook& AlchemicalBook::operator = (const AlchemicalBook& other)
{
    if(this != &other)
    {
        formulas = other.formulas;
    }
    return *this;
}

std::vector<Formula> AlchemicalBook::get_formulas() const { return formulas; }

void AlchemicalBook::add_formula(Formula& formula)
{
    if(formula.correct_formula() == 1)
    {
        formulas.push_back(formula);
    }else{
        std::cout << "Invalid formula. Not added." << std::endl;
    }
}

Formula AlchemicalBook::how_to_create_element(const std::string& element)
{
    for(size_t i = 0; i < formulas.size(); ++i)
    {
        if(formulas[i].get_end_element() == element)
        {
            return formulas[i];
        }
    }

    throw  "'" + element + "' cannot be created.";
}

bool AlchemicalBook::has_formula(const std::string& str_formula)
{
    bool found = false;

    for(size_t i = 0; i < formulas.size(); ++i)
    {
        if(formulas[i] == Formula::from_string_to_Formula(str_formula))
        {
            return true;
        }
    }

    return false;
}