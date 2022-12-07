#include <iostream>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/ActorMovieIMDB.h"
#include <algorithm>    // std::reverse

using namespace std;
using namespace bridges;
//based off code at https://www.geeksforgeeks.org/radix-sort/

class RadixSort {
    //only works for integers (or doubles, if converted to integers) and doesn't work for negative values
    private:

    static int toInteger(double input){
      input *= 10.0;
      return int(input);
    }

    static int getMax(vector<ActorMovieIMDB> input){
            int maxValue = toInteger(input.at(0).getMovieRating());
            
            for(int i = 0; i < input.size(); i++){
               if(toInteger(input.at(i).getMovieRating())  > maxValue){
                  maxValue = toInteger(input.at(i).getMovieRating());
               }     
            }

            return maxValue;
   }

    static int getDigits(int value){
      int digits = 0;

      while(value != 0){
          digits += 1;
          value /= 10;
      }

      return digits;
   }

    static vector<ActorMovieIMDB> countSort(vector<ActorMovieIMDB> input, int digits, int exp){
          vector<ActorMovieIMDB> output = input;
          vector<int> count;
       
          for(int i = 0; i < digits; i++){
            count.emplace_back(0);
          }

          for(int i = 0; i < input.size(); i++){
            count.at((toInteger(input.at(i).getMovieRating()) / exp) % digits) += 1;
          }

          for(int i = 1; i < digits; i++){
            count.at(i) += count.at(i-1);
          }

          for(int i = input.size() - 1; i >= 0; i--){
            output.at(count.at((toInteger(input.at(i).getMovieRating()) / exp) % digits) - 1) = input.at(i);
            count.at((toInteger(input.at(i).getMovieRating()) / exp) % digits) -= 1;
          }
          
          return output;
    }

    public:
    static vector<ActorMovieIMDB> sortAscending(vector<ActorMovieIMDB> input){
          int maxInt = getMax(input);
          int numDigits = getDigits(maxInt);

          for(int exp = 1; maxInt / exp > 0; exp *= 10){
              //cout << exp << endl;
              input = countSort(input, 10, exp);
          }

          return input;
    }

    static vector<ActorMovieIMDB> sortDescending(vector<ActorMovieIMDB> input){
        input = sortAscending(input);
        reverse(input.begin(), input.end());
        return input;
    }

    
};//Vladimir Alekseev