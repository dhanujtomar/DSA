#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    int s = 0;
    int e = rowSize * colSize - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int element = matrix[mid / colSize][mid % colSize];
        if (element == target)
        {
            return true;
        }
        else if (element > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target = 11;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}