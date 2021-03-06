#include "zfile.h"

ZFile::ZFile(){
    opened = false;
    readable = true;
    writeable = false;
}
ZFile::ZFile(ZString file){
    readable = true;
    writeable = false;
    open(file);
}
ZFile::ZFile(int mode){
    opened = false;
    setMode(mode);
}
ZFile::ZFile(int mode, ZString name){
    open(mode, name);
}

bool ZFile::open(int mode, ZString name){
    opened = false;
    setMode(mode);
    return open(name);
}

void ZFile::setMode(int mode){
    if(mode == READ){
        readable = true;
        writeable = false;
    } else if(mode == WRITE){
        readable = false;
        writeable = true;
    } else if(mode == READWRITE){
        readable = true;
        writeable = true;
    } else {
        readable = false;
        writeable = false;
    }
}

#ifdef ZFILE_USE_QT

bool ZFile::open(ZString name){
    fl = new QFile(name.QS());
    if(readable && !writeable){
        if(fl->open(QIODevice::ReadOnly))
            return true;
    } else if(writeable && !readable){
        if(fl->open(QIODevice::WriteOnly | QIODevice::Text))
            return true;
    } else if(readable && writeable){
        if(fl->open(QIODevice::ReadWrite | QIODevice::Text))
            return true;
    }
    opened = true;
    return false;
}

void ZFile::close(){
    if(opened){
        fl->close();
        opened = false;
    }
}

ZFile::~ZFile(){
    close();
}

ZString ZFile::read(){
    ZString cont = "";
    if(opened){
        while (!fl->atEnd() && !fl->error())
            cont += fl->read(65536);
    }
    return cont;

}
bool ZFile::write(ZString cont){
    if(opened){
        if(fl->write(cont.cc(), cont.size())){
            return true;
        }
    }
    return false;
}
bool ZFile::remove(){
    if(opened){
        return fl->remove();
    }
    return false;
}

bool ZFile::exists(ZString name){
    QFile file(name.QS());
    return file.exists();
}

#else

bool ZFile::open(ZString name){
    if(readable && !writeable){
        file.open(name.cc(), std::ios::in | std::ios::binary);
    } else if(writeable && !readable){
        file.open(name.cc(), std::ios::out);
    } else if(readable && writeable){
        file.open(name.cc(), std::ios::in | std::ios::binary | std::ios::out);
    }
    if(file)
        return true;
    return false;
}

void ZFile::close(){
    //if(in)
    //    in->close();
    //if(out)
    //    out->close();
    if(file)
        file.close();
}

ZFile::~ZFile(){
    close();
}

// v2
ZString ZFile::read(){
    std::string contents;
    file.seekg(0, std::ios::end);
    contents.resize(file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&contents[0], contents.size());
    file.close();
    return(ZString(contents));
}

ZString ZFile::readFile(ZString filename){
    std::ifstream infile(filename.cc(), std::ios::in | std::ios::binary);
    if(infile){
        std::string buffer;
        infile.seekg(0, std::ios::end);
        buffer.resize(infile.tellg());
        infile.seekg(0, std::ios::beg);
        infile.read(&buffer[0], buffer.size());
        infile.close();
        return(ZString(buffer));
    }
    return ZString();
}

bool ZFile::append(ZString cont){
    if(writeable){
        if(file.is_open()){
            file.seekp(0, std::ios::end);
            file << cont.cc();
            file.flush();
            return true;
        }
    }
    return false;
}

bool ZFile::write(ZString cont){
    if(writeable){
        if(file.is_open()){
            file << cont.cc();
            file.flush();
            return true;
        }
    }
    return false;
}

bool ZFile::remove(){
    return true;
}

bool ZFile::exists(ZString name){
    return true;
}

#endif
