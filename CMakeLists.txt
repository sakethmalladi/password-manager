cmake_minimum_required(VERSION 3.10)

project(PasswordManager)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)
find_package(SQLite3 REQUIRED)

include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(${SQLITE3_INCLUDE_DIRS})

add_executable(PasswordManager main.cpp DatabaseManager.cpp PasswordManager.cpp)

target_link_libraries(PasswordManager ${OPENSSL_LIBRARIES} ${SQLITE3_LIBRARIES})
