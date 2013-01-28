#ifndef ASSOCARRAY_H
#define ASSOCARRAY_H

#include <iostream>
#include <vector>
#include <string>
//#include "zstring.h"

#define CT template <class T>
using namespace std;

//class ZString;
template <class T> class AssocArray;

typedef AssocArray<string> StrAsAr;
//typedef AssocArray<ZString> AsArZ;

template <class T> class AssocArray {
    public:
        AssocArray();
        T &at(int numindex);
        T &operator[](int numindex);
        T &at(string index);
        T &operator[](string index);
        string &getIndex(int numindex);
        string &I(int numindex);
        void push(T value);
        void clean(); // Remove empty entries
        unsigned size();
        AssocArray<T> shift();
        T &last();
        bool empty();
    private:
        struct Data {
            //Data();
            Data(string inx, int ninx, T val);
            string index;
            int numindex;
            T value;
        };
        vector<Data> data;
};

#include "asar.tpp"

#endif // ASSOCARRAY_H
