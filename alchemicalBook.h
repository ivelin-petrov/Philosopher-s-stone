#ifndef ALCHEMICAL_BOOK_H_
#define ALCHEMICAL_BOOK_H_

#include "formula.h"

class AlchemicalBook
{
  private:
    std::vector<Formula> formulas;
  public:
    AlchemicalBook(const std::vector<Formula> _formulas = {});
    AlchemicalBook(const AlchemicalBook& other);
    AlchemicalBook& operator = (const AlchemicalBook& other);
    ~AlchemicalBook() {}

    std::vector<Formula> get_formulas() const;

    void add_formula(Formula& formula);
    bool has_formula(const std::string& str_formula);

    Formula how_to_create_element(const std::string& element);
};

#endif // ALCHEMICAL_BOOK_H_