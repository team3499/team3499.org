
#include <stdio.h>
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