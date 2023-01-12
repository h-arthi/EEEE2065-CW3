#include "headerFile.h"

/**This function takes no input but returns a value to ensure the game is still being played until exit command**/
/**Processes the user command and executes the relevant fucntion**/
int adventureGame::processCommand(){

    //tocheck if the getline stream is empty
    if(command.empty()){command = prevCommand; cout<<command<<endl;}
    //if it isn't, constantly sets previous command to current command
    else{prevCommand = command;}

    //Process exit command
    if(command == "exit"){
        win = -1;
        cout<<"Player Exits Games"<<endl;
        printStatus();
        return(0);
        }

    //Process look command
    if(command=="look" || command=="l"){processLook();return(1);}

    //Process the movement command and constantly check for player victory
    if(processMovement()== 1){checkVictory();return(1);}

    //Process the commands to kill all monsters
    if(command=="killMonster"||command=="km"){processKillMonster();return(1);}

    if(command=="killWerewolf"||command=="kw"){processKillWerewolf();return(1);}

    if(command=="killLizard"||command=="kl"){processKillLizard();return(1);}

    if(command=="killDracula"||command=="kd"){processKillDracula();return(1);}

    if(command=="killZombie"||command=="kz"){processKillZombie();return(1);}

    if(command=="killDragon"||command=="kD"){processKillDragon();return(1);}

    //process inventory command
    if(command=="inventory"||command == "i"){inventory();return(1);}

    //process the object to obtain
    if(command.substr(0,4)=="get "){processGet(command.substr(4,command.size()));return(1);}

    //process the object to drop
    if(command.substr(0,5)=="drop "){processDrop(command.substr(5,command.size()));return(1);}

    //process to display player stats
    if(command == "stats"){printStatus();return(1);}

    //process to display list of commands
    if(command == "help"){helpPlayer();return(1);}

    //process to eat food
    if(command.substr(0,4)=="eat "){
        string check = command.substr(4,command.size());
        convertToLower(check);
        if(check == "food"){restoreHealth(check);}
        else{cout<<"You cannot use this command"<<endl;}
        return(1);
    }

    //process to use medpack
    if(command.substr(0,4)=="use "){
        string check = command.substr(4,command.size());
        if(check == "medpack"){restoreHealth(check);}
        else{cout<<"You cannot use this command"<<endl;}
        return(1);
    }
    //process to drink elixir
    if(command.substr(0,6)=="drink "){
        string check = command.substr(6,command.size());
        if(check == "elixir"){restoreHealth(check);}
        else{cout<<"You cannot use this command"<<endl;}
        return(1);
    }

    //process to unlock copper key
    if(command == "unlock door" && room == 5){
        for(long long unsigned int i=0;i<Pinventory.size();i++){
        convertToLower(Pinventory[i]);
        }
        auto checkKey = find(Pinventory.begin(),Pinventory.end(),"copper key");
        if(checkKey==Pinventory.end()){cout<<"You don't have the key"<<endl;}
        else{moveToArray[5][1]=8; moveArray[5][1]= Entry;Pinventory.erase(checkKey);cout<<"Room unlocked"<<endl;}
        return(1);
    }

    else{
        cout<<"Unknown Command: "<<command<<endl;
    }

    return(1);
}

