#include "zstring.h"

ZString::ZString(){
    data = "";
}

ZString &ZString::operator=(ZString str){
    data = str.str();
    return *this;
}
bool ZString::operator==(ZString str){
    if(data == str.str())
        return true;
    return false;
}
bool ZString::operator!=(ZString str){
    if(data != str.str())
        return true;
    return false;
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
bool ZString::operator==(const std::string rhs){
    if(data == rhs)
        return true;
    return false;
}
bool ZString::operator!=(const std::string rhs){
    if(data != rhs)
        return true;
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

#ifdef ZSTRING_USE_QT
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
bool ZString::operator==(char *rhs){
    ZString comp = rhs;
    if(data == comp.str())
        return true;
    return false;
}
bool ZString::operator!=(char *rhs){
    ZString comp = rhs;
    if(data != comp.str())
        return true;
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
    if(data == comp.str())
        return true;
    return false;
}
bool ZString::operator!=(const char *rhs){
    ZString comp = rhs;
    if(data != comp.str())
        return true;
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
    data.clear();
    data += str;
    return *this;
}
ZString ZString::operator+(char str){
    return ZString(data.append(ZString(str).str()));
}
ZString &ZString::operator+=(char str){
    data += str;
    return *this;
}
ZString &ZString::operator<<(char str){
    return operator+=(str);
}

#ifdef ZSTRING_USE_QT
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
int ZString::tint(){
    const char *str = data.c_str();
    return atoi(str);
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

ZString ZString::replace(std::string before, std::string after, bool modify){
    std::string tmpdata = data;
    std::string tmp = "";
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
                tmp = tmp.append(pre).append(after);
                tmpdata = suff;
                i = -1;
            }
        }
    }
    tmp = tmp.append(tmpdata);

    if(modify){
        data = tmp;
        return ZString(data);
    } else {
        return ZString(tmp);
    }
}

ZString ZString::label(AsArZ values, bool modify){
    for(unsigned i = 0; i < values.size(); ++i)
        label(values.getIndex(i), values[i], modify);
    return ZString(data);
}
ZString ZString::label(std::string labeltxt, ZString value, bool modify){
    std::string label = std::string("<?").append(labeltxt).append("?>");
    return replace(label, value.str(), modify);
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

ZString ZString::strip(char target, bool modify){
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

    if(modify){
        data = tmp.str();
        return ZString(data);
    } else {
        return tmp;
    }
}

ZString ZString::substr(int pos, bool modify){
    std::string tmp = data;
    tmp.substr(pos);

    if(modify){
        data = tmp;
        return ZString(data);
    } else {
        return ZString(tmp);
    }
}

ZString ZString::substr(int pos, int npos, bool modify){
    std::string tmp = data;
    tmp.substr(pos, npos);

    if(modify){
        data = tmp;
        return ZString(data);
    } else {
        return ZString(tmp);
    }
}

ZString ZString::invert(bool modify){
    std::string buff;
    for(unsigned i = data.length(); i > 0; --i){
        buff += data[i];
    }

    if(modify){
        data = buff;
        return ZString(data);
    } else {
        return ZString(buff);
    }
}

ZString ZString::toLower(bool modify){
    std::string tmp = data;
    for(unsigned i = 0; i < data.size(); ++i){
        // Custom tolower()
        //if((int)tmp[i] >= 65 && (int)tmp[i] <= 90)
        //    tmp[i] = (char)((int)tmp[i] + 32);
        tmp[i] = tolower(tmp[i]);
    }
    if(modify){
        data = tmp;
        return ZString(data);
    } else {
        return ZString(tmp);
    }
}

ZString ZString::toJSON(AsArZ arr, bool modify){
    ZString tmp;
    tmp << "{\"" << ZString(arr.getIndex(0)).replace("\"", "\\\"").str() << "\":\"" << arr[0].replace("\"", "\\\"") << "\"";
    for(unsigned i = 1; i < arr.size(); ++i)
        tmp << ",\"" << ZString(arr.getIndex(i)).replace("\"", "\\\"").str() << "\":\"" << arr[i].replace("\"", "\\\"") << "\"";
    tmp << "}";
    if(modify)
        data = tmp.str();
    return tmp;
}

bool ZString::validJSON(){
    string s = data;
    enum Locat {
        start = 1,
        firstc = 2,
        skey = 3,
        key = 4,
        ekey = 5,
        colon = 6,
        svalue = 7,
        value = 8,
        evalue = 9,
        //comma = 10,
        space = 11,
        trailing = 12
    }loc = start;
    for(unsigned i = 0; i < s.size()-2; ++i){
        char c = s[i];
        switch(loc){
        case start:
            if(c != '{') return false;
            loc = firstc;
            break;
        case firstc:
            if(c != '"') return false;
            loc = skey;
            break;
        case skey:
            if(c == '"') return false;
            loc = key;
            break;
        case key:
            if(c == '"' && s[i-1] != '\\') loc = ekey;
            break;
        case ekey:
            if(c != ':') return false;
            loc = colon;
            break;
        case colon:
            if(c != '"') return false;
            loc = svalue;
            break;
        case svalue:
            if(c == '"' && s[i-1] != '\\') loc = evalue; else loc = value;
            break;
        case value:
            if(c == '"' && s[i-1] != '\\') loc = evalue;
            break;
        case evalue:
            if(c == ',') loc = firstc; else if(c == '}') loc = trailing; else return false;
            break;
        //case comma:
        //    if(c != '"') return false;
        //    loc = firstc;
        //    break;
        case trailing:
            return false;
            break;
        default:
            // Not Good.
            break;
        }
    }
    return true;
}

AsArZ ZString::fromJSON(){
    if(!validJSON())
        return AsArZ();
    enum Locat {
        start = 1,
        firstc = 2,
        skey = 3,
        key = 4,
        ekey = 5,
        colon = 6,
        svalue = 7,
        value = 8,
        evalue = 9,
        //comma = 10,
        space = 11,
        trailing = 12
    }loc = start;
    AsArZ final;
    string s = data;
    string kbuff;
    string vbuff;
    for(unsigned i = 0; i < s.size()-2; ++i){
        char c = s[i];
        switch(loc){
        case start:
            loc = firstc;
            break;
        case firstc:
            loc = skey;
            break;
        case skey:
            kbuff += c;
            loc = key;
            break;
        case key:
            if(c == '"' && s[i-1] != '\\') loc = ekey; else kbuff += c;
            break;
        case ekey:
            loc = colon;
            break;
        case colon:
            loc = svalue;
            break;
        case svalue:
            if(c == '"' && s[i-1] != '\\') loc = evalue; else { loc = value; vbuff += c; }
            break;
        case value:
            if(c == '"' && s[i-1] != '\\'){ loc = evalue; } else vbuff += c;
            break;
        case evalue:
            if(c == ',') loc = firstc; else if(c == '}') loc = trailing;
            final[ZString(kbuff).replace("\\\"", "\"").str()] = ZString(vbuff).replace("\\\"", "\"");
            kbuff.clear();
            vbuff.clear();
            break;
        //case comma:
        //    loc = firstc;
        //    break;
        case trailing:
            break;
        default:
            // Not Good.
            break;
        }
    }
    final[ZString(kbuff).replace("\\\"", "\"").str()] = ZString(vbuff).replace("\\\"", "\"");
    kbuff.clear();
    vbuff.clear();
    return final;
}

ostream &operator<<(ostream& lhs, ZString rhs){
    lhs << rhs.str();
    return lhs;
}
