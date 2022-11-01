//
// Created by dora on 1/11/2022.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
T max_here(const T &a, const T &b) {
    return a > b ? a : b;
}

template<class In, class Out>
Out copy_here(In a, In b, Out c) {
    while (a != b) *c++ = *a++;
    return c;
}

template<class T>
T median(const vector<T> &num) {
    typedef typename vector<T>::size_type vecLen;
    vecLen s = num.size();
    int mid = s / 2;
    return s % 2 == 0 ? (num[mid] + num[mid - 1]) / 2 : num[mid] / 2;
}

template <class T>
void reverse_here(T s, T e){
    while(s!=e){
        --e;
        if (s!=e) swap(*s++, *e);
    }
}

template <class T, class In>
bool binaryFind(In s, In e, const T &x){  // binary is not right here;
    while(s<e){  // [ )
        In mid = s + (e-s)/2;
        if (*mid == x) return true;
        else if (*mid > x) e = mid;
        else s = mid+1;
    }
    return false;
}

int main() {
    int a = 1, b = 2;
    cout << max_here(a, b) << "\n";
    char x = 'c', y = 'f';
    cout << max_here(x, y) << "\n";

    vector<int> x_copy{1, 2, 3, 6, 7, 9};
    vector<int> y_copy;
    auto res_here = copy_here(x_copy.begin(), x_copy.end(), back_inserter(y_copy));
    cout << "After copy: ";
    for (int it: y_copy) cout << it << " ";
    cout << "\n";
    cout << "Median of previous line: " << median(y_copy) << endl;
    reverse_here(y_copy.begin(), y_copy.end());
    cout << "After Reverse: ";
    for (int it: y_copy) cout << it << " ";
    cout << "\n";
    sort(y_copy.begin(), y_copy.end());
    cout << "check all elements in the vector: ";
    for (int x : y_copy) {
        if (binaryFind(y_copy.begin(), y_copy.end(), x)) cout << "Yes ";
        else cout << "No\n";
    }
    cout << "\nif 100 in the vector: ";
    if (binaryFind(y_copy.begin(), y_copy.end(), 100)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

