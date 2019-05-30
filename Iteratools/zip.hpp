#pragma once

#include<iostream>
using namespace std;

namespace itertools{
  template <typename T,typename T1>
  class zip{
    public:
    zip(const T a,const T1 b) : container1(a),container2(b){}
    auto begin() const{
      return iterator<decltype(container1.begin()),decltype(container2.begin())>(container1.begin(),container2.begin());}
    auto end() const {
      return iterator<decltype(container1.end()),decltype(container2.end())>(container1.end(),container2.end());} 
  
  private:
    const T container1; // iterator for first type
    const T1 container2; // iterator for second type

    template<typename E,typename E1>
    class iterator{
      private:
        E start; // first iterator
        E1 stop; // second iterator

        public:
        iterator(E val1,E1 val2) : start(val1),stop(val2){}

          iterator& operator++() // advaced value
          {
            ++start;
            ++stop;
            return *this;
          }
          auto operator*() const{return pair< decltype(*start),decltype(*stop)> (*start,*stop);}
          bool operator!= (const iterator& temp){return start != temp.start || stop != temp.stop;}
    };
  };
  template <typename F,typename F1>
    ostream& operator<<(ostream& os, const pair<F,F1> p)
      {
       os << p.first << "," << p.second;
       return os;
      }
};
