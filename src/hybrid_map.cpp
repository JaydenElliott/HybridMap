#include <vector>
#include "hash.cpp"

template <typename T, size_t S>
struct HybridMap {
  // std::vector<Hash<int>> map;
  public:
    Hash<T> m_map[S];
    constexpr int Size() const {
      return S;
    } 

  private:
    // Pointer to the hashmap in memory
    Hash<T> *m_data = nullptr;

    // Number of elements in the hashmap
    size_t m_size = 0;

    // Size of allocated block of memory
    size_t m_capacity = 0;


    // Reallocates the hashmap with the size new_size
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
      return m_data[idx]; 
    } 
};

