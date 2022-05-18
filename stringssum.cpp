/*
    Time complexity: O(|NUM1| + |NUM2|)
    Space complexity: O(1)
    
    Where |NUM1| and |NUM2| are the length of the strings.
*/

#include <algorithm>

string stringSum(string &num1, string &num2) {
    
    // Indices to traverse the strings.
    int idx1 = num1.size() - 1;
    int idx2 = num2.size() - 1;
    
    // To store the sum.
    string res = "";
    
    // To store the carry.
    int carry = 0;
    
    // Add characters individually,
    while(idx1 >= 0 || idx2 >= 0) {
        
        // To store sum of current character.
        int localSum = 0;
        
        // Check if num1 is present.
        if(idx1 >= 0) {
            
            // Add current character.
            localSum += num1[idx1] - '0';
            --idx1;
        }
        
        // Check if num2 is present.
        if(idx2 >= 0) {
            
            // Add current character.
            localSum += num2[idx2] - '0';
            --idx2;
        }
        
        // Add carry to the sum.
        localSum += carry;
        
        carry = 0;
        
        // Check if sum is greater than 9.
        if(localSum > 9) {
            
            // Update sum and carry.
            localSum %= 10;
            carry = 1;
        }
        
        // Update the result.
        res += (localSum % 10) + '0';
    }
    
    // If carry is present.
    if(carry) {
        res += '1';
    }
    
    // Reverse the string.
    reverse(res.begin(), res.end());
    
    return res;
}
