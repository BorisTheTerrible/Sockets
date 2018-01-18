//
//  CompilerChecks.hpp
//  Sockets
//
//  Created by games on 1/17/18.
//  Copyright © 2018 games. All rights reserved.
//

#ifndef EnvironmentChecks_hpp
#define EnvironmentChecks_hpp

#include <iostream>

/*
    Compile time assertions should be below here.
 
    This program will probably not compile without a c++11 GNU compatible compiler
 */

/*
    Checks operating system at compile time.
 */
#if defined(unix) || defined(__unix) || (__unix__)
    #define PLATFORM "UNIX-LIKE"
#elif defined(__APPLE__) || defined(__MACH__)
    #define PLATFORM "UNIX-LIKE"
#elif defined(__linux__)
    #define PLATFORM "UNIX-LIKE"
#elif defined(__FreeBSD__)
    #define PLATFORM "UNIX-LIKE"
#elif defined(_WIN32) && !defined(_WIN64)
    #define PLATFORM "WIN-32"
#elif defined(_WIN64)
    #define PLATFORM "WIN-64"
#else
    #warning "Compiling on unknown platform! Will default to compiling for UNIX-LIKE standards."
    #define PLATFORM "UNIX-LIKE"
#endif

/*
    Checks c++ support at compile time.
 */
#if __cplusplus < 201103L
    #warning "Your compiler is likely not c++11 compliant! Compilation will most likely fail!"
#endif

/*
    Checks to make sure variables types are of correct size at compile time.
 */
static_assert(sizeof(bool) == 1, "bool is not one byte!");
static_assert(sizeof(char) == 1, "char is not one byte!");
static_assert(sizeof(short) == 2,  "short is not two bytes!");
static_assert(sizeof(int) == 4, "int is not four bytes!");
static_assert(sizeof(long) == 8, "long is not eight bytes!");
static_assert(sizeof(float) == 4, "float is not four bytes!");
static_assert(sizeof(double) == 8, "double is not eight bytes!");

/*
    This class is never mean't to be instantianed.
    It is meant for runtime checks.
 
    It is marked as final so you cannot try to be silly and extend the class.
 */
class EnvironmentChecks final
{
public:
    /*
        This is here to keep someone from being frisky and trying to instantiate this class.
     */
    virtual void f() = 0;
    
    bool getIsBigEndian();
//public
    
private:
    /*
        This only used to call runtimeMethod() where runtime checks are run.
     */
    static int dummyVariable;
    
    static bool isBigEndian;
    
    /*
        Runtime checks should be placed in here.
        Runtime environment variables should be set in here.
     */
    static int runtimeMethod();
//private
};

#endif /* EnvironmentChecks_hpp */
