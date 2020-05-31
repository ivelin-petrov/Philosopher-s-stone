#ifndef ALCHEMIST_H_
#define ALCHEMIST_H_

#include "alchemicalBook.h"

class numbers_of_baseElements
{
  private:
    std::string earth = "Earth";
    int earth_counter;
    std::string fire = "Fire";
    int fire_counter;
    std::string water = "Water";
    int water_counter;
    std::string air = "Air";
    int air_counter;

  public:
    numbers_of_baseElements(int e_counter = 0, int f_counter = 0, int w_counter = 0, int a_counter = 0);

    numbers_of_baseElements(const numbers_of_baseElements& other);
    
    numbers_of_baseElements& operator = (const numbers_of_baseElements& other);

    ~numbers_of_baseElements() {}

    int get_earth_counter() { return earth_counter; }
    int get_fire_counter() { return fire_counter; }
    int get_water_counter() { return water_counter; }
    int get_air_counter() { return air_counter; }

    void add_earth(int n) { earth_counter += n; }
    void add_fire(int n) { fire_counter += n; }
    void add_water(int n) { water_counter += n; }
    void add_air(int n) { air_counter += n; }

    bool all_base_elements_are_enough(const numbers_of_baseElements& other);

    void print_info();
};

class Alchemist
{ 
  private:
    AlchemicalBook book;
    numbers_of_baseElements starting_elements;
  public:
    Alchemist(const AlchemicalBook _book = {}, const numbers_of_baseElements _elements = {});
    Alchemist(const Alchemist& other);
    Alchemist& operator = (const Alchemist& other);
    ~Alchemist() {}

    AlchemicalBook& get_book();
    numbers_of_baseElements get_starting_elements() const;

    void add_starting_elements(int number, const std::string& element);

    void disassemble_element(const std::string& element, numbers_of_baseElements& _base);
    bool can_make_PS();
};

#endif // ALCHEMIST_H_