#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MergeArray
{

public:
    int data;
    int row;
    int col;
    // MergeArray() {}
    MergeArray(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(MergeArray *a, MergeArray *b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKthArray(int arr[][4], int k, int n)
{
    // k(row)
    // n(col)
    priority_queue<MergeArray *, vector<MergeArray *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        MergeArray *temp = new MergeArray(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while (!minHeap.empty())
    {
        MergeArray *temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row; //*(temp).row;//temp->row
        int topCol = temp->col;

        ans.push_back(topElement);

        minHeap.pop();

        if (topCol + 1 < n)
        {
            MergeArray *temp = new MergeArray(arr[topRow][topCol + 1], topRow, topCol + 1);
            minHeap.push(temp);
        }
    }

    return ans;
}

int main()
{

    // MergeArray h;
    int arr[][4] = {
        {2, 4, 6, 8},
        {1, 3, 5, 7},
        {0, 9, 10, 11}};

    vector<int> ans = mergeKthArray(arr, 3, 4);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}