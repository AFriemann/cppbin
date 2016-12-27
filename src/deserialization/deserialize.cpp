#include <algorithm>
#include <exception>

namespace cppbin {
    namespace deserialization {
        template<typename T>
        T deserialize(std::vector<unsigned char>& c) {
            throw std::domain_error();
        }

        template<typename T>
        inline check_size(std::vector<unsigned char>& c, const std::string& type_name) {
            if (c.size() != sizeof(T)) {
                throw std::domain_error("Can not deserialize to " + type_name);
            }
        }

        template<>
        int parse<int>(std::vector<unsigned char>& c) {
            check_size<int>(c, "int");

            
        }

        template<>
        float parse<float>(std::vector<unsigned char>& c) {
            if (c.size() != 1) {
                throw std::domain_error("Can not deserialize to float");
            }
            
        }
    }
}