#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <typeinfo>

namespace cppbin {
    namespace deserialization {
        template<typename T>
        T deserialize(std::iterator<unsigned char>& begin, const std::iterator<unsigned char>& end) {
            throw std::range_error("Not implemented");
        }
    
        template<typename T>
        constexpr std::string type_name() {
            T* type;
            return typeid(*type).name();
        }
        
        template<typename T>
        inline void check_size(const std::iterator<unsigned char>& begin, const std::iterator<unsigned char>& end) {
            if (std::distance(begin, end) != sizeof(T)) {
                throw constexpr std::range_error("Can not deserialize to " + type_name<T>());
            }
        }

        template<typename IntegerType>
        inline IntegerType deserialize_integer(const std::vector<unsigned char>& chars) {
            check_size<IntegerType>(chars);
            int offset = (sizeof(IntegerType) << 3) -8;
            return std::accumulate(
                chars.begin(),
                chars.end(),
                IntegerType{0},
                [&offset](const IntegerType acc, const unsigned char c) {
                    IntegerType tmp = acc | ((IntegerType) (c) << offset);
                    offset -= 8;
                    return tmp;
                }
            );
        }

        template<>
        int deserialize<int>(const std::vector<unsigned char>& chars) {
            return deserialize_integer<int>(chars);
        }

        template<>
        unsigned int deserialize<unsigned int>(const std::vector<unsigned char>& chars) {
            return deserialize_integer<unsigned int>(chars);
        }

        template<>
        long deserialize<long>(const std::vector<unsigned char>& chars) {
            return deserialize_integer<long>(chars);
        }

        template<>
        long long deserialize<long long>(const std::vector<unsigned char>& chars) {
            return deserialize_integer<long long>(chars);
        }

        template<>
        unsigned long deserialize<unsigned long>(const std::vector<unsigned char>& chars) {
            return deserialize_integer<unsigned long>(chars);
        }

        template<>
        unsigned long long deserialize<unsigned long long>(const std::vector<unsigned char>& chars) {
            return deserialize_integer<unsigned long long>(chars);
        }
        /*
        TODO 
        deserialize works on iterators
        moves begin forward
        */
        template<typename T>
        std::vector<T> deserialize<std::vector<T>>(const std::vector<unsigned char>& chars) {
            return 
        }

    }
}

int main(int argc, char const *argv[]) {
    std::vector<unsigned char> v = {'0', '0', '0', '0'};
    for (unsigned long i = 0; i < (unsigned long)0xffffffff; ++i) {
        cppbin::deserialization::deserialize<int>(v);
    }
    return 0;
}