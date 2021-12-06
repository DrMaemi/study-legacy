#include <iostream>
#include <vector>
#include <iterator>

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::copy;

int main()
{
    vector<double> arr {-3.5, -21.1, -1.99, 0.129, 2.5, 3.111};

    copy(arr.begin(), arr.end(),
         std::ostream_iterator<double>(cout,"; "));
    cout << endl;

    double *d_arr = arr.data();
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << d_arr[i] << "; ";
    }
    cout << endl;

    return EXIT_SUCCESS;

    /* & 주소할당을 이용한 벡터-배열 변환 */
    /*
        vector<double> arr {-3.5, -21.1, -1.99, 0.129, 2.5, 3.111};

    copy(arr.begin(), arr.end(),
         std::ostream_iterator<double>(cout,"; "));
    cout << endl;

    double *d_arr = &arr[0];
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << d_arr[i] << "; ";
    }
    cout << endl;

    return EXIT_SUCCESS;
    */
}