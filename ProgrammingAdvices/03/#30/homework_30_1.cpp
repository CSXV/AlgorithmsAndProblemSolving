#include <iostream>
#include <string>
using namespace std;

int main()
{
// from sting to Double, Float, Int
    string st1 = "43.22";
    double st2 = stod(st1);
    float st3 = stof(st1);
    int st4 = stoi(st1);
   cout << st2 <<endl;
// from int to string
    int N1= 20;
    string NtoS;
    NtoS = to_string(N1);
    cout << NtoS <<endl;
// from double to string
    double N2 = 33.5;
    string DtoS;
    DtoS = to_string(N2);
    cout << DtoS <<endl;
// from float to string
    float N3 = 55.23;
    string FtoS;
    FtoS = to_string(N3);
    cout << FtoS <<endl;

    return 0;
}
