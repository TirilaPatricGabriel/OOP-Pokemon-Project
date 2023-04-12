#include <iostream>
#include <vector>
#include <string>

using namespace std;

class IOInterface{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
};

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

    return *this;
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


class Pokemon:public IOInterface{
protected:
    const int idPokemon;
    static int pokemonNumber;
    int age, iq;
    string name, color;
    float movementSpeed, ap, attackSpeed;
    vector<Ability> abilities;
public:
    virtual float getDamagePerSecond() const = 0;

    Pokemon();
    Pokemon(int, int, string, string, float, float, float, vector<Ability>);
    Pokemon(const Pokemon& pkm);
    ~Pokemon();

    string getName() { return this->name; }

    virtual istream& citire(istream& in);
    virtual ostream& afisare(ostream& out) const;

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
    this->abilities = {};
}
Pokemon::Pokemon(int age, int iq, string name, string color, float movementSpeed, float ap, float attackSpeed, vector<Ability> abilities):idPokemon(pokemonNumber++){
    this->age = age;
    this->iq = iq;
    this->name = name;
    this->color = color;
    this->movementSpeed = movementSpeed;
    this->ap = ap;
    this->attackSpeed = attackSpeed;
    this->abilities = abilities;
}
Pokemon::Pokemon(const Pokemon& pkm):idPokemon(pokemonNumber++){
    this->age = pkm.age;
    this->iq = pkm.iq;
    this->name = pkm.name;
    this->color = pkm.color;
    this->movementSpeed = pkm.movementSpeed;
    this->ap = pkm.ap;
    this->attackSpeed = pkm.attackSpeed;
    this->abilities = pkm.abilities;
}
Pokemon::~Pokemon(){
    this->age = 0;
    this->iq = 0;
    this->name.clear();
    this->color.clear();
    this->movementSpeed = 0;
    this->ap = 0;
    this-> attackSpeed = 0;
    this->abilities.clear();
}

istream& operator >>(istream& in, Pokemon& pkm){
    return pkm.citire(in);
}
ostream& operator <<(ostream& out, const Pokemon& pkm){
    return pkm.afisare(out);
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

istream& Pokemon::citire(istream& in){
    cout<<"================CREATE YOUR OWN POKEMON!==================="<<endl;
    cout<<"Name: "; in>>this->name;
    cout<<"Color: "; in>>this->color;
    cout<<"Age: "; in>>this->age;
    cout<<"Iq: "; in>>this->iq;
    cout<<"Movement speed: "; in>>this->movementSpeed;
    cout<<"Ability power: "; in>>this->ap;
    cout<<"Attack speed: "; in>>this->attackSpeed;
    int n;
    cout<<"Number of abilities: "; in>>n;
    for(int i=0; i<n; i++){
        Ability ab;
        cin>>ab;
        this->abilities.push_back(ab);
    }

    return in;
}
ostream& Pokemon::afisare(ostream& out) const {
    out<<"Name: "; out<<this->name<<endl;
    out<<"Color: "; out<<this->color<<endl;
    out<<"Age: "; out<<this->age<<endl;
    out<<"Iq: "; out<<this->iq<<endl;
    out<<"Movement speed: "; out<<this->movementSpeed<<endl;
    out<<"Ability power: "; out<<this->ap<<endl;
    out<<"Attack speed: "; out<<this->attackSpeed<<endl;
    cout<<"Abilities: "<<endl;
    for(int i=0; i<this->abilities.size(); i++){
        out<<this->abilities[i]<<endl;
    }

    return out;  
}

class AquaPokemon:virtual public Pokemon{
protected:
    float pressure, power, maximumVolume;
public:
    virtual float getDamagePerSecond() const;

    AquaPokemon();
    AquaPokemon(int, int, string, string, float, float, float, vector<Ability>, float pressure, float power, float maximumVolume);
    AquaPokemon(float pressure, float power, float maximumVolume);
    AquaPokemon(const AquaPokemon& pkm);
    ~AquaPokemon();
    
    virtual istream& citire(istream& in);
    virtual ostream& afisare(ostream& out) const;
    
    friend istream& operator >>(istream& in, AquaPokemon& pkm);
    friend ostream& operator <<(ostream& out, const AquaPokemon& pkm);
    AquaPokemon& operator =(const AquaPokemon& pkm);
};

AquaPokemon::AquaPokemon():Pokemon(){
    this->pressure = 0;
    this->power = 0;
    this->maximumVolume = 0;
}
AquaPokemon::AquaPokemon(int age, int iq, string name, string color, float ms, float ap, float as, vector<Ability> abilities, float pressure, float power, float maximumVolume)
:Pokemon(age, iq, name, color, ms, ap, as, abilities){
    this->pressure = pressure;
    this->power = power;
    this->maximumVolume = maximumVolume;
}
AquaPokemon::AquaPokemon(float pressure, float power, float maximumVolume){
    this->pressure = pressure;
    this->power = power;
    this->maximumVolume = maximumVolume;
}
AquaPokemon::AquaPokemon(const AquaPokemon& pkm):Pokemon(pkm){
    this->pressure = pkm.pressure;
    this->power = pkm.power;
    this->maximumVolume = pkm.maximumVolume;
}
AquaPokemon::~AquaPokemon(){
    this->pressure = 0;
    this->power = 0;
    this->maximumVolume = 0;
}

float AquaPokemon::getDamagePerSecond() const {
    return this->attackSpeed*this->ap*this->power*this->pressure;
};

istream& AquaPokemon::citire(istream& in){
    cout<<"==============CREATE A NEW AQUA POKEMON!================"<<endl;
    ///in>>(Pokemon&)pkm;
    Pokemon::citire(in);
    cout<<"Power: "; in>>this->power;
    cout<<"Pressure: "; in>>this->pressure;
    cout<<"Maximum volume of water: "; in>>this->maximumVolume;

    return in;
}
ostream& AquaPokemon::afisare(ostream& out) const{
    Pokemon::afisare(out);
    out<<"Power: "; out<<this->power<<endl;
    out<<"Pressure: "; out<<this->pressure<<endl;
    out<<"Maximum volume of water: "; out<<this->maximumVolume<<endl;

    return out;
}
istream& operator >>(istream& in, AquaPokemon& pkm){
    return pkm.citire(in);
}
ostream& operator <<(ostream& out, const AquaPokemon& pkm){
    return pkm.afisare(out);
}
AquaPokemon& AquaPokemon::operator =(const AquaPokemon& pkm){
    if(this!=&pkm) {
        Pokemon::operator=(pkm);
        this->pressure = pkm.pressure;
        this->power = pkm.power;
        this->maximumVolume = pkm.maximumVolume;
    }

    return *this;
}

class FirePokemon:virtual public Pokemon{
protected:
    int maximumTemperature;
    float intensity, oxygenLevel;
    string fuelSource;
public:
    virtual float getDamagePerSecond() const;
    
    virtual istream& citire(istream& in);
    virtual ostream& afisare(ostream& out) const;

    FirePokemon();
    FirePokemon(int, int, string, string, float, float, float, vector<Ability>, int maximumTemperature, float intensity, float oxygenLevel, string fuelSource);
    FirePokemon(int maximumTemperature, float intensity, float oxygenLevel, string fuelSource);
    FirePokemon(const FirePokemon& pkm);
    ~FirePokemon();

    friend istream& operator >>(istream& in, FirePokemon& pkm);
    friend ostream& operator <<(ostream& out, const FirePokemon& pkm);
    FirePokemon& operator =(const FirePokemon& pkm);
};
FirePokemon::FirePokemon():Pokemon(){
    this->maximumTemperature = 0;
    this->intensity = 0;
    this->oxygenLevel = 0;
    this->fuelSource = "";
}
FirePokemon::FirePokemon(int age, int iq, string name, string color, float ms, float ap, float as, vector<Ability> abilities, int maximumTemperature, float intensity, float oxygenLevel, string fuelSource)
:Pokemon(age, iq, name, color, ms, ap, as, abilities){
    this->maximumTemperature = maximumTemperature;
    this->intensity = intensity;
    this->oxygenLevel = oxygenLevel;
    this->fuelSource = fuelSource;
}
FirePokemon::FirePokemon(int maximumTemperature, float intensity, float oxygenLevel, string fuelSource){
    this->maximumTemperature = maximumTemperature;
    this->intensity = intensity;
    this->fuelSource = fuelSource;
}
FirePokemon::FirePokemon(const FirePokemon& pkm):Pokemon(pkm){
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

float FirePokemon::getDamagePerSecond() const {
    return this->ap*this->attackSpeed*this->intensity*this->oxygenLevel;
}

istream& FirePokemon::citire(istream& in){
    cout<<"==============CREATE A NEW FIRE POKEMON!================"<<endl;
    ///in>>(Pokemon&)pkm;
    Pokemon::citire(in);
    cout<<"Intensity: "; in>>this->intensity;
    cout<<"Maximum Temperature: "; in>>this->maximumTemperature;
    cout<<"Average oxygen level: "; in>>this->oxygenLevel;
    cout<<"Fuel source: "; in>>this->fuelSource;

    return in;
}
ostream& FirePokemon::afisare(ostream& out) const{
    ///out<<(Pokemon&)pkm;
    Pokemon::afisare(out);
    out<<"Intensity: "; out<<this->intensity<<endl;
    out<<"Maximum Temperature: "; out<<this->maximumTemperature<<endl;
    out<<"Average oxygen level: "; out<<this->oxygenLevel<<endl;
    out<<"Fuel source: "; out<<this->fuelSource<<endl;

    return out;
}

istream& operator >>(istream& in, FirePokemon& pkm){
    return pkm.citire(in);
}
ostream& operator <<(ostream& out, const FirePokemon& pkm){
    return pkm.afisare(out);
}
FirePokemon& FirePokemon::operator =(const FirePokemon& pkm){

    if(this!=&pkm){
        Pokemon::operator=(pkm);
        this->maximumTemperature = pkm.maximumTemperature;
        this->intensity = pkm.intensity;
        this->oxygenLevel = pkm.oxygenLevel;
        this->fuelSource = pkm.fuelSource;
    }

    return *this;
}


class ElectricityPokemon:virtual public Pokemon{
protected:
    float wattage;
    bool stun;
    int minutesTilRecharge;
public:
    virtual float getDamagePerSecond() const;
    
    virtual istream& citire(istream& in);
    virtual ostream& afisare(ostream& out) const;

    ElectricityPokemon();
    ElectricityPokemon(int, int, string, string, float, float, float, vector<Ability>, float wattage, bool stun, int minutesTilRecharge);
    ElectricityPokemon(float wattage, bool stun, int minutesTilRecharge);  // pentru diamant
    ElectricityPokemon(const ElectricityPokemon& pkm);
    ~ElectricityPokemon();

    friend istream& operator >>(istream& in, ElectricityPokemon& pkm);
    friend ostream& operator <<(ostream& out, const ElectricityPokemon& pkm);
    ElectricityPokemon& operator =(const ElectricityPokemon& pkm);
};
ElectricityPokemon::ElectricityPokemon():Pokemon(){
    this->wattage = 0;
    this->stun = 0;
    this->minutesTilRecharge = 0;
}
ElectricityPokemon::ElectricityPokemon(int age, int iq, string name, string color, float ms, float ap, float as, vector<Ability> abilities, float wattage, bool stun, int minutesTilRecharge)
:Pokemon(age, iq, name, color, ms, ap, as, abilities){
    this->wattage = wattage;
    this->stun = stun;
    this->minutesTilRecharge = minutesTilRecharge;
}
ElectricityPokemon::ElectricityPokemon(float wattage, bool stun, int minutesTilRecharge){
    this->wattage = wattage;
    this->stun = stun;
    this->minutesTilRecharge = minutesTilRecharge;
}
ElectricityPokemon::ElectricityPokemon(const ElectricityPokemon& pkm):Pokemon(pkm){
    this->wattage = pkm.wattage;
    this->stun = pkm.stun;
    this->minutesTilRecharge = pkm.minutesTilRecharge;
}
ElectricityPokemon::~ElectricityPokemon(){
    this->wattage = 0;
    this->stun = 0;
    this->minutesTilRecharge = 0;
}

float ElectricityPokemon::getDamagePerSecond() const {
    return this->ap*this->attackSpeed*this->wattage;
}

istream& ElectricityPokemon::citire(istream& in){
    cout<<"==============CREATE A NEW ELECTRICITY POKEMON!================"<<endl;
    ///in>>(Pokemon&)pkm;
    Pokemon::citire(in);
    cout<<"Wattage: "; in>>this->wattage;
    cout<<"Minutes until recharge is needed: "; in>>this->minutesTilRecharge;
    cout<<"Stun: "; in>>this->stun;

    return in;
}
ostream& ElectricityPokemon::afisare(ostream& out) const{
    ///out<<(Pokemon&)pkm;
    Pokemon::afisare(out);
    out<<"Wattage: "; out<<this->wattage<<endl;
    out<<"Minutes until recharge is needed: "; out<<this->minutesTilRecharge<<endl;
    out<<"Stun: "; out<<this->stun<<endl;

    return out;
}

istream& operator >>(istream& in, ElectricityPokemon& pkm){
    return pkm.citire(in);
}
ostream& operator <<(ostream& out, const ElectricityPokemon& pkm){
    return pkm.afisare(out);
}
ElectricityPokemon& ElectricityPokemon::operator =(const ElectricityPokemon& pkm){

    if(this!=&pkm){
        Pokemon::operator=(pkm);
        this->wattage = pkm.wattage;
        this->stun = pkm.stun;
        this->minutesTilRecharge = pkm.minutesTilRecharge;
    }

    return *this;
}

class StormPokemon:public ElectricityPokemon, public AquaPokemon{
    int level, windSpeed;
public:
    float getDamagePerSecond() const;

    StormPokemon();
    StormPokemon(int age, int iq, string name, string color, float ms, float ap, float as,
                 vector<Ability> abilities, float wattage, bool stun, int minutesTilRecharge, float pressure, float power,
                 float maximumVolume, int level, int windSpeed);
    ~StormPokemon();

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;
    friend istream& operator >>(istream& in, StormPokemon& pkm);
    friend ostream& operator <<(ostream& out, const StormPokemon& pkm);
    StormPokemon& operator =(const StormPokemon& pkm);
};
StormPokemon::StormPokemon():Pokemon(), ElectricityPokemon(), AquaPokemon(){
    this->level = 0;
    this->windSpeed = 0;
}
StormPokemon::StormPokemon(int age, int iq, string name, string color, float ms, float ap, float as,
                           vector<Ability> abilities, float wattage, bool stun, int minutesTilRecharge, float pressure, float power,
                           float maximumVolume, int level, int windSpeed)
                           :Pokemon(age, iq, name, color, ms, ap, as, abilities),
                           ElectricityPokemon(wattage, stun, minutesTilRecharge),
                           AquaPokemon(pressure, power, maximumVolume){
    this->level = level;
    this->windSpeed = windSpeed;
}
StormPokemon::~StormPokemon(){
    this->level = 0;
    this->windSpeed = 0;
}

float StormPokemon::getDamagePerSecond() const {
    return this->ap*this->attackSpeed*this->wattage*this->attackSpeed*this->ap*this->power*this->pressure*this->level;
}

istream& StormPokemon::citire(istream& in){
    cout<<"==============CREATE A NEW STORM POKEMON!================"<<endl;
    Pokemon::citire(in);
    cout<<"Wattage: "; in>>this->wattage;
    cout<<"Minutes until recharge is needed: "; in>>this->minutesTilRecharge;
    cout<<"Stun: "; in>>this->stun;
    cout<<"Power: "; in>>this->power;
    cout<<"Pressure: "; in>>this->pressure;
    cout<<"Maximum volume of water: "; in>>this->maximumVolume;
    cout<<"Max storm level: "; in>>this->level;
    cout<<"Max wind speed: "; in>>this->windSpeed;

    return in;
}
ostream& StormPokemon::afisare(ostream& out) const {
    Pokemon::afisare(out);
    out<<"Wattage: "; out<<this->wattage<<endl;
    out<<"Minutes until recharge is needed: "; out<<this->minutesTilRecharge<<endl;
    out<<"Stun: "; out<<this->stun<<endl;
    out<<"Power: "; out<<this->power<<endl;
    out<<"Pressure: "; out<<this->pressure<<endl;
    out<<"Maximum volume of water: "; out<<this->maximumVolume<<endl;
    out<<"Maximum level of storm: "; out<<this->level;
    out<<"Maximum wind speeds: "; out<<this->windSpeed;

    return out;
}
istream& operator >>(istream& in, StormPokemon& pkm){
    return pkm.citire(in);
}
ostream& operator <<(ostream& out, StormPokemon& pkm){
    return pkm.afisare(out);
}
StormPokemon& StormPokemon::operator=(const StormPokemon& pkm){
    if(this!=&pkm){
        AquaPokemon::operator=(pkm);
        ElectricityPokemon::operator=(pkm);
        this->level = pkm.level;
        this->windSpeed = pkm.windSpeed;
    }
    return *this;
}

class LavaPokemon:public FirePokemon, public AquaPokemon{
    float damageResistance;
    bool stun;
public:
    float getDamagePerSecond() const;

    LavaPokemon();
    LavaPokemon(int age, int iq, string name, string color, float ms, float ap, float as,
                vector<Ability> abilities,  int maximumTemperature, float intensity, float oxygenLevel, string fuelSource,
                float pressure, float power, float maximumVolume, float damageRes, bool stun);
    ~LavaPokemon(){};
    
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;
    friend istream& operator >>(istream& in, LavaPokemon& pkm);
    friend ostream& operator <<(ostream& out, const LavaPokemon& pkm);
    LavaPokemon& operator =(const LavaPokemon& pkm);
};

LavaPokemon::LavaPokemon():Pokemon(), FirePokemon(), AquaPokemon(){
    this->damageResistance = 0;
    this->stun = 0;
}
LavaPokemon::LavaPokemon(int age, int iq, string name, string color, float ms, float ap, float as,
                         vector<Ability> abilities,  int maximumTemperature, float intensity, float oxygenLevel, string fuelSource,
                         float pressure, float power, float maximumVolume, float damageRes, bool stun)
                         :Pokemon(age, iq, name, color, ms, ap, as, abilities),
                         FirePokemon(maximumTemperature, intensity, oxygenLevel, fuelSource),
                         AquaPokemon(pressure, power, maximumVolume)
{
    this->damageResistance = damageRes;
    this->stun = stun;
}

float LavaPokemon::getDamagePerSecond() const {
    return this->ap*this->attackSpeed*this->intensity*this->oxygenLevel*this->attackSpeed*this->ap*this->power*this->pressure;
}

istream& LavaPokemon::citire(istream& in){
    Pokemon::citire(in);
    cout<<"Intensity: "; in>>this->intensity;
    cout<<"Maximum Temperature: "; in>>this->maximumTemperature;
    cout<<"Average oxygen level: "; in>>this->oxygenLevel;
    cout<<"Fuel source: "; in>>this->fuelSource;
    cout<<"Power: "; in>>this->power;
    cout<<"Pressure: "; in>>this->pressure;
    cout<<"Maximum volume of water: "; in>>this->maximumVolume;
    cout<<"Damage resistance: "; in>>this->damageResistance;
    cout<<"Stun? "; in>>this->stun;
    return in;
}
ostream& LavaPokemon::afisare(ostream& out) const {
    Pokemon::afisare(out);
    out<<"Intensity: "; out<<this->intensity<<endl;
    out<<"Maximum Temperature: "; out<<this->maximumTemperature<<endl;
    out<<"Average oxygen level: "; out<<this->oxygenLevel<<endl;
    out<<"Fuel source: "; out<<this->fuelSource<<endl;
    out<<"Power: "; out<<this->power<<endl;
    out<<"Pressure: "; out<<this->pressure<<endl;
    out<<"Maximum volume of water: "; out<<this->maximumVolume<<endl;
    out<<"Damage resistance: "; out<<this->damageResistance<<endl;
    out<<"Stun: "; out<<this->stun<<endl;
    return out;
}
istream& operator <<(istream& in, LavaPokemon& pkm){
    return pkm.citire(in);
}
ostream& operator >>(ostream& out, const LavaPokemon& pkm){
    return pkm.afisare(out);
}
LavaPokemon& LavaPokemon::operator=(const LavaPokemon &pkm) {
    if(this!=&pkm){
        FirePokemon::operator=(pkm);
        AquaPokemon::operator=(pkm);
        this->damageResistance = pkm.damageResistance;
        this->stun = pkm.stun;
    }
    return *this;
}


int Pokemon::pokemonNumber = 0;
vector<Pokemon*> allPokemons;


class Deck{
    const int idDeck;
    static int deckNumber;
    string name;
    vector<Pokemon*> pokemons;
public:
    Deck();
    Deck(string name, vector<Pokemon*> pokemons);
    Deck(const Deck& obj);
    ~Deck();

    string getName() { return this->name; }

    Deck& operator =(const Deck& obj);

    friend istream& operator >>(istream& in, Deck& deck);
    friend ostream& operator <<(ostream& out, const Deck& deck);
};
Deck::Deck():idDeck(deckNumber++){
    this->pokemons = {};
}
Deck::Deck(string name, vector<Pokemon*> pokemons):idDeck(deckNumber++){
    this->name = name;
    this->pokemons = pokemons;
}
Deck::Deck(const Deck& obj):idDeck(deckNumber++){
    this->name = obj.name;
    this->pokemons = obj.pokemons;
}
Deck::~Deck(){
    this->name.clear();
    this->pokemons.clear();
}
Deck& Deck::operator =(const Deck& obj){
    this->pokemons = obj.pokemons;
    return *this;
}
istream& operator >>(istream& in, Deck& deck){
    cout<<"Name: "; in>>deck.name;

    int inp;

    if(!deck.pokemons.empty()) deck.pokemons.clear();
    cout<<"This deck will need three pokemons! Search (1) or create (2)?"; cin>>inp;
    switch(inp){
        case 1: {
            for(int i=0; i<allPokemons.size() && deck.pokemons.size() < 3; i++){
                cout<<*allPokemons[i];
                cout<<"Is this the desired pokemon? Yes (1) or no (0): "; cin>>inp;
                if(inp){
                    deck.pokemons.push_back(allPokemons[i]);
                }
            }
            if(deck.pokemons.size() < 3){
                cout<<"You will need to create another pokemon!"<<endl;
                for(int i=deck.pokemons.size(); i<3; i++){
                    cout<<"Pokemon "<<i+1<<": "<<endl;
                    int choice;
                    cout<<"Please choose between Aqua (1), Fire (2), Electricity (3), Storm (4) or Lava (5): "<<endl; cin>>choice;
                    switch(choice){
                        case 1: {
                            allPokemons.push_back(new AquaPokemon);
                            cin>>*allPokemons.back();
                            break;
                        }
                        case 2: {
                            allPokemons.push_back(new FirePokemon);
                            cin>>*allPokemons.back();
                            break;
                        }
                        case 3: {
                            allPokemons.push_back(new ElectricityPokemon);
                            cin>>*allPokemons.back();
                            break;
                        }
                        case 4: {
                            allPokemons.push_back(new StormPokemon);
                            cin>>*allPokemons.back();
                            break;
                        }
                        case 5: {
                            allPokemons.push_back(new LavaPokemon);
                            cin>>*allPokemons.back();
                            break;
                        }
                    }
                    deck.pokemons.push_back(allPokemons.back());
                }
            }
            break;
        }
        case 2: {
            for(int i=0; i<3; i++){
                cout<<"Pokemon "<<i+1<<": "<<endl;
                int choice;
                cout<<"Please choose between Aqua (1), Fire (2), Electricity (3), Storm (4) or Lava (5): "<<endl; cin>>choice;
                switch(choice){
                    case 1: {
                        allPokemons.push_back(new AquaPokemon);
                        cin>>*allPokemons.back();
                        break;
                    }
                    case 2: {
                        allPokemons.push_back(new FirePokemon);
                        cin>>*allPokemons.back();
                        break;
                    }
                    case 3: {
                        allPokemons.push_back(new ElectricityPokemon);
                        cin>>*allPokemons.back();
                        break;
                    }
                    case 4: {
                        allPokemons.push_back(new StormPokemon);
                        cin>>*allPokemons.back();
                        break;
                    }
                    case 5: {
                        allPokemons.push_back(new LavaPokemon);
                        cin>>*allPokemons.back();
                        break;
                    }
                }
                deck.pokemons.push_back(allPokemons.back());
            }
            break;
        }
    }

    return in;
}
ostream& operator <<(ostream& out, const Deck& deck){
    out<<"HOHOHODECK"<<endl;
    out<<deck.name;
    for(int i=0; i<deck.pokemons.size(); i++){
        out<<*deck.pokemons[i];
    }
    return out;
}

vector<Deck*> allDecks;

class Player{
    const int idPlayer;
    static int playerNumber;

    string name;
    vector<Deck*> decks;
public:
    Player();
    Player(string name, vector<Deck*> decks);
    Player(const Player& ply);
    ~Player();

    string getName() { return this->name; }

    void deleteDeck(string name);
    void addDeck();

    Player& operator =(const Player& ply);
    friend istream& operator >>(istream& in, Player& ply);
    friend ostream& operator <<(ostream& out, const Player& ply);
};
Player::Player():idPlayer(playerNumber++){
    this->name = "";
    this->decks = {};
}
Player::Player(string name, vector<Deck*> decks):idPlayer(playerNumber++){
    this->name = name;
    this->decks = decks;
}
Player::Player(const Player& ply):idPlayer(playerNumber++){
    this->name = ply.name;
    this->decks = ply.decks;
}
Player::~Player(){
    this->name.clear();
    this->decks.clear();
}

Player& Player::operator=(const Player& ply){
    this->name = ply.name;
    this->decks = ply.decks;
    return *this;
}
istream& operator >>(istream& in, Player& ply){
    cout<<"Name: "; in>>ply.name;

    int inp;
    if(!ply.decks.empty()) ply.decks.clear();
    cout<<"This player must have atleast one pokemon deck!"<<endl;
    while(true){
        cout<<"Add new pokemon deck: "<<endl;
        allDecks.push_back(new Deck);
        cin>>*allDecks.back();
        ply.decks.push_back(allDecks.back());
        cout<<"Add another deck for this player? Yes (1) or no (0): "; cin>>inp;
        if(!inp) break;
    }

    return in;
}
ostream& operator <<(ostream& out, const Player& ply){
    out<<ply.name;
    for(int i=0; i<ply.decks.size(); i++){
        out<<*ply.decks[i];
    }
    return out;
}

void Player::deleteDeck(string name){
    for(int i=0; i<this->decks.size(); i++){
        if(this->decks[i]->getName() == name){
            this->decks.erase(this->decks.begin()+i);
            cout<<"Delete done!"<<endl;
            return;
        }
    }
    cout<<"Deck was not found!"<<endl;
}
void Player::addDeck(){
    int inp;
    cout<<"Add new deck (1) or find an existing deck? (2)"; cin>>inp;
    switch(inp){
        case 1: {
            Deck dk;
            allDecks.push_back(new Deck);
            cin>>*allDecks.back();
            this->decks.push_back(allDecks.back());
            break;
        }
        case 2: {
            for(int i=0; i<allDecks.size(); i++){
                cout<<*allDecks[i];
                cout<<"Is this the desired deck? Yes (1) or no (0): "; cin>>inp;
                if(inp){
                    this->decks.push_back(allDecks[i]);
                    return;
                }
            }

            cout<<"Deck was not found!"<<endl;
            break;
        }
    }
}

vector<Player*> allPlayers;

int Deck::deckNumber = 0;
int Player::playerNumber = 0;

int main() {
    while(true){
        int inp;
        cout<<"Create (1), read(2), update (3), delete (4): "; cin>>inp;
        switch(inp){
            case 1: {
                cout<<"Create player (1), deck (2), pokemon (3): "; cin>>inp;
                switch(inp){
                    case 1: {
                        allPlayers.push_back(new Player);
                        cin>>*allPlayers.back();
                        break;
                    }
                    case 2: {
                        allDecks.push_back(new Deck);
                        cin>>*allDecks.back();
                        break;
                    }
                    case 3: {
                        cout<<"Fire (1), Aqua (2), Electricity (3), Lava (4), Storm (5): "; cin>>inp;
                        switch(inp){
                            case 1: {
                                allPokemons.push_back(new FirePokemon);
                                cin>>*allPokemons.back();
                                break;
                            }
                            case 2: {
                                allPokemons.push_back(new AquaPokemon);
                                cin>>*allPokemons.back();
                                break;
                            }
                            case 3: {
                                allPokemons.push_back(new ElectricityPokemon);
                                cin>>*allPokemons.back();
                                break;
                            }
                            case 4: {
                                allPokemons.push_back(new LavaPokemon);
                                cin>>*allPokemons.back();
                                break;
                            }
                            case 5: {
                                allPokemons.push_back(new StormPokemon);
                                cin>>*allPokemons.back();
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 2: {
                cout<<"Read player (1), deck (2), pokemon (3): "; cin>>inp;
                switch(inp){
                    case 1: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allPlayers.size(); i++){
                            if(allPlayers[i]->getName() == name) {
                                cout << *allPlayers[i];
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allDecks.size(); i++){
                            if(allDecks[i]->getName() == name) {
                                cout << *allDecks[i];
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allPokemons.size(); i++){
                            if(allPokemons[i]->getName() == name) {
                                cout << *allPokemons[i];
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 3: {
                cout<<"Update player (1), deck (2), pokemon (3): "; cin>>inp;
                switch(inp){
                    case 1: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allPlayers.size(); i++){
                            if(allPlayers[i]->getName() == name) {
                                cin >> *allPlayers[i];
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allDecks.size(); i++){
                            if(allDecks[i]->getName() == name) {
                                cin >> *allDecks[i];
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allPokemons.size(); i++){
                            if(allPokemons[i]->getName() == name) {
                                cin >> *allPokemons[i];
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 4: {
                cout<<"Delete player (1), deck (2), pokemon (3): "; cin>>inp;
                switch(inp){
                    case 1: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allPlayers.size(); i++){
                            if(allPlayers[i]->getName() == name) {
                                allPlayers.erase(allPlayers.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allDecks.size(); i++){
                            if(allDecks[i]->getName() == name) {
                                allDecks.erase(allDecks.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        string name; cout<<"Name: "; cin>>name;
                        for(int i=0; i<allPokemons.size(); i++){
                            if(allPokemons[i]->getName() == name) {
                                allPokemons.erase(allPokemons.begin() + i);
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
        cout<<"============================PLAYERS=================================="<<endl;
        for(int i=0; i<allPlayers.size(); i++){
            cout<<*allPlayers[i]<<endl;
        }
        cout<<"============================DECKS=================================="<<endl;
        for(int i=0; i<allDecks.size(); i++){
            cout<<*allDecks[i]<<endl;
        }
        cout<<"============================POKEMONS=================================="<<endl;
        for(int i=0; i<allPokemons.size(); i++){
            cout<<*allPokemons[i]<<endl;
        }
        cout<<"Continue? Yes(1), no (0): "; cin>>inp;
        if(!inp) break;
    }

    return 0;
}
