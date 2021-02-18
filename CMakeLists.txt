cmake_minimum_required(VERSION 3.10)
project(EmitEnumFromNamspaceTest CXX)

find_package(Qt5 REQUIRED COMPONENTS Core)

add_executable(EmitEnumFromNamspaceTest
    main.cpp
    Sender.h
    Sender.cpp
    MetaRegister.h
    MetaRegister.cpp
    Receiver.h
)

set_property(TARGET EmitEnumFromNamspaceTest PROPERTY AUTOMOC ON)

target_link_libraries(EmitEnumFromNamspaceTest
    PRIVATE
        Qt5::Core
)
