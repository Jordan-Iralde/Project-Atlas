#include <iostream>
#include <string>

class Player
{
public:
int TakeDamage(int damage);

int Heal(int amount);

int GetHealth() const;


private:
    std::string name;
    int health;
};