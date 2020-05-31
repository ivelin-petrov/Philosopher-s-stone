#ifndef ELEMENTS_H_
#define ELEMENTS_H_

#include <iostream>
#include <vector>
#include <string>

class Element
{
  protected:
    std::string type;
    std::vector<std::string> components;
    std::vector<std::string> reactions;

  public:
    static bool already_written_reaction(const std::string& element, const std::vector<std::string>& reactions);
    static void add_unrepeatable_elements(const std::vector<std::string>& reading_from, std::vector<std::string>& add_in);
    static bool element1_can_react_with_element2(const Element& element1, const Element& element2);

    virtual Element* identity() = 0;
    virtual std::string id() const = 0;
    virtual std::vector<Element*> element_division() = 0;

    virtual std::vector<std::string> get_components() const = 0;
    virtual std::vector<std::string> get_reactions() const = 0;
};

class ElementFactory
{
  public:
    static Element* make_element(const std::string& type);
};

class Earth : virtual public Element
{
  public:
    Earth();
    Earth(const Earth& other);
    Earth& operator = (const Earth& other);
    virtual ~Earth() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};

class Fire : virtual public Element
{
  public:
    Fire();
    Fire(const Fire& other);
    Fire& operator = (const Fire& other);
    virtual ~Fire() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};

class Water : virtual public Element
{
  public:
    Water();
    Water(const Water& other);
    Water& operator = (const Water& other);
    virtual ~Water() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};

class Air : virtual public Element
{
  public:
    Air();
    Air(const Air& other);
    Air& operator = (const Air& other);
    virtual ~Air() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};

class Metal : public Earth, public Fire
{
  public:
    Metal();
    Metal(const Metal& other);
    Metal& operator = (const Metal& other);
    ~Metal() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};

class Gold : public Metal
{
  public:
    Gold();
    Gold(const Gold& other);
    Gold& operator = (const Gold& other);
    ~Gold() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};

class Stone : public Fire, public Water
{
  public:
    Stone();
    Stone(const Stone& other);
    Stone& operator = (const Stone& other);
    ~Stone() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};

class Energy : public Water, public Air
{
  public:
    Energy();
    Energy(const Energy& other);
    Energy& operator = (const Energy& other);
    ~Energy() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};

class Spirit : public Air
{
  public:
    Spirit();
    Spirit(const Spirit& other);
    Spirit& operator = (const Spirit& other);
    ~Spirit() {}

    Element* identity();
    std::string id() const;
    std::vector<Element*> element_division();

    std::vector<std::string> get_components() const;
    std::vector<std::string> get_reactions() const;
};


#endif // ELEMENTS_H_