class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int save = 1;
        int j = digits.size() - 1;
        while (save and j >= 0) {
            digits[j] += save;
            if (digits[j] == 10) {
                digits[j] = 0;
            } else {
                save = 0;
            }
            j--;
        }
        if (save == 1) {
            digits.insert(digits.begin(), 1);
        }
        while (digits.size() > 1 and digits[0] == 0) {
            digits.erase(digits.begin());
        }
        return digits;
    }
};
