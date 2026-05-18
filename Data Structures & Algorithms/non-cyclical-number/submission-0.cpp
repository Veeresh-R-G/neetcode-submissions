class Solution {
public:
    int squared_num(int n){
        int temp_sum = 0;

        while(n){
            temp_sum += (n % 10) * (n % 10);
            n = n / 10;
        }

        return temp_sum;
    }

    bool isHappy(int n) {
        unordered_map<int, int> umap;

        while(umap.find(n) == umap.end()){
            umap[n] = 1;
            n = squared_num(n);
        }

        return n == 1;
    }
};
