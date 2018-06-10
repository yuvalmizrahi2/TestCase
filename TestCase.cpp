#include "TestCase.hpp"

TestCase::TestCase(string name , ostream& os):total(0),failed(0),passed(0),stream(os.rdbuf()),namecase(name)
{
}

void TestCase::print()
{
    stream << namecase << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl << endl;
    cout << *this;
}

ostream& operator<<(ostream& os, TestCase& obj)
{
    return obj.stream;
}
