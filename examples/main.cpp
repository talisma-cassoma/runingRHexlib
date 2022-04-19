#include "ModuleManager.hpp"
#include "SymbolTable.hpp"

int main(){

Symbol simbolo; 
float * floats = new float [2];
floats[0]= 4;
floats[1]= 41;
floats[2]= 48;

simbolo.setFarray( floats, 0);

std::cout<<"ola todo mundo"<<std::endl;

    return 0;
}