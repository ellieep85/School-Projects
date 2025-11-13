/******************************************************************************
 * Title of program: The Logic Legends
 * Purpose: This code will execute the Logic Legends Text Based Adventure Game
 * Version: 1.1.0
 * Authors: Ellie Pfeiffer, Zechariah Winters, Joshua Barroso, Devon Sabody, Wyatt Cox
 * Last Date of Update: 3/5/2025
 *
 *
 *
 *
 *******************************************************************************/

 #include "characterType.h"
 #include "skillType.h"
 #include <algorithm>
 #include <cctype>
 #include <climits>
 #include <iomanip>
 #include <iostream>
 #include <string>
 #include <vector>
 
 using namespace std;
 
 // function declarations
 string getRaceString(int);
 string getClassString(int);
 void resetStream();
 int banditCampQuest(skillType& player);
 void zechariahQuest(skillType& player);
 int statHandler(skillType& character, int);
 int joshQuest(skillType& character, int index = 0, int jndex = 0, string selector = "intro");
 void innScene(skillType& player);
 void tableScene(skillType& player);
 void thiefForestScene(skillType& player);
 bool playerSparedThieves = false; // Tracks whether the player avoided killing thieves
 
 int main()
 {
     // variable declarations
     skillType character; // stores character info
     string name; // store character name
     int raceChoice; // stores choice made by user for race
     string raceStr;
     int classChoice; // store choice made by user for class
     string classStr;
     char yOrN; // for input validation
     int result;
 
     cout << "Welcome to the magical world of Logicopia!" << endl;
     cout << "This is a land of adventures and endless opportunity for travelers like you." << endl;
 
     // This block gets the players name.
     while (yOrN != 'Y') {
         cout << "Please... tell me your name: ";
         cin >> name;
         cout << "Your name is " << name << "? Did I get it right? (Enter Y or N) ";
         cin >> yOrN;
         yOrN = toupper(yOrN);
         while (yOrN != 'Y' && yOrN != 'N') {
             if (yOrN != 'Y' && yOrN != 'N') {
                 resetStream();
                 cout << "I do not understand. I was expecting Y or N. Try again! " << endl;
                 cin >> yOrN;
                 yOrN = toupper(yOrN);
             }
         }
         while (yOrN == 'N') {
             if (yOrN == 'N') {
                 cout << "My apologies... Come again: ";
                 cin >> name;
                 cout << "Your name is " << name << "? Did I get it right? (Enter Y or N) ";
                 cin >> yOrN;
                 yOrN = toupper(yOrN);
                 while (yOrN != 'Y' && yOrN != 'N') {
                     if (yOrN != 'Y' && yOrN != 'N') {
                         resetStream();
                         cout << "I do not understand. I was expecting Y or N. Try again! " << endl;
                         cin >> yOrN;
                         yOrN = toupper(yOrN);
                     }
                 }
             }
         }
         if (yOrN == 'Y') {
             character.setName(name);
         }
     }
 
     // This block will get and set the race of the player as an integer
     cout << endl;
     cout << "So " << character.getName() << " where do you come from? What is the race of your people?" << endl;
     cout << "Please select a race from the list below: " << endl;
     cout << "1. Elf" << endl;
     cout << "2. Dwarf" << endl;
     cout << "3. Human" << endl;
     cout << "4. Orc" << endl;
     cout << "5. Dragonborn" << endl;
     cout << "6. Gnome" << endl;
     cout << "7. Tiefling" << endl;
     cout << "8. Lizardfolk" << endl;
     cout << "9. Halfling" << endl;
     cin >> raceChoice;
     while (!cin || raceChoice < 1 || raceChoice > 9) {
         if (!cin) {
             resetStream();
             cout << "Sorry, I was expecting a number. Try again: ";
             cin >> raceChoice;
         } else {
             resetStream();
             cout << "You entered a number that isn't on the list. Try again: ";
             cin >> raceChoice;
         }
     }
 
     raceStr = getRaceString(raceChoice);
     character.setRace(raceStr);
 
     cout << "Ah, I see " << character.getName() << " you're a " << character.getRace() << "!" << endl;
     cout << endl;
 
     // This block will get and set the class of the player
     cout << "Last question, I swear!" << endl;
     cout << "What is your skill class?" << endl;
     cout << "Please select a class from below: " << endl;
     cout << "1. Barbarian" << endl;
     cout << "2. Bard" << endl;
     cout << "3. Cleric" << endl;
     cout << "4. Druid" << endl;
     cout << "5. Fighter" << endl;
     cout << "6. Monk" << endl;
     cout << "7. Paladin" << endl;
     cout << "8. Ranger" << endl;
     cout << "9. Rogue" << endl;
     cout << "10. Wizard" << endl;
     cout << "11. Warlock" << endl;
     cin >> classChoice;
     while (!cin || classChoice < 1 || classChoice > 11) {
         if (!cin) {
             resetStream();
             cout << "Sorry, I was expecting a number. Try again: ";
             cin >> classChoice;
         } else {
             resetStream();
             cout << "You entered a number that isn't on the list. Try again: ";
             cin >> classChoice;
         }
     }
 
     classStr = getClassString(classChoice);
     character.setClass(classStr);
 
     cout << "What a sight! a " << character.getRace() << " " << character.getClass() << "!" << endl;
 
     // this line sets the character stats based on race and class
     character.setSkillPoints(raceChoice, classChoice);
 
     cout << "Well " << character.getName() << ", I suppose it's time you start your journey..." << endl;
 
     // story code starts here
 
     // Josh's story function call
     joshQuest(character);
 
     // in between story function fluff
     cout << "\nYou stumble back onto the path finally escaping the caverns of the mountain. The faces of the shadowy beasts fill your mind." << endl;
     cout << "You're not sure where you're heading now, but you think back to your waking moments." << endl;
     cout << "You can't remember a thing... but your encounter with the shadow figures haunt you." << endl;
     cout << "What evils haunt this land? Does the glowing mark on your hand mean?" << endl;
     cout << "\nThe sun begins to set over the horizon, despite walking leagues under the sun, your legs feel light and your head heavy." << endl;
     cout << "You make camp along the road and try to ease your mind from the anxieties you feel." << endl;
     cout << "Maybe sleep will help..." << endl;
     cout << endl;
     cout << "...zZZ" << endl;
     cout << endl;
 
     // zach's function call
     zechariahQuest(character);
 
     // story in betweens
     cout << endl;
     cout << "\n..." << endl;
     cout << "You managed to escape another bad situation... however a coolness pricks on your back." << endl;
     cout << "Maybe you could be a hero, a soldier, or something else significant- but first you needed answers." << endl;
     cout << "You decide the best thing for you now is to find your people. Other " << character.getRace() << "s." << endl;
     cout << "With this resolve, you push further down the winding road. " << endl;
     cout << "\n";
 
     // Devon's Function call
     result = banditCampQuest(character);
     if (result == 1) {
         cout << "\nYou got away safely!" << endl;
     } else if (result == 2 || result == 4) {
         cout << "\nYour spoils were added to your inventory!" << endl;
         cout << "Gold: " << character.getGold() << endl;
         cout << "Items: ";
         character.printItem();
         cout << endl;
     } else {
         return 0;
     }
 
     //story in-betweens
     cout << "\nAs you travel deeper into the land of Logicopia, small memories begin to resurface." << endl;
     cout << "You begin to remember the unique traditions of the " << character.getRace() << "s." << endl;
     cout << "Feasts, holidays, coming of age ceremonies all fill your mind as the landscape slowing shifts into familiar horizons" << endl;
     cout << "It's not long before you see a little town in the distance." << endl;
     cout << endl;
 
     //Wyatt's Story code
     innScene(character);
 
     //story wrap up code by Ellie :)
     cout << endl;
     cout << "You have traveled far to get here, and after all your adventures you feel as if you have only begun the first chapter in this grand new world." << endl;
     cout << "Perhaps there is more to come, but for now, you could really use a nap..." << endl;
     cout << "The End" << endl;
 
     cout << "Congrats! You Earned the following title(s) on your Journey:" << endl;
     if(character.getStrength() > 20) {
         cout << character.getName() << "the Strong" << endl;
     }
     else if(character.getPerception() > 20) {
         cout << character.getName() << " the One with the World" << endl;
     }
     else if(character.getEndurance() > 20){
         cout << character.getName() << " the Endurer of all Challenges" << endl; 
     }
     else if(character.getCharisma() > 20){
         cout << character.getName() << " the Life of the Party" << endl;   
     }
     else if(character.getIntelligence() > 20){
         cout << character.getName() << " the Wise" << endl;    
     }
     else if(character.getAgility() > 20){
         cout << character.getName() << " the Quick Footed" << endl;    
     }
     else if(character.getLuck() > 20){
         cout << character.getName() << " the Fortunate" << endl;    
     }
     else{
         cout << character.getName() << " the Insignificant" << endl;
     }
 
     return 0;
 }
 
 // this is a function for input validation
 void resetStream()
 {
     cin.clear();
     cin.ignore(INT_MAX, '\n');
 }
 
 // Turns race int into string
 string getRaceString(int r)
 {
     switch (r) {
     case 1:
         return "Elf";
         break;
 
     case 2:
         return "Dwarf";
         break;
 
     case 3:
         return "Human";
         break;
 
     case 4:
         return "Orc";
         break;
 
     case 5:
         return "Dragonborn";
         break;
 
     case 6:
         return "Gnome";
         break;
 
     case 7:
         return "Tiefling";
         break;
 
     case 8:
         return "Lizardfolk";
         break;
 
     case 9:
         return "Halfling";
         break;
     }
     return "Human";
 }
 
 // get string version of class
 string getClassString(int c)
 {
     switch (c) {
     case 1:
         return "Barbarian";
         break;
 
     case 2:
         return "Bard";
         break;
 
     case 3:
         return "Cleric";
         break;
 
     case 4:
         return "Druid";
         break;
 
     case 5:
         return "Fighter";
         break;

     case 6:
         return "Monk";
         break;
 
     case 7:
         return "Paladin";
         break;
 
     case 8:
         return "Ranger";
         break;
 
     case 9:
         return "Rogue";
         break;
 
     case 10:
         return "Wizard";
         break;
 
     case 11:
         return "Warlock";
         break;
     }
     return "Fighter";
 }
 
 // bandit Camp Quest
 int banditCampQuest(skillType& player)
 {
     class Bandit {
     public:
         string name;
         int hp;
         int attack;
 
         // Constructor
         Bandit(string n, int h, int a)
         {
             name = n;
             hp = h;
             attack = a;
         }
     };
     srand(time(0));
     char choice;
     int axeDamage = 5 + player.getStrength(); // Base damage of 5 + player's strength
     // Camp description
     cout << "You come across a secluded camp with a few bandits lounging around. There are some tents, a campfire, and barrels of loot stacked nearby.\n";
     cout << "The bandits seem to be guarding the area, but they are distracted by a game of dice. This could be your chance.\n";
     cout << "Do you want to:\n";
     cout << "A) Ignore the camp and continue on your travels.\n";
     cout << "B) Attempt to talk your way in and steal the loot.\n";
     cout << "C) Fight the bandits and claim the loot for yourself.\n";
     cin >> choice;
     choice = toupper(choice);
     while (choice != 'A' && choice != 'B' && choice != 'C') {
         resetStream();
         cout << "Sorry I don't understand. I was expecting a letter between A-C. Try again: ";
         cin >> choice;
         choice = toupper(choice);
     }
 
     if (choice == 'A') {
         cout << "You decide it's not worth the risk and move on.\n";
         return 1;
     }
 
     if (choice == 'B') {
         int charismaCheck = rand() % 20 + 1 + player.getCharisma();
 
         cout << "You approach the bandits, trying to talk your way in...\n";
         if (charismaCheck >= 17) {
             cout << "Your silver tongue convinces the bandits. You steal the loot without a fight!\n";
             cout << "The Two-Handed Axe you found has a base damage of 5, and it scales with your strength!\n";
             cout << "The axe's total damage is: " << axeDamage << "\n";
             cout << "you also obtain 50 gold and two health potions" << "\n";
             player.addGold(50);
             player.addItem("Two-Handed Axe");
             player.addItem("Health Potion");
             player.addItem("Health Potion");
             return 2;
         } else {
             cout << "The bandits see through your deception and grow suspicious...\n";
             choice = 'C'; // If charisma fails, the player is forced to fight.
         }
     }
 
     if (choice == 'C') {
         Bandit bandits[4] = { { "Bandit 1", 30, 5 }, { "Bandit 2", 25, 6 }, { "Bandit 3", 35, 4 }, { "Bandit Leader", 40, 8 } };
         int playerHP = 50;
         string weapon;
 
         cout << "Choose your weapon:\n";
         if (player.getRace() == "Elf") {
             weapon = "Bow";
         } else if (player.getRace() == "Orc") {
             weapon = "Axe";
         } else if (player.getRace() == "Human") {
             weapon = "Sword";
         } else {
             weapon = "Sword"; // Default if race is unspecified
         }
 
         cout << "You are armed with a " << weapon << "\n";
 
         // Combat loop
         while (playerHP > 0 && (bandits[0].hp > 0 || bandits[1].hp > 0 || bandits[2].hp > 0 || bandits[3].hp > 0)) {
             // Display Player and Bandit Health
             cout << "\nYour current health: " << playerHP << "\n";
             for (int i = 0; i < 4; i++) {
                 cout << bandits[i].name << " health: " << bandits[i].hp << "\n";
             }
 
             cout << "Choose a bandit to attack (A-D) or (I) to access invetory: ";
             char action;
             cin >> action;
             action = toupper(action);
             while (action != 'A' && action != 'B' && action != 'C' && action != 'D' && action != 'I') {
                 resetStream();
                 cout << "Sorry, I don't understand. Please enter a letter between A-D or I to access inventory: ";
                 cin >> action;
                 action = toupper(action);
             }
 
             if (action == 'I') {
                 if (player.getNumItems() > 0) {
                     cout << "Inventory: ";
                     player.printItem(); // Display inventory
                     cout << "\nSelect an item by number to use (1-" << player.getNumItems() << "): ";
                     int itemChoice;
                     cin >> itemChoice;
                     if (itemChoice >= 1 && itemChoice <= player.getNumItems()) {
                         string selectedItem = player.getItem(itemChoice - 1); // Get selected item
                         cout << "You used: " << selectedItem << "\n";
                         // Implement effects based on the item used (e.g., healing potion)
                         if (selectedItem == "Health Potion") {
                             playerHP += 20; // Example: Heal 20 HP
                             cout << "You restored 20 HP!\n";
                         }
                         // After using an item, continue to combat
                     } else {
                         cout << "Invalid choice.\n";
                     }
                 } else {
                     cout << "Your inventory is empty.\n";
                 }
                 continue; // After accessing inventory, the loop goes back to attacking
             } else if (action == 'A' || action == 'B' || action == 'C' || action == 'D') {
                 int target;
                 // Convert '1'-'4' to array index
                 if (action == 'A') {
                     target = 0;
                 } else if (action == 'B') {
                     target = 1;
                 } else if (action == 'C') {
                     target = 2;
                 } else {
                     target = 3;
                 }
 
                 if (bandits[target].hp > 0) {
                     int damage = rand() % 10 + 5 + player.getStrength();
                     bandits[target].hp -= damage;
                     cout << "You attack " << bandits[target].name << " for " << damage << " damage!\n";
                     if (bandits[target].hp <= 0) {
                         cout << bandits[target].name << " is defeated!\n";
                     }
                 }
             }
 
             // Bandits retaliate
             for (int i = 0; i < 4; i++) {
                 if (bandits[i].hp > 0) {
                     int enemyDamage = rand() % 6 + bandits[i].attack;
                     playerHP -= enemyDamage;
                     cout << bandits[i].name << " attacks you for " << enemyDamage << " damage!\n";
                 }
             }
 
             if (playerHP <= 0) {
                 cout << "You were defeated... Game over.\n";
                 return 3;
             }
         }
 
         // If the player wins the fight
         cout << "You defeated the bandits and claim the loot!\n";
 
         // Axe scales with player strength
         cout << "The Two-Handed Axe you found has a base damage of 5, and it scales with your strength!\n";
         cout << "The axe's total damage is: " << axeDamage << "\n";
         player.addGold(50);
         player.addItem("Two-Handed Axe (Damage: " + to_string(axeDamage) + ")");
         player.addItem("Health Potion");
         player.addItem("Health Potion");
     }
     return 4;
 } // end
 
 // Zach's story function
 void zechariahQuest(skillType& player)
 {
     char choice;
     char choiceOne;

     // Start of the Quest
     cout << "In the wee hours of the morning, as you pass by a village, a local dwarven man runs toward you, waving his arms frantically.";
     cout << "\nDwarven Man: 'Wait, please! I need your help. My wife was taken last night by a creature of the Hells. I don't have much to offer but this.'";
     cout << "\nHe holds up a strange-looking amulet, unlike anything you've ever seen before.";
     cout << "\nDwarven Man: 'Will you help me?'\n";
 
     // Dialog Options
     cout << "\nA) 'Piss off, peasant. I have no time for you.'";
     cout << "\nB) 'Well, she isn't going to save herself, is she?'";
     cout << "\nC) 'Sure, I guess.'";
     cout << "\nD) 'Describe the creature.'\n";
 
     cin >> choice;
     choice = toupper(choice); // Convert to uppercase for uniformity
     while (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D') {
         resetStream();
         cout << "Sorry, I don't understand. I was expecting a letter between A-D. Please try again: ";
         cin >> choice;
         choice = toupper(choice);
     }

     // Choice scenarios
     if (choice == 'A') {
         cout << "\nThe dwarven man looks down sadly toward the ground and walks away. You continue on your journey, indifferent to his plight.\n";
         return;
     } else {
         cout << "\nDwarven Man: 'Oh, thank you! Thank you! Sorry, I've been looking for aid all night. Follow me, and I'll show you where we were attacked.'";
     }
 
     // Describing the Beast
     cout << "\nHe leads you through the village. It's a small, bustling farming settlement. The roads are dirt, and the people are covered in filth.";
     cout << "\nOnce outside the village, he takes you to a narrow dirt road flanked by cornfields.";
     cout << "\nDwarven Man: 'It was here. My wife and I were walking home when a humanoid creature came running through the corn.'";
     cout << "\n'The creature threw me aside and grabbed my wife. As I tried to stand and fight for the love of my life, the bastard threw a knife at me, pinning me to the ground.'";
     cout << "\nHe shows you the knife. The handle is carved from bone, depicting lost souls in intricate engravings. The blade is iron not fancy, but well-maintained.";
     cout << "\nDwarven Man: 'That cursed blade held me in place too long. By the time I got free, the beast spread its wings ten to fifteen feet across and took off to the south.'";
     cout << "\n'Feel free to ask me anything. I'll help however I can.'\n";
 
     choice = 'Z'; // Reset choice variable
 
     while (choice != 'D') {
         cout << "\nDialog Options:";
         cout << "\nA) 'Can you describe the creature in more detail?'";
         cout << "\nB) 'Any idea where it could have gone?'";
         cout << "\nC) 'Come with me. I could use an assistant.'";
         cout << "\nD) 'I don't think you can help any more than you have.'\n";
         cin >> choice;
         choice = toupper(choice);
         while (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D') {
             resetStream();
             cout << "Sorry, I don't understand. I was expecting a letter between A-D. Please try again: ";
             cin >> choice;
             choice = toupper(choice);
         }
 
         // Choice option outcomes
         if (choice == 'A') {
             cout << "\nDwarven Man: 'Yes, I remember some details. The creature wore a strange hat with a short brim all around, but the back and most of the sides were folded up.'";
             cout << "\n'It wore the hat tilted slightly. Its skin was leathery, its eyes yellow. It stood about six or seven feet tall, and all its teeth were pointed grinning the whole time.'";
         } else if (choice == 'B') {
             cout << "\nDwarven Man: 'Well, there's a forest with caves to the south. That's my best guess. Many strange things happen there.'";
         } else if (choice == 'C') {
             cout << "\nDwarven Man: 'What?! No, no way! I have to watch over our children. That's why I was searching for help in the first place.'";
         }
     }
 
     // Quest Progression - Heading to the forest
     cout << "\nDwarven Man: 'When you find her, bring her back to our stead it's just up this road, you can't miss it.'";
     cout << "\nYou take a deep breath and set off toward the darkened forest, ready to face whatever lurks within...";
     cout << "\nAs you reach the forest it's now mid-day yet the forest is silent. No birds chirping, or bugs buzzing around. It's as if the forest is asleep.";
     cout << "\nAs you continue to wonder searching the woods you have a gut feeling you're being watched. Something somewhere is watching in silence.";
     cout << "\nYou hear a faint voice far in the distance. As you move towards it the voice becomes clearer. It's singing.";
     cout << "\nUp ahead you can see a old frail woman picking mushrooms and singing.";
     // Interaction options
     cout << "\nOptions: ";
     cout << "\nA) Announce yourself";
     cout << "\nB) Listen to her sing";
     cin >> choiceOne;
     choiceOne = toupper(choiceOne);
     while (choiceOne != 'A' && choiceOne != 'B') {
         resetStream();
         cout << "Sorry, I don't understand. I was expecting a letter between A-B. Please try again: ";
         cin >> choiceOne;
         choiceOne = toupper(choiceOne);
     }
 
     if (choiceOne == 'A') {
         cout << "\nShe stops singing. Slowly turn towards you. As she turns around you can see details on her face much clearer. She has leathery skin and yellow eyes.";
         cout << "\nIt grins and lifts its hand up and wiggles a finger at you as if your a child in trouble.";
         cout << "\nFrom under the creatures clothes it's winds rip through and it flys away heading further south.";
     } else {
         cout << "\nOut on the road, the night is long,";
         cout << "\nWheels keep turning, something's wrong.";
         cout << "\nShadows move where none should be,";
         cout << "\nA whisper calls...it's haunting me.";
         cout << "\nJeepers, Creepers, hide your eyes,";
         cout << "\nRun too slow, you'll say goodbye.";
         cout << "\nFeast on fear, I love the chase,";
         cout << "\nOnce you're seen, there's no escape.";
         cout << "\nOld church standing, dark and cold,";
         cout << "\nTrophies taken, stories told.";
         cout << "\nI smell the blood, I hear the cries,";
         cout << "\nA thousand souls behind my eyes.";
         cout << "\nJeepers, Creepers, hide your eyes,";
         cout << "\nRun too slow, you'll say goodbye.";
         cout << "\nFeast on fear, I love the chase,";
         cout << "\nOnce you're seen, there's no escape.";
         cout << "\nWhen the night is black as coal,";
         cout << "\nAnd the wind begins to moan...";
         cout << "\nIf you see my wicked grin,";
         cout << "\nPray to the Gods it's not your skin.";
         cout << "\nAs the song finishes you can see the leathery skin. Just as you realize that this is the creature. It's wings pop out of it's back and it takes off flying south.";
     }
 
     // The Church
     cout << "\nIf this creature can blend in as an old lady what other tricks may it have up its sleeve. With that taught you press on further south.";
 
     if (choiceOne == 'A') {
         cout << "\nAfter hours of walking you can see a large structure nestled in these woods. It's severely rundown with vines climbing up the sides as if the ground is about to swallow it whole.";
         cout << "\nAs you get closer the details become clearer. It's an abandoned church. There's no lights or sounds. Where the door once stood is a dark doorway. All of a sudden you can hear faint crying.";
     } else {
         cout << "\nAfter hours of walking you can see a large structure nestled in these woods. Immediately you recognize the building as the church depicted in the creature's song. This must be it's home.";
         cout << "\nVines climb the walls and where the door once stood is a dark doorway. All of a sudden you can hear faint crying.";
     }
 
     cout << "\nChoices: ";
     cout << "\nA) Comfort the crying voice";
     cout << "\nB) draw your weapon and slow follow the voice";
     cin >> choice;
     choice = toupper(choice);
     while (choice != 'A' && choice != 'B') {
         resetStream();
         cout << "Sorry, I don't understand. I was expecting a letter between A-B. Please try again: ";
         cin >> choice;
         choice = toupper(choice);
     }
 
     if (choice == 'A') {
         cout << "\nYou call out to attempt to comfort the voice. The crying stops and there is a moment of silence.";
         cout << "\nPlease whoever it is help me. I'm in the basement. Hurry before it comes back. P-P-Please.";
         cout << "\nThe voice is different from the one you heard in the forest. You draw your weapon to be safe and head to the basement.";
     } else {
         cout << "\nYou draw your weapon and slowly advance through the church. The crying persists and leads you to the basement.";
     }
 
     cout << "\nAs you slowly move down the stairs you can see something no words could ever properly describe. The walls and ceiling of the basement and covered in this creatures other victims.";
     cout << "\nThey are all stitched together like a fleshy tapestry. Some missing hands others missing eyes or even heads. This beast must reign from the hells.";
     cout << "\nThere is a table soaked in dried blood with leather straps to tie down it's victims. The shelves on the walls host a wide range of jars filled with a yellowish amber liquid containing eyes, and organs";
     cout << "\nTo the right are three cages one is empty the other two are occupied. One is the woman you are looking for crying the other has an old man sitting holding his legs like a scared child.";
     cout << "\nWoman: Please get us out of here before it comes back.";
     cout << "\nYou gather your thoughts and begin looking for keys...";
     cout << "\nYou scan the room, but there are no keys to be found the beast must keep them on it.";
     cout << "\n Choices: ";
     cout << "\nA) Wait for the beast to comeback and fight it for the keys";
     cout << "\nB) Leave you've seen enough";
     cout << "\nC) Use your weapon to break the locks";
     cin >> choice;
     choice = toupper(choice);
     while (choice != 'A' && choice != 'B' && choice != 'C') {
         resetStream();
         cout << "Sorry, I don't understand. I was expecting a letter between A-C. Please try again: ";
         cin >> choice;
         choice = toupper(choice);
     }
 
     if (choice == 'A') {
         cout << "\nYou take a seat on the stool waiting for the beasts return. The woman continuing to cry asks you what your doing saying it'll kill you.";
         cout << "\nYou decide to hide behind one of the cages waiting for it to come back. After a few hours you can hear heavy foot falls up stairs.";
         cout << "\n The beast comes down the stairs and stops. It stops and take a large breath in and looks through the cage directly at you. There is no hiding now.";
         cout << "\nYou jump out from cover weapon in hand and the beast throws two daggers one connects with your shoulder the other to your leg. The daggers send you to the wall pinned against it.";
         cout << "\nThe beast approaches you sniffing you up and down as if it's looking for something.";
         cout << "\nThe bease pulls back and grins and comes back this time licking you cheek like and ice cream cone.";
         cout << "\nThe beast takes it's large hands and puts one on either side of your head and twists.";
         return;

     } else if (choice == 'B') {
         cout << "\nThis is crazy. A beast from the hells why are you here. You turn around and run up the stairs. Behind you you can hear the woman begging for you to come back.";
         return;
     } else {
         cout << "\nYou take you weapon and give it a good swing on the locks freeing the two captives. The oldman looks at you with dispair.";
         cout << "\nTonights it's last night he says as he runs past you up the stairs and out of the church.";
         cout << "\nYou and the woman run out of the church and return to her homestead where her husband and children wait. The husband awards you with the amulet and says it's a goodluck charm.";
         return;
     }
 } // end
 
 // skill update function
 int statHandler(skillType& character, int index)
 {
     switch (index) {
     case 0:
         cout << "Your perception has been increased by 1." << endl;
         character.updateSkills(0, 1, 0, 0, 0, 0, 0);
         break;
     case 1:
         cout << "Your intelligence has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 0, 1, 0, 0);
         break;
     case 2:
         cout << "Your agility has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 0, 0, 1, 0);
         break;
     case 3:
         cout << "Your strength has been increased by 1." << endl;
         character.updateSkills(1, 0, 0, 0, 0, 0, 0);
         break;
     case 4:
         cout << "Your perception has been increased by 1." << endl;
         character.updateSkills(0, 1, 0, 0, 0, 0, 0);
         break;
     case 5:
         cout << "Your luck has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 0, 0, 0, 1);
         break;
     case 6:
         cout << "Your charisma has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 1, 0, 0, 0);
         break;
     case 7:
         cout << "Your agility has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 0, 0, 1, 0);
         break;
     case 8:
         cout << "Your intelligence has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 0, 1, 0, 0);
         break;
     case 9:
         cout << "Your endurance has been increased by 1." << endl;
         character.updateSkills(0, 0, 1, 0, 0, 0, 0);
         break;
     case 10:
         cout << "Your intelligence has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 0, 1, 0, 0);
         break;
     case 11:
         cout << "Your strength has been increased by 1." << endl;
         character.updateSkills(1, 0, 0, 0, 0, 0, 0);
         break;
     case 12:
         cout << "Your perception has been increased by 1." << endl;
         character.updateSkills(0, 1, 0, 0, 0, 0, 0);
         break;
     case 13:
         cout << "Your agility has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 0, 0, 1, 0);
         break;
     case 14:
         cout << "Your endurance has been increased by 1." << endl;
         character.updateSkills(0, 0, 1, 0, 0, 0, 0);
         break;
     case 15:
         cout << "Your luck has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 0, 0, 0, 1);
         break;
     case 16:
         cout << "Your charisma has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 1, 0, 0, 0);
         break;
     case 17: {
         cout << "Your strength has been increased by 1.\nYour endurance has been decreased by 1." << endl;
         character.updateSkills(1, 0, -1, 0, 0, 0, 0);
         break;
     }
     case 18:
         cout << "Your charisma has been increased by 1." << endl;
         character.updateSkills(0, 0, 0, 1, 0, 0, 0);
         break;
     }
     return 0;
 }
 
 // Josh's story quest
 int joshQuest(skillType& character, int index, int jndex, string selector)
 {
     resetStream();

     const int strength = character.getStrength();
     const int perception = character.getPerception();
     const int endurance = character.getEndurance();
     const int charisma = character.getCharisma();
     const int intelligence = character.getIntelligence();
     const int agility = character.getAgility();
     const int luck = character.getLuck();
     int i = index; // counts the index of the intro/story array
     int j = jndex; // counts the index of the choices/outcomes array
     int storyLength = 0; // used to the determine the length of the story array
     int introLength = 0; // used to the determine the length of the intro array
     string input; // used to store the user's input
     int ending = 7;
     int endingChoice = 4;
     int end = 10;
     bool artifact = false;

     string intro[] = {
         "In a world where ancient ruins whisper forgotten secrets and the skies burn with unnatural storms",
 
         "You awaken in a field of ash, a strange symbol glowing faintly on your hand",
 
         "The air is thick with tension, and the land feels alive, as if watching your every move",
 
         "A distant mountain looms on the horizon, its peak shrouded in swirling darkness",
 
         "With no memory of how you arrived, you take your first step into the unknown, the symbol pulsing faintly in time with your heartbeat",
         // intro prompts
     };
 
     string story[] = {
         "You awaken in a strange land, a glowing symbol on your hand and a distant mountain on the horizon",
 
         "The path splits: a dark forest to the left and a rocky canyon to the right",
 
         "A wounded traveler collapses at your feet, whispering about a 'key' hidden in the forest or canyon",
 
         "You reach a village under attack by shadowy creatures, the mountain looming closer",
 
         "A mysterious merchant offers you a strange artifact, claiming it will help you on your journey",
 
         "The mountain's entrance is sealed by a massive gate, covered in ancient runes",
 
         "Inside the mountain, you find a labyrinth filled with traps and strange whispers",
 
         "A voice echoes in the caverns, offering you power if you turn back",
 
         "You reach the heart of the mountain, where a swirling darkness pulses with energy",
 
         "The final choice: destroy the darkness once and for all or embrace its power",
     };
 
     string choices[] = {
         "Follow the symbol's pull toward the mountain",
 
         "Ignore the symbol and explore the nearby ruins",
 
         "Take the path through the dark forest",
 
         "Take the path through the rocky canyon",
 
         "Help the traveler and search for the 'key'",
 
         "Leave the traveler and continue on your journey",
 
         "Defend the village from the shadowy creatures",
 
         "Sneak past the village to avoid the danger",
 
         "Refuse the artifact and continue without it",
 
         "Accept the artifact and agree to the merchant's terms",
 
         "Decipher the runes to open the gate",
 
         "Attempt to break through the gate by force",
 
         "Solve the labyrinth's puzzles carefully",
 
         "Rush through the labyrinth, risking the traps",
 
         "Reject the voice's offer and press forward",
 
         "Consider the voice's offer and hesitate",
 
         "Use the artifact to expose the darkness",
 
         "Show the darkness who's boss!",
 
         "Destroy the corrupted heart and save the land",

         "Tell everyone you banished the darkness... for now...",
 
         // users input for choices here will always be 1 or 2, but my code will call the neccessary index of this array
     };
 
 
     string outcomes[] = {
         "The symbol guides you toward the mountain, increasing your Perception as you learn to trust its guidance",
 
         "The ruins hold ancient knowledge, increasing your Intelligence, but the journey is delayed",
 
         "The forest is eerie, but you find a hidden path, increasing your Agility as you navigate the terrain",
 
         "The canyon is treacherous, and you barely escape a rockslide, increasing your Strength from the effort",

         "The traveler reveals the 'key' and it is a map fragment, increasing your Perception, but you hear screaming in the distance...",

         "You avoid the traveler, increasing your Luck, but the path ahead is longer and more dangerous",
 
         "The villagers reward you with a clue about the mountain, increasing your Charisma, but the battle leaves you wounded",

         "You avoid the fight, increasing your Agility, but the shadowy creatures notice you and give chase",
 
         "The artifact helps you overcome obstacles, increasing your Intelligence, but the merchant's favor comes at a cost",

         "You avoid the merchant's debt, increasing your Endurance, but the journey becomes harder without the artifact",
 
         "You decipher the runes and open the gate, increasing your Intelligence, but it triggers a trap",

         "You break the gate, increasing your Strength, but the noise awakens a guardian that attacks you",
 
         "You solve the puzzles and find a safe path, increasing your Perception, but it takes time and effort",
 
         "You trigger traps but reach the end faster, increasing your Agility, though you are injured",
 
         "You resist the voice's temptation, increasing your Endurance, and gain clarity to face the final challenge",
 
         "The voice's offer distracts you, increasing your Luck, but you lose focus, making the final challenge harder",
 
         "The artifact weakens the darkness and exposes a corrupted heart, increasing your Charisma, but it shatters...",
 
         "You attempt to attack the darkness... but instead it is absorbed into the strange symbol on your wrist\n\nYou feel more... powerful... but the darkness begins to slowly corrupt you, reducing your Endurance but increasing your Strength",
 
         "[Good ending] The land is saved, increasing your Charisma as you are hailed as a hero, and the journey is one to remember...",
 
         "[Bad ending] The darkness is banished, however, it's influence begins to consume you for the unseeable future... You are a hero?... well.. we'll see...",
         // outcomes based on the user's choices
     };
 
     if (selector == "intro") { // determines the length of the array being used, for loop control
         introLength = sizeof(intro) / sizeof(intro[0]);
     } else if (selector == "story") {
         storyLength = sizeof(story) / sizeof(story[0]);
     }
 
     if (selector == "intro") {
 
         for (; i < introLength; i++) { // loops through the intro one prompt at a time, (requires user to hit enter to proceed)
             if (i + 1 != introLength) {
                 cout << "\n\n\n";
                 cout << intro[i] << endl;
 
 
 
 
                 cout << "\nPress enter to continue..." << endl;
 
 
 
 
                 getline(cin, input);
                 if (input.empty()) {
                     continue;
                 }
             }
 
             else { // this is just a prompt for the final line of the intro, it will only be displayed once
                 cout << "\n\n\n";
                 cout << intro[i] << endl;
                 cout << "\nPress enter TWICE to begin the story..." << endl;
 
                 getline(cin, input);
                 if (input.empty()) {
                     continue;
                 }
             }
         }
 
         index = 0;
         jndex = 0;
 
         joshQuest(character, index, jndex, "story"); // recursive function call to start the story
     }
 
     if (selector == "story") {
 
         int statIncreased;
 
         vector<int> history;
         while (i <= ending) {
             cout << "\n\n\n\n\n";
             cout << story[i] << endl;
             cout << "\n\n";
             cout << "\nWhat would you like to do?\n\n";
             cout << "1) " << choices[j] << endl;
             cout << "2) " << choices[j + 1] << endl;
             cout << "\nEnter 1 or 2 (enter \"back\" to return to the previous prompt): ";
 
             getline(cin, input);
             if (input == "1") {
                 cout << "\n\n\n";
                 cout << outcomes[j] << endl;
                 statHandler(character, j);
                 cout << "\nPress enter to continue..." << endl;
                 history.push_back(i);
                 i += 1;
                 j += 2;
                 getline(cin, input);
             } else if (input == "2") {
                 if (i == endingChoice)
                     artifact = true;
                 cout << "\n\n\n";
                 cout << outcomes[j + 1] << endl;
                 statHandler(character, j + 1);
                 cout << "\nPress enter to continue..." << endl;
                 history.push_back(i);
                 i += 1;
                 j += 2;
                 getline(cin, input);
                 if (input.empty())
                     continue;
                 else
                     cout << "Press enter to continue..." << endl;
             } else if (input == "back" && !history.empty()) {
                 i = history.back();
                 history.pop_back();
                 j -= 2;
             } else {
                 cout << "\n\n\n\n\nInvalid input, please choose 1 or 2.." << endl;
             }
         }
 
 
         while (i > ending && i != end) {
             cout << "\n\n\n\n\n";
             cout << story[i] << endl;
             cout << "\n\n";
             cout << "\nWhat would you like to do?\n\n";
             cout << "1) " << choices[j] << " [Artifact needed]" << endl;
             cout << "2) " << choices[j + 1] << endl;
             cout << "\nEnter 1 or 2: ";

             getline(cin, input);
             if (input == "1" && artifact) {
                 cout << "\n\n\n";
                 cout << outcomes[j] << endl;
                 statHandler(character, j);
                 cout << "\nPress enter to continue..." << endl;
                 i += 1;
                 j += 2;
                 getline(cin, input);
             } else if (input == "1" && !artifact) {
                 cout << "\n\n\n\n\nYou do not have the artifact (select option 2)" << endl;
             } else if (input == "2") {
                 cout << "\n\n\n";
                 cout << outcomes[j + 1] << endl;
                 statHandler(character, j + 1);
                 cout << "\nPress enter to continue..." << endl;
                 i += 1;
                 j += 2;
                 getline(cin, input);
                 if (input.empty())
                     continue;
             } else if (input == "back") {
                 cout << "\n\n\n\n\nYou cannot go back at this point in the story (please choose 1 or 2)" << endl;
             } else {
                 cout << "\n\n\n\n\nInvalid input, please choose 1 or 2" << endl;
             }
         }
         if (i == end)
             selector = "end";
     }
 
     if (selector == "end") {
         // prints updated stats
         cout << "Updated Stats:" << endl;
         cout << "Strength: " << strength << " + (" << character.getStrength() - strength << ")" << endl;
         cout << "Perception: " << perception << " + (" << character.getPerception() - perception << ")" << endl;
         cout << "Endurance: " << endurance << " + (" << character.getEndurance() - endurance << ")" << endl;
         cout << "Charisma: " << charisma << " + (" << character.getCharisma() - charisma << ")" << endl;
         cout << "Intelligence: " << intelligence << " + (" << character.getIntelligence() - intelligence << ")" << endl;
         cout << "Agility: " << agility << " + (" << character.getAgility() - agility << ")" << endl;
         cout << "Luck: " << luck << " + (" << character.getLuck() - luck << ")" << endl;
 
         getline(cin, input);
     }
     return -1;
 }
 
 
 //Wyatt's functions below
 int skillCheck(int difficulty, int skillLevel) {
     int roll = rand() % 20 + 1 + skillLevel;
     cout << "Rolling for skill check... You rolled: " << roll - skillLevel << " + " << skillLevel << " (skill) = " << roll << "\n";
     return roll >= difficulty;
 }
 
 
 void innScene(skillType& player) {
     cout << "You step into the warm glow of the inn, the scent of roasted meat and fresh bread filling the air.\n";
     cout << "The innkeeper eyes you as you approach the counter.\n\n";
     cout << "Innkeeper: 'Welcome, traveler! Would you like to rent a room for the night? It's 5 gold per night.'\n";
     cout << "(You currently have: " << player.getGold() << " gold)\n";
 
     char choice;
     cout << "A) Rent a room\nB) Decline and sit at a table\nC) Leave the inn\n";
     cin >> choice;
     choice = toupper(choice);
 
     while (choice != 'A' && choice != 'B' && choice != 'C') {
         cout << "Invalid choice. Please enter A, B, or C: ";
         cin >> choice;
         choice = toupper(choice);
     }
 
     if (choice == 'A') {
         if (player.getGold() >= 5) {
             player.addGold(-5);
             cout << "You hand over 5 gold and are given a comfortable room. After a full night's rest, you feel completely rejuvenated.\n";
             cout << "(Your HP and stats have been restored!)\n";
 
 
             cout << "Innkeeper: 'Oh, by the way, someone was asking about you after you retired. They're waiting at a table.'\n";
             cout << "You decide to approach the table.\n\n";
             tableScene(player);
         } else {
             cout << "Innkeeper: 'I'm sorry, but you don't have enough gold. However, you're welcome to sit at a table and order something to eat.'\n";
             cout << "You take a seat at a table.\n\n";
             tableScene(player);
         }
     } else if (choice == 'B') {
         cout << "You take a seat at a table.\n\n";
         tableScene(player);
     } else {
         cout << "You decide to leave the inn and continue your journey.\n";
     }
 }
 
 
 void tableScene(skillType& player) {
     cout << "As you sit at the table, a figure draped in a large cloak approaches and sits across from you.\n";
     cout << "Their features are obscured, and their presence is both mysterious and intriguing.\n\n";
     cout << "A) 'Who are you, and why are you sitting at my table?'\n";
     cout << "B) 'Excuse me, I think you have the wrong table.'\n";
     cout << "C) '...'\n";
 
 
     char choice;
     cin >> choice;
     choice = toupper(choice);
 
 
     while (choice != 'A' && choice != 'B' && choice != 'C') {
         cout << "Invalid choice. Please enter A, B, or C: ";
         cin >> choice;
         choice = toupper(choice);
     }
 
 
     cout << "Cloaked Man: ";
     if (choice == 'A') {
         cout << "'Just a guy looking to talk.'\n";
     } else if (choice == 'B') {
         cout << "'No, in fact, I think you're just the person I'm looking for.'\n";
     } else {
         cout << "'Not much for confrontation, huh? Me neither, to be honest.'\n";
     }
 
     cout << "The cloaked figure leans in slightly. 'I have a job for you. A simple retrieval task.'\n";
     cout << "'A group of thieves stole something precious from me, a polished silver pocket watch.'\n";
     cout << "'They've holed up in the forest outside of town. If you get it back, I'll pay you 110 gold.'\n";
     cout << "Do you accept the quest?\nA) Accept the job\nB) Refuse\n";
     cin >> choice;
     choice = toupper(choice);
 
 
     while (choice != 'A' && choice != 'B') {
         cout << "Invalid choice. Please enter A or B: ";
         cin >> choice;
         choice = toupper(choice);
     }
 
 
     if (choice == 'A') {
         cout << "'Great. I knew I saw a good person in ya.'\n";
         thiefForestScene(player);
     } else {
         cout << "You decline the offer, and the cloaked figure nods before leaving the table.\n";
     }
 }
 
 
 void thiefForestScene(skillType& player) {
     cout << "You make your way into the dense forest, searching for the thieves' hideout.\n";
 
 
     cout << "You approach the hideout and decide to listen in on a conversation.\n";
     bool success = skillCheck(15, player.getPerception());
 
 
     if (success) {
         cout << "You overhear the thieves discussing how the Cloaked Man never paid his debts.\n";
         playerSparedThieves = true;
     } else {
         cout << "You fail to make out any useful information.\n";
     }
 
 
     cout << "After sneaking in, you retrieve the polished silver pocket watch and return to the inn.\n";
 
 
     cout << "Cloaked Man: 'Did you take care of them?'\n";
 
 
     if (playerSparedThieves) {
         cout << "A) 'I didn't even have to kill them all.'\n";
     }
     cout << "B) 'Yes, it's been done.'\n";
 
 
     char choice;
     cin >> choice;
     choice = toupper(choice);
     while (choice != 'B') {
         cout << "Invalid choice. Please enter B: ";
         cin >> choice;
         choice = toupper(choice);
     }
 
 
     if (choice == 'A' && playerSparedThieves) {
         cout << "The cloaked man stiffens for a moment before hastily asking for the watch.\n";
         cout << "You hand it over, and he quickly drops a bag of 130 gold on the table before leaving.\n";
         player.addGold(130);
     } else {
         cout << "You hand over the watch and receive 110 gold in return.\n";
         player.addGold(110);
     }
 
 
     cout << "With that, the quest is complete.";
 }
 
 