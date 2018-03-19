

template<typename T>
class model
{
  public:
  //using base_t = std::decay(T);
  virtual T v_method() = 0;
};
