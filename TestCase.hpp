#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class TestCase
{
    
    public:
        int total, failed, passed;
        ostream stream;
        string namecase;
        TestCase(string name , ostream& os);
        void print();
        friend ostream& operator<<(ostream& os, TestCase& obj);
        template <typename T> TestCase& check_equal(T a ,T b)
        {
            total++;
            if(a == b)
            {
                passed++;
            }
            else
            {
                stream << namecase << ": Failure in test #" << total << ": " << a << " should equal " << b << "!" << endl;
                failed++;
            }
            return *this;
        }
        template <typename T> TestCase& check_different(T a ,T b)
        {
            total++;
            if(a != b)
            {
                passed++;
            }
            else
            {
                stream << namecase << ": Failure in test #" << total << ": " << a << " should not equal " << b << "!" << endl;
                failed++;
            }
            return *this;
        }
        template <typename T> TestCase& check_output(T a ,string b)
        {
            ostringstream ss;
            ss << a;
            total++;
            if(ss.str() == b)
            {
                passed++;
            }
            else
            {
                stream << namecase << ": Failure in test #" << total << ": string value should be " << b << " but is " << a << endl;
                failed++;
            }
            return *this;
        }
        template <typename T,typename Func> TestCase& check_function(Func fun ,T a , int b)
        {
            total++;
            if((*fun)(a) == b)
            {
                passed++;
            }
            else
            {
                stream << namecase << ": Failure in test #" << total << ": Function should return " << b << " but returned " << (*fun)(a) << "!" << endl;
                failed++;
            }
            return *this;
        }
};