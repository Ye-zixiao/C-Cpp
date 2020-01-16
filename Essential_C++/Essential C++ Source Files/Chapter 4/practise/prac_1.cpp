#include<iostream>
#include<string>
using namespace std;

class program
{
public:
    program(){}
    ~program(){}

    static string program_name;
    static string version_stamp;
    static int version_number;
    static int tests_run;
    static int tests_passed;

private:

};

string program::program_name="";
string program::version_stamp="";
int program::version_number=0;
int program::tests_run=0;
int program::tests_passed=0;

int main(void)
{
    program pro_1;

    return 0;
}
