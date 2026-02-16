class Solution {
public:
    int reverseBits(int n) {
        uint32_t result = 0;
      
        for (int i = 0; i < 32 && n != 0; ++i) {
            result |= (n & 1) << (31 - i);
          
            n >>= 1;
        }
      
        return result;

    }
};