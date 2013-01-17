//#include "asar.h"

#ifndef ASAR_TMP
 #include "asar.h"
#endif

CT AssocArray<T>::AssocArray(){}

CT T &AssocArray<T>::at(int numindex){
    if(numindex < (int)data.size()){
        return data[numindex].value;
    }
    for(unsigned i = 0; i < data.size(); ++i){
        if(data[i].numindex == numindex){
            return data[i].value;
        }
    }
    data.push_back(Data("", numindex, T()));
    return data[data.size() - 1].value;
}

CT T &AssocArray<T>::operator[](int numindex){
    return at(numindex);
}

CT T &AssocArray<T>::at(string index){
    for(unsigned i = 0; i < data.size(); ++i){
        if(data[i].index == index)
            return data[i].value;
    }
    data.push_back(Data(index, data.size(), T()));
    return data[data.size() - 1].value;
}

CT T &AssocArray<T>::operator[](string index){
    return at(index);
}

CT string &AssocArray<T>::getIndex(int numindex){
    if(numindex < (int)data.size())
        return data[numindex].index;
    for(unsigned i = 0; i < data.size(); ++i){
        if(data[i].numindex == numindex)
            return data[i].index;
    }
    data.push_back(Data("", numindex, T()));
    return data[data.size() - 1].index;
}

CT string &AssocArray<T>::I(int numindex){
    return getIndex(numindex);
}

CT void AssocArray<T>::push(T value){
    operator[](size()) = value;
}

CT void AssocArray<T>::clean(){
    vector<Data> tmp;
    for(unsigned i = 0; i < data.size(); ++i){
        Data tmpem = data[i];
        if(!(tmpem.value == ""))
            tmp.push_back(Data(tmpem.index, i, tmpem.value));
    }
    data = tmp;
}

CT unsigned AssocArray<T>::size(){
    return data.size();
}

CT AssocArray<T> AssocArray<T>::shift(){
    vector<Data> tmp;
    for(unsigned i = 1; i < data.size(); ++i)
        tmp.push_back(Data(data[i].index, i, data[i].value));
    data = tmp;
    return *this;
}

CT T &AssocArray<T>::last(){
    return data[data.size() - 1].value;
}

CT bool AssocArray<T>::empty(){
    if(data.size() <= 0){
        return true;
    }
    return false;
}

CT void AssocArray<T>::print(){
    cout << "Size: " << size() << endl;
    for(int i = 0; i < size(); ++i){
        cout << i << " " << getIndex(i) << " = -" << at(i).str() << "-" << endl;
    }
}

CT AssocArray<T>::Data::Data(string inx, int ninx, T val){
    index = inx;
    numindex = ninx;
    value = val;
}

/*template <class T> ZString AssocArray<T>::toString(){
    ZString tmp("{");
    for(int i = 0; i < size(); ++i){
        ZString temp = operator[](i);
        temp.replace("\"", "\\\"");
        tmp << "\"" << getIndex(i) << "\":\"" << temp << "\", ";
    }
    tmp = tmp.str().substr(0, tmp.length() - 2);
    tmp << "}";
    return tmp;
}*/

//template class AssocArray<string>;
//template class AssocArray<ZString>;
