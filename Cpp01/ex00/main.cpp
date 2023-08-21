#include "Zombie.hpp"

int main()
{
    cout << "newZombie declaration." << std:: endl;
    Zombie *zom = newZombie("quaso");
    zom->announce();
    cout << "randomChump declaration." << std:: endl;
    randomChump("liaon");
    delete (zom);
    return (0);
}