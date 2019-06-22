class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        auto ps = [&matrix](int index)->int{
            return matrix[index / matrix[0].size()][index % matrix[0].size()];
        };
        int b = 0, e = matrix.size() * matrix[0].size();
        while (b < e) {
            int k = (b + e) / 2;
            if (ps(k) < target) {
                b = k + 1;
            } else {
                e = k;
            }
        }
        return b < matrix.size() * matrix[0].size()  && ps(b) == target;
    }
};
