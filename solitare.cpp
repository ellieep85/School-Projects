/* Program name: tictactoe.cpp
* Author: Ellie Pfeiffer
* Date last updated: 2/17/2020
* Purpose: Play the game of Tic-Tac-Toe                         
*/

#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;


//enum to represent the card suits
enum suitType  {
                 DIAMOND,
                 CLUBS,
                 HEARTS,
                 SPADES
                };
//const array to print the suits according to enum values
const int NUM_SUIT = 4;
const suitType suitIn[NUM_SUIT] = {DIAMOND, CLUBS, HEARTS, SPADES}; //gets enum value
const string suitStr[NUM_SUIT] = {"♦", "♣", "♥", "♠"}; //prints correctly

//enum for representing the card faces (Ace - King)
enum faceType  {
                 ACE,
                 TWO,
                 THREE,
                 FOUR,
                 FIVE,
                 SIX,
                 SEVEN,
                 EIGHT,
                 NINE,
                 TEN,
                 JACK,
                 QUEEN,
                 KING
                };
//const int and arrays to print cards and store their numerical values
const int NUM_FACE = 13;
const faceType faceIn[NUM_FACE] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING}; //allows to get enum values for cards
const string faceStr[NUM_FACE] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; //will allow me to print face correctly
const int faceValue[NUM_FACE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

//struct for enum values to be accessed by
struct cardType
{
    suitType suit;
    faceType face;
    bool used;
};

//struct for deck array
const int DECK_SIZE =52;
struct deckType
{
    cardType deck[DECK_SIZE];
    int cardsRemaining;
};

//function prototypes
void generateDeck(deckType&, int);
void generatefound1(cardType[]);
void generatefound2(cardType[]);
void generatefound3(cardType[]);
void generatefound4(cardType[]);
int getOption();
char startOrEndGame();
void getStartingCards(deckType&, cardType[], cardType[], cardType[], cardType[]);
string printFoundationFace(cardType[], int);
string printFoundationSuit(cardType[], int);
string printWasteFace(cardType[], int, int);
string printWasteSuit(cardType[], int, int);
void printPiles(cardType[], cardType[], cardType[], cardType[], cardType[], cardType[], cardType[], cardType[], int, int, int, int, int, int, int, int, deckType);
int firstPlay();
int firstCardEntered(deckType&);
string printCardFace(deckType, int);
string printCardSuit(deckType, int);
void playFirstCard(int, cardType[], cardType[], cardType[], cardType[], cardType[], cardType[], cardType[], cardType[], int&, int&, int&, int&, int&, int&, int&, int&, deckType&);
void resetStream();


int main()
{
    //variable declarations
    int option;
    char yesOrNo;
    deckType theDeck;
    int f1pos = 0;
    int f2pos = 0;
    int f3pos = 0;
    int f4pos = 0;
    int w1pos = 0;
    int w2pos = 0;
    int w3pos = 0;
    int w4pos = 0;
    int playOption;
    int cardNum;
    
    //foundation pile creations and initialization below 
    cardType found1[NUM_FACE];
    cardType found2[NUM_FACE];
    cardType found3[NUM_FACE];
    cardType found4[NUM_FACE];
    
    generatefound1(found1);
    generatefound2(found2);
    generatefound3(found3);
    generatefound4(found4);
    
    //waste pile creation below 
    //initialized to DECK_SIZE so they could play entire deck on pile if they wanted to
    cardType waste1[DECK_SIZE];
    cardType waste2[DECK_SIZE];
    cardType waste3[DECK_SIZE];
    cardType waste4[DECK_SIZE];
    
    //deck creation below
    generateDeck(theDeck, DECK_SIZE);
    
    cout << "Welcome to Calculation!" << endl;
    
    option = getOption();
    
    //this if statement allows the program to progress according to the first option
    if(option == 1)
    {
        yesOrNo = startOrEndGame();
        //this will allow the program to terminate if N is entered to the console
        //if Y is entered program will continue in main
        if(yesOrNo == 'N')
        {
            return 0;
        }
    }
    //this is printed if second option is chosen
    else if(option == 2)
    {
       cout << "Options Menu: " << endl;
       cout << "1. Enable ASCII Cards " << endl;
       cout << "2. Display Stats " << endl;
    }
    //terminates program is third option is selected
    else if(option == 3)
    {
        return 0;
    }
    
   
    getStartingCards(theDeck, found1, found2, found3, found4);
    
    printPiles(found1, found2, found3, found4, waste1, waste2, waste3, waste4, f1pos, f2pos, f3pos, f4pos, w1pos, w2pos, w3pos, w4pos, theDeck);
    cout << "Remaining cards (" << theDeck.cardsRemaining << ")" << endl;
    
    while(playOption != -1)
    {
        playOption = firstPlay();
        
        if(playOption == -1) //this will present the starting options again if they input -1
        {
        cout << "Welcome to Calculation!" << endl;
    
        option = getOption();
    
        if(option == 1)
        {
        yesOrNo = startOrEndGame();
        
        if(yesOrNo == 'N')
        {
            return 0;
        }
        }
        else if(option == 2)
        {
            cout << "Options Menu: " << endl;
            cout << "1. Enable ASCII Cards " << endl;
            cout << "2. Display Stats " << endl;
        }
        else if(option == 3)
        {
            return 0;
        }
        }
        else
        //gets card num
        cardNum = firstCardEntered(theDeck);
        
        //updates foundation pils and prints pulled card
        printPiles(found1, found2, found3, found4, waste1, waste2, waste3, waste4, f1pos, f2pos, f3pos, f4pos, w1pos, w2pos, w3pos, w4pos, theDeck);
        cout << "Drawn Card: ";
        printCardFace(theDeck, cardNum);
        printCardSuit(theDeck, cardNum);
        cout << endl;
        
        //next part of game play (playing the firt card pulled) I'm not making a function for this because that ended up being a waste of time..
        cout << "What would you like to do: (Enter -1 to quit)" << endl;
        cout << "1. Play Drawn Card" << endl;
        cin >> playOption;
        while(!cin || playOption > 1 || playOption < -1)
        {
            if(!cin)
            {
                resetStream();
                cout << "You entered something that is not a number. Please try again." << endl;
                cin >> playOption;
            }
            else if(playOption > 1 || playOption < -1)
            {
                resetStream();
                cout << "That is not a valid entry. Please try again." << endl;
                cin >> playOption;
            }
        }
        if(playOption == -1) //this will present the starting options again if they input -1
        {
        cout << "Welcome to Calculation!" << endl;
    
        option = getOption();
    
        if(option == 1)
        {
        yesOrNo = startOrEndGame();
        
        if(yesOrNo == 'N')
        {
            return 0;
        }
        }
        else if(option == 2)
        {
            cout << "Options Menu: " << endl;
            cout << "1. Enable ASCII Cards " << endl;
            cout << "2. Display Stats " << endl;
        }
        else if(option == 3)
        {
            return 0;
        }
        }
        else
        playFirstCard(cardNum, found1, found2, found3, found4, waste1, waste2, waste3, waste4, f1pos, f2pos, f3pos, f4pos, w1pos, w2pos, w3pos, w4pos, theDeck);
        
        //this will allow me to loop through gameplay until cards run out
        while(theDeck.cardsRemaining != 0)
        {
            //put funct here
        }
    }
    

    return 0;
}

//functions below_________________________________________________________________

//this function generates the deck and initialized the remaining cards
void generateDeck(deckType &theDeck, int deckSize)
{
    //deck creation below
    for(int i = 0; i < NUM_SUIT; i++)
    {
        for(int j = 0; j < NUM_FACE; j++)
        {
            theDeck.deck[i * 13 + j].suit = suitIn[i];
            theDeck.deck[i*13 + j].face = faceIn[j];
            theDeck.deck[i*13 + j].used = false;
        }
    }
    theDeck.cardsRemaining = deckSize;
}

//this function initializes the faces for foundation 1
void generatefound1(cardType found1[NUM_FACE])
{
    int count = 0;
    int i = 0;
    for(count; count < NUM_FACE; i = i + 1)
    {
        found1[count].face = faceIn[i%13];
        count++;
    }
}

//this function initializes the second foundation pile
void generatefound2(cardType found2[NUM_FACE])
{
    int count = 0;
    int i = 2;
    for(count; count < NUM_FACE; i = i + 2)
    {
        found2[count].face = faceIn[i%13];
        count++;
    }
}

//this function generates the third foundation pile
void generatefound3(cardType found3[NUM_FACE])
{
    int count = 0;
    int i = 3;
    for(count; count < NUM_FACE; i = i + 3)
    {
        found3[count].face = faceIn[i%13];
        count++;
    }
}

//this function generates the fourth foundation pile
void generatefound4(cardType found4[NUM_FACE])
{
   int count = 0;
   int i = 4;
   for(count; count < NUM_FACE; i = i + 4)
   {
       found4[count].face = faceIn[i%13];
       count++;
   }
}

//this function prints the prompt list to the user
//it does user validation 
//and returns the option they selected as an int
int getOption()
{
    int userchoice;
    
    cout << "1. Play Game" << endl;
    cout << "2. Options" << endl;
    cout << "3. Quit" << endl;
    cin >> userchoice;
    
    while(!cin || userchoice < 1 || userchoice > 3)
    {
       if(!cin) 
       {
           resetStream();
           cout << "You entered something that isn't a number. Please try again. " << endl;
           cout << "1. Play Game" << endl;
           cout << "2. Options" << endl;
           cout << "3. Quit" << endl;
           cin >> userchoice;
       }
       else
       {
          resetStream();
          cout << "Please enter an option from the menu. " << endl;
          
          cout << "1. Play Game" << endl;
          cout << "2. Options" << endl;
          cout << "3. Quit" << endl;
          cin >> userchoice;
       }
    }
    return userchoice;
}


//this function prompts the user to input if they are ready to start the game or not
//it does user validation
//then returns the user's choice
char startOrEndGame()
{
    char answer;
    cout << "Are you ready to play? ";
    cin >> answer;
    answer = toupper(answer);
    
    while(answer != 'Y' && answer != 'N')
    {
        if(answer != 'Y' && answer != 'N')
        {
            resetStream();
            cout << "I don't understand. I was expecting Y or N. " << endl;
             cout << "Are you ready to play? ";
             cin >> answer;
             answer = toupper(answer);
        }
    }
    
    return answer;
}

//This function gets the starting cards for the four foundation piles and does input validation
void getStartingCards(deckType &theDeck, cardType found1[NUM_FACE], cardType found2[NUM_FACE], cardType found3[NUM_FACE], cardType found4[NUM_FACE])
{
    int playerCard;
    cout << "Enter the card number for the starting A: ";
    cin >> playerCard;
    cout << endl;
    while(theDeck.deck[playerCard].face != ACE)
    {
        if(theDeck.deck[playerCard].face != ACE)
        {
            resetStream();
            cout << "That is not a valid card. Please try again. " << endl;
            cout << "Enter the card number for the starting A: ";
            cin >> playerCard;
            cout << endl;
        }
    }
    found1[0] = theDeck.deck[playerCard];
    theDeck.deck[playerCard].used = true;
    theDeck.cardsRemaining = theDeck.cardsRemaining - 1;
    
    cout << "Enter the card number for the starting 2: ";
    cin >> playerCard;
    cout << endl;
    while(theDeck.deck[playerCard].face != TWO)
    {
        if(theDeck.deck[playerCard].face != TWO)
        {
           resetStream();
           cout << "That is not a valid card. Please try again. " << endl;
           cout << "Enter the card number for the starting 2: ";
           cin >> playerCard;
           cout << endl;
        }
    }
    found2[0] = theDeck.deck[playerCard];
    theDeck.deck[playerCard].used = true;
    theDeck.cardsRemaining = theDeck.cardsRemaining - 1;
    
    cout << "Enter the card number for the starting 3: ";
    cin >> playerCard;
    cout << endl;
    while(theDeck.deck[playerCard].face != THREE)
    {
        if(theDeck.deck[playerCard].face != THREE)
        {
            resetStream();
            cout << "That is not a valid card. Please try again. " << endl;
            cout << "Enter the card number for the starting 3: ";
            cin >> playerCard;
            cout << endl;
        }
    }
    found3[0] = theDeck.deck[playerCard];
    theDeck.deck[playerCard].used = true;
    theDeck.cardsRemaining = theDeck.cardsRemaining - 1;
    
    cout << "Enter the card number for the starting 4: ";
    cin >> playerCard;
    cout << endl;
    while(theDeck.deck[playerCard].face != FOUR)
    {
        if(theDeck.deck[playerCard].face != FOUR)
        {
            resetStream();
            cout << "That is not a valid card. Please try again. " << endl;
            cout << "Enter the card number for the starting 4: ";
            cin >> playerCard;
            cout << endl;
        }
    }
    found4[0] = theDeck.deck[playerCard];
    theDeck.deck[playerCard].used = true;
    theDeck.cardsRemaining = theDeck.cardsRemaining - 1;
}

//this function will take the face value from the foundation piles and print it
string printFoundationFace(cardType foundation[NUM_FACE], int fcard)
{
    cout << faceStr[foundation[fcard].face]; 
    return faceStr[foundation[fcard].face];
}

//this function takes the suit value from the foundation piles and prints it
string printFoundationSuit(cardType foundation[NUM_FACE], int fcard)
{
    cout << suitStr[foundation[fcard].suit];
    return suitStr[foundation[fcard].suit];
}

//this function prints the face of the card on the waste pile
string printWasteFace(cardType waste[DECK_SIZE], int wcard, int position)
{
    if(position == 0)
    {
        return " ";
    }
    else
    cout << faceStr[waste[wcard].face];
    return faceStr[waste[wcard].face];
}

//this function prints the correct suit for the card on the waste pile
string printWasteSuit(cardType waste[DECK_SIZE], int wcard, int position)
{
    if(position == 0)
    {
        return " ";
    }
    else
    cout << suitStr[waste[wcard].suit];
    return suitStr[waste[wcard].suit];
}

//this function will do all the updating output for the piles and remaining cards
void printPiles(cardType found1[NUM_FACE], cardType found2[NUM_FACE], cardType found3[NUM_FACE], cardType found4[NUM_FACE], 
cardType waste1[DECK_SIZE], cardType waste2[DECK_SIZE], cardType waste3[DECK_SIZE], cardType waste4[DECK_SIZE], int f1pos, int f2pos,
int f3pos, int f4pos, int w1pos, int w2pos, int w3pos, int w4pos, deckType theDeck)
{
    cout << "F1: ";
    printFoundationFace(found1, f1pos);
    printFoundationSuit(found1, f1pos);
    cout << "   ";
    
    cout << "F2: ";
    printFoundationFace(found2, f2pos);
    printFoundationSuit(found2, f2pos);
    cout << "   ";
    
    cout << "F3: ";
    printFoundationFace(found3, f3pos);
    printFoundationSuit(found3, f3pos);
    cout << "   ";
    
    cout << "F4: ";
    printFoundationFace(found4, f4pos);
    printFoundationSuit(found4, f4pos);
    cout << endl;
    
    cout << "W1: ";
    printWasteFace(waste1, w1pos, w1pos);
    printWasteSuit(waste1, w1pos, w1pos);
    cout << "   ";
    
    cout << "W2: ";
    printWasteFace(waste2, w2pos, w2pos);
    printWasteSuit(waste2, w2pos, w2pos);
    cout << "   ";
    
    cout << "W3: ";
    printWasteFace(waste3, w3pos, w3pos);
    printWasteSuit(waste3, w3pos, w3pos);
    cout << "   ";
    
    cout << "W4: ";
    printWasteFace(waste4, w4pos, w4pos);
    printWasteSuit(waste4, w4pos, w4pos);
    cout << endl;
    
   // cout << "Remaining cards (" << theDeck.cardsRemaining << ")" << endl;
    
}

//this does the first card draw of the game and input validation
int firstPlay()
{
    int playOption;
    cout << "What would you like to do: (Enter -1 to quit)" << endl; //the very first card I am programming into main for convenience
    cout << "1. Draw Card" << endl;
    cin >> playOption;
    while(!cin || playOption > 1 || playOption < -1) //input validation
    {
        if(!cin)
        {
            resetStream();
            cout << "You entered something that is not a number. Please try again." << endl;
            cout << "1. Draw Card" << endl;
            cin >> playOption;
        }
        else
        {
            resetStream();
            cout << "You have entered an invalid number. Please try again" << endl;
            cout << "1. Draw Card" << endl;
            cin >> playOption;
        }
    }
    return playOption;
}

//this gets the number for the first card drawn
int firstCardEntered(deckType &theDeck)
{
    int cardNum;
    cout << "Enter the card number for the drawn card: ";
        cin >> cardNum;
        cout << endl;
        while(!cin || cardNum < 0 || cardNum > DECK_SIZE || theDeck.deck[cardNum].used != false)
        {
            if(!cin)
            {
                resetStream();
                cout << "You entered something that is not a number. Please try again" << endl;
                cin >> cardNum;
            }
            else if(cardNum < 0 || cardNum > DECK_SIZE)
            {
                resetStream();
                cout << "That is not a valid card number. Please enter a different card." << endl;
                cin >> cardNum;
            }
            else
            {
                resetStream();
                cout << "That card has already been played. Please enter a different card." << endl;
                cin >> cardNum;
            }
        }
        theDeck.cardsRemaining = theDeck.cardsRemaining - 1;
        theDeck.deck[cardNum].used = true;
        return cardNum;
}

//the next two functions are for printing the card faces and suits
string printCardFace(deckType theDeck, int cardNum)
{
    cout << faceStr[theDeck.deck[cardNum].face];
    return faceStr[theDeck.deck[cardNum].face];
}

string printCardSuit(deckType theDeck, int cardNum)
{
    cout << suitStr[theDeck.deck[cardNum].suit];
    return suitStr[theDeck.deck[cardNum].suit];
}

//this function takes the first card drawn and asks the player which pile they want to play it on and updates the piles
void playFirstCard(int cardNum, cardType found1[], cardType found2[], cardType found3[], cardType found4[], 
cardType waste1[], cardType waste2[], cardType waste3[], cardType waste4[], int &f1pos, int &f2pos, int & f3pos, int &f4pos, int &w1pos, 
int &w2pos, int &w3pos, int &w4pos, deckType &theDeck)
{
    char foundOrWaste;
    int pileNum = 0;
    cout << "Do you want to play on a:" << endl;
    cout << "F. Foundation Pile" << endl;
    cout << "W. Waste Pile" << endl;
    cin >> foundOrWaste;
    foundOrWaste = toupper(foundOrWaste);
    while(foundOrWaste != 'W' && foundOrWaste != 'F')
    {
        if(foundOrWaste != 'W' && foundOrWaste != 'F')
        {
            resetStream();
            cout << "I don't understand. I was expecting F or W." << endl;
            cout << "Do you want to play on a:" << endl;
            cout << "F. Foundation Pile" << endl;
            cout << "W. Waste Pile" << endl;
            cin >> foundOrWaste;
            foundOrWaste = toupper(foundOrWaste);
        }
    }
    if(foundOrWaste == 'F')
    {
    cout << "Which foundation pile (1-4) do you want to play on? ";
    cin >> pileNum;
    while(pileNum > 4 || pileNum < 1)
    {
        if(pileNum > 4 || pileNum < 1)
        {
            resetStream();
            cout << "That is not a valid entry. Please try again.";
            cout << "Which foundation pile (1-4) do you want to play on? ";
            cin >> pileNum;
        }
    }
    if(pileNum == 1)
    {
        f1pos++;
        found1[f1pos] = theDeck.deck[cardNum];
        
    }
    else if(pileNum == 2)
    {
        f2pos++;
        found2[f2pos] = theDeck.deck[cardNum];
    }
    else if(pileNum == 3)
    {
        f3pos++;
        found3[f3pos] = theDeck.deck[cardNum];
        
    }
    else if(pileNum == 4)
    {
        f4pos++;
        found4[f4pos] = theDeck.deck[cardNum];
        
    }
    }

    else if(foundOrWaste == 'W')
    {
       cout << "Which waste pile (1-4) do you want to play on? ";
       cin >> pileNum; 
       while(pileNum > 4 || pileNum < 1)
    {
        if(pileNum > 4 || pileNum < 1)
        {
            resetStream();
            cout << "That is not a valid entry. Please try again.";
            cout << "Which waste pile (1-4) do you want to play on? ";
            cin >> pileNum;
        }
    }
    if(pileNum == 1)
    {
        w1pos++;
        waste1[w1pos] = theDeck.deck[cardNum];
    }
    else if(pileNum == 2)
    {
        w2pos++;
        waste2[w2pos] = theDeck.deck[cardNum];
    }
    else if(pileNum == 3)
    {
        w3pos++;
        waste3[w3pos] = theDeck.deck[cardNum];
    }
    else if(pileNum == 4)
    {
        w4pos++;
        waste4[w4pos] = theDeck.deck[cardNum];
    }
    }
    
    printPiles(found1, found2, found3, found4, waste1, waste2, waste3, waste4, f1pos, f2pos, f3pos, f4pos, w1pos, w2pos, w3pos, w4pos, theDeck);
    cout << "Remaining cards (" << theDeck.cardsRemaining << ")" << endl;
}

//this is a function for input validation
void resetStream()
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}













