#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pokemon{
protected:
    const int idPokemon;
    static int pokemonNumber;
    int age, iq;
    string name, color;
    float movementSpeed, ap, attackSpeed;
public:
    Pokemon();
    Pokemon(int, int, string, string, float, float, float);
    Pokemon(const Pokemon& pkm);
    ~Pokemon();

    friend istream& operator >>(istream& in, Pokemon& pkm);
    friend ostream& operator <<(ostream& out, const Pokemon& pkm);
    Pokemon& operator =(const Pokemon& pkm);
};

Pokemon::Pokemon():idPokemon(pokemonNumber++){
    this->age = 0;
    this->iq = 0;
    this->attackSpeed = 0;
    this->name = "Necunoscut";
    this->color = "Necunoscut";
    this->movementSpeed = 0;
    this->ap = 0;
}
Pokemon::Pokemon(int age, int iq, string name, string color, float movementSpeed, float ap, float attackSpeed):idPokemon(pokemonNumber++){
    this->age = age;
    this->iq = iq;
    this->name = name;
    this->color = color;
    this->movementSpeed = movementSpeed;
    this->ap = ap;
    this->attackSpeed = attackSpeed;
}
Pokemon::Pokemon(const Pokemon& pkm):idPokemon(pokemonNumber++){
    this->age = pkm.age;
    this->iq = pkm.iq;
    this->name = pkm.name;
    this->color = pkm.color;
    this->movementSpeed = pkm.movementSpeed;
    this->ap = pkm.ap;
    this->attackSpeed = pkm.attackSpeed;
}
Pokemon::~Pokemon(){
    this->age = 0;
    this->iq = 0;
    this->name.clear();
    this->color.clear();
    this->movementSpeed = 0;
    this->ap = 0;
    this-> attackSpeed = 0;
}

istream& operator >>(istream& in, Pokemon& pkm){
    cout<<"================CREATE YOUR OWN POKEMON!==================="<<endl;
    cout<<"Name: "; in>>pkm.name;
    cout<<"Color: "; in>>pkm.color;
    cout<<"Age: "; in>>pkm.age;
    cout<<"Iq: "; in>>pkm.iq;
    cout<<"Movement speed: "; in>>pkm.movementSpeed;
    cout<<"Ability power: "; in>>pkm.ap;
    cout<<"Attack speed: "; in>>pkm.color;
    cout<<"Color: "; in>>pkm.attackSpeed;

    return in;
}
ostream& operator <<(ostream& out, const Pokemon& pkm){
    out<<"Name: "; out<<pkm.name<<endl;
    out<<"Color: "; out<<pkm.color<<endl;
    out<<"Age: "; out<<pkm.age<<endl;
    out<<"Iq: "; out<<pkm.iq<<endl;
    out<<"Movement speed: "; out<<pkm.movementSpeed<<endl;
    out<<"Ability power: "; out<<pkm.ap<<endl;
    out<<"Attack speed: "; out<<pkm.attackSpeed<<endl;

    return out;
}
Pokemon& Pokemon::operator =(const Pokemon& pkm){
    this->age = pkm.age;
    this->iq = pkm.iq;
    this->name = pkm.name;
    this->color = pkm.color;
    this->movementSpeed = pkm.movementSpeed;
    this->ap = pkm.ap;
    this->attackSpeed = pkm.attackSpeed;

    return *this;
}

class Ability{
    string name;
    float damage;
    bool aoe;

public:
    Ability();
    Ability(string name, float damage, bool aoe);
    Ability(const Ability& abl);
    ~Ability();

    Ability& operator =(const Ability& abl);
    friend istream& operator >>(istream& in, Ability& abl);
    friend ostream& operator <<(ostream& out, const Ability& abl);
};

Ability::Ability(){
    this->name = "Unknown";
    this->damage = 0;
    this->aoe = 0;
}
Ability::Ability(string name, float damage, bool aoe){
    this->name = name;
    this->damage = damage;
    this->aoe = aoe;
}
Ability::Ability(const Ability& abl){
    this->name = abl.name;
    this->damage = abl.damage;
    this->aoe = abl.aoe;
}
Ability::~Ability(){
    this->name.clear();
    this->damage = 0;
    this->aoe = 0;
}

Ability& Ability::operator =(const Ability& abl){
    this->name = abl.name;
    this->damage = abl.damage;
    this->aoe = abl.aoe;
}
istream& operator >>(istream& in, Ability& abl){
    cout<<"============CREATE NEW ABILITY!====================="<<endl;
    cout<<"Name: "; in>>abl.name;
    cout<<"Damage: "; in>>abl.damage;
    cout<<"AOE?: "; in>>abl.aoe;

    return in;
}
ostream& operator <<(ostream& out, const Ability& abl){
    out<<"Nume: "<<abl.name<<endl<<"Damage: "<<abl.damage<<endl;
    abl.aoe == false ? cout<<"Ability does 0 aoe damage"<<endl : cout<<"Ability does aoe damage";
    return out;
}

class AquaPokemon:public Pokemon{
protected:
    float pressure, power, maximumVolume;
public:
    AquaPokemon();
    AquaPokemon(float pressure, float power, float maximumVolume);
    AquaPokemon(const AquaPokemon& pkm);
    ~AquaPokemon();
    
    friend istream& operator >>(istream& in, AquaPokemon& pkm);
    friend ostream& operator <<(ostream& out, const AquaPokemon& pkm);
    AquaPokemon& operator =(const AquaPokemon& pkm);
};

AquaPokemon::AquaPokemon(){
    this->pressure = 0;
    this->power = 0;
    this->maximumVolume = 0;
}
AquaPokemon::AquaPokemon(float pressure, float power, float maximumVolume){
    this->pressure = pressure;
    this->power = power;
    this->maximumVolume = maximumVolume;
}
AquaPokemon::AquaPokemon(const AquaPokemon& pkm){
    this->pressure = pkm.pressure;
    this->power = pkm.power;
    this->maximumVolume = pkm.maximumVolume;
}
AquaPokemon::~AquaPokemon(){
    this->pressure = 0;
    this->power = 0;
    this->maximumVolume = 0;
}

istream& operator >>(istream& in, AquaPokemon& pkm){
    cout<<"==============CREATE A NEW AQUA POKEMON!================"<<endl;
    cout<<"Power: "; in>>pkm.power;
    cout<<"Pressure: "; in>>pkm.pressure;
    cout<<"Maximum volume of water: "; in>>pkm.maximumVolume;
    
    return in;
}
ostream& operator <<(ostream& out, const AquaPokemon& pkm){
    out<<"Power: "; out<<pkm.power;
    out<<"Pressure: "; out<<pkm.pressure;
    out<<"Maximum volume of water: "; out<<pkm.maximumVolume;

    return out;
}
AquaPokemon& AquaPokemon::operator =(const AquaPokemon& pkm){
    this->pressure = pkm.pressure;
    this->power = pkm.power;
    this->maximumVolume = pkm.maximumVolume;

    return *this;
}

class FirePokemon:public Pokemon{
protected:
    int maximumTemperature;
    float intensity, oxygenLevel;
    string fuelSource;
public:
    FirePokemon();
    FirePokemon(int maximumTemperature, float intensity, float oxygenLevel, string fuelSource);
    FirePokemon(const FirePokemon& pkm);
    ~FirePokemon();

    friend istream& operator >>(istream& in, FirePokemon& pkm);
    friend ostream& operator <<(ostream& out, const FirePokemon& pkm);
    FirePokemon& operator =(const FirePokemon& pkm);
};
FirePokemon::FirePokemon(){
    this->maximumTemperature = 0;
    this->intensity = 0;
    this->oxygenLevel = 0;
    this->fuelSource = "";
}
FirePokemon::FirePokemon(int maximumTemperature, float intensity, float oxygenLevel, string fuelSource){
    this->maximumTemperature = maximumTemperature;
    this->intensity = intensity;
    this->oxygenLevel = oxygenLevel;
    this->fuelSource = fuelSource;
}
FirePokemon::FirePokemon(const FirePokemon& pkm){
    this->maximumTemperature = pkm.maximumTemperature;
    this->intensity = pkm.intensity;
    this->oxygenLevel = pkm.oxygenLevel;
    this->fuelSource = pkm.fuelSource;
}
FirePokemon::~FirePokemon(){
    this->maximumTemperature = 0;
    this->intensity = 0;
    this->oxygenLevel = 0;
    this->fuelSource.clear();
}

istream& operator >>(istream& in, FirePokemon& pkm){
    cout<<"==============CREATE A NEW AQUA POKEMON!================"<<endl;
    cout<<"Intensity: "; in>>pkm.intensity;
    cout<<"Maximum Temperature: "; in>>pkm.maximumTemperature;
    cout<<"Average oxygen level: "; in>>pkm.oxygenLevel;
    cout<<"Fuel source: "; in>>pkm.fuelSource;

    return in;
}
ostream& operator <<(ostream& out, const FirePokemon& pkm){
    out<<"Intensity: "; out<<pkm.intensity;
    out<<"Maximum Temperature: "; out<<pkm.maximumTemperature;
    out<<"Average oxygen level: "; out<<pkm.oxygenLevel;
    out<<"Fuel source: "; out<<pkm.fuelSource;

    return out;
}
FirePokemon& FirePokemon::operator =(const FirePokemon& pkm){
    this->maximumTemperature = pkm.maximumTemperature;
    this->intensity = pkm.intensity;
    this->oxygenLevel = pkm.oxygenLevel;
    this->fuelSource = pkm.fuelSource;

    return *this;
}


class ElectricityPokemon:public Pokemon{
protected:
    float wattage;
    bool stun;
    int minutesTilRecharge;
public:
    ElectricityPokemon();
    ElectricityPokemon(float wattage, bool stun, int minutesTilRecharge);
    ElectricityPokemon(const ElectricityPokemon& pkm);
    ~ElectricityPokemon();

    friend istream& operator >>(istream& in, ElectricityPokemon& pkm);
    friend ostream& operator <<(ostream& out, const ElectricityPokemon& pkm);
    ElectricityPokemon& operator =(const ElectricityPokemon& pkm);
};
ElectricityPokemon::ElectricityPokemon(){
    this->wattage = 0;
    this->stun = 0;
    this->minutesTilRecharge = 0;
}
ElectricityPokemon::ElectricityPokemon(float wattage, bool stun, int minutesTilRecharge){
    this->wattage = wattage;
    this->stun = stun;
    this->minutesTilRecharge = minutesTilRecharge;
}
ElectricityPokemon::ElectricityPokemon(const ElectricityPokemon& pkm){
    this->wattage = pkm.wattage;
    this->stun = pkm.stun;
    this->minutesTilRecharge = pkm.minutesTilRecharge;
}
ElectricityPokemon::~ElectricityPokemon(){
    this->wattage = 0;
    this->stun = 0;
    this->minutesTilRecharge = 0;
}

istream& operator >>(istream& in, ElectricityPokemon& pkm){
    cout<<"==============CREATE A NEW AQUA POKEMON!================"<<endl;
    cout<<"Wattage: "; in>>pkm.wattage;
    cout<<"Minutes until recharge is needed: "; in>>pkm.minutesTilRecharge;
    cout<<"Stun: "; in>>pkm.stun;

    return in;
}
ostream& operator <<(ostream& out, const ElectricityPokemon& pkm){
    cout<<"Wattage: "; out<<pkm.wattage;
    cout<<"Minutes until recharge is needed: "; out<<pkm.minutesTilRecharge;
    cout<<"Stun: "; out<<pkm.stun;

    return out;
}
ElectricityPokemon& ElectricityPokemon::operator =(const ElectricityPokemon& pkm){
    this->wattage = pkm.wattage;
    this->stun = pkm.stun;
    this->minutesTilRecharge = pkm.minutesTilRecharge;

    return *this;
}











int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}