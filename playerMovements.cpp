#include "headerFile.h"


/**This function takes no input but returns a value to ensure the game is still being played until exit command**/
/**Gives a description of the room user is in**/
int adventureGame::processLook(){

    cout<< lookArray[room]<<endl;

    /**MONSTER CODE**/
    //Indicates if there is a monster in the room
    if(monsterStatusArray[room]==1){
            cout<<"There is a "<<monsterArray[room]<< " here"<<endl;
    }
    else if(monsterStatusArray[room]==0){
            cout<<"There is a dead "<<monsterArray[room]<< " here"<<endl;
    }

    /**ARTIFACT CODE**/
    //adding artifacts in each room
    for(int i=0;i<N_artifact;i++){
        if(artifactLoc[i]==room && artifact[i]!=" "){
            cout<<"You see a "<<artifact[i]<<" here"<<endl;
        }
    }
    return(1);
}


/**This function takes no input but returns a value to ensure the game is still being played until exit command**/
/**Moves the player from room to room**/
int adventureGame::processMovement() {

    //moves north
    if(command=="north" || command=="n") {
    cout << moveArray[room][0] << endl;
        if (moveToArray[room][0]!=-1) {
            room = moveToArray[room][0];
            processLook();

        }
        return(1);
    }

    //moves south
    else if(command=="south" || command=="s") {
        cout << moveArray[room][1] << endl;
        if (moveToArray[room][1]!=-1) {
            room = moveToArray[room][1];
            processLook();
        }
        return(1);
    }

    //moves east
    else if(command=="east" || command=="e") {
        cout << moveArray[room][2] << endl;
        if (moveToArray[room][2]!=-1) {
            room = moveToArray[room][2];
            processLook();
        }
        return(1);
    }

    //moves west
    else if(command=="west" || command=="w") {
        cout << moveArray[room][3] << endl;
        if (moveToArray[room][3]!=-1) {
            room = moveToArray[room][3];processLook();
        }
        return(1);
    }

    else return(0);
}

/**This function checks if the player won and exit the game, takes not input returns 1**/
int adventureGame::checkVictory(){

    for(long long unsigned int i=0;i<Pinventory.size();i++){
        convertToLower(Pinventory[i]);
    }
    auto victory = find(Pinventory.begin(),Pinventory.end(),"golden chalice");
    if(victory==Pinventory.end()){
        //this means player has not won yet because they don't have the golden chalice
    }
    else{
        //if they do have the golden chalice check if they are at the entrance, if they are they win
        if(room==0){//they have reached the entrance with gc
            cout<<"Congratulations player you made it out alive!"<<endl;
            win = 1;
            return(0);
        }
        else{
            //they are not in the entrance so they don't win yet
            //cout<<"Go to entrance to win"<<endl;
        }
    }

    return(1);
}

/**This function displays the player stats takes no input and returns no value**/
void adventureGame::printStatus(){

    if(win == 0){
        cout<<"\n---------PLAYER STATS----------"<<endl;
        cout<<"\n\tPlayer XP: "<<player_score<<endl;
        cout<<"\n\tPlayer HP: "<<player_health<<endl;
        cout<<"\n\tPlayer Attack: "<<player_attack<<endl;
        cout<<"-------------------------------"<<endl;
    }

    else{
        cout<<"\n\t---------PLAYER STATS----------"<<endl;
        cout<<"\n\t\tPlayer XP: "<<player_score<<endl;
        cout<<"\n\t\tPlayer HP: "<<player_health<<endl;
        cout<<"\n\t\tYou killed these monsters: "<<endl;
        for(long long unsigned int i=0,j=0;i<monstersKilled.size();i++){
            cout<<"\t\t"<<++j <<" "<<monstersKilled[i]<<endl;
        }
        cout<<"\n\t\tYou collected these treasures throughout the game: "<<endl;
        for(long long unsigned int i=0,j=0;i<ExInventory.size();i++){
            cout<<"\t\t"<<++j <<" "<<ExInventory[i]<<endl;
        }
        cout<<"\t-------------------------------"<<endl;
    }

}

/**This function is to list the commands, takes not input and returns no value**/
void adventureGame::helpPlayer(){
    cout<<"\n\t|----------------------List of Commands and functions-------------------------|"<<endl;
    cout<<"\t|1. Kill/Fight Commands:                                                      |"<<endl;
    cout<<"\t|       -killMonster or km                                                    |"<<endl;
    cout<<"\t|       -killWerewolf or kw                                                   |"<<endl;
    cout<<"\t|       -killZombie or kz                                                     |"<<endl;
    cout<<"\t|       -killDracula or kd                                                    |"<<endl;
    cout<<"\t|       -killLizard or kl                                                     |"<<endl;
    cout<<"\t|       -killDragon or kD                                                     |"<<endl;
    cout<<"\t|2. Movement Commands:                                                        |"<<endl;
    cout<<"\t|       -north or n                                                           |"<<endl;
    cout<<"\t|       -south or s                                                           |"<<endl;
    cout<<"\t|       -east or e                                                            |"<<endl;
    cout<<"\t|       -west or w                                                            |"<<endl;
    cout<<"\t|3. Get Commands:                                                             |"<<endl;
    cout<<"\t|       -get diamond cross                                                    |"<<endl;
    cout<<"\t|       -get sword                                                            |"<<endl;
    cout<<"\t|       -get silver spear                                                     |"<<endl;
    cout<<"\t|       -get golden chalice                                                   |"<<endl;
    cout<<"\t|       -get copper key                                                       |"<<endl;
    cout<<"\t|       -get elixir                                                           |"<<endl;
    cout<<"\t|       -get food                                                             |"<<endl;
    cout<<"\t|       -get medpack                                                          |"<<endl;
    cout<<"\t|4. Drop Commands:                                                            |"<<endl;
    cout<<"\t|       -drop diamond cross                                                   |"<<endl;
    cout<<"\t|       -drop sword                                                           |"<<endl;
    cout<<"\t|       -drop silver spear                                                    |"<<endl;
    cout<<"\t|       -drop golden chalice                                                  |"<<endl;
    cout<<"\t|5. Healing Commands:                                                         |"<<endl;
    cout<<"\t|       -use medpack                                                          |"<<endl;
    cout<<"\t|       -eat food                                                             |"<<endl;
    cout<<"\t|       -drink elixir                                                         |"<<endl;
    cout<<"\t|6. Inventory Commands:                                                       |"<<endl;
    cout<<"\t|       -inventory or i                                                       |"<<endl;
    cout<<"\t|7. Unlock Commands:                                                          |"<<endl;
    cout<<"\t|       -unlock door                                                          |"<<endl;
    cout<<"\t|8. Check Stats:                                                              |"<<endl;
    cout<<"\t|       -stats                                                                |"<<endl;
    cout<<"\t|9. Exit Commands:                                                            |"<<endl;
    cout<<"\t|       -exit                                                                 |"<<endl;
    cout<<"\t|10. Look Commands:                                                           |"<<endl;
    cout<<"\t|       -look or l                                                            |"<<endl;
    cout<<"\n\t|----------------------------Rules and Gameplay-------------------------------|"<<endl;
    cout<<"\t|1. To win the game, player should slay the dragon, get the golden chalice    |"<<endl;
    cout<<"\t|   and return to the entrance                                                |"<<endl;
    cout<<"\t|2. Players can only have a maximum of 3 items in their inventory including   |"<<endl;
    cout<<"\t|   the health boosters                                                       |"<<endl;
    cout<<"\t|3. Weapons such as the sword, diamond cross, and silver spear gives player an|"<<endl;
    cout<<"\t|   advantage when they fight monsters                                        |"<<endl;
    cout<<"\t|4. Player needs to obtain the copper key before unlocking the door           |"<<endl;
    cout<<"\t|5. Player can only unlock door when standing in  front of the door           |"<<endl;
    cout<<"\t|   or the 'unlock door' command won't work                                   |"<<endl;
    cout<<"\t|6. Commands are case-sensitive                                               |"<<endl;
    cout<<"\t|7. Once you drop an object you won't get it back...drop wisely               |"<<endl;
    cout<<"\t|-----------------------------------------------------------------------------|"<<endl;
}

