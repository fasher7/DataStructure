#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct patient
{
    string name = "";
    int age = 0;
    string bloodgroup = "";
    patient(string n, int a, string b)
    {
        name = n;
        age = a;
        bloodgroup = b;
    }
};

void setAttribute(patient& p, string n, int a, string b)
{
    p.name = n;
    p.age = a;
    p.bloodgroup = b;
}

string getAttribute(patient p)
{
    return (p.name + " " + to_string(p.age) + " " + p.bloodgroup);
}

void writetoFile (ofstream& myfile, patient& p)
{
    string str = ""; int age = 0; string bloodgroup = "";
    cout << "Name Please: ";  
    cin >> str;   //This code is efficient only for nickname
    cout << "Age: ";
    cin >> age;
    cout << "Blood Group: ";
    cin >> bloodgroup;

    setAttribute (p, str, age, bloodgroup);
    myfile << getAttribute(p) << endl;

}

int main()
{
    ofstream myfile("Code1.txt",  ios::app);

    if (!myfile.is_open())
    {
        cerr << "Error";
        return 0;
    }

    patient p ("", 0, "");
    writetoFile (myfile, p);

    myfile.close();
    return 0;
}
