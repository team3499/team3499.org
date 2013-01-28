#include "database.h"
#include <stdio.h>
#include <fstream>

Database::Database(){}

void Database::open(string file){
    sqlite3_open(file.c_str(), &db);
}

void Database::close(){
    sqlite3_close(db);
}

bool Database::ok(){
    if(db == 0){
        return false;
    } else {
        return true;
    }
}

int Database::sel_callback(int num_fields, char **p_fields, char **p_col_names){
    if(format == 0){
        for(int i = 0; i < num_fields; ++i){
            records[tmp_record_id][p_col_names[i]] = p_fields[i];
        }
    }else if(format == 1){
        for(int i = 0; i < num_fields; ++i){
            records[p_col_names[i]][tmp_record_id] = p_fields[i];
        }
    }else{
        return 1;
    }
    ++tmp_record_id;
    return 0;
}
static int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names){
    Database *dbptr = (Database*) p_data;
    return dbptr->sel_callback(num_fields, p_fields, p_col_names);
}
int Database::select_rows(string stmt){
    char *errmsg = (char*)"";
    format = 0;
    tmp_record_id = 0;
    records = SqlRows();
    sqlite3_exec(db, stmt.c_str(), select_callback, this, &errmsg);
    //stringstream ss;
    //ss << errmsg;
    //last_error = string();
    //ss >> last_error;
    //last_error = errmsg;
    return tmp_record_id;
}
int Database::select_cols(string stmt){
    char *errmsg = (char*)"";
    format = 1;
    tmp_record_id = 0;
    records = SqlRows();
    sqlite3_exec(db, stmt.c_str(), select_callback, this, &errmsg);
    //stringstream ss;
    //ss << errmsg;
    //last_error = string();
    //ss >> last_error;
    //last_error = errmsg;
    return tmp_record_id;
}


bool Database::sql_stmt(string stmt){
    char *errmsg;
    int ret;
    ret = sqlite3_exec(db, stmt.c_str(), 0, 0, &errmsg);
    //stringstream ss;
    //ss << errmsg;
    //last_error = string();
    //ss >> last_error;
    //last_error = errmsg;
    if(ret == SQLITE_OK){
        return true;
    }else{
        return false;
    }
}

#ifdef USE_QT
QString Database::print_html(){
    QString table = "<style>\n\ttable,td,th,tr{border:1px solid black;}\n</style>\n<table>\n\t<tr>\n";
    for(int i = 0; i < records[0].size(); ++i){
        table = table.append("\t\t<th>");
        table = table.append(ZString(records[0].getIndex(i)).QS());
        table = table.append("</th>\n");
    }
    table = table.append("\t</tr>\n");
    for(int i = 0; i < records.size(); ++i){
        table = table.append("\t<tr>\n");
        for(int j = 0; j < records[i].size(); ++j){
            table = table.append("\t\t<td>");
            table = table.append(ZString((records[i][j])).QS());
            table = table.append("</td>\n");
        }
        table = table.append("\t</tr>\n");
    }
    table = table.append("</table>\n");
    return table;
}
#endif

string Database::lastError(){
    return last_error;
}
SqlRows Database::result(){
    return records;
}
