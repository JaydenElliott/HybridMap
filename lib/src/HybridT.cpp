/// Temporary, move later
template<typename K, typename T>
struct Hash
{
public:
  K key;    // need to make this less than 8 bytes
  T* data;  // make this 8 bytes


  Hash(K k, T* d) : key(k), data(d)
  {
  }

  Hash() : key(0), data(nullptr)
  {
  }
};
