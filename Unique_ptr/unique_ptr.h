namespace rain {
template <typename T>
class unique_ptr {
 public:
  unique_ptr(T* ptr = nullptr) : ptr_(ptr) {}

  ~unique_ptr() {
    if (this->ptr_ != nullptr) {
      printf("~unique ptr delete ptr_\n");
      delete this->ptr_;
      this->ptr_ = nullptr;
    }
  }

  unique_ptr(const unique_ptr<T>&& up) : ptr_(up) {
    printf("move constructor\n");
    up.ptr_ = nullptr;
  }

  unique_ptr<T>& operator=(const unique_ptr<T>&& up) {
    if (this == up.ptr_) {
      return *this;
    }
    printf("operator=\n");
    ptr_    = up.ptr_;
    up.ptr_ = nullptr;
    return *this;
  }

  T& operator*() const { return *(this->ptr_); }
  T* operator->() const { return this->ptr_; }
  T* get() const { return this->ptr_; }
  unique_ptr(const unique_ptr<T>& up)               = delete;
  unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;

 private:
  T* ptr_;
};
}  // namespace rain
