#include "Player.hpp"
    
int Player::TakeDamage(int damage)
{
    health -= damage;
    return health;
}

int Player::Heal(int amount)
{
    health += amount;
    return health;
}

int Player::GetHealth()
{
    return health;
}

