/***********************************************************
 ** File:    Mario.cpp
 ** Project: UMBC Mario Kart
 ** Author:  Kirtan Thakkar
 ** Date     11/1/2021
 ** Section: N/A
 ** This file contains the header file of the Wario class
 **********************************************************/
#include "Wario.h"


  // Name: Wario() - Default Constructor
  // Description: Creates a new Wario
  // Preconditions: None
  // Postconditions: Can create a Wario
Wario::Wario(): Character(){



}
  // Name: Wario(string name)
  // Description: Creates a new Wario
  // Preconditions: None
  // Postconditions: Can create a Wario
Wario::Wario(string entity, double topSpeed, double acceleration, double handling): Character(entity, topSpeed, acceleration, handling){


}
  // Name: ~Wario - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
Wario::~Wario(){



}

  // OPTIONAL: EXTRA CREDIT
  // Name: SpecialAttack
  // Description: Defines the Wario's special attack (up to you what it does)
  // Preconditions: None
  // Postconditions: Does something (think turbo, star etc. Must do something other than just changing output!)
void Wario::SpecialMove(){


}
  // Name: GetType
  // Description: Returns the name of the object type (Wario in this case)
  // Precondition: Must be populated
  // Postcondition: Returns m_type (used to output)
string Wario::GetType(){

  return "Wario"; 

  }
  // Name: Overloaded << operator
  // Description: Returns information about the racer
  // Precondition: Must be populated
  // Postcondition: Returns something like Wario (J) has gone 348 meters and is currently going 80 m/s
  // Usage is *m_Racers.at(i) << cout << endl;
ostream& Wario::operator<<(ostream& output){

  output << GetType() << " (" << GetName() << ") has gone " << GetCurLocation() << " meters and is currently going " << GetCurSpeed() << " m/s" << endl;

  return output;
  }
