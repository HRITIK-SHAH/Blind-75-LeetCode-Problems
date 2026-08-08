class Solution {
public:
    int reverseBits(int n) {
        return rev(n , 32);
    }
    private:
    int rev(int v , int len){
        if(len == 1) return v & 1u;

        int half = len >> 1;
        int mask = (1u << half) - 1u;
        int lo = v & mask;
        int hi = v >> half;

        return (rev(lo , half) << half) | rev(hi , half);


    }
        
    
};