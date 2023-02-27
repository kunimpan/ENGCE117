#include <iostream>
#include <set>

int main() {
    std::set<int> my_set;

    // Add elements to the set
    my_set.insert(3);
    my_set.insert(1);
    my_set.insert(4);
    my_set.insert(1); // Not added because 1 already exists in the set
    for(auto it = my_set.begin(); it != my_set.end(); ++it){
        std::cout << *it << "\n";
    }
    // Check if an element exists in the set
    if (my_set.count(5) > 0) {
        std::cout << "3 is in the set" << std::endl;
    } else {
        std::cout << "3 is not in the set" << std::endl;
    }

}