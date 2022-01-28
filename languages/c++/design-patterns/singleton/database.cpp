#include<iostream>
#include<mutex>
#include<memory>
/*

https://refactoring.guru/design-patterns/singleton
clear; g++ -std=c++2a Database.cpp && ./a.exe

DRAW BACKS
1. we can't use smart pointers for this. because destructor is private.
no, we can use it. yes. the smart pointer should be a member variable.
that is all.
shared pointer could a good candidate... but in any way..
.
*/

class Database {
    private:        
        /* make construstor private so that no one can call it.
        no object creation, no new/delete usage.
        */
        int db_socket;
        Database(void);
        ~Database(void);

        /* this is not definition. just declaration.
        this has to be static as this will be returned by static method.
        */
        static Database *p_instance; 
        static std::mutex mut;
        Database& operator=(const Database &) = delete;
        Database& operator=(const Database &&) = delete;
        Database(const Database &) = delete;
        Database(const Database &&) = delete;
    public:
        static Database *getInstance();
        static void deleteInstance();
        // This is not static fn
        std::string query(std::string op);
};

Database::Database(void) {
    std::cout << " Constructor Database is called";
    this->db_socket = 100; // open sql db socket etc...
}

Database::~Database(void){
    // close the sql db connection gracefully
    std::cout << " Destructor Database is called";    
    this->db_socket = 0;
}

std::string Database::query(std::string op){
    /* since all sql op come here, we need to handle
    parallel access through locking etc.
    we can also throttle the  connections, cache the output etc
    or keep the statistics etc...    
    */
   return std::string { "hello" };
}

Database* Database::getInstance(void){
    
    if( !p_instance ){
        std::lock_guard<std::mutex> my_lock { mut }; // mut gets changed here...    
        if( !p_instance ){
            std::cout << "first time\n";
            p_instance = new Database;
        }
    }else {
        std::cout << "already init\n";
    }
    return p_instance;
}
void Database::deleteInstance(void){
    if(p_instance){
        std::lock_guard<std::mutex> my_lock { mut };
        if(p_instance){
            std::cout << "deleting Database instance" << std::endl;
            delete p_instance;
        } else {
            std::cout << " Database instance not exists!!! " << std::endl;
        }
    }

}

Database *Database::p_instance = nullptr; // this is definition. mem is allocated here.
std::mutex Database::mut;

int main(int argc, char *argv[]){
    std::cout << "main starts\n";    
    Database *p { Database::getInstance() };
    std::cout << p->query("select hi") << std::endl;

    Database *q { Database::getInstance()};
    std::cout << q->query("select world") << std::endl;

    q->deleteInstance();    
    return 0;
}