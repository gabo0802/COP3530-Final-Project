#include <iostream>
#include <vector>
#include <algorithm>    // std::reverse
using namespace std;

template <typename T>
class MergeSort {

private:
static vector<T> merge(vector<T> vectorOne, vector<T> vectorTwo) {
  vector<T> finalVector;
  int vectorOneIndex = 0;
  int vectorTwoIndex = 0;
  
  while(vectorTwoIndex < vectorTwo.size() || vectorOneIndex < vectorOne.size()){
    if(vectorTwoIndex == vectorTwo.size() || (vectorOneIndex != vectorOne.size() && vectorOne.at(vectorOneIndex) < vectorTwo.at(vectorTwoIndex))){
        finalVector.emplace_back(vectorOne.at(vectorOneIndex));
        vectorOneIndex += 1;
    } else {
        finalVector.emplace_back(vectorTwo.at(vectorTwoIndex));
        vectorTwoIndex += 1;
    } 
  }
  
  return finalVector;
}

public:
static vector<T> sortAscending(vector<T> inputVector) {  
  if (inputVector.size() == 1) {
    return inputVector;
  } else {
    // get middle
    int middleIndex = inputVector.size() / 2;
    if (inputVector.size() % 2 == 1) {
      middleIndex++;
    }

    // split into two vectors
    vector<T> rightVector;

    while (inputVector.size() != middleIndex) {
      rightVector.insert(rightVector.begin(), inputVector.back());
      inputVector.pop_back();
    }

    // continue split
    vector<T> leftVector = sortAscending(inputVector);
    rightVector = sortAscending(rightVector);

    // merge vectors
    return merge(leftVector, rightVector);
  }
}

 static vector<T> sortDescending(vector<T> input){
    input = sortAscending(input);
    reverse(input.begin(), input.end());
    return input;
}

};//Vladimir Alekseev