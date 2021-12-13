/***********************************************************
 ** File:    Game.h
 ** Project: UMBC Mario Kart
 ** Author:  Kirtan Thakkar
 ** Date     11/1/2021
 ** Section: N/A
 ** This file contains the header file of the Game class
 **********************************************************/


//Includes of required classes
#include "Game.h"

//******************************************************


  // Name: Game() - Default Constructor
  // Description: Creates a new Game. Welcomes player to UMBC Mario Kart. Initializes laps and racers to 1
  // Preconditions: None
  // Postconditions: m_numLaps and m_numRacers initialized to 1
Game::Game(){

 m_numLaps = 0; //Number of laps in race
 m_numRacers = 0; //Number of racers in race


}
  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game(){

  for(unsigned int i = 0; i < m_Racers.size(); i++)
    {
      delete m_Racers.at(i);
      
    }


}
  // Name: LoadTrack
  // Description: Asks user which track to use (1-3)
  //              Calls LoadTrack for use in myTrack
  //              If three laps then the same track is loaded three times
  // Precondition: Files must exist. m_numLaps must be populated
  // Postcondition: myTrack is populated with track Pieces
void Game::LoadTrack(){

int trackNum;
bool run = false;
 

 do{
   
  cout << "Which track would tou like to use?" << endl;
  cout << "1. "<< TRACK[0][0] << endl;
  cout << "2. " << TRACK[1][0] << endl;
  cout << "3. " << TRACK[2][0] << endl;
  cin >> trackNum;

	  if(trackNum <= NUM_TRACKS && trackNum > 0)
	    {
	      switch(trackNum){
	      case 1:
		for(int i = 0; i < m_numLaps; i++)
		myTrack.LoadTrack(TRACK[0][1]);
		
		break;
	      case 2:

		for(int i = 0; i < m_numLaps; i++)
		myTrack.LoadTrack(TRACK[1][1]);
		break;
	      case 3:
		
		for(int i = 0; i < m_numLaps; i++)
		myTrack.LoadTrack(TRACK[2][1]);
		break;
	      default:
		
		cout << "File Failiur, unable to open track file" << endl;
	      }

	      run = false;
	      
	    }else{

	    run = true;

	  }

    
   
 }while(run);
  

}
  // Name: RaceSetup
  // Description: Asks the user for their name and stores it in local variable
  //              Allows user to choose which racer to use (Mario, Wario, or Toad) using provided name
  //              Allows the user to choose how many other racers to use (no limit) - Randomly assigned (can be duplicates)
  //              Allows the user to choose how many laps to race (no limit)
  // Preconditions: None
  // Postconditions: m_Racers populated with racers, m_numLaps populated
void Game::RaceSetup(){

  int selection, randChar;
  string input;
  Entity *opponent;

  cout << "What is your name?" << endl;
  getline(cin, m_playerName, '\n');

  do{
    
    cout << "Select a racer" << endl;
    cout << "1. Toad" << endl;
    cout << "2. Wario" << endl;
    cout << "3. Mario" << endl;

    cin >> selection;

  }while((selection < 1) || selection > 3);

  if(selection > 0 && selection < 4)
	switch(selection)
	  {
	  case 1:
	    opponent = new Toad(m_playerName,TOAD_STATS[0],TOAD_STATS[1],TOAD_STATS[2]);
	    opponent->SetCurLocation(0);
 	    m_Racers.push_back(opponent);
	    
	    break;
	  case 2:
	    opponent = new Wario(m_playerName,WARIO_STATS[0],WARIO_STATS[1],WARIO_STATS[2]);
	    opponent->SetCurLocation(0);
	    m_Racers.push_back(opponent);
 
	    break;
	  case 3:
	    opponent = new Mario(m_playerName,MARIO_STATS[0],MARIO_STATS[1],MARIO_STATS[2]);
	    opponent->SetCurLocation(0);
	    m_Racers.push_back(opponent);

	    break;
 
	  default:
	    cout << "Error 404: opponent not found" << endl;

	  }


      do{
	
	cout << "How many other competitors would you like?" << endl;
	cin >> m_numRacers;
	
      }while(m_numRacers == 0);
	
	    for(int i = 0; i < m_numRacers; i++)
	      {

		randChar = 1 + (rand() % 3);

		switch(randChar)
		  {
		case 1:

		  opponent = new Toad("CPU"+to_string(i),TOAD_STATS[0],TOAD_STATS[1],TOAD_STATS[2]);
		  m_Racers.push_back(opponent);
		  
		  break;
		case 2:
	       
		  opponent = new Wario("CPU" + to_string(i),WARIO_STATS[0],WARIO_STATS[1],WARIO_STATS[2]);
		m_Racers.push_back(opponent);
		
		break;
		case 3:
		  
		  opponent = new  Mario("CPU" + to_string(i),MARIO_STATS[0],MARIO_STATS[1],MARIO_STATS[2]);
		m_Racers.push_back(opponent);
		
		break;

	      default:
		cout << "Error 404: opponent not found" << endl;
		
		  }

	      }

         do{
	  
	    cout << "How many laps would you like to complete for the race?" << endl;
	    cin >> m_numLaps;

	 }while(m_numLaps < 1);
	    
	
}
  // Name: StartRace()
  // Description: As long as the race isn't over or the user hasn't quit repeat these:
  //              Displays current position in track for user
  //              Shows round number
  //              Displays current piece description on track
  //              Displays the next piece description on track (like what is ahead)
  //              Makes computer racers randomly choose a speed for this round (100%, 75%, 50%, 25%)
  //              Tick (passing max speed)
  //              Reorder vector based on who has moved the most down the track (m_curLocation)
  //              Display the order
  // Preconditions: LoadTrack and RaceSetup must have been completed
  // Postconditions: Continues until race is over. If completed, displays result (who won)
void Game::StartRace(){

  int round = 0, player = 0;
  bool GameOver = false;
  
  cout << "You will be racing " << m_numLaps << ((m_numLaps) > 1? " laps": " lap")<< endl;
  cout << "The total length of the race is " << myTrack.GetTotalLength() << " meters" << endl;
  cout << "Start of the Race Track" << endl;

  cout << endl;
  cout <<"*******ON YOUR MARKS*********" << endl;

  cout << endl;
  cout <<"*******GET SET********" << endl;

  cout << endl;
  cout <<"*******GO! GO! GO!*********" << endl;
  cout << endl;

  cout << "You currently see: " << endl;

  myTrack.DisplayPiece(m_Racers.at(FindPlayer())->GetCurLocation());

  
      while(!GameOver)
        {
	  
	  switch(Action())
	    {
	    case 1:
	      
	      m_Racers.at(FindPlayer())->CalcSpeed(1.0);
	      
	      break;
	    case 2:
	      
	      m_Racers.at(FindPlayer())->CalcSpeed(.75);
	      
	      break;
	    case 3:
	      
	      m_Racers.at(FindPlayer())->CalcSpeed(0.5);
	      
	      break;
	    case 4:
	      
	      m_Racers.at(FindPlayer())->CalcSpeed(0.25);
	      
	      break;
	    case 5:
	      
	      cout << "This feature is not available in this version" << endl;
	      
	      break;
	    case 6:

	      GameOver = true;
	      cout << "Quitting..." << endl;
	      
	      break;
	      
	    default:

	      cout << "Error: Please select one of the followings" << endl;
	    }
	  
	  round++;
	  cout << "*****************************" << endl;
	  cout << "Round : " << round << endl;
	  cout << "*****************************" << endl;

	  player = FindPlayer();
	  
	  cout << "You currently see: " << endl;
	  myTrack.DisplayPiece(myTrack.GetPiece(m_Racers.at(player)->GetCurLocation())); // Displays current location
 
	  
	  
 	   cout << "Ahead is: " << endl;
	   myTrack.DisplayPiece(myTrack.GetPiece(m_Racers.at(player)->GetCurLocation())+1); // Displays next location
	  
   	  CpuRandom();
          Tick(myTrack.GetMaxSpeed(myTrack.GetPiece(m_Racers.at(FindPlayer())->GetCurLocation())));
          Order();    
	  Display();

	  
	  if(!GameOver) // if player hasn't quit the game
 	    {	      
	      if(CheckFinish())
		{
		  GameOver = true;
		  
		}else{
		
		GameOver = false;
	      }
	    }
     }
	
}
  // Name: CheckFinish
  // Description: Checks to see if any racer has exceeded total length of the track
  // Precondition: m_Racers has been populated and myTrack has been populated
  // Postcondition: Returns true if race is over; else false
bool Game::CheckFinish(){
  
  for(unsigned int i = 0; i < m_Racers.size(); i++)
    {
      if(m_Racers.at(i)->GetCurLocation() > myTrack.GetTotalLength())
	{
	  cout << "The race is over!" << endl;
	  cout << m_Racers.at(i)->GetType() << " (" << m_Racers.at(i)->GetName() << ") " << endl;
	  return true;

	}
      
    }
  
  return false;
}
  // Name: CpuRandom
  // Description: Iterates over all computer m_Racers and uses CalcSpeed to randomly assign either (100%, 75%, 50%, 25%)
  // Precondition: m_Racers has been populated
  // Postcondition: Using CalcSpeed, updates racer's speeds
void Game::CpuRandom(){

  int randNum = 0;
  
  for(unsigned int i = 0; i < m_Racers.size(); i++)
    {
      
      if(m_Racers.at(i)->GetName() != m_playerName)
	{
	     randNum = 1+ (rand() % 4);
	      
	      switch(randNum)
		{

	    case 1:
	      
	      m_Racers.at(i)->CalcSpeed(1.0);
	      
	      break;
	    case 2:

	      m_Racers.at(i)->CalcSpeed(.75);
	      
	      break;
	    case 3:

	      m_Racers.at(i)->CalcSpeed(.50);	      
	      break;
	    case 4:

	      m_Racers.at(i)->CalcSpeed(.25);	      
	      break;
	    default:
	      
	      cout << "Error: not able to set a speed for CPU Character." << endl;
	      
	    }// switch statment end
	}
      
    }//for loop end
  

}
  // Name: Tick
  // Description: Iterates over all computer m_Racers and calls Tick and passes the maxSpeed of the current piece of track that racer is on
  // Precondition: m_Racers has been populated and myTrack has been populated
  // Postcondition: Checks to see if the racer crashes by exceeding the max limit of that track piece
void Game::Tick(double maxSpeed){

  for(unsigned int i = 0; i < m_Racers.size(); i++)
    {
      m_Racers.at(i)->Tick(maxSpeed);
      
    }

}
  // Name: Order
  // Description: Uses a simple bubble sort (nested for loops) to reorder who has traveled the farthest
  // Precondition: m_Racers has been populated
  // Postcondition: m_Racers is sorted from highest distance traveled to lowest distance traveled
void Game::Order(){

  Entity* temp;

  for(unsigned int i = 0; i < m_Racers.size(); i++)
    {      
      for(unsigned int j = 0; j < m_Racers.size(); j++)
	{

	  if(m_Racers.at(i)->GetCurLocation() > m_Racers.at(j)->GetCurLocation())
	    {
	      temp = m_Racers.at(i);
	      m_Racers.at(i) =  m_Racers.at(j);
	      m_Racers.at(j) = temp;
	    }

	}
	
    }

}
  // Name: Attack
  // Description: Optional-extra credit
  //              Uses obstacles to make things crash. Uses bananas to make racers crash behind the user
  //              Uses shells to crash racers ahead.
  //              Can only attempt after the base project is completed
  //              Can add additional member functions and variables to make this functionality work
void Game::Attack(){

  

}
  // Name: Display
  // Description: Displays each racer in m_Racers by using overloaded << operator
  // Precondition: m_Racers has been populated
  // Postcondition: Usage is *m_Racers.at(i) << cout << endl;
void Game::Display(){

  cout << "*****************************" << endl;
  cout << endl;
  
  for(unsigned int i = 0; i < m_Racers.size(); i++)
    {
      *m_Racers.at(i) << cout << endl;
    }

  cout << "*****************************" << endl;
  cout << endl;
  
}
  // Name: Tick
  // Description: Iterates over all racers in m_Racers to return the index of where the player's racer exists (after sort)
  // Precondition: m_Racers has been populated and sort has been called
  // Postcondition: Returns the index of where the player's racer exists
int Game::FindPlayer(){
  
  for(unsigned int i = 0; i < m_Racers.size(); i++)
    {
      if(m_Racers.at(i)->GetName() == m_playerName)
	{
	  return i;
	}
      
    }
  
  return 0;

}
  // Name: Action()
  // Description: Menu for game
  //              Required to implement cases 1-4 and 6.
  //              Choice 5 (Attack) is optional and is part of the extra credit
  //              Asks the user if they want to change their speed
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until someone finishes race

int Game::Action(){

  int input;

  do{

    cout <<"What would you like to do?" << endl;
    cout << "1. Max Speed" << endl;
    cout << "2. Pretty Fast" << endl;
    cout << "3. Fast" << endl;
    cout << "4. Slow" << endl;
    cout << "5. Use Obstacle (not supported in this version)" << endl;
    cout << "6. Quit" << endl;
    cin >> input;


  }while((input < 1) || input > 6);

  
  return input;
  
}
