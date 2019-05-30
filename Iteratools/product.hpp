#pragma once

#include<iostream>
using namespace std;

namespace itertools{
  bool flag=false;
  template <typename T,typename T1>
  class product{
    public:
      product(const T a,const T1 b) : container1(a),container2(b){
        flag = false;
        if(!(b.begin() != b.end())) 
          flag = true;
      }
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
          E1 tempstop;
        public:
          iterator(E val1,E1 val2) : start(val1),stop(val2),tempstop(val2){}
          iterator& operator++() // advaced value
          {
            ++stop;
            return *this;
          }
          auto operator*() const{return pair< decltype(*start),decltype(*stop)> (*start,*stop);}
          bool operator!= (const iterator& temp){
            if(start !=temp.start&& !(stop!=temp.stop)){
              stop=tempstop;
              ++start;
            }
            return (start != temp.start && !flag);}
      };
  };
};
