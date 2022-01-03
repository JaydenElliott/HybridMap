#include "hash.cpp"
#include <utility>
#include <vector>

/**
 * \brief A open-addressing / chaining hybrid
 *        hash map implementation
 *
 * \tparam T: Value type stored in map. Must be of type (Key, Value)
 *         S: Hash-map capacity (can be altered post-init)
 *         F: Pointer to hash function
 *         K: Hash function key type
 *
 */
template<typename T, size_t S, typename F, typename K>
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
  Hash<K, T>* m_data[S];

  /// Number of elements in the hashmap
  size_t m_size = 0;

  /// Size of allocated block of memory
  size_t m_capacity = S;

  /// Reallocates the hashmap with the size new_size
  void realloc(const size_t new_size)
  {
    Hash<K, T>* new_data = new T[new_size];

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

  Hash<K, T> operator[](const K key) const
  {
    auto idx = F(key);
    while (key != m_data[idx].first)
    {
      if (idx > S)
      {
        throw std::out_of_range("Index out of range");
      }
      idx++;
    }
    return m_data[idx].second;
  }

  /**
   *\brief Inserts a value/object into the hashmap using
   * the hash function provided on intialisation
   */
  void insert(const K key, const T value)
  {
    auto idx = F(key);
    while (m_data[idx])
    {
      idx++;
    };
    m_data[idx] = std::pair<K, T>(key, value);
  }
};
