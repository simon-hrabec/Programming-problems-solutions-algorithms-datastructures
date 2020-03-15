#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

template <class T, size_t DIM>
class arrayND{
    std::array<size_t, DIM> sizes;
    std::array<size_t, DIM-1> access_multiplier;
    vector<T> data;

  public:
    template <typename... Args, typename std::enable_if_t<sizeof...(Args) == DIM, int> = 0>
    arrayND(Args&&... args) {
        std::array<size_t, DIM> temp{args...};
        sizes = temp;
        size_t mult = 1;
        for(int i = DIM-2; i >= 0; --i){
            mult *= sizes[i+1];
            access_multiplier[i] = mult;
        }
        data.resize(mult*temp[0]);
    }

    template <typename... Args, typename std::enable_if_t<sizeof...(Args) == DIM, int> = 0>
    T& get(Args&&... args){
        std::array<size_t, DIM> idx_copy{args...};
        size_t index = idx_copy[DIM-1];
        for(int i = DIM-2; i >= 0; --i){
            index += idx_copy[i]*access_multiplier[i];
        }
        return data[index];
    }
    
    template <typename... Args, typename std::enable_if_t<sizeof...(Args) == DIM, int> = 0>
    T& operator()(Args&&... args){
        return get(args...);
    }
    
    void set(const T& elem){
        fill(data.begin(), data.end(), elem);
    }
    
    void print_info(){
        std::cout << "Total elements: " << data.size() << std::endl;
        std::cout << "Sizes: ";
        for(int i = 0; i < DIM; i++){
            cout << sizes[i] << " ";
        }
        std::cout << endl;
        std::cout << "Access_multipliers: ";
        for(int i = 0; i < DIM-1; i++){
            cout << access_multiplier[i] << " ";
        }
        std::cout << endl;
    }
    
    typename std::vector<T>::iterator begin(){
        return data.begin();
    }

    typename std::vector<T>::iterator end(){
        return data.end();
    }
    
    typename std::vector<T>::const_iterator begin() const{
        return data.begin();
    }

    typename std::vector<T>::const_iterator end() const{
        return data.end();
    }
};

void test(){
    arrayND<int, 4> arr(1,2,3,4);
    arr.get(1,2,3,4);
    
    arrayND<int,3> arr2(2,3,4);
    arr.set(10);
    arr2.get(0,0,0) = 23;
    arr2(1,1,1) = 15;
    cout << arr2(0,0,0) << endl;
    
    
    for(auto elem : arr2){
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    test();
    return 0;
}
