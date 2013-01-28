#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#ifdef USE_QT
    #include <QString>
#endif
#include <sstream>
#include <iostream>
#include <stdio.h>
#define SQLITE_CUSTOM
#include "sqlite3.h"
#include "asar.h"
#include "zstring.h"
using namespace std;

typedef AssocArray< AssocArray<string> > SqlRows;

class Database {
public:
    Database();
    void open(string file);
    bool ok();
    void close();
    bool sql_stmt(string stmt);
    int select_rows(string stmt);
    int select_cols(string stmt);
    int sel_callback(int num_fields, char **p_fields, char **p_col_names);
    SqlRows result();
    string lastError();
#ifdef USE_QT
    QString print_html();
#endif
private:
    sqlite3* db;
    SqlRows records;
    string last_error;
    short format;
    int tmp_record_id;
};

#endif // DATABASE_H
