// Problem: https://leetcode.com/problems/strictly-palindromic-number/

#include <bitset>
#include <algorithm>
#include <math.h>
#include <iostream>


// Recursive solution.
class Solution
{
public:
    int orig = 0;
    
    bool recursePalindromic(int pow)  // Checks orig to a power's binary for palindromicy.
    {
        if (pow > (orig - 2)) {
            return true;  // All binary powers were palindromic.
        }
        
        // Binary palindromicy checks.
        std::bitset<17> binaryOrig(orig);
        std::string binStr = binaryOrig.to_string();
        std::reverse(binStr.begin(), binStr.end());
        std::bitset<17> reverseBinaryOrig(binStr);
        if (reverseBinaryOrig != binaryOrig) {
            return false;
        }
        
        recursePalindromic(++pow);
        return false;
    }
    
    bool isStrictlyPalindromic(int n)
    {
        orig = n;
        return recursePalindromic(2);
    }
};

int main()
{
    Solution solution;

    std::cout << solution.isStrictlyPalindromic(9) << std::endl;
}
