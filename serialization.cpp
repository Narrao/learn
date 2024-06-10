// main.cpp
#include "serialization.h"
#include <utility>

int main() {
    // Binary serialization
    int n0 = 256, n1;
    binary::serialize(n0, "n.data");
    binary::deserialize(n1, "n.data");
    std::cout << "Binary serialization test passed: " << (n0 == n1) << std::endl;

    // String serialization
    std::string s0 = "Hello, World!", s1;
    binary::serialize(s0, "s.data");
    binary::deserialize(s1, "s.data");
    std::cout << "String serialization test passed: " << (s0 == s1) << std::endl;

    // Pair serialization
    std::pair<int, double> p0 {2, 3.1}, p1;
    binary::serialize(p0, "p.data");
    binary::deserialize(p1, "p.data");
    std::cout << "Pair serialization test passed: " << (p0 == p1) << std::endl;

    // Vector serialization
    std::vector<int> vec0 {1, 2, 3, 4, 5}, vec1;
    binary::serialize(vec0, "vec.data");
    binary::deserialize(vec1, "vec.data");
    std::cout << "Vector serialization test passed: " << (vec0 == vec1) << std::endl;

    // List serialization
    std::list<int> list0 {1, 2, 3, 4, 5}, list1;
    binary::serialize(list0, "list.data");
    binary::deserialize(list1, "list.data");
    std::cout << "List serialization test passed: " << (list0 == list1) << std::endl;

    // Set serialization
    std::set<int> set0 {1, 2, 3, 4, 5}, set1;
    binary::serialize(set0, "set.data");
    binary::deserialize(set1, "set.data");
    std::cout << "Set serialization test passed: " << (set0 == set1) << std::endl;

    // Map serialization
    std::map<int, double> map0 {{1, 1.1}, {2, 2.2}, {3, 3.3}}, map1;
    binary::serialize(map0, "map.data");
    binary::deserialize(map1, "map.data");
    std::cout << "Map serialization test passed: " << (map0 == map1) << std::endl;

    // XML serialization
    std::pair<int, double> pair0 {2, 3.1}, pair1;
    xml::serialize_xml(pair0, "std_pair", "pair.xml");
    xml::deserialize_xml(pair1, "std_pair", "pair.xml");
    std::cout << "XML serialization test passed: " << (pair0 == pair1) << std::endl;

    return 0;
}
