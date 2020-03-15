#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

class bigint{
    vector<uint32_t> arr = {1};
    static constexpr uint32_t maxSize = 1000000000;
    
    void shrink(vector<uint32_t> & vec){
        for(int i = vec.size()-1; i > 1; i--){
            if (vec[i]==0)
                vec.pop_back();
        }
    }
    
    bigint(const vector<uint32_t> &vec) : arr(vec) {
        shrink(arr);
    }
    
public:
    bigint() = default;
    bigint(uint64_t num){
        arr.clear();
        while(num){
            uint32_t lim = num%maxSize;
            arr.push_back(lim);
            num/=maxSize;
        }
    }
    
    bigint(string str){
        arr.clear();
        const int len = (int)str.size();
        while(str.size() > 0){
            const int len = (int)str.size();
            string sub = str.substr(max(len-9,0),max(len,len-9));
            uint32_t num = stoi(sub,nullptr);
            str.resize(max(0,len-9));
            arr.push_back(num);
        }
    }
    
    void multiply(const bigint &val){
        const int len1 = min(arr.size(), val.arr.size()), len2 = max(arr.size(), val.arr.size());
        const bool switcharr = arr.size() > val.arr.size();
        const vector<uint32_t> &a1 = (switcharr ? val.arr : arr);
        const vector<uint32_t> &a2 = (switcharr ? arr : val.arr); 

        vector<uint32_t> res(2*max(len1, len2)+1,uint32_t(0));
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                const int pos = i+j;
                uint64_t multres = a1[i] * uint64_t(a2[j]);
                res[pos] += multres % maxSize;
                res[pos+1] += multres/maxSize + res[pos]/maxSize;
                res[pos] %= maxSize;
            }
        }
        shrink(res);
        arr = std::move(res);
    }
    
    void add(const bigint &val){
        const int len1 = min(arr.size(), val.arr.size()), len2 = max(arr.size(), val.arr.size());
        const bool switcharr = arr.size() > val.arr.size();
        const vector<uint32_t> &a1 = (switcharr ? val.arr : arr);
        const vector<uint32_t> &a2 = (switcharr ? arr : val.arr); 

        vector<uint32_t> res(max(len1, len2)+1,uint32_t(0));
        for(int i = 0; i < len2; i++){
            res[i] += a2[i] + (i < len1 ? a1[i] : 0);
            res[i+1] = res[i]/maxSize;
            res[i] %= maxSize;
        }
        shrink(res);
        arr = std::move(res);
    }

    void power(uint32_t exp){
        bigint res(1);
        while(exp){
            if (exp & 1){
                res.multiply(*this);
            }
            exp >>= 1;
            multiply(*this);
        }
        arr=res.arr;
    }
    
    string tostr() const{
        stringstream ss;
        ss << setfill('0');
        ss << arr.back();
        for(int i = (int)arr.size()-2; i >= 0; i--){
            ss << setw(9) << arr[i];
        }
        return ss.str();
    }
    
    void print() const{
        cout << tostr();
    }
    
    void printl() const{
        cout << tostr() << endl;
    }  
    
    friend bigint operator+(bigint val1, bigint val2);
    friend bigint operator*(bigint val1, bigint val2);
    
    uint32_t digit_sum() {
        uint32_t sum = 0;
        for(uint32_t val : arr){
            int copy = val;
            while (copy){
                sum += copy % 10;
                copy /= 10;
            }
        }
        return sum;
    }
};

bigint operator+(const bigint &val1, const bigint &val2){
    bigint copy = val1;
    copy.add(val2);
    return copy;
}

bigint operator*(const bigint &val1, const bigint &val2){
    bigint copy = val1;
    copy.multiply(val2);
    return copy;
}
