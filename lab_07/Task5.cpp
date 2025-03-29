#include "iostream"
using namespace std;

class character{
    protected:
        int id ;
        string name;
        int level;
        double healthPoints;
        string weaponType;

    public:
        character(int id ,string name,int level,double hp,string weaponType="None")
        :id(id),name(name),level(level),healthPoints(hp),weaponType(weaponType){}

        virtual void attack(){
                cout <<name<<" is attacking with "<<weaponType<<endl;
        }
        virtual void defend(){
            cout <<name<<"is defending"<<endl;
        }

        virtual void displayStats() {
            cout << "Character ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Level: " << level << endl;
            cout << "Health Points: " << healthPoints << endl;
            cout << "Weapon Type: " << weaponType << endl;
        } 
};


class warrior:public character{
    private:
        double armorStrength;
        double meleeDamage;

    public:
        warrior(int id ,string name ,int level,double hp,double strength,double meleeDamage,string weaponType = "none")
        :character(id,name,level,hp,weaponType),armorStrength(strength),meleeDamage(meleeDamage){}

        void attack()override{
            character::attack();
            cout <<"Melee Damage : "<<meleeDamage<<endl;
            cout <<"Armour Strength : "<<armorStrength<<endl;

        }
};


class mage:public character{
    private :
        int manaPoints ;
        int spellPower;

    public :
        mage(int id ,string name,int level,double hp,int manaPoints,int spellPower,string weaponType = "none")
        :character(id,name,level,hp,weaponType),manaPoints(manaPoints),spellPower(spellPower){}

        void defend() override{
            character::defend();
            cout <<"Creating Magical Barriers "<<endl;
        }
};

class archer:public character{
    private:
        int arrowCount;
        double rangeAccuracy;
    
    public:
    archer(int id ,string name,int level,double hp,int count ,double accuracy,string weaponType ="none")
    :character(id,name,level,hp,weaponType),arrowCount(count),rangeAccuracy(rangeAccuracy){}

    void attack()override{
        character::attack();
        cout <<"Range Accuracy : "<<rangeAccuracy<<endl;
        cout <<"Remaining Arrows : "<<arrowCount<<endl;
    }

};

class rogue : public character{
    private :
        int stealthLevel;
        int agility ;

    public:
        rogue(int id ,string name,int level,double hp,int stealthLevel,int agility,string weaponType = "none")
        :character(id,name,level,hp,weaponType),stealthLevel(stealthLevel),agility(agility){}

        void displayStats()override {
            character::displayStats();
            cout << "Stealth Level : "<<stealthLevel<<endl;
            cout << "Agility : "<<agility<<endl;
        }

};


int main (){
    warrior warrior1(101, "Thor", 50, 100, 50000, 1000,"hammer");
    mage mage1(102, "leonard", 12, 300, 200, 150);
    archer archer1(103, "Hawkeye", 8, 400, 20, 90,"Bow");
    rogue rogue1(104, "Omen", 9, 350, 80, 95);

    cout << "\n--- Character Stats ---\n";
    warrior1.displayStats();
    cout << "\n";
    mage1.displayStats();
    cout << "\n";
    archer1.displayStats();
    cout << "\n";
    rogue1.displayStats();
    cout << "\n";

    cout << "--- Attacks and Defenses ---\n";
    warrior1.attack();
    mage1.defend();
    archer1.attack();

    return 0;
}

