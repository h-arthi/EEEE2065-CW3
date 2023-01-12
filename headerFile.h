#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

class adventureGame{

private:

    string command;//stores user command
    string prevCommand;
    int room = 0;//initializing the first room to 1, changes based where user goes
    int win = 0;//indicates if player has won the game
    string noEntry = "This room is locked";
    string Entry = "Room to the basement is unlocked, you go south to the basement.";
    int player_health = 12;//initializing health of player
    int player_score = 0;//initializing score of player
    string player_choice;//takes user command for attacks
    int player_attack = 1;//initial player attack


    /**********Room Environments***********/
    string lookArray[9]={
        "You are in the entrance.Dining room lies in the east.",
        "You are in the dining room.Courtyard lies in the east, entrance lies in the west and a library in the south",
        "You are in the courtyard.Dining room lies in the west.",
        "You are in the outhouse.Library lies in the east, and kitchen in the south",
        "You are in the library.Bedroom lies in the east, outhouse lies in the west, dining room lies north of you and a ballroom at your south",
        "You are in the bedroom.Library lies in the west and basement in the south",
        "You are in the kitchen.Outhouse lies in the north",
        "You are in the ballroom.Library lies in the north",
        "You are in the basement.Bedroom lies in the north"
    };

    /**2D-Array where the first dimension is each room, and the second dimension is each direction to move**/
    string moveArray[9][4]{
        //0-north,1-south,2-east,3-west
        {"You cannot go north","You cannot go south","You go east to the dining room","You cannot go west"},
        {"You cannot go north","You go south to the library","You go east to the courtyard","You go west to the entrance"},
        {"You cannot go north","You cannot go south","You cannot go east","You go west to the dining room"},
        {"You cannot go north","You go south to the kitchen","You go east to the library","You cannot go west"},
        {"You go north to the dining room","You go south to the ballroom","You go east to the bedroom","You go west to the outhouse"},
        {"You cannot go north",noEntry,"You cannot go east","You go west to the library"},
        {"You go north to the outhouse","You cannot go south","You cannot go east","You cannot go west"},
        {"You go north to the library","You cannot go south","You cannot go east","You cannot go west"},
        {"You go north to the bedroom","You cannot go south","You cannot go east","You cannot go west"}
    };

    /***********Destination Room to move to************/
    /**Each number represents the room you want to move to**/
    int moveToArray[9][4]={
        {-1,-1,1,-1},
        {-1,4,2,0},
        {-1,-1,-1,1},
        {-1,6,4,-1},
        {1,7,5,3},
        {-1,-1,-1,4},
        {3,-1,-1,-1},
        {4,-1,-1,-1},
        {5,-1,-1,-1}
        };


    /**Everything Monster Related here**/
    //types of monsters corresponds to monster in each room
    string monsterArray[9]={" "," ","Zombie"," ","Lizard-man","Monster","Dracula","Werewolf","Dragon"};
    //monster display
    string killedMonster[9]={" "," ",
            "I'll miss eating brains\n"," ","Although I should regenerate being part lizard, I am still part man\n",
            "I just wanted a friend why?!\n","Bring me to the sunlight one last time\n",
            "You have freed me from my curse, I can look at the moon again\n","Hssss-you will not take my preciousssss\n"};
    //determines if the monster is dead or alive
    int monsterStatusArray[9]={-1,-1,1,-1,1,1,1,1,1};
    //indicates monster health, -1 means theres is no monster
    int monsterHealth[9]={-1,-1,6,-1,5,4,12,12,12};
    //monster attack damage
    int monsterAttack[9]={-1,-1,1,-1,2,2,2,2,3};
    vector<string> monstersKilled;//listing down all the monsters killed


    /**Everything Artifact related here**/
    int food = 5;//player hp if they use
    int medpack = 10;//player hp if they use
    int elixir = 10;//player hp if they use
    int N_artifact = 9;
    string artifact[9] ={" ", "Food","Silver Spear","Medpack","Sword","Elixir","Copper Key","Diamond Cross","Golden Chalice"};
    //room number in which the artifact is located
    //using -1 to indicate artifact is in the player's possession
    //using -2 to indicate the artifact is gone and no longer available in the game
    int artifactLoc[9] = {0,1,2,3,4,5,6,7,8};
    vector<string> Pinventory;//declaring a vector here to store player items
    vector<string> ExInventory;//stores everything player has collected and dropped throughout the game


public:

    /**get command function declared here**/
    int getCommand(){

        if(player_health > 0){
            if(win == 1){
                cout<<"\n\tCongratulations Player you survived Agaroth\n"<<endl;
                cout<<"\n\tYou are free to leave now\n"<<endl;
                printStatus();
                command = "exit";
                return(0);
            }
            cout<<"\nEnter Command:\n";
            getline(cin, command);//take single word commands using cin
            return(1);
        }
        else{
            cout<<"\n\tPlayer did not survive\n"<<endl;
            win = -1;
            printStatus();
            command = "exit";
            return(0);
        }
    }


    /**Declaring Functions here**/
    int processCommand();
    int processMovement();
    int processLook();
    int processKillMonster();
    int processKillDracula();
    int processKillWerewolf();
    int processKillLizard();
    int processKillZombie();
    int processKillDragon();
    int processGet(string object);
    int processDrop(string object);
    int restoreHealth(string restore);
    int checkWeapon(string weapon_choice);
    int removeWeapon(string weapon_choice);
    int checkInventory(string checking);
    int checkVictory();
    int attack();
    void convertToLower(string &object);
    void convertToCap(string &object);
    void printStatus();
    void helpPlayer();
    void inventory();






};
