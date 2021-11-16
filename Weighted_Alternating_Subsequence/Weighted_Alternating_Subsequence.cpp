// Weighted_Alternating_Subsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<math.h>
using namespace std;


vector<int> find_Maximun_alternating_subsequence(const vector<int>& nums, const vector<int>& weight) {  //O(n^2)
    vector<vector<int>> dptable(nums.size(), vector<int>(2));
    for (int i = 0; i < dptable.size(); i++) {
        for (int j = 0; j < 2; j++) {
            dptable[i][j] = weight[i];
        }
    }
    int Up_Max = dptable[0][0];
    int Up_id = 0;
    int Down_Max = dptable[0][1];
    int Down_id = 0;
    for (int i = 0; i < nums.size(); i++) { //O(n^2)
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dptable[i][0] = max(dptable[i][0], dptable[j][1] + weight[i]);
                if (dptable[i][0] > Up_Max) {
                    Up_Max = dptable[i][0];
                    Up_id = i;
                }
            }
            else if (nums[j] > nums[i]) {
                dptable[i][1] = max(dptable[i][1], dptable[j][0] + weight[i]);
                if (dptable[i][1] > Down_Max) {
                    Down_Max = dptable[i][1];
                    Down_id = i;
                }
            }
        }
    }

    vector<int> temp;
    int score = max(Up_Max, Down_Max);
    int id = 0;
    int head = 0;
    if (Up_Max > Down_Max) {
        head = 0;
        id = Up_id;
    }
    else {
        head = 1;
        id = Down_id;
    }
    while (score != 0 && id >= 0) {  //O(n)
        if (score == dptable[id][head]) {
            temp.insert(temp.begin(), nums[id]);
            score = score - weight[id];
        }
        if (head == 1) {
            head = 0;
        }
        else {
            head = 1;
        }
        id--;
    }
    return temp;
}
int main()
{
    vector<int> input = { 1, 6, 7, 4, 2, 3, 5};
    vector<int> inputW = { -3,4,10,3,-6,9,-2 };
    vector<int> result = find_Maximun_alternating_subsequence(input, inputW);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}


/* wrong in some cases
vector<int> find_Maximun_alternating_subsequence(const vector<int>& nums, const vector<int>& weight) {  //O(n)
    vector<vector<int>> dptable(nums.size(),vector<int>(2));
    for (int i = 0; i < dptable.size(); i++) {
        for (int j = 0; j < 2; j++) {
            dptable[i][j] = weight[i];
        }
    }
    int Up_Max = dptable[0][0];
    int Up_id = 0;
    int Down_Max = dptable[0][1];
    int Down_id = 0;
    for (int i = 1; i < nums.size(); i++) { //O(n)
        if (nums[Down_id] < nums[i]) {
            dptable[i][0] = max(dptable[i][0], Down_Max + weight[i]);
        }
        if (nums[Up_id] > nums[i]) {
            dptable[i][1] = max(dptable[i][1], Up_Max + weight[i]);
        }
        if (dptable[i][0] > Up_Max) {
            Up_Max = dptable[i][0];
            Up_id = i;
        }
        if (dptable[i][1] > Down_Max) {
            Down_Max = dptable[i][1];
            Down_id = i;
        }

    }

    vector<int> temp;
    int score = max(Up_Max, Down_Max);
    int id = 0;
    int head = 0;
    if (Up_Max > Down_Max) {
        head = 0;
        id = Up_id;
    }
    else {
        head = 1;
        id = Down_id;
    }
    while (score!=0 && id>=0) {  //O(n)
        if (score == dptable[id][head]) {
            temp.insert(temp.begin(), nums[id]);
            score = score - weight[id];
        }
        if (head == 1) {
            head = 0;
        }else {
            head = 1;
        }
        id--;
    }
    return temp;
}
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
