#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <numeric>
#include <math.h>



#pragma region Class Decleration And Build

    class Fighter 
    {
        private:
            std::string name;
            int health; 
            int dmg;            //damage is randomized
            int maxDmg;         //maximum damage by fighter

            static int numOfFighters;
            static const int minDmg = 0;
            
        public:

            #pragma region gets and sets

                //getset for name

                std::string getName(){ return this->name; }

                void setName(std::string newName){ this->name = newName; }

                //getset for health

                int getHealth(){ return this->health; }

                void setHealth(int newHealth){ this->health = newHealth; }

                //getset for damage

                int getDmg(){ return this->dmg; }

                void setDmg(int newDmg){ this->dmg = newDmg; }


                /// @brief used to set all properties 
                void SetAll(std::string, int, int, int);

            #pragma endregion
        
            #pragma region functionality methods
                
                /// @brief randomises the value of dmg, uses the `stl` function rand()
                void rndDmg()
                {

                    this->dmg = this->minDmg + ( std::rand() % ( this->maxDmg - this->minDmg  + 1 ) );
                }

                void takeDmg(Fighter person)
                {
                    person.rndDmg();
                    this->health -= person.getDmg();
                    std::cout << person.getName() << " attacks " << this->name << " and deals " << person.getDmg() << " damage \n";

                    this->fighterStatus();
                }

                void duel(Fighter f2)
                {
                    int winflag = 0, numOfRounds = 0;                // winflag Bool:     1: fighter 1 won, 2: fighter 2 won 

                    while ( this->getHealth() > 0 && f2.getHealth() > 0 )
                    {
                        numOfRounds ++;


                        ( numOfRounds % 2 != 0 ) ? this->takeDmg(f2) : f2.takeDmg( *this );

                        if ( this->getHealth() <= 0 ) { winflag = 1; } 
                        if ( f2.getHealth() <= 0 ) { winflag = 2; } 
                    }

                    switch (winflag)
                    {
                        case 1:
                            std::cout << this->getName() << " has Died and " <<  f2.getName() << " is victorious \n";
                            break;

                        default:
                            std::cout <<  f2.getName()  << " has Died and " << this->getName() << " is victorious \n";
                    }
                }

            #pragma endregion

            #pragma region Constructors

                /// @brief Constructor
                Fighter(std::string, int, int);

                /// @brief Overloaded Constructor
                Fighter();

            #pragma endregion
            
            #pragma region Overwritten

                void fighterStatus();

                void doDmg();

            #pragma endregion

    };

    #pragma region Fighter Build

        int Fighter::numOfFighters = 0;

        void Fighter::SetAll(std::string name, int health, int dmg, int maxDmg)
        {
            this->name = name;
            this->health = health;
            this->dmg = dmg;
            this->maxDmg = maxDmg;

            Fighter::numOfFighters++;
        }

        Fighter::Fighter(std::string name, int health, int maxDmg)
        {
            this->name = name;
            this->health = health;
            this->dmg = 0;
            this->maxDmg = maxDmg;

            Fighter::numOfFighters++;
        }

        Fighter::Fighter()
        {
            this->name = "Fighter";
            this->health = 100;
            this->dmg = 0;
            this->maxDmg = 20;

            Fighter::numOfFighters++;              
        }

        void Fighter::fighterStatus()
        {
            if (this->health < 0) { this->health = 0; }

            std::cout << this->name << " is down to " << this->health << " Health. \n";
        }

        void Fighter::doDmg()
        {
            rndDmg();
            std::cout << this->name << " does " << this->dmg << " Damage. \n";
        }

    #pragma endregion



#pragma endregion


int main()
{ 
    std::srand(std::time(0));    // initialises rand to be random

    Fighter test("Fred", 100, 30);
    Fighter test2("John", 100, 30);

    test.duel(test2);

}