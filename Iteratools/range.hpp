#pragma once

#include<iostream>

using namespace std;

namespace itertools{

  template <class T>
  class range{
    public:
      range(T a,T b) : start(a),stop(b){}
      auto begin() const{return iterator(start);}
      auto end() const{return iterator(stop);}
    private:
      const T start; // start point
      const T stop; // end point

      class iterator{
        public :

        T value; // "now" value

        iterator(T val) : value(val){}

        iterator& operator++() // advaced value
        {
            ++value;
            return *this;
        }

        bool operator!= (const iterator& temp) const{return value != temp.value;}
        T operator*() const{return value;}

    };

  };
};
