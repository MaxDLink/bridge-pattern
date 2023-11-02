#include <vector> 

class Algorithm{
    public: 
        virtual void Load(){};
        virtual void Display(){};
        virtual void Stats(){};
        virtual void Save(){};

        virtual void Select(int) = 0; 
        virtual void Execute() = 0; 

        virtual void Configure(){}; 

    //Prototype Pattern 
    virtual Algorithm* Clone() = 0; 
    Algorithm(const Algorithm&){
        //configure properties of algo object for prototype 
        
    }; 

    Algorithm(){}; 
    virtual ~Algorithm(){}; 

    enum SortingAlgos{
        BUBBLE = 0, 
        MERGE, 
        INSERTION, 
        BINARYTREE, 
        LAST //this is the last of the SortingAlgos 
    }; 

    enum SearchAlgo{
        DFS = Algorithm::SortingAlgos::LAST, //last added here so that you know where you left off in SortingAlgos.
        BFS
        // BFS, 
        // LAST //this is the last of the SearchAlgos  
    }; 
    //do not know how many algorithms you have, so you need to add LAST as a marker that tells you where the last algo is, you can do a for loop that starts at 0 and increments to last. This lets others add as many algorithms you want. 
    //essentially creating an index with the names of the sorting algorithms. Pass in 0 if you want BUBBLE etc. 
}; 