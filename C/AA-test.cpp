#include "associativearray.h"
#include <stdio.h>
// #include "stringclass.h"
#include <string>
#include <string.h>

class String : public std::string{
public:
    String(char const *str): std::string(str) {};
    
    String *getThis(){ printf("Returning this. value = '%s'. this = '%lld'\n", this->c_str(), (unsigned long long)(void *)this); return this; };
    
    bool operator== (String str) { printf("Comparing '%s' to '%s'\n",this->c_str(), str.c_str());
        if (this->compare(str.c_str()) == 0) return true; return false;}
    bool operator== (String *str) { printf("Comparing '%s' to '%s'\n",this->c_str(), str->c_str());
        if (this->compare(str->c_str()) == 0) return true; return false;}
    bool operator!= (String str) { printf("Comparing '%s' to '%s'\n",this->c_str(),str.c_str());
        if (this->compare(str.c_str()) == 0) return false; return true;}
    bool operator!= (String *str) { printf("Comparing '%s' to '%s'\n",this->c_str(),str->c_str());
        if (this->compare(str->c_str()) == 0) return false; return true;}
};

int main(int argc, char *argv[]){
    
    String *id1  = new String("ID1");
    String *va1  = new String("VALUE1");
//    String *str3 = new String("ID1");
//     if(*str == *str2){ printf("They _ and 2 are equal!\n");}
//     if(*str != *str2){ printf("They _ and 2 are unequal!\n");}
//     if(*str == *str3){ printf("They _ and 3 are equal!\n");}
//     if(*str != *str3){ printf("They _ and 3 are unequal!\n");}
    
//     String *id1("ID1");
//     String *va1("VALUE1");
//     String str3 = new String("ID1");
    
    // A new AAB object created with both types as character pointers, (strings).
    AssociativeArrayBase<String*, String*> aab; // WARNING: for now, this NEEDS to be a pointer!
    printf("(std::string, std::string) Object Created.\n");

    // add the first entry
    //std::string id1;// id1 = (char *)malloc(sizeof(char)*501); strcpy(id1, "ID1\0");
   // std::string va1;// va1 = (char *)malloc(sizeof(char)*501); strcpy(va1, "VALUE 1\0");
    //id1 = "ID1";
    //va1 = "VALUE1";
    printf("New element added with id of '%s' and a value of '%s'\n", id1->c_str(), va1->c_str());
    aab.addElement(id1, va1);
    printf("New element added with id of '%s' and a value of '%s'\n", id1->c_str(), va1->c_str());
    
    // retreive first entry
    //printf("Retreiving the first entry (of id '%s'), we get a value of '%s'\n", id1->c_str(), aab.getValue(id1)->c_str());
    printf("Getting the value of id ID1 using the [] method. Value = '%s'\n",aab[id1]->c_str());
    //*(aab[id1]) = *(str3);
    *aab[id1] = *(new String("Hi"));
    printf("Getting the value of id ID1 using the [] method. Value = '%s'\n",aab[id1]->c_str());
    *aab[id1] = "bye";
    printf("Getting the value of id ID1 using the [] method. Value = '%s'\n",aab[id1]->c_str());
    String *t = new String("test");
    *aab[t] = "WASSUP";
    printf("Getting the value of id ID1 using the [] method. Value = '%s'\n",aab[t]->c_str());
    //delete[] va1;
    //delete[] id1;
}