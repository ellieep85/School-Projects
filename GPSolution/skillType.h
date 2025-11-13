#ifndef skillType_h
#define skillType_h

#include <iostream>
//#include "characterType.h"

using namespace std;

/*The races include:
elf
dwarf
Human
Orc
dragonborn
gnome
tiefling
lizardfolk
halfling (we love hobbits)
*/

/*classes will include:
barbarian
bard
cleric
druid
fighter
monk
paladin
ranger
rogue
wizard
warlock
*/

//by Ellie
class skillType : public characterType {

    private:
    //These are all int variables because they will store the point value for each skill
    int strength;
    //stores the skill points for strength
    
    int perception;
    //stores the skill points for perception
    
    int endurance;
    //stores the skill points for endurance
    
    int charisma;
    //stores the skill points for charisma
    
    int intelligence;
    //stores the skill points for intelligence
    
    int agility;
    //stores the skill points for agility
    
    int luck;
    //stores the skill points for luck
    
    public:
    void setSkillPoints(int, int);
    //This function sets the skill points based on the character traits selected by the player
    
    //The following functions will return the skill points that have been set
    int getStrength();
    int getPerception();
    int getEndurance();
    int getCharisma();
    int getIntelligence();
    int getAgility();
    int getLuck();
    
    void updateSkills(int, int, int, int, int, int, int);
    /*This function will take the value of the integers that are being passed into the function and add their value to the private variables for each skill. This will update the skills based on the player’s choice.*/
    };
    

    void skillType::setSkillPoints(int r, int c){
        
        switch(r){
            case 1: //elf
                strength = 2;
                perception = 5;
                endurance = 5;
                charisma = 10;
                intelligence = 15;
                agility = 10;
                luck = 8;
                break;

            case 2: //dwarf
                strength = 15;
                perception = 2;
                endurance = 15;
                charisma = 5;
                intelligence = 5;
                agility = 2;
                luck = 10;
                break;
            
            case 3: //human
                strength = 8;
                perception = 5;
                endurance = 10;
                charisma = 8;
                intelligence = 8;
                agility = 8;
                luck = 5;
                break;

            case 4: //Orc
                strength = 15;
                perception = 2;
                endurance = 15;
                charisma = 2;
                intelligence = 2;
                agility = 8;
                luck = 2;
                break;

            case 5: //Dragonborn
                strength = 15;
                perception = 5;
                endurance = 10;
                charisma = 15;
                intelligence = 8;
                agility = 5;
                luck = 2;
                break;

            case 6: //gnome
                strength = 5;
                perception = 8;
                endurance = 5;
                charisma = 15;
                intelligence = 8;
                agility = 2;
                luck = 15;
                break;

            case 7: //tiefling
                strength = 8;
                perception = 10;
                endurance = 8;
                charisma = 5;
                intelligence = 8;
                agility = 15;
                luck = 5;
                break;

            case 8: //lizardFolk
                strength = 8;
                perception = 2;
                endurance = 10;
                charisma = 5;
                intelligence = 5;
                agility = 15;
                luck = 5;
                break;

            case 9: //halflings (they're taking the hobbits to isengard)
                strength = 2;
                perception = 10;
                endurance = 10;
                charisma = 15;
                intelligence = 5;
                agility = 2;
                luck = 8;
                break;
        }

        //next switch will be for the classes race stats will be added to the additional class stat bonuses
        switch(c){
            case 1:
                strength = strength + 10;
                endurance = endurance + 10;
                break;

            case 2:
                charisma = charisma + 10;
                luck = luck + 10;
                break;

            case 3:
                perception = perception + 10;
                endurance = endurance + 10;
                break;

            case 4:
                intelligence = intelligence + 10;
                perception = perception + 10;
                break;

            case 5:
                agility = agility + 10;
                strength = strength + 10;
                break;

            case 6:
                strength = strength + 10;
                agility = agility + 10;
                break;
            
            case 7:
                charisma = charisma + 10;
                strength = strength + 10;
                break;

            case 8:
                endurance = endurance + 10;
                intelligence = intelligence + 10;
                break;

            case 9:
                luck = luck + 10;
                perception = perception + 10;
                break;

            case 10:
                luck = luck + 10;
                intelligence = intelligence + 10;
                break;

            case 11:
                perception = perception + 10;
                intelligence = intelligence + 10;
                break;
        }
    }

    int skillType::getStrength(){
        return strength;
    }

    int skillType::getPerception(){
        return perception;
    }

    int skillType::getEndurance(){
        return endurance;
    }

    int skillType::getCharisma(){
        return charisma;
    }

    int skillType::getIntelligence(){
        return intelligence;
    }

    int skillType::getAgility(){
        return agility;
    }

    int skillType::getLuck(){
        return luck;
    }

    void skillType::updateSkills(int s, int p, int e, int c, int i, int a, int l){
        strength = strength + s;
        perception = perception + p;
        endurance = endurance + e;
        charisma = charisma + c;
        intelligence = intelligence + i;
        agility = agility + a;
        luck = luck + l;
    }


#endif