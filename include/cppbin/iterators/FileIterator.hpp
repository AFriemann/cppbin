
#pragma once

#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <typeinfo>

#include "boost/filesystem.hpp"

namespace cppbin {
    namespace iterators {
        template<typename T>
        class FileIterator : std::iterator<std::random_access_iterator_tag, T> {
            private:
                const boost::filesystem::path path;

            public:
                ~FileIterator() {};
                FileIterator(FileIterator &) = default;
                FileIterator operator= (FileIterator & other) { return FileIterator(other); }

                FileIterator() {
                    // TODO
                };
                FileIterator(const boost::filesystem::path & path) : path(path) {
                    // TODO
                }

                FileIterator & operator[] (const size_t) { return this; };

                /**
                 * increment/decrement
                 */
                FileIterator & operator++ () { return this; }
                FileIterator & operator-- () { return this; }

                /**
                 * TODO
                 */
                FileIterator & operator+= (const FileIterator & other) { return false; }
                FileIterator & operator-= (const FileIterator & other) { return false; }

                /**
                 * TODO
                 */
                FileIterator & operator+ (const int) { return this; }
                FileIterator & operator- (const int) { return this; }

                /**
                 * TODO
                 */
                FileIterator & operator- (const FileIterator & other) { return this; }

                /**
                 * TODO
                 */
                FileIterator & operator* () { return this; }

                /**
                 * TODO
                 */
                bool operator== (const FileIterator & other) { return false; }
                bool operator!= (const FileIterator & other) { return ! this == other; }

                /**
                 * TODO
                 */
                bool operator> (const FileIterator & other) { return false; }
                bool operator< (const FileIterator & other) { return false; }
                bool operator>= (const FileIterator & other) { return false; }
                bool operator<= (const FileIterator & other) { return false; }
        };
    }
}

