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


template <class T, class DIM>
class array2D{
    std::array<site_t, DIM> sizes;
    vector<T> data;
    size_t x_size, y_size;
    
    //constructor

    //get function

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



template <class T, size_t DIM>
class arrayND{
    std::array<size_t, DIM> sizes;
    std::array<size_t, DIM-1> access_multiplier;
    vector<T> data;
    
    //constructor

    //get function

  public:
    array2D(size_t x, size_t y) : data(x*y), x_size(x), y_size(y) {}
    array2D(size_t x, size_t y, T val) : data(x*y, val), x_size(x), y_size(y) {}
    
    template <typename... Args>
    T& get(Args&&... args)
    T& get(size_t x, size_t y) {
        return data[x*y_size+x]; 
    }
}
