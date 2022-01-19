#include "HybridT.cpp"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

/**
 * \brief A open-addressing / chaining hybrid
 *        hash map implementation.
 *
 *        Values in the hashmap are stored as
 *        Hash(K Key, T Value)
 *
 * \tparam T: Value type stored in map. Must be of type
 * \tparam S: Hash-map capacity (can be altered post-init)
 * \tparam K: Data key type
 * \tparam F: Function type Example std::function<double()>(double)
 *
 */
template<typename T, size_t S, typename K, typename F>
struct HybridMap
{

private:
  /// Pointer to the hashmap in memory
  Hash<K, T> m_data[S];

  /// Number of elements in the hashmap
  size_t m_size = 0;

  /// Size of allocated block of memory
  size_t m_capacity = S;

  /// Hash function
  F m_hash;

public:
  /// Returns the number of values stored in the map
  constexpr int Size() const
  {
    return S;
  }


  HybridMap(F f) : m_hash(f)
  {
  }

  /// Iterates through the map, printing the data portion
  /// of the Hash
  void printMap()
  {
    std::cout << "Printing" << '\n';
    for (auto i : m_data)
    {
      std::cout << m_data->data << ", ";
    }
  }

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


  /**
   * \brief Indexing into the hash table will perform a hash
   *        operation using 'key' and search for the corresponding
   *        Hash.key value which contains the data
   */
  T* operator[](const K key) const
  {
    int idx = m_hash(key);  // TODO: update the data type later. Should be dependent on size of hashmap
    while (key != m_data[idx].key)
    {
      if (idx > S)
      {
        throw std::out_of_range("Index out of range");
      }
      idx++;
    }

    return m_data[idx].data;
  }

  /**
   *\brief Inserts a value/object into the hashmap using
   * the hash function provided on intialisation
   */
  void insert(K&& key, T&& value)
  {
    int idx = m_hash(key);
    while (m_data[idx].data)
    {
      idx++;
    };
    m_data[idx] = Hash<K, T>(std::move(key), std::move(value));
  }

  void insert(K key, T& value)
  {
    int idx = m_hash(key);
    while (m_data[idx].data)
    {
      idx++;
    };
    m_data[idx] = Hash<K, T>(std::move(key), std::move(value));
  }
};
