
#cd memory
#PROG=memory.cpp

#cd memory
#PROG=memory.cpp

#cd memory
#PROG=memory.cpp

#cd memory
#PROG=memory.cpp

#cd memory
#PROG=smart-pointer.cpp

#cd enum
#PROG=enum1.cpp

cd uniform-initialization
PROG=uniform-initialization.cpp

#clear; rm -rf ./a.out;g++ -std=c++11 -Werror -Wall -g $PROG && ./a.out
clear; rm -rf ./a.out;g++ -std=c++11 -Wall  $PROG && ./a.out

