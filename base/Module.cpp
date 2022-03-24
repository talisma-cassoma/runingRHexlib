#include "ModuleManager.hpp"

//Module class c-tors
Module::Module( const char* n, int i, bool single, bool poll){

    state       = UNINIT;
    name        = n;
    usedby      = NULL;
    index       = i;
    grabCount   = 0;
    single_user = single;
    polling     = poll;
    next = prev = NULL;
} 

//A Linked List Utility Function
void Module::addToList(Module **head){

 if((*head)== NULL){
    *head = this;
     next = prev = this;
 }else{
    Module *temp = *head;

    while ( temp->order < order && temp->next != *head ){temp = temp->next;}
    
    // This is necessary if the module is to be added at the end of the list
    if ( temp->order < order && temp->next == *head ){temp = temp->next;}
    
    next = temp;
    prev = temp->next;
    temp->prev->next = this;
    temp->prev = this;
    
    if( temp == *head && order <= temp->order ){*head = this;}
 }
}
// A Linked List Utility Function
void Module::removeFromList( Module ** head ) {

  if ( prev == NULL || next == NULL ) {
    *head = NULL;
    return;
  }
  if ( this == (*head) ) {

    if ( next != *head )
      *head = next;
    else
      *head = NULL;

  } 

  prev->next = next;
  next->prev = prev;
  next = prev = NULL;

}