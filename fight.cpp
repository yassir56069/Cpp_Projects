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
            std::cout << this->name << " is down to " << this->health << "health. \n";
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
    test.fighterStatus();
    test.doDmg();

}