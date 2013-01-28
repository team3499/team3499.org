#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include "server.hpp"
#include "database.h"

int main(int argc, char* argv[]){
    try {
        // Check command line arguments.
        if(argc == 2){
            Database userdb;
            userdb.open(USERDB);
            if(userdb.ok()){
                userdb.sql_stmt("CREATE TABLE users (uid INTEGER, uname TEXT, rname TEXT, password TEXT, perms INTEGER, data TEXT)");
                userdb.sql_stmt("INSERT INTO users (uid, uname, rname, password, perms, data)  VALUES (1, 'chaos', 'Charlie', 'tstwrd', 3, '')");
                userdb.close();
            } else {
                std::cerr << "Could Not Open User DB" << std::endl;
                return 1;
            }
            Database sitedb;
            sitedb.open(SITEDATADB);
            if(sitedb.ok()){
                sitedb.sql_stmt("CREATE TABLE projects (projid INTEGER, projname TEXT, status TEXT)");
                sitedb.sql_stmt("INSERT INTO projects (projid, projname, status)  VALUES (1, 'Site', 'WIP')");
                sitedb.close();
            } else {
                std::cerr << "Could Not Open Site DB" << std::endl;
                return 1;
            }std::cout << "Databases Built" << std::endl;
        } else {
            if(argc != 5){
                std::cerr << "Usage: http_server <address> <port> <threads> <doc_root>" << std::endl;
                return 1;
            }

            // Initialise the server.
            std::size_t num_threads = boost::lexical_cast<std::size_t>(argv[3]);
            HttpServer server(argv[1], argv[2], argv[4], num_threads);

            // Run the server until stopped.
            server.run();
        }
    } catch (std::exception& e){
        std::cerr << "exception: " << e.what() << "\n";
    }
    return 0;
}
