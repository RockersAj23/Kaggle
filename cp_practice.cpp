#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(int i, vector<int>& lst, int ad,
          const vector<int>& machineCount, const
          vector<int>& finalMachineCount, int
          shiftingCost) {
    int n = machineCount.size();
    if (i == n) {
        int res = ad;
        for (int k = 0; k < 3; ++k) {
            res += abs(lst[k] - finalMachineCount[k]);
        }
        return res;
    }

    int res = INT_MAX;
    res = min(res, solve(i + 1, lst, ad, machineCount, finalMachineCount, shiftingCost));

    for (int j = 0; j < 3; ++j) {
        lst[j] += machineCount[i];
        if (lst[j] - machineCount[i] != 0) {
            res = min(res, solve(i + 1, lst, ad + shiftingCost, machineCount, finalMachineCount, shiftingCost));
        } else {
            res = min(res, solve(i + 1, lst, ad, machineCount, finalMachineCount, shiftingCost));
        }
        lst[j] -= machineCount[i];
    }

    return res;
}

int getMinimumCost(const vector<int>& machineCount, const vector<int>& finalMachineCount, int shiftingCost) {
    vector<int> lst(3, 0);
    return solve(0, lst, 0, machineCount, finalMachineCount, shiftingCost);
}

int main() {
    // ... rest of the code ...

    // Sample usage:
    vector<int> machineCount = {1, 2, 3};
    vector<int> finalMachineCount = {2, 3, 1};
    int shiftingCost = 5;

    int minimumCost = getMinimumCost(machineCount, finalMachineCount, shiftingCost);
    cout << "Minimum cost: " << minimumCost << endl;
}