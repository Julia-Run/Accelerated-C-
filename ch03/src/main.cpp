// to calculate average grade of a student
// mid 0.3, homework 0.3, final 0.4
#include<iostream>
#include<ios>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>

using std::cin; using std::cout; using std::string;
using std::streamsize; using std::vector; using std::sort;
using std:: setprecision; using std::endl;

int main()
{
    cout << endl;
    cout << "please input your name: \n";
    string name;
    cin >> name;

    cout << "Hello, " << name << " !\n" << "Please input your midterm and final exam grades: \n";
    double mid, final;
    cin >> mid >> final;

//    int count = 0;
//    double sum = 0;
    double x;
    vector<double> homework;

    cout << "Please input your homework grades: "
            " (and end with 'Ctrl + D') \n";

    while (cin >> x)
    {
        homework.push_back(x);
//        ++count;
//        sum += x;
    }

    typedef vector<double> :: size_type vec_sz;
    vec_sz size = homework.size();

    if (size == 0) return 1;
    sort(homework.begin(),homework.end());

    int mid_index = size / 2;
    double median;
    median = size%2 == 0 ? (homework[mid_index]+homework[mid_index-1])/2 : homework[mid_index];

    streamsize pre = cout.precision();
    cout << "Your final grade is: " << setprecision(3) << mid*0.3 + final * 0.4 + median*0.3 <<
    setprecision(pre) << endl;

    return 0;
}