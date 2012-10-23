#include <stdlib.h>
#include <stdio.h>
// #include "stringclass.h"



/* B = Associator type, base -- usually a string in php
   V = Associated value  -- usually an array of sorts
   Also, dont get scared by the <class> part either.
   As well, the template <...> can go on the same line of class ... {
   but it looks nicer this way (subject to change).
   0 as an exit code means all is well.
   Positive means it worked, but not cleanly (example: deleted and element that didnt exist, created a preexisting element).
   Negative means it did not succed at all.*/
template <class B, class V>
class AssociativeArrayBase{
public:
    struct Data {
        B id;
        V value;
    };
private:
    Data *data[];
    unsigned int count;// NOTE: these are counting numbers.
    int unhandled[]; // this is for unhandled memory
    int unhCount;    // or, assumed to be unhandled memory.
public:
    AssociativeArrayBase();
    ~AssociativeArrayBase();
    
    bool doesIdExist(B id);
    
    int addElement(B id, V value);   // All arguments are called the same thing
    int addId(B id);
    
    int removeElement(B id);
    int removeAll();
    
    int rename(B oldId, B newId);
    
    int setValue(B id, V value);
    int clearValue(B id);
    
    int getValue(B id, V *value);
    V getValue(B id);
    
    //AssociativeArrayBase<B, V>::Data getElement(int index);
    //AssociativeArrayBase<B, V>::Data getElement(B id); // might break if B is an int
    
    V operator[] (B id) { 
        if (doesIdExist(id))
            return getValue(id);
        addId(id);
        return getValue(id); // WARNING: THIS WILL CAUSE A NULL POINTER EXCEPTION!
    };
    //public operator= {};
private:
    int getIndex(B id); // negative numbers are for errors
};

template <class B, class V>
AssociativeArrayBase<B,V>::AssociativeArrayBase(){
    count = 0;
    //data[0] = new Data;
    //B b("");
    //V v("");
    //data[0]->id = B("");
    //data[0]->value = V("");
    unhCount = 0;
}

template <class B, class V>
AssociativeArrayBase<B,V>::~AssociativeArrayBase(){
    removeAll();
    if(unhCount)
        delete[] unhandled;
}


template <class B, class V>
bool AssociativeArrayBase<B,V>::doesIdExist(B id){
    //if(!count) //count should also be == to zero...
    //    return false;
    for(int i = 1; i < count+1; i++){
        if(*(data[i]->id) == *id){
            return true;
        }
    }
    return false;
}


// This function does not generate the seg-fault.
template <class B, class V>
int AssociativeArrayBase<B,V>::addElement(B id, V value){
    if(doesIdExist(id))
        return 1;
    count++;
    data[count] = new Data;
    B newId(id);
    V newValue(value);
    data[count]->id = newId;
    data[count]->value = newValue;
    printf("New Element added with an ID = --%s--, a Value = --%s--, and a index of '%d'\n", data[count]->id->c_str(),  data[count]->value->c_str(), count);
    return 0;
}

template <class B, class V>
int AssociativeArrayBase<B,V>::addId(B id){
    if(doesIdExist(id))
        return 1;
    count++;
    data[count] = new Data;
    //if(!data[count])
    //    return -1;
    data[count]->id = id;
    return 0;
}

template <class B, class V>
int AssociativeArrayBase<B,V>::removeElement(B id){
    if(!doesIdExist(id))
        return 1;
    bool at = false;
    for(int i = 0; i < count; i++){
        if(at && i == count-1)
            delete data[i];
        else if(at){
            data[i] = data[i+1];
        }
        else if(data[i]->id == id) // OH CRAP! this might not work well with pointers. We may need to use a string class.
            at = true;
    }
    count--;
    return 0;
}

template <class B, class V>
int AssociativeArrayBase<B,V>::removeAll(){
    if(!count)
        return 0; // they are all gone.
//     delete[] data;
    //data = (Data **)NULL; // Yep. Got to do this.
    return 0;
}

template <class B, class V>
int AssociativeArrayBase<B,V>::rename(B oldId, B newId){
    if(!doesIdExist(oldId))
        return -1;
    if(doesIdExist(newId))
        return -2; // lol. the id already exists.
    data[getIndex(oldId)]->id = newId;
    if(!doesIdExist(newId))
        return -3; // it didnt work, says test one.
    if(doesIdExist(oldId))
        return -4; // it didnt work, says test two.
    return 0;
}

// Note: This has not been implemnted into other functions in this class yet, and maybe shouldnt.
// Returns negatory if failed.
template <class B, class V>
int AssociativeArrayBase<B,V>::getIndex(B id){ 
    if(!doesIdExist(id))
        return -1;
    printf("The DIDE passed on getIndex(B id)! (id = '%s')\n", id->c_str());
    for(int i = 1; i <= count; i++){ // This could also not have the i < count, see below.
        if(data[i]->id == id){
            return i;
        }
    }
    
    return -9000; // You broke math, logic, physics and the universe.
}


template <class B, class V>
int AssociativeArrayBase<B,V>::setValue(B id, V value){
    if(!doesIdExist(id))
        return -1;
    data[getIndex(id)]->value = value;
    return 0;// No error checking here.
}

template <class B, class V>
int AssociativeArrayBase<B,V>::clearValue(B id){
    if(!doesIdExist(id))
        return -1;
    data[getIndex(id)]->value = new V;
    return 0;// No error checking here.
}


template <class B, class V>
int AssociativeArrayBase<B,V>::getValue(B id, V *value){ // i dont even know if you can do this.
    if(!doesIdExist(id))                                 // also, this might turn into a array of sorts depending on the V type.
        return -1;
    int ret = 0;
    if(value != NULL){
        unhCount++;
        unhandled[unhCount] = new int; // this is kind of pointless, but is a cool concept in general.
        unhandled[unhCount] = value;   // it would be best to have this be its own base class and have things extend it.
        ret = 1;
    }
    *value = *data[getIndex(id)]->value; // its been a while since ive had to use pointers like this, so it *might* need a correction.
    return ret;
}

template <class B, class V>
V AssociativeArrayBase<B,V>::getValue(B id){
    printf("getValue(B id): Getting Value of '%s'\n", id->c_str());
    if(!doesIdExist(id))
        return (V) 0; // Negative 1
    printf("getValue(B id): DIDE Passed, Getting Value of '%s'\n", id->c_str());
    return data[getIndex(id)]->value; // Note: if type V is a pointer already, or a class/struct, this will return its address.
}


/*
template <class B, class V>
AssociativeArrayBase<B,V>::
*/

//really good laugh: http://www.cplusplus.com/forum/articles/17108/
// apparently someone doesnt know that int** is the same as int[][].