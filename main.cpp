#include "alchemist.h"

int main()
{
    // g++ main.cpp elements.cpp equation.cpp formula.cpp alchemicalBook.cpp alchemist.cpp -o main.exe

    // Gold gold;
    // Energy energy;
    // std::cout << Element::element1_can_react_with_element2(energy, gold) << std::endl;


    // std::string str1 = "Stone + Metal + Gold = Philosopher's Stone";
    // std::string str2 = "Air + Fire = Philosopher's Stone";
    // std::string str3 = "Earth + Air = Philosopher's Stone";

    // std::cout << Formula::from_string_to_Formula(str1).correct_formula() << std::endl;
    // std::cout << Formula::from_string_to_Formula(str2).correct_formula() << std::endl;
    // std::cout << Formula::from_string_to_Formula(str3).correct_formula() << std::endl;

    /*
     * Formula f = Formula::from_string_to_Formula(str1);
     * AlchemicalBook ab;
     * ab.add_formula(f);
     * std::cout << ab.has_formula(str1) << std::endl;
     * Formula f2;
     * f2 = ab.how_to_create_element("Philosopher's Stone");
     * f2.print_formula();
     */

    Alchemist alchemist;

    int n;
    std::cout << "Enter the quantity of Earth:" << std::endl;
    std::cin >> n;

    alchemist.add_starting_elements(n, "Earth");

    std::cout << "Enter the quantity of Fire:" << std::endl;
    std::cin >> n;

    alchemist.add_starting_elements(n, "Fire");

    std::cout << "Enter the quantity of Water:" << std::endl;
    std::cin >> n;

    alchemist.add_starting_elements(n, "Water");

    std::cout << "Enter the quantity of Air:" << std::endl;
    std::cin >> n;

    alchemist.add_starting_elements(n, "Air");

    std::cout << "Enter the number of formulas:" << std::endl;
    std::cin >> n;

    std::cin.ignore();
    std::string line;
    for(size_t i = 0; i < n; ++i)
    {
        std::getline(std::cin, line);
        Formula formula = Formula::from_string_to_Formula(line);
        
        alchemist.get_book().add_formula(formula);
    }
    
    // alchemist.get_starting_elements().print_info();

    if(alchemist.can_make_PS() == 1){
        std::cout << "YES. The Philosopher's Stone has been created. " << std::endl;
    }else{
        std::cout << "NO. You CANNOT create the Philosopher's Stone." << std::endl;
    }
    


    return 0;
}