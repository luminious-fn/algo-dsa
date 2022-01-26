#include<iostream>
#include<mutex>
#include<memory>
/*

https://refactoring.guru/design-patterns/singleton
g++ -std=c++2a Database.cpp && ./a.exe

DRAW BACKS
1. we can't use smart pointers for this. because destructor is private.
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
        static Database *pobject; 
        static std::mutex mut;
        Database& operator=(const Database &) = delete;
        Database& operator=(const Database &&) = delete;
        Database(const Database &) = delete;
        Database(const Database &&) = delete;
    public:
        static Database *getInstance();
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
    
    if( !pobject ){
        std::lock_guard<std::mutex> my_lock { mut }; // mut gets changed here...    
        if( !pobject ){
            std::cout << "first time\n";
            pobject = new Database;
        }
    }else {
        std::cout << "already init\n";
    }
    return pobject;
}

Database *Database::pobject = nullptr; // this is definition. mem is allocated here.
std::mutex Database::mut;

int main(int argc, char *argv[]){
    std::cout << "main starts\n";    
    Database *p { Database::getInstance() };
    std::cout << p->query("select hi") << std::endl;

    Database *q { Database::getInstance()};
    std::cout << q->query("select world") << std::endl;
    
    return 0;
}