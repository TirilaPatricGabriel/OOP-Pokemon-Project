#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

class Pokemon{
protected:
    const int idPokemon;
    static int pokemonNumber;
    int age, iq;
    string name, color;
    float movementSpeed, ap, attackSpeed;
    vector<Ability> abilities;
public:
    Pokemon();
    Pokemon(int, int, string, string, float, float, float, vector<Ability>);
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
    cout<<"================CREATE YOUR OWN POKEMON!==================="<<endl;
    cout<<"Name: "; in>>pkm.name;
    cout<<"Color: "; in>>pkm.color;
    cout<<"Age: "; in>>pkm.age;
    cout<<"Iq: "; in>>pkm.iq;
    cout<<"Movement speed: "; in>>pkm.movementSpeed;
    cout<<"Ability power: "; in>>pkm.ap;
    cout<<"Attack speed: "; in>>pkm.attackSpeed;
    int n;
    cout<<"Number of abilities: "; in>>n;
    for(int i=0; i<n; i++){
        Ability ab;
        cin>>ab;
        pkm.abilities.push_back(ab);
    }

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
    cout<<"Abilities: "<<endl;
    for(int i=0; i<pkm.abilities.size(); i++){
        out<<pkm.abilities[i]<<endl;
    }

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

class AquaPokemon:public Pokemon{
protected:
    float pressure, power, maximumVolume;
public:
    AquaPokemon();
    AquaPokemon(int, int, string, string, float, float, float, vector<Ability>, float pressure, float power, float maximumVolume);
    AquaPokemon(const AquaPokemon& pkm);
    ~AquaPokemon();
    
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

istream& operator >>(istream& in, AquaPokemon& pkm){
    cout<<"==============CREATE A NEW AQUA POKEMON!================"<<endl;
    in>>(Pokemon&)pkm;
    cout<<"Power: "; in>>pkm.power;
    cout<<"Pressure: "; in>>pkm.pressure;
    cout<<"Maximum volume of water: "; in>>pkm.maximumVolume;
    
    return in;
}
ostream& operator <<(ostream& out, const AquaPokemon& pkm){
    out<<(Pokemon&)pkm;
    out<<"Power: "; out<<pkm.power<<endl;
    out<<"Pressure: "; out<<pkm.pressure<<endl;
    out<<"Maximum volume of water: "; out<<pkm.maximumVolume<<endl;

    return out;
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

class FirePokemon:public Pokemon{
protected:
    int maximumTemperature;
    float intensity, oxygenLevel;
    string fuelSource;
public:
    FirePokemon();
    FirePokemon(int, int, string, string, float, float, float, vector<Ability>, int maximumTemperature, float intensity, float oxygenLevel, string fuelSource);
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

istream& operator >>(istream& in, FirePokemon& pkm){
    cout<<"==============CREATE A NEW AQUA POKEMON!================"<<endl;
    in>>(Pokemon&)pkm;
    cout<<"Intensity: "; in>>pkm.intensity;
    cout<<"Maximum Temperature: "; in>>pkm.maximumTemperature;
    cout<<"Average oxygen level: "; in>>pkm.oxygenLevel;
    cout<<"Fuel source: "; in>>pkm.fuelSource;

    return in;
}
ostream& operator <<(ostream& out, const FirePokemon& pkm){
    out<<(Pokemon&)pkm;
    out<<"Intensity: "; out<<pkm.intensity<<endl;
    out<<"Maximum Temperature: "; out<<pkm.maximumTemperature<<endl;
    out<<"Average oxygen level: "; out<<pkm.oxygenLevel<<endl;
    out<<"Fuel source: "; out<<pkm.fuelSource<<endl;

    return out;
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


class ElectricityPokemon:public Pokemon{
protected:
    float wattage;
    bool stun;
    int minutesTilRecharge;
public:
    ElectricityPokemon();
    ElectricityPokemon(int, int, string, string, float, float, float, vector<Ability>, float wattage, bool stun, int minutesTilRecharge);
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

istream& operator >>(istream& in, ElectricityPokemon& pkm){
    cout<<"==============CREATE A NEW AQUA POKEMON!================"<<endl;
    in>>(Pokemon&)pkm;
    cout<<"Wattage: "; in>>pkm.wattage;
    cout<<"Minutes until recharge is needed: "; in>>pkm.minutesTilRecharge;
    cout<<"Stun: "; in>>pkm.stun;

    return in;
}
ostream& operator <<(ostream& out, const ElectricityPokemon& pkm){
    out<<(Pokemon&)pkm;
    out<<"Wattage: "; out<<pkm.wattage<<endl;
    out<<"Minutes until recharge is needed: "; out<<pkm.minutesTilRecharge<<endl;
    out<<"Stun: "; out<<pkm.stun<<endl;

    return out;
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
                    cout<<"Pokemon "<<i<<": "<<endl;
                    Pokemon pkm;
                    cin>>pkm;
                    allPokemons.push_back(new Pokemon);
                    cin>>*allPokemons.back();
                    deck.pokemons.push_back(allPokemons.back());
                }
            }
            break;
        }
        case 2: {
            for(int i=0; i<3; i++){
                cout<<"Pokemon "<<i<<": "<<endl;
                allPokemons.push_back(new Pokemon);
                cin>>*allPokemons.back();
                deck.pokemons.push_back(allPokemons.back());
            }
            break;
        }
    }

    return in;
}
ostream& operator <<(ostream& out, const Deck& deck){
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
private:
    Player();
    Player(string name, vector<Deck*> decks);
    Player(const Player& ply);
    ~Player();

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
    cout<<"This player must have atleast one pokemon deck!"<<endl;
    while(true){
        cout<<"Add new pokemon deck: ";
        Deck dk;
        cin>>dk;
        ply.decks.push_back(&dk);
        allDecks.push_back(&dk);
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

int Deck::deckNumber = 0;
int Player::playerNumber = 0;

int main() {
    Ability ab;
    cin>>ab;
    vector<Ability> v = {ab};
    Pokemon pkm(1, 1, "c", "c", 1.0, 1.0, 1.0, v);
    cout<<pkm;
//    Pokemon pkm;
//    cin>>pkm;
//    Pokemon pkm2(pkm), pkm3;
//    pkm3 = pkm;
//    cout<<pkm2<<endl<<pkm3;
//    AquaPokemon pkm, pkm2;
//    cin>>pkm;
//    pkm2 = pkm;
//    AquaPokemon pkm3(pkm2);
//    cout<<pkm2<<endl<<pkm3;
//    FirePokemon pkm, pkm2;
//    cin>>pkm;
//    pkm2 = pkm;
//    FirePokemon pkm3(pkm2);
//    cout<<pkm2<<endl<<pkm3;
//    ElectricityPokemon pkm, pkm2;
//    cin>>pkm;
//    pkm2 = pkm;
//    ElectricityPokemon pkm3(pkm2);
//    cout<<pkm2<<endl<<pkm3;
    return 0;
}
