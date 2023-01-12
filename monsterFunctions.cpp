#include "headerFile.h"

/**Function for to check for valid monster in room, takes no input returns 1**/
int adventureGame::processKillMonster(){

    //checks if the monster is actually the right one
    if(command=="killMonster"||command=="km"){
        //checks if monster is dead or not or if monster is in room
        if(monsterStatusArray[room]>0){attack();}
        else if(monsterStatusArray[room]==0){ cout<<"The "<<monsterArray[room]<<" is already dead"<<endl;}
        else{cout<<"There is no monster here."<<endl;}
    }
    else{cout<<"That monster not found in this room"<<endl;}

    return (1);
}

/**Function for to check for valid werewolf in room, takes no input returns 1**/
int adventureGame::processKillWerewolf(){

    //checks if the monster is actually the right one
    if((command=="killWerewolf"||command=="kw")&&(monsterArray[room]== monsterArray[7])){
        //check if special weapon is present
        if(checkInventory(artifact[2])== 2){monsterAttack[7]-= 2;cout<<"You have the silver spear werewolf is weakened"<<endl;}
        else{monsterAttack[7]+=2;cout<<"You do not have the silver spear, werewolf is stronger now"<<endl;}
        //checks if monster is dead or not or if monster is in room
        if(monsterStatusArray[room]>0){attack();}
        else if(monsterStatusArray[room]==0){ cout<<"The "<<monsterArray[room]<<" is already dead"<<endl;}
        else{cout<<"There is no monster here."<<endl;}
    }
    else{cout<<"That monster not found in this room"<<endl;}

    return(1);
}

/**Function for to check for valid zombie in room, takes no input returns 1**/
int adventureGame::processKillZombie(){

    //checks if the monster is actually the right one
    if((command=="killZombie"||command=="kz")&&(monsterArray[room]== monsterArray[2])){
        //checks if monster is dead or not or if monster is in room
        if(monsterStatusArray[room]>0){attack();}
        else if(monsterStatusArray[room]==0){ cout<<"The "<<monsterArray[room]<<" is already dead"<<endl;}
        else{cout<<"There is no monster here."<<endl;}
    }
    else{cout<<"That monster not found in this room"<<endl;}

    return(1);
}

/**Function for to check for valid dracula in room, takes no input returns 1**/
int adventureGame::processKillDracula(){

    //checks if the monster is actually the right one
    if((command=="killDracula"||command=="kd")&&(monsterArray[room]== monsterArray[6])){
        //checks if they have special weapon
        if(checkInventory(artifact[7])== 2){monsterAttack[6]-= 2;cout<<"You have the diamond cross dracula is weakened"<<endl;}
        else{monsterAttack[6]+=2;cout<<"You do not have the diamond cross, dracula is stronger now"<<endl;}
	//checks if monster is dead or not or if monster is in room
        if(monsterStatusArray[room]>0){attack();}
        else if(monsterStatusArray[room]==0){ cout<<"The "<<monsterArray[room]<<" is already dead"<<endl;}
        else{cout<<"There is no monster here."<<endl;}
    }
    else{cout<<"That monster not found in this room"<<endl;}

    return (1);
}

/**Function for to check for valid lizard-man in room, takes no input returns 1**/
int adventureGame::processKillLizard(){

    //checks if the monster is actually the right one
    if((command=="killLizard"||command=="kl")&&(monsterArray[room]== monsterArray[4])){
        //checks if monster is dead or not or if monster is in room
        if(monsterStatusArray[room]>0){attack();}
        else if(monsterStatusArray[room]==0){ cout<<"The "<<monsterArray[room]<<" is already dead"<<endl;}
        else{cout<<"There is no monster here."<<endl;}
    }
    else{cout<<"That monster not found in this room"<<endl;}

    return (1);
}

/**Function for to check for valid dragon in room, takes no input returns 1**/
int adventureGame::processKillDragon(){

    //checks if the monster is actually the right one
    if((command=="killDragon"||command=="kD")&&(monsterArray[room]== monsterArray[8])){
        //checks if monster is dead or not or if monster is in room
        if(monsterStatusArray[room]>0){attack();}
        else if(monsterStatusArray[room]==0){ cout<<"The "<<monsterArray[room]<<" is already dead"<<endl;}
        else{cout<<"There is no monster here."<<endl;}
    }
    else{cout<<"That monster not found in this room"<<endl;}

    return (1);
}

/**Function for player and monster to fight each other, takes no input returns 1**/
int adventureGame::attack(){

    /**For the player to attack the monster**/
    cout<<"\n-----Player Turn-----\n"<<endl;
    cout<<"Player damages  "<<monsterArray[room]<<" by "<<player_attack<<endl;
    monsterHealth[room] -= player_attack;
    cout<<"Player Health: "<<player_health<<endl;
    cout<<"Monster Health: "<<monsterHealth[room]<<endl;

    if(monsterHealth[room]>0){
        rand();//calling rand time to get a better random number
        rand();//to determine the power of the monster attack
        /**For the monster to attack player**/
        cout<<"\n-----Monster Turn-----\n"<<endl;
        cout<<"Monster chooses between random attack and power attack"<<endl;
        int m_attack = 1+(3*rand())/(RAND_MAX+1.0);//random computer number

        if(m_attack>3){

            cout<<"Monster damages player by  "<<monsterAttack[room]+ m_attack<<" with power attack"<<endl;
            player_health -= monsterAttack[room];
            cout<<"Player Health: "<<player_health<<endl;
            cout<<"Monster Health: "<<monsterHealth[room]<<endl;
        }
        else{

            cout<<"Monster damages player by  "<<monsterAttack[room]<<" with random attack"<<endl;
            player_health -= monsterAttack[room];
            cout<<"Player Health: "<<player_health<<endl;
            cout<<"Monster Health: "<<monsterHealth[room]<<endl;
        }
    }
    else{
        monsterStatusArray[room] = 0;
        monstersKilled.push_back(monsterArray[room]);//stores the monsters killed here
        cout<<"\n"<<monsterArray[room]<<": "<<killedMonster[room]<<endl;
        cout<<"You have killed "<<monsterArray[room]<<"! You can pick up the "<<artifact[room]<<" now"<<endl;
        printStatus();
        //adding to player score
        player_score += monsterAttack[room];
    }

    return (1);
}



