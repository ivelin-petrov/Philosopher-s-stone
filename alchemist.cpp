#include "alchemist.h"

numbers_of_baseElements::numbers_of_baseElements(int e_counter, int f_counter, int w_counter, int a_counter)
      : earth_counter(e_counter), fire_counter(f_counter), water_counter(w_counter), air_counter(a_counter) {}

numbers_of_baseElements::numbers_of_baseElements(const numbers_of_baseElements& other)
      : earth_counter(other.earth_counter), fire_counter(other.fire_counter), 
        water_counter(other.water_counter), air_counter(other.air_counter) {}

numbers_of_baseElements& numbers_of_baseElements::operator = (const numbers_of_baseElements& other)
{
    if(this != &other)
    {
    earth_counter = other.earth_counter;
    fire_counter = other.fire_counter; 
    water_counter = other.water_counter;
    air_counter = other.air_counter;
    }
    return *this;
}

bool numbers_of_baseElements::all_base_elements_are_enough(const numbers_of_baseElements& other)
{
    return (this->earth <= other.earth && this->fire <= other.fire &&
            this->water <= other.water && this->air <= other.air);
}

void numbers_of_baseElements::print_info()
{
    std::cout << "Earth: " << earth_counter << std::endl;
    std::cout << "Fire:" << fire_counter << std::endl;
    std::cout << "Water:" << water_counter << std::endl;
    std::cout << "Air:" << air_counter << std::endl;
}

Alchemist::Alchemist(const AlchemicalBook _book, const numbers_of_baseElements _elements)
                : book(_book), starting_elements(_elements) {}

Alchemist::Alchemist(const Alchemist& other) : book(other.book), starting_elements(other.starting_elements) {}

Alchemist& Alchemist::operator = (const Alchemist& other)
{
    if(this != &other)
    {
        book = other.book;
        starting_elements = other.starting_elements;
    }
    return *this;
}

AlchemicalBook& Alchemist::get_book() { return book; }

numbers_of_baseElements Alchemist::get_starting_elements() const { return starting_elements; }

void Alchemist::add_starting_elements(int number, const std::string& element)
{
    if(element == "Earth"){
        starting_elements.add_earth(number);
    }else if(element == "Fire"){
        starting_elements.add_fire(number);
    }else if(element == "Water"){
        starting_elements.add_water(number);
    }else if(element == "Air"){
        starting_elements.add_air(number);
    }
}

void Alchemist::disassemble_element(const std::string& element, numbers_of_baseElements& _base)
{
    if(element == "Earth"){
        _base.add_earth(1);
        return;
    }else if(element == "Fire"){
        _base.add_fire(1);
        return;
    }else if(element == "Water"){
        _base.add_water(1);
        return;
    }else if(element == "Air"){
        _base.add_air(1);
        return;
    }

    if(element != "Earth" && element != "Fire" && element != "Water" && element != "Air")
    {
        Formula result = book.how_to_create_element(element);
        std::cout << "You used this formula trying to create the Philosopher's Stone." << std::endl;
        result.print_formula();
        std::vector<std::string> core_elements = result.get_elements();

        for(size_t i = 0; i < core_elements.size(); ++i)
        {
            disassemble_element(core_elements[i], _base);
        }
    }else if(element == "Earth"){
        _base.add_earth(1);
    }else if(element == "Fire"){
        _base.add_fire(1);
    }else if(element == "Water"){
        _base.add_water(1);
    }else if(element == "Air"){
        _base.add_air(1);
    }
}

bool Alchemist::can_make_PS()
{
    bool result = true;
    Formula formula;

    int helper = 0;
    try
    {
        formula = book.how_to_create_element("Philosopher's Stone");
        helper = 1; // example
    }
    catch(std::string s)
    {
        std::cout << "Error: " << s << std::endl;
    }

    if(helper != 1)
    {
        return false;
    }

    std::vector<std::string> needed_elements = formula.get_elements();
    numbers_of_baseElements needed(0, 0, 0, 0);

    try
    {
        for(size_t i = 0; i < needed_elements.size(); ++i)
        {
            if(needed_elements[i] != "Earth" && needed_elements[i] != "Fire" && 
               needed_elements[i] != "Water" && needed_elements[i] != "Air")
            {
                formula = book.how_to_create_element(needed_elements[i]);
                disassemble_element(needed_elements[i], needed);
            }else if(needed_elements[i] == "Earth"){
                needed.add_earth(1);
            }else if(needed_elements[i] == "Fire"){
                needed.add_fire(1);
            }else if(needed_elements[i] == "Water"){
                needed.add_water(1);
            }else if(needed_elements[i] == "Air"){
                needed.add_air(1);
            }
        }
    }
    catch(std::string s)
    {
        std::cout << "Error: " << s << std::endl;
        return false;
    }

    // needed.print_info();


    if(needed.all_base_elements_are_enough(starting_elements) == 0)
    {
        return true; // all needed base elements were found
    }


    bool need_earth = false;
    bool need_fire = false;
    bool need_water = false;
    bool need_air = false;

    if(needed.get_earth_counter() > starting_elements.get_earth_counter())
    {
        need_earth = true;
        if(starting_elements.get_earth_counter() >= 1 && book.has_formula("/Earth"))
        {
            need_earth = false;
        }
    }
    if(needed.get_fire_counter() > starting_elements.get_fire_counter())
    {
        need_fire = true;
        if(starting_elements.get_fire_counter() >= 1 && book.has_formula("/Fire"))
        {
            need_fire = false;
        }
    }
    if(needed.get_water_counter() > starting_elements.get_water_counter())
    {
        need_water = true;
        if(starting_elements.get_water_counter() >= 1 && book.has_formula("/Water"))
        {
            need_water = false;
        }
    }
    if(needed.get_air_counter() > starting_elements.get_air_counter())
    {
        need_air = true;
        if(starting_elements.get_air_counter() >= 1 && book.has_formula("/Air"))
        {
            need_air = false;
        }
    }

    return (need_earth == false && need_fire == false && need_water == false && need_air == false);
}