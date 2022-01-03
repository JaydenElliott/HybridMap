template<typename T>
struct Hash
{

private:
  size_t key;  // should this be templated too?
  T* data;     // make this 8 bytes somehow
};
