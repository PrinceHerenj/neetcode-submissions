class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1; 
                // take i shifted n to zero index to get bit
            res |= (bit << (31 - i));
                // append bit to the mirrored index in result
        }
        return res;
    }
};
