#ifndef EX01_DATA_HPP_
#define EX01_DATA_HPP_

class Data {
  int value_;

 public:
  Data();
  explicit Data(int value);
  Data(const Data& ohter);
  Data& operator=(const Data& ohter);
  ~Data();
};

#endif  // EX01_DATA_HPP_
