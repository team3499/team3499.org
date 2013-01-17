#include "zstring.h"

ZString::ZString(){
    data = "";
}

ZString &ZString::operator=(ZString str){
    data = str.str();
    return *this;
}
ZString ZString::operator+(ZString str){
    return ZString(data.append(str.str()));
}
ZString &ZString::operator+=(ZString str){
    data = data.append(str.str());
    return *this;
}
ZString &ZString::operator<<(ZString str){
    return operator+=(str);
}

ZString::ZString(std::string str){
    operator=(str);
}
ZString &ZString::operator=(std::string str){
    data = str;
    return *this;
}
inline bool ZString::operator==(const std::string rhs){
    if(data == rhs){
        return true;
    }
    return false;
}
ZString ZString::operator+(std::string str){
    return ZString(data.append(str));
}
ZString &ZString::operator+=(std::string str){
    data = data.append(str);
    return *this;
}
ZString &ZString::operator<<(std::string str){
    return operator+=(str);
}
std::string &ZString::str(){
    return data;
}

#ifdef USE_QT
ZString::ZString(QString str){
    operator=(str);
}
ZString &ZString::operator=(QString str){
    data = str.toStdString();
    return *this;
}
inline bool ZString::operator==(const QString rhs){
    ZString comp = rhs;
    if(data == comp.str()){
        return true;
    }
    return false;
}
ZString ZString::operator+(QString str){
    return ZString(data.append(ZString(str).str()));
}
ZString &ZString::operator+=(QString str){
    data = data.append(ZString(str).str());
    return *this;
}
ZString &ZString::operator<<(QString str){
    return operator+=(str);
}
QString ZString::QS(){
    return QString::fromStdString(data);
}

ZString::ZString(QByteArray str){
    operator=(str);
}
ZString &ZString::operator=(QByteArray str){
    data = QString(str).toStdString();
    return *this;
}
inline bool ZString::operator==(const QByteArray rhs){
    ZString comp = rhs;
    if(data == comp.str()){
        return true;
    }
    return false;
}
ZString ZString::operator+(QByteArray str){
    return ZString(data.append(ZString(str).str()));
}
ZString &ZString::operator+=(QByteArray str){
    data = data.append(ZString(str).str());
    return *this;
}
ZString &ZString::operator<<(QByteArray str){
    return operator+=(str);
}
QByteArray ZString::QBA(){
    return QByteArray(data.c_str());
}
#endif

ZString::ZString(char *str){
    operator=(str);
}
ZString &ZString::operator=(char *str){
    data = str;
    return *this;
}
inline bool ZString::operator==(char *rhs){
    ZString comp = rhs;
    if(data == comp.str()){
        return true;
    }
    return false;
}
ZString ZString::operator+(char *str){
    return ZString(data.append(ZString(str).str()));
}
ZString &ZString::operator+=(char *str){
    data = data.append(ZString(str).str());
    return *this;
}
ZString &ZString::operator<<(char *str){
    return operator+=(str);
}
char* ZString::c(){
    char str[size()];
    return strcpy(str, data.c_str());
}

ZString::ZString(const char *str){
    operator=(str);
}
ZString &ZString::operator=(const char *str){
    data = str;
    return *this;
}
bool ZString::operator==(const char *rhs){
    ZString comp = rhs;
    if(data == comp.str()){
        return true;
    }
    return false;
}
ZString ZString::operator+(const char *str){
    return ZString(data.append(ZString(str).str()));
}
ZString &ZString::operator+=(const char *str){
    data = data.append(ZString(str).str());
    return *this;
}
ZString &ZString::operator<<(const char *str){
    return operator+=(str);
}
const char* ZString::cc(){
    return data.c_str();
}

ZString::ZString(char str){
    operator=(str);
}
ZString &ZString::operator=(char str){
    data = "";
    data[0] = str;
    return *this;
}
ZString ZString::operator+(char str){
    return ZString(data.append(ZString(str).str()));
}
ZString &ZString::operator+=(char str){
    data = data.append(ZString(str).str());
    return *this;
}
ZString &ZString::operator<<(char str){
    return operator+=(str);
}

#ifdef USE_QT
ZString::ZString(qint64 num){
    const char *str = reinterpret_cast<const char *>(&num);
    //std::stringstream ss; std::string out;
    //ss << num; ss >> out;
    data = str;
}
#endif
ZString::ZString(int num){
    std::stringstream ss; std::string out;
    ss << num; ss >> out;
    data = out;
}

int ZString::size(){
    return data.size();
}
int ZString::length(){
    return data.length();
}

int ZString::count(std::string needle){
    std::string haystack = data;
    int count = 0;
    for(unsigned i = 0; i < haystack.length(); ++i){
        if(haystack[i] == needle[0]){
            bool good = true;
            for(unsigned g = i, j = 0; j < needle.length(); ++g, ++j){
                if(haystack[g] != needle[j]){
                    good = false;
                    break;
                }
            }
            if(good)
                ++count;
        }
    }
    return count;
}

ZString &ZString::replace(std::string before, std::string after){
    std::string tmpdata = data;
    data = "";
    for(unsigned i = 0; i < tmpdata.length(); ++i){
        if(tmpdata[i] == before[0]){
            bool match = true;
            int last = 0;
            for(unsigned j = 0; j < before.length(); ++j){
                if(tmpdata[i+j] != before[j]){
                    match = false;
                    break;
                }
                last = i + j;
            }
            if(match){
                std::string pre = tmpdata.substr(0, i);
                std::string suff = tmpdata.substr(last+1);
                data = data.append(pre).append(after);
                tmpdata = suff;
                i = -1;
            }
        }
    }
    data = data.append(tmpdata);
    return *this;
}
void ZString::label(std::string labeltxt, ZString value){
    std::string label = std::string("<?").append(labeltxt).append("?>");
    replace(label, value.str());
}
void ZString::label(AsArZ values){
    for(int i = 0; i < values.size(); ++i)
        label(values.getIndex(i), values[i]);
}
AsArZ ZString::explode(char delim){
    AsArZ out;
    std::string str = data;
    for(unsigned i = 0; i < str.length(); ++i){
        if(str[i] == '"'){
            for(unsigned j = i; j < str.length(); ++j){
                if(str[j] == '"'){
                    out.push(str.substr(0, j));
                    str = str.substr(j+1, str.length());
                    i = -1;
                }
            }
        } else if(str[i] == delim){
            out.push(str.substr(0, i));
            str = str.substr(i+1, str.length());
            i = -1;
        }
    }
    out.push(str);
    return out;
}
AsArZ ZString::strict_explode(char delim){
    AsArZ out;
    std::string str = data;
    for(unsigned i = 0; i < str.length(); ++i){
        if(str[i] == delim && str[i-1] != '\\'){
            string substr = str.substr(0, i);
            if(substr != ""){
                out.push(substr);
            }
            str = str.substr(i+1, str.length());
            i = -1;
        }
    }
    out.push(str);
    return out;
}

ZString ZString::strip(char target){
    ZString tmp = data;
    for(unsigned i = 0; i < data.length(); ++i){
        if(data[i] == target){
            tmp = data.substr(i+1, data.length());
        } else {
            break;
        }
    }
    data = tmp.str();
    for(unsigned i = 0; i < data.length(); ++i){
        int curr = data.length() - 1 - i;
        if(data[curr] == target){
            tmp = data.substr(0, curr);
        } else {
            break;
        }
    }
    data = tmp.str();
    return tmp;
}

ZString &ZString::substr(int pos){
    data.substr(pos);
    return *this;
}

ZString &ZString::substr(int pos, int npos){
    data.substr(pos, npos);
    return *this;
}

ZString ZString::toJSON(AsArZ arr){
    ZString tmp("{");
    for(int i = 0; i < arr.size(); ++i){
        ZString temp = arr[i];
        temp.replace("\"", "\\\"");
        //temp.replace(",", "\\,");
        tmp << "\"" << arr.getIndex(i) << "\":\"" << temp << "\", ";
    }
    tmp = tmp.str().substr(0, tmp.length() - 2);
    tmp << "}";
    data = tmp.str();
    return tmp;
}

AsArZ ZString::fromJSON(){
    AsArZ final;
    ZString copy = data;
    copy.strip(' ');
    copy.strip('{');
    copy.strip('}');
    AsArZ tmp = copy.strict_explode(',');
    tmp.clean();
    for(int i = 0; i < tmp.size(); ++i){
        tmp[i].strip(' ');
    }
    for(int i = 0; i < tmp.size(); ++i){
        AsArZ subtmp = tmp[i].strict_explode(':');
        final[subtmp[0].strip('"').str()] = subtmp[1].strip('"');
    }
    return final;
}
