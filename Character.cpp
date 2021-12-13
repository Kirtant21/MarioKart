/***********************************************************
 ** File:    Character.h
 ** Project: UMBC Mario Kart
 ** Author:  Kirtan Thakkar
 ** Date     11/18/2021
 ** Section: 21
 ** This file contains the header file of the Character class
 ***********************************************************/

#include "Character.h"

  // Name: Character() - Default Constructor
  // Description: Creates a new character
  // Preconditions: None
  // Postconditions: Can create a character
Character::Character(): Entity(){

    m_curLocation = 0;//Current location
    m_curSpeed = 0;//Current Speed
    m_topSpeed = 0;//Top Speed (provided)
    m_handling = 0;//Handling (provided)
    m_acceleration = 0;
    

  }
  // Name: Character(string name) - Overloaded constructor
  // Description: Creates a new character (name, top speed, handling, acceleration)
  // Preconditions: None
  // Postconditions: Can be used to populate character or child classes
Character::Character(string entity, double topSpeed, double acceleration , double handling): Entity(entity){
    
    m_curLocation = 0;//Current location
    m_curSpeed = 0;//Current Speed
    m_topSpeed = topSpeed;//Top Speed (provided)
    m_handling = handling;//Handling (provided)
    m_acceleration = acceleration;


  }
  // Name: ~Character - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  Character::~Character(){

  }
  // Name: GetCurLocation()
  // Description: Returns m_curLocation
  // Precondition: Must be populated
  // Postcondition: Returns m_curLocation (how far down the track has the racer gone)
double Character::GetCurLocation(){


  return m_curLocation;
 }
  // Name: SetCurLocation()
  // Description: Sets m_curLocation
  // Precondition: None
  // Postcondition: Sets m_curLocation (how far down the track has the racer gone)
void Character::SetCurLocation(double location){

  m_curLocation = location;

}
  // Name: GetCurSpeed()
  // Description: Returns m_curSpeed
  // Precondition: Must be populated
  // Postcondition: Returns m_curSpeed (how fast the racer is going)
double Character::GetCurSpeed(){

  return m_curSpeed;

}
  // Name: SetCurSpeed()
  // Description: Sets m_curSpeed
  // Precondition: Must be populated
  // Postcondition: Sets m_curSpeed (does not calculate)
void Character::SetCurSpeed(double speed){

  m_curSpeed = speed;

}
  // Name: GetTopSpeed()
  // Description: Returns m_topSpeed
  // Precondition: Must be populated
  // Postcondition: Returns m_topSpeed (What is the top speed of the racer - provided)
double Character::GetTopSpeed(){


  return m_topSpeed;
}
  // Name: GetHandling()
  // Description: Returns m_handling
  // Precondition: Must be populated
  // Postcondition: Returns m_handling (How well can the racer steer? - provided)
double Character::GetHandling(){

  return m_handling;

}
  // Name: GetAcceleration()
  // Description: Returns m_acceleration
  // Precondition: Must be populated
  // Postcondition: Returns m_acceleration (How fast can the racer accelerate?)
double Character::GetAcceleration(){

  return m_acceleration;
}
  // OPTIONAL: EXTRA CREDIT
  // DO NOT EDIT UNTIL YOU HAVE COMPLETED BASE PROJECT
  // Name: SpecialMove()
  // Description: Allows the child class to do a special move
  // Precondition: Must be implemented in the child class
  // Postcondition: Modifies something (think star, turbo, or something else interesting - MUST DO SOMETHING OTHER THAN JUST OUTPUT!)
void Character::SpecialMove(){



}


// Name: CalcSpeed
// Description: Calculates the current speed based on some rules described in project document
// Precondition: Must be populated
// Postcondition: Sets m_curSpeed
  void Character::CalcSpeed(double gas){

    if(m_curSpeed < m_topSpeed)
      {
	m_curSpeed += m_acceleration*m_handling;

      }

    if(m_curSpeed > m_topSpeed)
      {
	m_curSpeed = m_topSpeed;
      }
    
    m_curSpeed *=gas;
   


  }
  // Name: Tick
  // Description: Checks to see if the racer crashes
  // Precondition: m_curSpeed must be calculated and passed maximum speed of track
  // Postcondition: May update m_curSpeed to 0 if there is a crash
void Character::Tick(double maxSpeed){

  if(m_curSpeed > maxSpeed)
    {
      m_curSpeed = 0;
      
    }else{

    m_curLocation = m_curLocation + m_curSpeed;

  }
  

}
