// serialization.h
#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <type_traits>
#include <sstream>

namespace binary {

template<typename T>
void serialize(const T& object, const std::string& filename) {
    static_assert(std::is_arithmetic<T>::value || std::is_same<T, std::string>::value, "Unsupported type");
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(reinterpret_cast<const char*>(&object), sizeof(T));
}

template<typename T>
void deserialize(T& object, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    ifs.read(reinterpret_cast<char*>(&object), sizeof(T));
}

// Pair serialization
template<typename T1, typename T2>
void serialize(const std::pair<T1, T2>& object, const std::string& filename) {
    static_assert(std::is_arithmetic<T1>::value || std::is_same<T1, std::string>::value, "Unsupported type");
    static_assert(std::is_arithmetic<T2>::value || std::is_same<T2, std::string>::value, "Unsupported type");
    std::ofstream ofs(filename, std::ios::binary);
    ofs.write(reinterpret_cast<const char*>(&object.first), sizeof(T1));
    ofs.write(reinterpret_cast<const char*>(&object.second), sizeof(T2));
}

template<typename T1, typename T2>
void deserialize(std::pair<T1, T2>& object, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    ifs.read(reinterpret_cast<char*>(&object.first), sizeof(T1));
    ifs.read(reinterpret_cast<char*>(&object.second), sizeof(T2));
}

// Vector serialization
template<typename T>
void serialize(const std::vector<T>& object, const std::string& filename) {
    static_assert(std::is_arithmetic<T>::value || std::is_same<T, std::string>::value, "Unsupported type");
    std::ofstream ofs(filename, std::ios::binary);
    size_t size = object.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    ofs.write(reinterpret_cast<const char*>(object.data()), size * sizeof(T));
}

template<typename T>
void deserialize(std::vector<T>& object, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    object.resize(size);
    ifs.read(reinterpret_cast<char*>(object.data()), size * sizeof(T));
}

// List serialization
template<typename T>
void serialize(const std::list<T>& object, const std::string& filename) {
    static_assert(std::is_arithmetic<T>::value || std::is_same<T, std::string>::value, "Unsupported type");
    std::ofstream ofs(filename, std::ios::binary);
    size_t size = object.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    for (const T& elem : object) {
        ofs.write(reinterpret_cast<const char*>(&elem), sizeof(T));
    }
}

template<typename T>
void deserialize(std::list<T>& object, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    for (size_t i = 0; i < size; ++i) {
        T elem;
        ifs.read(reinterpret_cast<char*>(&elem), sizeof(T));
        object.push_back(elem);
    }
}

// Set serialization

template<typename T>
void serialize(const std::set<T>& object, const std::string& filename) {
    static_assert(std::is_arithmetic<T>::value || std::is_same<T, std::string>::value, "Unsupported type");
    std::ofstream ofs(filename, std::ios::binary);
    size_t size = object.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    for (const T& elem : object) {
        ofs.write(reinterpret_cast<const char*>(&elem), sizeof(T));
    }
}

template<typename T>
void deserialize(std::set<T>& object, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    for (size_t i = 0; i < size; ++i) {
        T elem;
        ifs.read(reinterpret_cast<char*>(&elem), sizeof(T));
        object.insert(elem);
    }
}

// Map serialization

template<typename K, typename V>
void serialize(const std::map<K, V>& object, const std::string& filename) {
    static_assert(std::is_arithmetic<K>::value || std::is_same<K, std::string>::value, "Unsupported type");
    static_assert(std::is_arithmetic<V>::value || std::is_same<V, std::string>::value, "Unsupported type");
    std::ofstream ofs(filename, std::ios::binary);
    size_t size = object.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
    for (const auto& pair : object) {
        ofs.write(reinterpret_cast<const char*>(&pair.first), sizeof(K));
        ofs.write(reinterpret_cast<const char*>(&pair.second), sizeof(V));
    }
}

template<typename K, typename V>
void deserialize(std::map<K, V>& object, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size_t));
    for (size_t i = 0; i < size; ++i) {
        K key;
        V value;
        ifs.read(reinterpret_cast<char*>(&key), sizeof(K));
        ifs.read(reinterpret_cast<char*>(&value), sizeof(V));
        object[key] = value;
    }
}

} 
namespace xml {

template<typename T>
void serialize_xml(const T& object, const std::string& rootName, const std::string& filename) {
    std::ofstream ofs(filename);
    ofs << "<serialization>\n";
    ofs << "<" << rootName << ">\n";
    ofs << "<first val=\""<< object.first << "\"/>\n";
    ofs << "<second val=\""<< object.second << "\"/>\n";
    ofs << "</" << rootName << ">\n";
    ofs << "</serialization>\n";
}

template<typename T>
void deserialize_xml(T& object, const std::string& rootName, const std::string& filename) {
    std::ifstream ifs(filename);
    std::string line;
    std::string startTag = "<" + rootName + ">";
    std::string endTag = "</" + rootName + ">";
    bool found = false;

    while (std::getline(ifs, line)) {
        if (line.find(startTag) != std::string::npos) {
            found = true;
            continue;
        }
        if (found) {
            std::string::size_type pos = line.find("val=\"");
            if (pos != std::string::npos) {
                std::string::size_type endPos = line.find("\"", pos + 5);
                std::string value = line.substr(pos + 5, endPos - pos - 5);
                if (line.find("first") != std::string::npos) {
                    std::istringstream(value) >> object.first;
                } else if (line.find("second") != std::string::npos) {
                    std::istringstream(value) >> object.second;
                }
            }
        }
        if (line.find(endTag) != std::string::npos) {
            break;
        }
    }
}

// Add more overloads or template specializations for STL containers and user-defined types...

}

#endif // SERIALIZATION_H
