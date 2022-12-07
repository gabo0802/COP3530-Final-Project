#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <string>

#include<bits/stdc++.h>

#include "mergesort.h"
#include "quicksort.h"
#include "radixsort.h"

using namespace std;
using namespace std::chrono;
using namespace bridges;

//Random ActorMovieIMDB generator by Mason Enojo
//created so there would be minimum 100,000 data values
void hundredKDataGenerator(vector<ActorMovieIMDB>& movieInfo) {
    //35 possible words in the title
    vector<string> titles = {"The", "Out", "Down", "Late", "West", "Gun", "Country", "Road", "Man", "Day", "When", "House", "With", "Dawn", "Love", "Secret", "Live", "Doctor", "Midnight", "Back", "King", "Return", "Meet", "Star", "New", "Under", "This", "Last", "Boy", "War", "Not", "Life", "Great", "One", "Up"};

    //17 possible names
    vector<string> names = {"Kim", "Jimmy", "Mike", "Howard", "Francesca", "Skyler", "Emilio", "Jesse", "Jane", "Walter", "Marie", "Hank", "Gustavo", "Eduardo", "Ignacio", "Charles", "Steve"};

    //10 possible genres
    vector<string> genres = {"Action", "Adventure", "Comedy", "Drama", "Fantasy", "Horror", "Mystery", "Romance", "Thriller", "Western"};

  string newName;
  string newTitle;
  string genre;
  vector<string> genreList;
  int rand1;
  int rand2;
  string rating;
  float floatRating;
  
  int cappedValue = 100000 - movieInfo.size();
  //pushes new random data to vector<ActorMovieIMDB> movieInfo, to total 100000 unique sets
  for (int i = 0; i < cappedValue; i++) {
    for (int j = 0; j < 2; j++) {
        newName += names.at(rand() % 17);
      if (j != 1) {
        newName += ", ";
        }
    }
    for (int j = 0; j < 3; j++) {
        newTitle += titles.at(rand() % 35);
        newTitle += " ";
    }
    newTitle += "(" + to_string(rand() % 80 + 1940) + ")";

    //makes 1 the lowest possible rating
    rand1 = rand() % 9 + 1;
    rand2 = rand() % 10;
    rating = to_string(rand1) + "." + to_string(rand2);
    floatRating = stof(rating);
    
    genre = genres.at(rand() % 10);
    genreList = {genre};

    movieInfo.push_back(ActorMovieIMDB(newName, newTitle, floatRating, genreList));

    //resets the name and title to empty strings since they are appended new words during each loop
    newName = "";
    newTitle = "";
  }
}

//All code in the main file from here on out was done by Gabriel Castejon
//Also rewrote parts of the ActorMovieIMDB.h and DataSource.h files

//Used to reuse code when printing the lists
void listPrinter(vector<ActorMovieIMDB>& actor_list, bool lastLoop) {

  string input;
  int integerInput;
  //cout << actor_list.size() << endl;
  
  while(lastLoop) {
    cout << endl;
    cout << "Now that the list is sorted, which would you like to see:\n" 
    << "1. Top 10 Movies\n"
    <<"2. Top 50\n" << "3. Top 100\n" << "4. Bottom 10\n"
    <<"5. Bottom 50\n" << "6. Bottom 100\n" << "7. Exit" << endl;
      cin >> input;
    if(input.length() == 0 || !isdigit(input[0]) || input.length() > 1) {
      cout << "Please type in a valid input." << endl;
      continue;
    }
    integerInput = stoi(input);
    if(integerInput > 7 || integerInput < 1) {
       cout << "Please type a digit between 1 and 7." << endl;
      continue;
    }
  switch(integerInput) {
    case 1:   
      for(int i = 0; i < 10; i++) {
        cout << i+1 << ". Movie: " << actor_list[i].getMovie()
          << ", Main Actor: " << actor_list[i].getActor() 
          << ", Rating: " << setprecision(1) << actor_list[i].getMovieRating()
          << ", Main Genre: " << actor_list[i].getMainGenre() << endl;
      }
      break;
    case 2:
      for(int i = 0; i < 50; i++) {
        cout << i+1 << ". Movie: " << actor_list[i].getMovie()
          << ", Main Actor: " << actor_list[i].getActor() 
          << ", Rating: " << setprecision(1) << actor_list[i].getMovieRating()
          << ", Main Genre: " << actor_list[i].getMainGenre() << endl;
      }
      break;
    case 3:
      for(int i = 0; i < 100; i++) {
        cout << i+1 << ". Movie: " << actor_list[i].getMovie()
          << ", Main Actor: " << actor_list[i].getActor() 
          << ", Rating: " << setprecision(1) << actor_list[i].getMovieRating()
          << ", Main Genre: " << actor_list[i].getMainGenre() << endl;
      }
      break;
    case 4:
      for(int i = actor_list.size()-1; i > actor_list.size()-11; i--) {
        cout << actor_list.size()-i << ". Movie: " << actor_list[i].getMovie()
          << ", Main Actor: " << actor_list[i].getActor() 
          << ", Rating: " << setprecision(1) << actor_list[i].getMovieRating()
          << ", Main Genre: " << actor_list[i].getMainGenre() << endl;
      }
      break;
    case 5:
      for(int i = actor_list.size()-1; i > actor_list.size()-51; i--) {
        cout <<actor_list.size()-i << ". Movie: " << actor_list[i].getMovie()
          << ", Main Actor: " << actor_list[i].getActor() 
          << ", Rating: " << setprecision(1) << actor_list[i].getMovieRating()
          << ", Main Genre: " << actor_list[i].getMainGenre() << endl;
      }
      break;
    case 6:
      for(int i = actor_list.size()-1; i > actor_list.size()-101; i--) {
        cout << actor_list.size()-i << ". Movie: " << actor_list[i].getMovie()
          << ", Main Actor: " << actor_list[i].getActor() 
          << ", Rating: " << setprecision(1) << actor_list[i].getMovieRating()
          << ", Main Genre: " << actor_list[i].getMainGenre() << endl;
      }
      break;
    default:
      lastLoop = false;
      cout << endl;
      break;
    }
  }
}

//Used to reuse code when sorting
void sorter(vector<ActorMovieIMDB>& actor_list, int sortState) {
  
  string input;
  int integerInput;
  bool curLoop = true;
  bool lastLoop = true;
  
  if(sortState == 2) {
      while(curLoop) {
      cout << "Which sorting mechanism would you like to use:\n" 
        << "1. Merge Sort\n"
        << "2. Quick Sort\n" 
        << "3. Radix Sort" << endl;
      cin >> input;
      if(input.length() == 0 || !isdigit(input[0]) || input.length() > 1) {
        cout << "Please type in a valid input." << endl;
        continue;
      }
      integerInput = stoi(input);
      if(integerInput > 3 || integerInput < 1) {
         cout << "Please type a digit between 1 and 3." << endl;
        continue;
      }
      // std::chrono library: https://en.cppreference.com/w/cpp/chrono 
      cout << "Setting sort state..." << endl;
      for(int i = 0; i < actor_list.size(); i++) {
        //sets the sort state to the appropriate one so the operator overloading works.
          actor_list[i].setSortState(sortState); 
      }
      cout << "Sort state set, beginning sort..." << endl;
      auto start = high_resolution_clock::now();
      if(integerInput == 1) {
        actor_list = MergeSort<ActorMovieIMDB>::sortDescending(actor_list);
      } else if(integerInput == 2) {
        actor_list = QuickSort<ActorMovieIMDB>::sortDescending(actor_list,0,actor_list.size()-1);
      } else {
        actor_list = RadixSort::sortDescending(actor_list);
        //Might work now.
      }
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      double newDur = duration.count() / 1000000.0;
      cout << "List has been sorted, it took " << setprecision (3) << fixed << newDur << " seconds to sort!" << endl;
      //Calls function that allows us to reuse code for printing.
      listPrinter(actor_list, lastLoop);
      //We reached the end, which means that we had valid inputs throughout, we break out of the loop
      break;
    }
  }
  else  {
      while(curLoop) {
      cout << "Which sorting mechanism would you like to use: (Radix Sort is not available for strings)\n" 
        << "1. Merge Sort\n"
        << "2. Quick Sort\n";
      cin >> input;
      if(input.length() == 0 || !isdigit(input[0]) || input.length() > 1) {
        cout << "Please type in a valid input." << endl;
        continue;
      }
      integerInput = stoi(input);
      if(integerInput > 2 || integerInput < 1) {
         cout << "Please type a digit between 1 and 2." << endl;
        continue;
      }
      // std::chrono library: https://en.cppreference.com/w/cpp/chrono 
      cout << "Setting sort state..." << endl;
      for(int i = 0; i < actor_list.size(); i++) {
        //sets the sort state to the appropriate one so the operator overloading works.
          actor_list[i].setSortState(sortState); 
      }
      cout << "Sort state set, beginning sort..." << endl;
      auto start = high_resolution_clock::now();
      if(integerInput == 1) {
        actor_list = MergeSort<ActorMovieIMDB>::sortAscending(actor_list);
      } else {
        actor_list = QuickSort<ActorMovieIMDB>::sortAscending(actor_list,0,actor_list.size()-1);
      }
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      double newDur = duration.count() / 1000000.0;
      cout << "List has been sorted, it took " << setprecision (3) << fixed << newDur << " seconds to sort!" << endl;
      //Calls function that allows us to reuse code for printing.
      listPrinter(actor_list, lastLoop);
      //We reached the end, which means that we had valid inputs throughout, we break out of the loop
      break;
    }
  }
}

//Main Function by Gabriel Castejon
int main() { 

  cout << " __________________________________________ \n" <<
      "|                                          |\n" <<
      "|         Welcome to the IMDB              |\n" <<
      "|         Database Comparator!             |\n" <<
      "|                                          |\n" <<
      "|               Made by:                   |\n" <<
      "|           Vladmir Alekseev               |\n" <<
      "|           Gabriel Castejon               |\n" <<
      "|             Mason Enojo                  |\n" <<
      "| ________________________________________ |\n\n" << endl;

   cout << "Loading data..." << endl;
  
   //Bridges implementation derived from our extra-credit opportunity
   Bridges bridges(1, "gabo0802", "991647485757");
   DataSource ds (&bridges);

  //Max # of IMDB data 1 is 1813
  //Max # of IMDB data 2 is 483, total is 2296 
  //getActorMovieIMDBData2() was modified to push all 2296 input values
  
  //See DataSource.h file for a description of how getActorMovieIMDBData2() was altered
  //See ActorMovieIMDB.h file to see how comparison operators and initialization of the data objects were altered
  vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData2();
  
  //For the 100000 movie case, we generate a separate list
  vector<ActorMovieIMDB> bigList = ds.getActorMovieIMDBData2();
  
  //creates 100,000 data points by appending randomly generated values to the original data set
  hundredKDataGenerator(bigList); 

  //Should always be true, we break out of the loop by using break;
  bool isInMenu = true;
  while(isInMenu) {

    cout << "Please select from the following: \n"
      << "Sort data by:\n1. Movie*\n2. Main Actor*\n" 
      << "3. Rating \n4. Main Genre**\n"
      << "5. 100000 Sort Case (also by Rating)\n" 
      << "6. Exit\n*Data would be sorted in alphabetical order\n"
      << "**The first Genre in a movie's list would be selected" << endl;
  
    string input;
    cin >> input;
    //if it is not even a digit or the length is too big, we go back:
    if(input.length() == 0 || !isdigit(input[0]) || input.length() > 1) {
      cout << "Please type in a valid input." << endl;
      continue;
    }
    int integerInput = stoi(input);
    //If it is not in rage, we go back:
    if(integerInput > 6 || integerInput < 1) {
       cout << "Please type a digit between 1 and 6." << endl;
      continue;
    }
    switch(integerInput) {
      case 1:
        sorter(actor_list, 1);
        break;
      case 2:
        sorter(actor_list, 0);
        break;
      case 3:
        sorter(actor_list, 2);
        break;
      case 4:
        sorter(actor_list, 3);
        break;
      case 5:
        sorter(bigList, 2);
        break;
      case 6:
        cout << "Thanks for using this application, Goodbye!" << endl;
        isInMenu = false;
        break;
      default:
        cout << "This should not be happening." << endl;
        break;
    }
  }
}