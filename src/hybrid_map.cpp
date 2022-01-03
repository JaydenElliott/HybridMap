#include "hash.cpp"
#include <vector>

/**
 * \brief A open-addressing / chaining hybrid
 *        hash map implementation
 *
 * \tparam T: Value type stored in map. Must be of type (Key, Value)
 *         S: Hash-map capacity (can be altered post-init)
 *         F: Pointer to hash function
 *         I: Hash function input type (e.g. uint_8, int, double)
 *
 */
template<typename T, size_t S, typename F, typename I>
struct HybridMap
{

public:
  /// Returns the number of values stored in the map
  constexpr int Size() const
  {
    return S;
  }

private:
  /// Pointer to the hashmap in memory
  Hash<T>* m_data[S];

  /// Number of elements in the hashmap
  size_t m_size = 0;

  /// Size of allocated block of memory
  size_t m_capacity = S;

  /// Reallocates the hashmap with the size new_size
  void realloc(const size_t new_size)
  {
    Hash<T>* new_data = new T[new_size];

    if (new_size < m_size)
    {
      m_size = new_size;
    }
    for (int i = 0; i < m_size; ++i)
    {
      new_data[i] = std::move(m_data[i]);
    }
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_size;
  }

  /**
   * \brief Obtains value at hash
   */
  Hash<T> operator[](const size_t idx) const
  {
    return m_data[idx];
    // need to do collision checks here
  }

  /// Returns value at map index 'idx' with bounds chec
  Hash<T> at(const size_t key) const
  {
    if (idx > S)
      throw std::out_of_range("Index out of range");

    // need to do collision checks
    return m_data[idx];
  }

  /**
   *\brief Inserts a value/object into the hashmap using
   * the hash function provided on intialisation
   */
  void insert(const I input, const T value)
  {
    auto idx = F(input);
    while
      m_data[idx]{idx++};
    m_data[idx] = value;
  }
};
