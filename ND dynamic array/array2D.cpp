#include <vector>
#include <tuple>

template <class T>
class array2D{
  std::vector<T> data;
  size_t x_size, y_size;
  
public:
  using value_type = T;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  array2D(std::tuple<size_t, size_t> sizes) : array2D(std::get<0>(sizes), std::get<1>(sizes)) {}
  array2D(std::tuple<size_t, size_t> sizes, const T &val) : array2D(std::get<0>(sizes), std::get<1>(sizes), val) {}
  array2D(size_t x, size_t y) : data(x*y), x_size(x), y_size(y) {}
  array2D(size_t x, size_t y, const T &val) : data(x*y, val), x_size(x), y_size(y) {}
  array2D(size_t x, size_t y, std::vector<T> &&dataSource) : data(std::move(dataSource)), x_size(x), y_size(y) {}
  array2D(size_t x, size_t y, std::initializer_list<T> dataSource) : data(std::move(dataSource)), x_size(x), y_size(y) {}

  T& operator()(size_t x, size_t y) {
      return get(x, y);
  }

  const T& operator()(size_t x, size_t y) const {
      return get(x, y);
  }
  
  T& get(size_t x, size_t y) {
    return data[x*y_size+y]; 
  }
  
  const T& get(size_t x, size_t y) const {
    return data[x*y_size+y];
  }
  
  iterator begin() {
    return std::begin(data);
  }
  
  iterator end() {
    return std::end(data);
  }
  
  const_iterator begin() const {
    return std::cbegin(data);
  }
  
  const_iterator end() const {
    return std::cend(data);
  }

  size_t getSizeX() const {
    return x_size;
  }

  size_t getSizeY() const {
    return y_size;
  }

  std::tuple<size_t, size_t> getSizes() const {
    return {x_size, y_size};
  }

  size_t size() const {
    return x_size*y_size;
  }
};
