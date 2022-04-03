#include <iostream>
#include "map.hpp"
#include "pair.hpp"
#include <string>
#include <iterator>
#include <algorithm>
int main() {

    ft::map<int, int> mapOfWordCount;
    // Insert Element in map
    mapOfWordCount.insert(ft::pair<int, int>(4, 4));
    mapOfWordCount.insert(ft::pair<int, int>(1, 1));
    mapOfWordCount.insert(ft::pair<int, int>(12, 12));
    mapOfWordCount.insert(ft::pair<int, int>(5, 5));
    mapOfWordCount.insert(ft::pair<int, int>(3, 3));
	mapOfWordCount.insert(ft::pair<int, int>(45, 45));
	mapOfWordCount.insert(ft::pair<int, int>(33, 33));
    // Create a map iterator and point to beginning of map
//     ft::map<int, int>::iterator it = mapOfWordCount.begin();
//   // go to the 3rd item from the beggining
// 	std::cout << "it begin " << it->first << "\n";
// 	it++;
// 	std::cout << "it begin " << it->first << "\n";
// 	it++;
// 	std::cout << "it begin " << it->first << "\n";
// 	it++;
// 	std::cout << "it begin " << it->first << "\n";
// 	it++;
// 	std::cout << "it begin " << it->first << "\n";
// 	it++;
// 	std::cout << "it begin " << it->first << "\n";
    // // Iterate over the map using Iterator till end.
    // while (it != mapOfWordCount.end())
    // {
    //     // Accessing KEY from element pointed by it.
    //     int word = it->first;
    //     // Accessing VALUE from element pointed by it.
    //     int count = it->second;
    //     std::cout << word << " :: " << count << std::endl;
    //     // Increment the Iterator to point to next entry
    //     it++;
    // }
    return 0;
}