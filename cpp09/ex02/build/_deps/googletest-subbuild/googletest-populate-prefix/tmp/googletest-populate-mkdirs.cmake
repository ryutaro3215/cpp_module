# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-src"
  "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-build"
  "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/ryutaro320515/Documents/42Tokyo/cpp_module/cpp09/ex02/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
