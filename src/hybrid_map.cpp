#include <vector>
#include "hash.cpp"

/// T: Hash value type 
/// S: Initial hashmap capacity
/// F: Hash function 
/// I: Hash functin input type
template <typename T, size_t S, typename F, typename I>
struct HybridMap {

  public:
    constexpr int Size() const {
      return S;
    } 

  private:
    /// Pointer to the hashmap in memory
    Hash<T> *m_data[S];

    /// Number of elements in the hashmap
    size_t m_size = 0;

    /// Size of allocated block of memory
    size_t m_capacity = S;


    /// Reallocates the hashmap with the size new_size
    void realloc(const size_t new_size) {
      Hash<T>* new_data = new T[new_size];

      if (new_size < m_size){
        m_size = new_size; 
      }
      for (int i=0; i < m_size; ++i){
        new_data[i] = std::move(m_data[i]);
      }
      delete[] m_data;
      m_data = new_data;
      m_capacity = new_size;
    }


    Hash<T> operator[](const size_t idx) const {
      // add bounds check
      return m_data[idx]; 
    } 

    /// input: hash function input
    /// value: value to insert
    void insert(const I input, const T value){
      // bounds chec
      m_data[F(input)] = value;
    }
};

