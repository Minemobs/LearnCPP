//
// Created by minemobs on 30/04/2021.
//

#ifndef LEARNCPP_PLAYER_H
#define LEARNCPP_PLAYER_H

#include <string>
#include "Entity.h"

using namespace std;

class Player : Entity {
public:
    Player(string playerName, int playerStrength, int playerHealth){
        name = playerName;
        strength = playerStrength;
        health = playerHealth;
    }

    bool isDead(){
        return health > 0;
    }

    void damagePlayer(int damage){
        if(health <= 0) return;
        health-=damage;
    }

    int getStrength(){
        return strength;
    }

    int getHealth(){
        return health;
    }

    string getName(){
        return name;
    }
};


#endif //LEARNCPP_PLAYER_H
