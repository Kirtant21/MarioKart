/***********************************************************                                                                                                               
 ** File:    Entity.h                                                                                                                                                      
 ** Project: UMBC Mario Kart                                                                                                                                               
 ** Author:  Jeremy Dixon                                                                                                                                                  
 ** Date     11/1/2021                                                                                                                                                     
 ** Section: N/A                                                                                                                                                           
 ** This file contains the header file of the Entity class                                                                                                                 
 *********************************************************/

#include "Entity.h"
                                                                                   
// Name: Entity() - Default Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes (not specifically used)                                                                                     

Entity::Entity(){

    m_name = "";
    
  }

// Name: Entity(string) - Overloaded Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes                                                                                                             
  Entity::Entity(string name){

    m_name = name;

  }

// Name: virtual ~Entity - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated                                                                                                       
 Entity::~Entity(){}

// Name: GetName()
// Description: Returns name of entity
// Preconditions: Entity has name
// Postconditions: None                                                              
  string Entity::GetName(){

    return m_name;

  }
// Name: SetName()                                                               
// Description: Sets name of entity                                               
// Preconditions: None
// Postconditions: Name is set                                                     
  void Entity::SetName(string name){

    m_name = name;


  }
  
                                                                                 

                                                                              
