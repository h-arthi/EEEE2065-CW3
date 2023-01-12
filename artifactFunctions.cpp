#include "headerFile.h"

/**Function for Getting Objects takes artifact name as input**/
int adventureGame::processGet(string object){

    if(monsterStatusArray[room]>0){
        cout<<"You have to kill "<<monsterArray[room]<<" before picking up artifact"<<endl;
    }

    else{
        convertToLower(object);
        //find the object in the list of artifacts
        for(int i=0;i<N_artifact;i++){
            convertToLower(artifact[i]);
            if(object==artifact[i]){//found the object in the list
                convertToCap(object);
                if(artifactLoc[i]==room){//if the artifact is in the room
                    if(Pinventory.size()<3){//player carrying less than 3 artifacts
                        cout<<"You pick up the "<<object<<endl;
                        artifactLoc[i] = -1;
                        ExInventory.push_back(artifact[i]);//stores everything player collects here
                        Pinventory.push_back(artifact[i]);//stores everything player holds here
                        checkWeapon(artifact[i]);//checks if it is a weapon to increase player attack
                        player_score+=2;
                        return(1);
                    }
                    else {cout<<"You are overloaded, drop another object first"<<endl;return(1);}
                }
                else {cout<<"There is no "<<object<<" here"<<endl;return(1);}
            }
        }
        cout<<"There is no "<<object<<" here"<<endl;
    }



    return(1);
}

/**Function to Check the Player Inventory**/
void adventureGame::inventory(){

    cout<<"You are carrying: "<<endl;
    for(long long unsigned int i=0,j=0;i<Pinventory.size();i++){
        cout<< ++j <<" "<<Pinventory[i]<<endl;
    }

}


/**Function for Dropping Objects takes artifact name as input**/
int adventureGame::processDrop(string object){

    convertToLower(object);
    for(long long unsigned int i=0;i<Pinventory.size();i++){
        convertToLower(Pinventory[i]);
        if(object==Pinventory[i]){//checking if object is in inventory
            //iterating over vectors to find matching artifact
            auto remove_artifact = find(Pinventory.begin(),Pinventory.end(),object);
            if(remove_artifact==Pinventory.end()){
                cout<<"Not found here"<<endl;
            }
            else{
                removeWeapon(object);//decreases attack score if player drops weapon
                //removing artifact from inventory
                Pinventory.erase(remove_artifact);
                cout<<object<<" has been dropped"<<endl;
                cout<<"There is no object here"<<endl;
            }
        }
    }

    return(1);
}

/**Function to restore player health takes string as input**/
int adventureGame::restoreHealth(string restore){

    convertToLower(restore);
    for(long long unsigned int i=0;i<Pinventory.size();i++){
            convertToLower(Pinventory[i]);
            if(restore==Pinventory[i]){//checking if object is in inventory
                //iterating over vectors to find matching artifact
                auto restore_health = find(Pinventory.begin(),Pinventory.end(),restore);
                if(restore_health!=Pinventory.end()){
                    //checks what to restore and removes from inventory once used
                    if(restore=="food"){player_health+=food;cout<<"Player health increased by: "<<food<<endl;Pinventory.erase(restore_health);}
                    if(restore=="medpack"){player_health+=medpack;cout<<"Player health increased by: "<<medpack<<endl;Pinventory.erase(restore_health);}
                    if(restore=="elixir"){player_health+=elixir;cout<<"Player health increased by: "<<elixir<<endl;Pinventory.erase(restore_health);}
                }
            }
            else {cout<<"You don't have this"<<endl;}
        }
        return(1);
}

/**Function to check inventory, takes weapon to check as input returns 1**/
int adventureGame::checkInventory(string checking){

    convertToLower(checking);
    for(long long unsigned int i=0;i<Pinventory.size();i++){
        convertToLower(Pinventory[i]);
    }
    auto yesGot = find(Pinventory.begin(),Pinventory.end(),checking);
    if(yesGot==Pinventory.end()){
        return(-1);
    }
    else{
        return(2);
    }

    return (1);
}

/**Function to determine what weapon is available, takes weapon to check as input returns 1**/
int adventureGame::checkWeapon(string weapon_choice){

    convertToLower(weapon_choice);
    for(long long unsigned int i=0;i<Pinventory.size();i++){
        convertToLower(Pinventory[i]);
    }
    auto weapon = find(Pinventory.begin(),Pinventory.end(),weapon_choice);
    if(weapon==Pinventory.end()){
        player_attack=player_attack;
    }
    else{
        if(weapon_choice=="sword"){player_attack+=1;cout<<"+1 Player attack"<<endl;}
        if(weapon_choice=="silver spear"){player_attack+=2;cout<<"+2 Player attack"<<endl;}
        if(weapon_choice=="diamond cross"){player_attack+=3;cout<<"+3 Player attack"<<endl;}
    }

    return (1);
}

/**Function if player drops weapon, takes weapon to check as input returns 1**/
int adventureGame::removeWeapon(string weapon_choice){

    convertToLower(weapon_choice);
    for(long long unsigned int i=0;i<Pinventory.size();i++){
        convertToLower(Pinventory[i]);
    }
    auto weapon = find(Pinventory.begin(),Pinventory.end(),weapon_choice);
    if(weapon==Pinventory.end()){
        player_attack=player_attack;
    }
    else{
        if(weapon_choice=="sword"){player_attack-=2;cout<<"-2 Player attack"<<endl;}
        if(weapon_choice=="silver spear"){player_attack-=3;cout<<"-3 Player attack"<<endl;}
        if(weapon_choice=="diamond cross"){player_attack-=5;cout<<"-5 Player attack"<<endl;}
    }

    return (1);
}

/**Convert to lowercase function**/
void adventureGame::convertToLower(string &object){
    for(long long unsigned int i=0;i<object.length();i++){
        object[i]=tolower(object[i]);
    }
}


/**Convert to uppercase function**/
//uses a flag first to tell when it is at the first character of a word, in which case it
//should capitalize the letter
void adventureGame::convertToCap(string &object){
    for(long long unsigned int i=0, first=1;i<object.length();i++){
        if(first==1){
            object[i]=toupper(object[i]);
            first=0;
        }
        if(object[i]==' ')
            first = 1;
    }
}

