#include "sort.h"
#include "sortalgos.h"
#include <iostream> 
#include <vector> 

int main() {
    Sort algo; 

    algo.Load(); //loads data in 
    algo.Display(); //displays algo to console 
    algo.Execute(); //should do a sort 
    algo.Display(); //displays algo to console, post sort 

    //Builder pattern -- pattern is to switch dynamically at runtime to do something differnt by switching pointers inside... 
    algo.Select(Sort::SortingAlgos::MERGE); //selects merge sort
    algo.Load(); //loads data in
    algo.Display(); //displays algo to console
    algo.Execute(); //should do a sort
    algo.Display(); //displays algo to console, post sort


    // //builder pattern 
    // algo.setExecutionType(Sort::Configuration::ITERATIVE); 
    // algo.setStorageType(Sort::Configuration::LIST); 
    // algo.Select(Sort::SortingAlgos::BINARYTREE); 

    // algo.getConfiguration();

    // //cloning 
    // std::cout << "NEW ALGO: " << std::endl;
    // Sort* newAlgo = (Sort*)algo.Clone(); //clones algo and casted as sort *. software sets properties! 
    // newAlgo->getConfiguration(); //should be the same as algo.getConfiguration()
    // newAlgo->Load(); //loads data in
    // newAlgo->Display(); //displays algo to console
    // newAlgo->Execute(); //should do a sort
    // newAlgo->Display(); //displays algo to console, post sort. Should see a binary tree sort 

}