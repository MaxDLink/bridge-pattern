#include "sort.h"
#include "sortalgos.h"
#include <iostream> 

std::vector <int> Sort::intData; 
std::vector<void(*)(std::vector<int>&)> Sort::algorithms;

Sort::Sort(){
    //Load Sorting Algos 
    Sort::algorithms.push_back(&SortAlgos<int>::bubbleSort); //SortAlgos is a different file that is not shown here, so this will error out 
    Sort::algorithms.push_back(&SortAlgos<int>::mergeSort);
    Sort::algorithms.push_back(&SortAlgos<int>::insertionSort);
    Sort::algorithms.push_back(&SortAlgos<int>::binaryTreeSort);

    activeAlgo = Sort::algorithms[Sort::SortingAlgos::BUBBLE]; //implementation stays the same but what you call under the hood changes 
}

void Sort::Load(){
    Sort::intData = {5,4,7,1,4,6,2}; 
}

void Sort::Display(){
    std::cout << "Data: "; 
    for(auto i : Sort::intData){
        std::cout << i << " ";
    }
    std::cout << std::endl; 
}

void Sort::Stats(){
    std::cout << "Stats: " << std::endl; 
}

void Sort::Select(int in){
    activeAlgo = Sort::algorithms[in]; 
}

void Sort::Execute(){
    activeAlgo(Sort::intData); 
}

void Sort::Save(){
    std::cout << "Save: " << std::endl; 
}

void Sort::setExecutionType(Sort::Configuration exe){
    executionType = exe; 
}

void Sort::setStorageType(Sort::Configuration stg){
    storageType = stg; 
}

void Sort::getConfiguration(){
    std::cout << "Execution Type: " << executionType << std::endl; 
    std::cout << "Storage Type: " << storageType << std::endl; 
}

Sort::Sort(const Sort *srt){ //star is incorrect, it should be an &. Star is incorrect because you have to 
//derefeerencing an object to get to its pointer--> this means the object exists, if you use the & it will not allow you to pass a pointer to where there is not an object. Good design to use & in .h
//Forcing them to go create the object first before passing. 
    executionType = srt->executionType;
    storageType = srt->storageType;
    activeAlgo = srt->activeAlgo;

}

// Sort::Sort(const Sort& srt) {
//     executionType = srt.executionType;
//     storageType = srt.storageType;
//     activeAlgo = srt.activeAlgo;
// }

//builder pattern and clone pattern can work together. Used clone is used to create copies of objects, lazy loading is moving image without having to load the entire page, stops page from freezing...  
Algorithm* Sort::Clone(){
    return new Sort(this);
}