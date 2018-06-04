#pragma once
#include <iostream>
using namespace std;

class TestCase
{
    
    public:
        string namecase;
        int total, failed, passed;
        TestCase(string name , ostream& os):total(0),failed(0),passed(0)
        {
            namecase = name;
        }
        template <typename T> TestCase& check_equal(T a ,T b)
        {
            total++;
            if(a == b)
            {
                passed++;
            }
            else
            {
                cout << namecase << ": Failure in test #" << total << ": " << a << " should equal " << b << "!" << endl;
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
                cout << namecase << ": Failure in test #" << total << ": " << a << " should not equal " << b << "!" << endl;
                failed++;
            }
            return *this;
        }
        template <typename T> TestCase& check_output(T a ,string b)
        {
            stringstream ss;
            ss << a;
            total++;
            if(ss.str() == b)
            {
                passed++;
            }
            else
            {
                cout << namecase << ": Failure in test #" << total << ": string value should be " << b << " but is " << a << endl;
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
                cout << namecase << ": Failure in test #" << total << ": Function should return " << b << " but returned " << (*fun)(a) << "!" << endl;
                failed++;
            }
            return *this;
        }
        void print()
        {
            cout << namecase << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl << endl;
        }
};