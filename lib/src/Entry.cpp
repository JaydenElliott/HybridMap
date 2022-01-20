/// Temporary, move later
template<typename K, typename T>
struct Entry
{
public:
  K key;    // need to make this less than 8 bytes
  T* data;  // make this 8 bytes


  Entry(K&& k, T&& d) : key(std::move(k)), data(std::move(&d))
  {
  }

  Entry() : key(0), data(nullptr)
  {
  }
};
