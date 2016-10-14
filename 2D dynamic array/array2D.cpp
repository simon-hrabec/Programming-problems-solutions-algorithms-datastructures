#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class array2D{
    vector<T> data;
    size_t x_size, y_size;
    
  public:
    array2D(size_t x, size_t y) : data(x*y), x_size(x), y_size(y) {}
    array2D(size_t x, size_t y, T val) : data(x*y, val), x_size(x), y_size(y) {}
    
    T& get(size_t x, size_t y) {
        return data[x*y_size+x]; 
    }
    
    const T& get(size_t x, size_t y) const{
        return data[x*y_size+x];
    }
    
    iterator begin(){
        return data.begin();
    }
    
    iterator end(){
        return data.end();
    }
    
    const_iterator begin() const{
        return data.begin();
    }
    
    const_iterator end() const{
        return data.end();
    }
}
