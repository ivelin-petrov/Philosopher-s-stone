#include "elements.h"

Element* ElementFactory::make_element(const std::string& type)
{
    Element* newElement = nullptr;
    if(type == "Earth"){
        newElement = new Earth;
    }
    else if(type == "Fire"){
        newElement = new Fire; 
    }
    else if(type == "Water"){
        newElement = new Water;
    }
    else if(type == "Air"){
        newElement = new Air;
    }
    else if(type == "Metal"){
        newElement = new Metal;
    }
    else if(type == "Gold"){
        newElement = new Gold;
    }
    else if(type == "Stone"){
        newElement = new Stone;
    }
    else if(type == "Energy"){
        newElement = new Energy;
    }
    else if(type == "Spirit"){
        newElement = new Spirit;
    }

    return newElement;
}

bool Element::already_written_reaction(const std::string& element, const std::vector<std::string>& reactions)
{
    bool found = false;
    for(size_t i = 0; i < reactions.size(); ++i)
    {
        if(element == reactions[i])
        {
            found = true;
            break;
        }
    }

    return found;
}

void Element::add_unrepeatable_elements(const std::vector<std::string>& reading_from, std::vector<std::string>& add_in)
{
    if(add_in.size() == 0)
    {
        for(size_t i = 0; i < reading_from.size(); ++i)
        {
            add_in.push_back(reading_from[i]);
        }

    }else{
        for(size_t i = 0; i < reading_from.size(); ++i)
        {
            if(already_written_reaction(reading_from[i], add_in) == 0)
            {
                add_in.push_back(reading_from[i]);
            }
        }
    }
}

bool Element::element1_can_react_with_element2(const Element& element1, const Element& element2)
{
    std::vector<std::string> reacts = element1.get_reactions();
    std::vector<std::string> comps = element2.get_components();

    int counter = 0;

    for(size_t i = 0; i < comps.size(); ++i)
    {
        for(size_t j = 0; j < reacts.size(); ++j)
        {
            if(comps[i] == reacts[j])
            {
                ++counter;
            }
        }
    }

    return (counter == comps.size());
}



// =====> EARTH <=====

Earth::Earth(){
    type = "Earth";
    components = {"Earth"};
    reactions = {"Fire", "Water", "Air"};
}

Earth::Earth(const Earth& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Earth& Earth::operator = (const Earth& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Earth::identity() { return new Earth(); }

std::string Earth::id() const { return type; }

std::vector<Element*> Earth::element_division()
{
    std::vector<Element*> result = {new Earth(), new Earth()};

    return result;
}

std::vector<std::string> Earth::get_components() const { return components; }

std::vector<std::string> Earth::get_reactions() const { return reactions; }

// =====> FIRE <=====

Fire::Fire(){
    type = "Fire";
    components = {"Fire"};
    reactions = {"Earth", "Fire", "Water"};
}

Fire::Fire(const Fire& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Fire& Fire::operator = (const Fire& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Fire::identity() { return new Fire(); }

std::string Fire::id() const { return type; }

std::vector<Element*> Fire::element_division()
{
    std::vector<Element*> result = {new Fire(), new Fire()};

    return result;
}

std::vector<std::string> Fire::get_components() const { return components; }

std::vector<std::string> Fire::get_reactions() const { return reactions; }

// =====> WATER <=====

Water::Water(){
    type = "Water";
    components = {"Water"};
    reactions = {"Fire", "Air"};
}

Water::Water(const Water& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Water& Water::operator = (const Water& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Water::identity() { return new Water(); }

std::string Water::id() const { return type; }

std::vector<Element*> Water::element_division()
{
    std::vector<Element*> result = {new Water(), new Water()};

    return result;
}

std::vector<std::string> Water::get_components() const { return components; }

std::vector<std::string> Water::get_reactions() const { return reactions; }

// =====> AIR <=====

Air::Air(){
    type = "Air";
    components = {"Air"};
    reactions = {"Earth", "Fire", "Water", "Air"};
}

Air::Air(const Air& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Air& Air::operator = (const Air& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Air::identity() { return new Air(); }

std::string Air::id() const { return type; }

std::vector<Element*> Air::element_division()
{
    std::vector<Element*> result = {new Air(), new Air()};

    return result;
}

std::vector<std::string> Air::get_components() const { return components; }

std::vector<std::string> Air::get_reactions() const { return reactions; }

// =====> METAL <=====

Metal::Metal(){
    type = "Metal";           
    components = {"Earth", "Fire"};

    Earth earth;
    Fire fire;
    add_unrepeatable_elements(earth.get_reactions(), reactions);
    add_unrepeatable_elements(fire.get_reactions(), reactions);
}                             // read from     // add in

Metal::Metal(const Metal& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Metal& Metal::operator = (const Metal& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Metal::identity() { return new Metal(); }

std::string Metal::id() const { return type; }

std::vector<Element*> Metal::element_division()
{
    std::vector<Element*> result = {new Earth(), new Fire()};

    return result;
}

std::vector<std::string> Metal::get_components() const { return components; }

std::vector<std::string> Metal::get_reactions() const { return reactions; }

// =====> GOLD <=====

Gold::Gold(){
    type = "Gold";      
    components = Metal::get_components();

    Metal metal;
    add_unrepeatable_elements(metal.get_reactions(), reactions);
}                             // read from      // add in

Gold::Gold(const Gold& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Gold& Gold::operator = (const Gold& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Gold::identity() { return new Gold(); }

std::string Gold::id() const { return type; }

std::vector<Element*> Gold::element_division()
{
    std::vector<Element*> result = {new Metal(), new Metal()};

    return result;
}

std::vector<std::string> Gold::get_components() const { return components; }

std::vector<std::string> Gold::get_reactions() const { return reactions; }

// =====> STONE <=====

Stone::Stone(){
    type = "Stone";          
    components = {"Fire", "Water"};

    Fire fire;
    Water water;
    add_unrepeatable_elements(fire.get_reactions(), reactions);
    add_unrepeatable_elements(water.get_reactions(), reactions);
}                             // read from     // add in

Stone::Stone(const Stone& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Stone& Stone::operator = (const Stone& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Stone::identity() { return new Stone(); }

std::string Stone::id() const { return type; }

std::vector<Element*> Stone::element_division()
{
    std::vector<Element*> result = {new Fire(), new Water()};

    return result;
}

std::vector<std::string> Stone::get_components() const { return components; }

std::vector<std::string> Stone::get_reactions() const { return reactions; }

// =====> ENERGY <=====

Energy::Energy(){
    type = "Energy";       
    components = {"Water", "Air"};

    Water water;
    Air air;
    add_unrepeatable_elements(water.get_reactions(), reactions);
    add_unrepeatable_elements(air.get_reactions(), reactions);
}                             // read from     // add in

Energy::Energy(const Energy& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Energy& Energy::operator = (const Energy& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Energy::identity() { return new Energy(); }

std::string Energy::id() const { return type; }

std::vector<Element*> Energy::element_division()
{
    std::vector<Element*> result = {new Water(), new Air()};

    return result;
}

std::vector<std::string> Energy::get_components() const { return components; }

std::vector<std::string> Energy::get_reactions() const { return reactions; }

// =====> SPIRIT <=====


Spirit::Spirit(){
    type = "Spirit";       
    components = {"Air"};

    Air air;
    add_unrepeatable_elements(air.get_reactions(), reactions);
}                             // read from    // add in

Spirit::Spirit(const Spirit& other){
    type = other.type;
    components = other.components;
    reactions = other.reactions;
}

Spirit& Spirit::operator = (const Spirit& other){
    if(this != &other){
        type = other.type;
        components = other.components;
        reactions = other.reactions;
    }
    return *this;
}

Element* Spirit::identity() { return new Spirit(); }

std::string Spirit::id() const { return type; }

std::vector<Element*> Spirit::element_division()
{
    std::vector<Element*> result = {new Air(), new Air()};

    return result;
}
std::vector<std::string> Spirit::get_components() const { return components; }

std::vector<std::string> Spirit::get_reactions() const { return reactions; }
