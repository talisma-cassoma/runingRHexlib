#include <iostream>
#include <stdio.h>
#include "Strings.hh"

using namespace std;

int main(void){

const char** Tableau = new const char* [3];
Tableau[0]= "ola";
Tableau[1]= "como te chamas";
Tableau[2]= "chamo-me Talisma";

Strings texto( Tableau, 3);
const char* nouveau_Tab;

nouveau_Tab = texto.get(3);

cout<<"count: "<<texto.getCount()<<endl;
for(int i=0; i<3; i++){
    cout<<nouveau_Tab[2]<<endl;
}

return 0;
}