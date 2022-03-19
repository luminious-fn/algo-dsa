/*how operator overloading works
 clear; g++ -std=c++2a array1.cpp && ./a.exe
 *
 * */

#include<iostream>
#include<array>

int main(int argc, char *argv[]){

	std::array<int, 5> my_array {1,2,3};
	for (const auto item : my_array){
		std::cout << item << ", ";
	}
	std::byte x { 'a'};
}
