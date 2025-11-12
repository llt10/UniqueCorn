#include <iostream> 
#include <string>
#include <stdexcept>

using namespace std;

class Unicorn
{
private:
   string name;

   static string takenName[100];
   static int nameCount;

public:
    
Unicorn(const string& unicornName) {
for (int i = 0; i < nameCount; i++) {
    if (takenName[i] == unicornName) {
        throw runtime_error("Error: This name is taken");
    }
}

name = unicornName;
takenName[nameCount] = unicornName;
nameCount++;

std::cout << "A unicorn named" << name << " has been born!" << std::endl;
}

~Unicorn() {
    std::cout << "The unicorn named " << name << " has vanished. So this name can be taken." << std::endl;
    for (int i = 0; i < nameCount; i++) {
        if (takenName[i] == name) {
            for (int j = i; j < nameCount-1; j++) {
                takenName[j] = takenName[j+1];
            }
            nameCount--;
            break;
        }
    }
}
void displayName() const {
    std::cout << "This unicorn's name is " << name << std::endl;
    }
};
