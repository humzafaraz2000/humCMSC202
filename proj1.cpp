/*
*File:    proj1.cpp 
*Project: CMSC 202 Project 1, Spring 2018
*Author:  Humza Faraz
*Date:    2/18/19
*Section: 32
*E-mail:  hfaraz1@umbc.edu
*Description:
*
*This program takes in user input, and allows the user to
*to load in a text file of ASCII art, create their own art,
*print out the art, rotate the art, or invert the art. It also
*displays the results in the format specified in the project 
*description.
*
*/

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_VALUE = 75;
const int MIN_VALUE = 0;
const int STOP = 6;

//prints main menu
int mainMenu();

//loads in file given by user
void load(char pic[MAX_VALUE][MAX_VALUE]);

//Create ASCII Art Manually
void create(char pic[MAX_VALUE][MAX_VALUE]);

//Display Art
void display(char pic[MAX_VALUE][MAX_VALUE]);

//Rotate Art
void rotate(char pic[MAX_VALUE][MAX_VALUE]);

//invert art
void invert(char pic[MAX_VALUE][MAX_VALUE]);


int main(){
  cout << "Welcome to ACII art tool." << endl;
  char image[MAX_VALUE][MAX_VALUE] = {{' '}};
  for (int i = 0; i < MAX_VALUE; i++){
    for (int j = 0; j < MAX_VALUE; j++){
      image[i][j] = ' ';
    }
  }
  
  int action = mainMenu();
  while (action != STOP){
    switch (action){
    case 1:
      load(image);
      break;
    case 2:
      create(image);
      break;
    case 3:
      display(image);
      break;
    case 4:
      rotate(image);
      break;
    case 5:
      invert(image);
      break;
    case 6:
      break;
    }
    action = mainMenu();
  }
  cout << "Thank you for using ASCII art tool" << endl;
  return 0;
}

//-----------------------------------------------------------
//Name: mainMenu
//PreCondition: None
//PostCondition: returns user's choice
//-----------------------------------------------------------
int mainMenu(){
  int choice;
  cout << "What would you like to do?" << endl << "1. Load ASCII Art from File" << endl <<
    "2. Create ASII art manually" << endl << "3. Display Art" << endl << "4. Rotate Art" <<
    endl << "5. Invert Art" << endl << "6. Exit" << endl;
  cin >> choice;
  return choice;
  
}

//-------------------------------------------------------------
//Name: load
//PreCondition: The user entered 1
//PostCondition: The file name is loaded in
//-------------------------------------------------------------
void load(char pic[MAX_VALUE][MAX_VALUE]){
  char fileName[MAX_VALUE];
  int x;
  int y;
  char symb;
  cout << "What's the name of the data file to import?" << endl;
  cin >> fileName;
  ifstream myfile(fileName);
  
  if (myfile.is_open()){
    while (myfile >> x){
      myfile >> y >> symb;
      pic[x][y] = symb;
    }
    cout << "Done" << endl;
  }
  else{
    cout << "Unable to open file";
  }
  myfile.close();

}

//------------------------------------------------------------
//Name: create
//PreCondition: User enetered 2
//PostCondition: The file is changed by the user's character
//------------------------------------------------------------
void create(char pic[MAX_VALUE][MAX_VALUE]){
  cout << "This will modify the current art." << endl;
  int x;
  int y;
  char symb;
  cout << "Enter x coordinate between " << MIN_VALUE << " and " << MAX_VALUE << ": " << endl;
  cin >> x;
  cout << "Enter y coordinate between " << MIN_VALUE << " and " << MAX_VALUE << ": " << endl;
  cin >> y;
  cout << "Enter the character for that location: " << endl;
  cin >> symb;
  pic[x][y] = symb;
}

//----------------------------------------------------------
//Name: display
//PreCondition: User entered 3
//PostCondition: The 2-D array is printed out
//----------------------------------------------------------
void display(char pic[MAX_VALUE][MAX_VALUE]){
  for (int i = 0; i < MAX_VALUE; i++){
    for (int j = 0; j < MAX_VALUE; j++){
      cout << pic[i][j];
    }
    cout << endl;
  }
}

//----------------------------------------------------------
//Name: rotate
//PreCondition: User entered 4
//PostCondition: Art is rotated 90 degrees clockwise
//----------------------------------------------------------
void rotate(char pic[MAX_VALUE][MAX_VALUE]){
  //makes an identical array to first
  char temp[MAX_VALUE][MAX_VALUE] = {{' '}};
  for (int i = 0; i < MAX_VALUE; i++){
    for (int j = 0; j < MAX_VALUE; j++){
      temp[i][j] = pic[i][j];
    }
  }
  //rotates pic
  for (int i = 0; i < MAX_VALUE; i++){
    for (int j = 0; j < MAX_VALUE; j++){
      pic[j][i] = temp[MAX_VALUE - 1 - i][j];
    }
  }
}

//-----------------------------------------------------------
//Name: invert
//PreCondition: User entered 5
//PostCondition: Art is inverted vertically or horizontally
//-----------------------------------------------------------
void invert(char pic[MAX_VALUE][MAX_VALUE]){
  //makes temp and identical array to pic
  char temp[MAX_VALUE][MAX_VALUE] = {{' '}};
  for (int i = 0; i < MAX_VALUE; i++){
    for (int j = 0; j < MAX_VALUE; j++){
      temp[i][j] = pic[i][j];
    }
  }
  
  int invert;
  cout << "Would you like to invert horizontally or vertically" << endl <<
    "1. Vertical" << endl << "2. Horizontal" << endl;
  cin >> invert;
  while (invert > 2 || invert < 1){
    cout << "Invalid input." << endl;
    cout << "Input 1. Vertical 2. Horizontal" << endl;
    cin >> invert;
  }
  switch(invert){
  case 1:
    //invert vertical
    for (int i = 0; i < MAX_VALUE; i++){
      for (int j = 0; j < MAX_VALUE; j++){
	pic[i][j] = temp[MAX_VALUE - 1 - i][j];
      }
    }
  break;
  case 2:
    //invert horizontal
    for (int i = 0; i < MAX_VALUE; i++){
      for (int j = 0; j < MAX_VALUE; j++){
	pic[i][j] = temp[i][MAX_VALUE - 1 - j];
      }
      break;
    }
  }
}

  

