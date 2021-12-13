/***********************************************************
 ** File:    Mario.cpp
 ** Project: UMBC Mario Kart
 ** Author:  Kirtan Thakkar
 ** Date     11/1/2021
 ** Section: N/A
 ** This file contains the header file of the Mario class
 **********************************************************/  
#include "Mario.h"

//The hero of so many Nintendo games!


  // Name: Mario() - Default Constructor
  // Description: Creates a new Mario
  // Preconditions: None
  // Postconditions: Can create a Mario
Mario::Mario(): Character(){


  }
  // Name: Mario(string name)
  // Description: Creates a new Mario
  // Preconditions: None
  // Postconditions: Can create a Mario

Mario::Mario(string entity, double topSpeed, double acceleration, double handling): Character(entity, topSpeed, acceleration, handling){

  //Character(entity, topSpeed, acceleration, handling);
    
  }
  // Name: ~Mario - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  Mario::~Mario(){



  }
  // OPTIONAL: EXTRA CREDIT
  // Name: SpecialAttack
  // Description: Defines the Mario's special attack (up to you what it does)
  // Preconditions: None
  // Postconditions: Does something (think turbo, star etc. Must do something other than just changing output!)
 void Mario::SpecialMove(){


  }
  // Name: GetType
  // Description: Returns the name of the object type (Mario in this case)
  // Precondition: Must be populated
  // Postcondition: Returns m_type (used to output)
 string Mario::GetType(){

   return "Mario";
  }
  // Name: Overloaded << operator
   // Description: Returns information about the racer
  // Precondition: Must be populated
  // Postcondition: Returns something like Mario (J) has gone 348 meters and is currently going 80 m/s
  // Usage is *m_Racers.at(i) << cout << endl;
ostream& Mario::operator<<(ostream& output){

  output << GetType() << " (" << GetName() << ") has gone " << GetCurLocation() << " meters and is currently going " << GetCurSpeed() << " m/s" << endl; 
    
   return output;

  }
  
