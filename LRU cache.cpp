#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            carry = sum > 1 ? 1 : 0;
            result = to_string(sum % 2) + result;
        }
        return result;
    }
};
