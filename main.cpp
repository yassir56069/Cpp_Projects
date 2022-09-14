#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>


#pragma region  Classes

    #pragma region Classes Prototypes

        class Animal 
        {
            private:
                std::string name;
                double  height;
                double  weight;

                static  int numOfAnimals;       // tally

            public:
                #pragma region Gets And Sets

                    /// @brief  Get function for the name of the animal
                    /// @return Name of the animal
                    std::string GetName() { return name; }

                    /// @brief Sets the name of the animal to a new name
                    /// @param newName The new name
                    void SetName(std::string newName) { this->name = newName; }


                    /// @brief  Get function for the height of the animal
                    /// @return Height of the animal
                    double GetHeight() { return height; }

                    /// @brief Sets the height of the animal to a new height
                    /// @param newHeight The new height
                    void SetHeight(double newHeight) { this->height = newHeight; }


                    /// @brief  Get function for the weight of the animal
                    /// @return Weight of the animal
                    double GetWeight() { return weight; }

                    /// @brief Sets the weight of the animal to a new weight
                    /// @param newWeight The new weight
                    void SetWeight(double newWeight) { this->weight = newWeight; }

                    /// @brief Get function for the number of animals
                    /// @return The number of animals
                    static int GetNumOfAnimals() { return numOfAnimals; }

                    /// @brief used to set all properties 
                    void SetAll(std::string, double, double);

                #pragma endregion

                #pragma region Constructor Method Prototype

                    /// @brief Constructor 
                    Animal(std::string, double, double);

                    /// @brief Overloaded Constructor 
                    Animal();

                    /// @brief Deconstructor
                    ~Animal();

                #pragma endregion

                #pragma region Overwritten
                    
                    void ToString();

                #pragma endregion

        };

        class Dog: public Animal
        {
            private:
                std::string sound = "Woof";
            
            public:

                std::string MakeSound(){ return "The dog " + this->GetName() + " says " + this->sound + ".\n"; }

                #pragma region Constructor Method Prototypes

                    Dog(std::string, double, double, std::string);
                    Dog(): Animal(){};

                #pragma endregion

                void ToString();
        };

    #pragma endregion

    #pragma region ANIMAL CLASS Constructor And Overwriting

            int Animal::numOfAnimals = 0;

            void Animal::SetAll(std::string name, double weight, double height)
            {
                this->name = name;
                this->weight = weight;
                this->height = height;

                Animal::numOfAnimals++;

            }

            Animal::Animal(std::string name, double weight, double height)
            {
                this->name = name;
                this->weight = weight;
                this->height = height;

                Animal::numOfAnimals++;

            }

            Animal::Animal()
            {
                this->name = "";
                this->weight = 0;
                this->height = 0;

                Animal::numOfAnimals++;
            }

            Animal::~Animal() 
            {
                std::cout << " Animal " << this->name << " removed. \n";
            }

            void Animal::ToString()
            {
                std::cout << this->name << " is " << this->height 
                        << " cms tall and "
                        << this->weight
                        << "kgs in weight. \n"
                        ; 
            }

        #pragma endregion

    #pragma region DOG CLASS INHERETING ANIMAL CLASS Constructor And Overwriting
        
        Dog::Dog(std::string name, double height, double weight, std::string sound) : Animal(name, height, weight) 
        {
            this->sound = sound;
        }

        void Dog::ToString()  
        {
            std::cout << this->GetName() 
                    << " is a dog, which is "
                    << this->GetHeight() 
                    << " cms tall and "
                    << this->GetWeight()
                    << "kgs in weight." 
                    << MakeSound()  
                    ; 
        }

    #pragma endregion

#pragma endregion

int main()
{
    Animal fred;

    fred.SetHeight(33);
    fred.SetName("Fred");
    fred.SetWeight(70);
    fred.ToString();

    Dog spot("Spot",38, 16, "Bork");

    spot.ToString();

    std::cout << "Number of Animals: " << Animal::GetNumOfAnimals() << "\n";

    return 0;
}