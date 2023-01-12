#include <iostream>
#include "headerFile.h"

using namespace std;

int main()
{
  cout<<"\tHi there player looks like you've just regained consciousness...\n"<<endl;
  cout<<"\tYou are in the mansion of Agaroth, trapped in a game\n"<<endl;
  cout<<"\tThere are nine rooms, six monsters and one Golden Chalice\n"<<endl;
  cout<<"\tGet the Golden Chalice and return to the entrance to win"<<endl;
  cout<<"\tType 'help' to get the list of commands and more details"<<endl;
  cout<<"\nWelcome to Agaroth hope you enjoy the visit....\n"<<endl;


  adventureGame ag;
  while (ag.getCommand()>0) {//Read a command from the user
        srand(time(0));
        if (ag.processCommand()==0) break;
        }



    return 0;
}
