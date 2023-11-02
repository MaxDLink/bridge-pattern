#include "algorithm.h"

class Sort : public Algorithm{
    public: 

    static std::vector <int> intData; 

    void Load(); 
    void Display(); 
    void Stats(); 
    void Save(); 

    void Select(int id); 
    void Execute(); 

    Sort(); 

    //Sort(const Sort&); //builder pattern, take in sort algo 
    Sort(const Sort* srt);
    Algorithm* Clone();

    //Builder Pattern 
    enum Configuration {
        RECURSIVE = 0, 
        ITERATIVE, 
        LIST, 
        MATRIX
    }; 

    void setExecutionType(Sort::Configuration exe); 
    void setStorageType(Sort::Configuration stg); 
    void getConfiguration();

    private: 
    void (*activeAlgo)(std::vector<int>&); //function pointer with a type of activeAlgo. Sort algorithm points to any object you want as long as you switch the function pointer. All abstracted away. 
    static std::vector<void(*)(std::vector<int>&)> algorithms; //vector of function pointers that are the pointers from line 20. Every search algo you have is going to have a function pointer here on line 21. Now you can switch which one becomes the active algorithm for your interface. Super useful!!! THIS STORES POINTERS TO IMPLEMENTATIONS THAT YOU CAN USE TO SWITCH IMPLEMENTATIONS!!! HEART OF BUILDER PATTERN! SEE MAIN FOR DYNAMIC SWITCH OF TASK!!! 
    //This can be used for flowscript. Instead of chaining executables together, can make a map or vector that holds all the flows. 
    //For the 1st approach you can point to a vector/map/hash table for all functions you've loaded, and you can look up the process and call execute on the process.... same as line 20 --> where are you in it? line 21 points to specific function stored in vector wrapped with functionality you need.... 

    Configuration executionType; 
    Configuration storageType;

    //sortAlgos.h is a different pattern file that is not shown here 
    //they are all template<typename T> functions so they can take any type of data for different situations 
}; 