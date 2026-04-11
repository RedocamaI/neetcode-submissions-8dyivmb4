class Solution {
public:
    string sumWithProd(string sum, string prod) {
        int n = sum.size();
        int m = prod.size();
        if(m == 0) {
            return sum;
        }
        
        int i = n-1, j = m-1;
        string newProd = "";
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int a = sum[i--] - '0';
            int b = prod[j--] - '0';
            int c = a+b + carry;

            newProd = char(c%10 + '0') + newProd;
            carry = c/10;
        }

        while(i >= 0) {
            int a = sum[i--] - '0';
            int c = a + carry;

            newProd = char(c%10 + '0') + newProd;
            carry = c/10;
        }

        while(j >= 0) {
            int a = prod[j--] - '0';
            int c = a + carry;

            newProd = char(c%10 + '0') + newProd;
            carry = c/10;
        }
        if(carry)
            newProd = char(carry + '0') + newProd;

        return newProd;
    }

    string multiply(string num1, string num2) {
        string prod = "";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0;i<num2.size();i++) {
            if(num2[i] == '0')
                continue;
            
            int a = num2[i]-'0';
            string sum = "";
            int carry = 0;
            for(int j=0;j<num1.size();j++) {
                int b = num1[j]-'0';
                int c = a*b + carry;
                
                sum = char(c%10 + '0') + sum;
                carry = c/10;
            }
            if(carry)
                sum = char(carry + '0') + sum;
            
            for(int z=0;z<i;z++)
                sum += '0';
            
            prod = sumWithProd(sum, prod);
        }

        return prod.empty() ? "0" : prod;
    }
};
