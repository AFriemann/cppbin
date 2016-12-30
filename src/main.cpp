/* main.cpp
 * -*- coding: utf-8 -*-
 *
 */

#include "boost/filesystem.hpp"

#include "iterators/FileIterator.hpp"

using namespace cppbin;

int main(int argc, char** argv) {
    iterators::FileIterator<int> it("iterators/FileIterator.hpp");

    return 0;
}

// vim: tabstop=8 expandtab shiftwidth=4 softtabstop=4 fenc=utf-8
