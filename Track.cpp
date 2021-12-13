/*Title: Track.h
Author: Kirtan Thakkar
Date: 10/29/2021
Description: This class defines track and pieces of a track for a race in Mario Kart project
*/

#include "Track.h"

  // Name: Track
  // Precondition: None
  // Postcondition: Creates a new empty track
Track::Track(){

 m_name = ""; //Name of track
 m_desc = ""; //Description of track
 m_fileName = ""; //Filename of track to load
 m_totalLength = 0;
 
}


Track::~Track(){
 
  for(unsigned int i = 0; i < m_track.size(); i++)
    {
      delete m_track.at(i);
    }
}

  // Name: LoadTrack(string fileName);
  // Description: Creates a piece of track from each line from input file
  // Precondition: m_filename is valid
  // Postcondition: Actually loads the track based on m_filename
void Track::LoadTrack(string fileName){

  ifstream inputFile;
  string length = "", pieceDesc = "", obstacle = "", maxSpeed = "", str = "";
  Piece* piece;
  int ln, ob, max;
  
  inputFile.open(fileName);

  if(inputFile.is_open())
    {

      getline(inputFile, m_name, '\n');
      getline(inputFile, m_desc, '\n');
  
      while(getline(inputFile, length, '|') && getline(inputFile, pieceDesc, '|') && getline(inputFile, obstacle, '|') && getline(inputFile, maxSpeed, '|') )
	{	  

	  ln = stoi(length);
	  ob = stoi(obstacle);
	  max = stoi(maxSpeed);
	  
	  m_totalLength += ln;
	  
       	   piece = new Piece(ln, pieceDesc, ob, max);
	   m_track.push_back(piece);


	}
      
      cout << "File Opened" << endl;
      inputFile.close();
      
    }else{

    cout << "Error: unable to open the file, Please check your input file." << endl;

  }

  //cout << "Total Pieces: " << m_track.size() << endl;  
}
  // Name: GetPiece (int)
  // Description: At a specific distance, the corresponding index of the piece is returned
  // For example, if 300 is passed, iterates through vector adding distance until 300 is reached
  // If next piece of the track exceeds the end, returns the end
  // Precondition: Must have  valid track and provided distance
  // Postcondition: Travels through track to described distance
int Track::GetPiece(int distance){
  
  int length = 0;
  unsigned int i = 0;

  if(distance < m_totalLength)
    {
      while(length < distance && i < m_track.size())
	{
	  length += m_track.at(i)->m_length;
	  if(length < distance)
	    {
	      i++;
	    }
	}

      return i;
      
    }

  return m_track.size();
  
}
  // Name: DisplayPiece
  // Description: At a specific index, returns the m_desc from a particular piece of track
  // Precondition: Track loaded and a valid index passed
  // Postcondition: Returns id of track in that direction if the exit exists
void Track::DisplayPiece(int index){
  
  unsigned int size = m_track.size();
  
  if(index >= int(size))
    {
      cout << m_track.at(m_track.size()-1)->m_desc << endl;
      
    }else{
    cout << m_track.at(index)->m_desc << endl;
  }
  
}
  // Name: GetMaxSpeed
  // Description: At a specific index, returns the m_maxSpeed from a particular piece of track
  // Precondition: Track loaded and a valid index passed
  // Postcondition: Returns double which is max speed before racer crashes
double Track::GetMaxSpeed(int index){


return m_track.at(index)->m_maxSpeed;

}
  // Name: GetTotalLength()
  // Description: Returns m_totalLength
  // Precondition: Track loaded
  // Postcondition: Returns int for totallength
int Track::GetTotalLength(){

  
  
  return m_totalLength;

}
  // Name: GetDesc()
  // Description: Returns m_desc
  // Precondition: Track loaded
  // Postcondition: Returns desc
string Track::GetDesc(){

return m_desc;

}
  
