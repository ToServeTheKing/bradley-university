#include <iostream>
#include <vector>

using namespace std;

void dump(const string test, const vector<int> &myVector)
{
    cout << test << " to sort size: " << myVector.size() << endl;

    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return;
}

vector<int> merge(vector<int> left, vector<int> right)
{
    size_t ileft = 0, iright = 0;
    vector<int> results;
    while (ileft < left.size() && iright < right.size())
        if (left[ileft] < right[iright])
            results.push_back(left[ileft++]);
        else
            results.push_back(right[iright++]);
    while (ileft < left.size())
        results.push_back(left[ileft++]);
    while (iright < right.size())
        results.push_back(right[iright++]);
    return results;
}

vector<int> myMergeSort(vector<int> &myVector)
{
    if (myVector.size() <= 1)
        return myVector;
    int len = myVector.size() / 2;
    vector<int> left(myVector.begin(), myVector.begin() + len);
    vector<int> right(myVector.begin() + len, myVector.end());
    return merge(myMergeSort(left), myMergeSort(right));
}

int main()
{
    // test 1
    vector<int> myVector1{2, 1};
    dump("test1", myMergeSort(myVector1));

    // test 2
    vector<int> myVector2{2, 4, 6, 7, 1, 2, 3, 5};
    dump("test2", myMergeSort(myVector2));

    return 0;
}