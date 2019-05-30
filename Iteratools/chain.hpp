#pragma once

#include<iostream>

using namespace std;

namespace itertools{

  template <typename T,typename T1>
  class chain{
    public:
      chain(const T a,const T1 b) : container1(a),container2(b){}
      auto begin() const{
        return iterator<decltype(container1.begin()),decltype(container2.begin())>(container1.begin(),container2.begin());}
      auto end() const {
        return iterator<decltype(container1.end()),decltype(container2.end())>(container1.end(),container2.end()); }
    
    private:
      const T container1; // iterator for first type
      const T1 container2; // iterator for second type
      template<typename E,typename E1>
      class iterator{
        private:
          E start; // first iterator
          E1 stop; // second iterator
          bool onsecond=false;

        public:
          iterator(E val1,E1 val2) : start(val1),stop(val2){}

          iterator& operator++() // advaced value
            {
            if(!onsecond)
              ++start;
            else
              ++stop;
            return *this;
            }

          auto operator*() const
            {
            if(!onsecond)
              return *start;
            return *stop;
            }

          bool operator!= (const iterator& temp)
            {
            if (!(start != temp.start)) // continue to the next range
              onsecond=true;
            if(!onsecond)  
              return start != temp.start;
            return stop != temp.stop;
            }
    }; 
  };
};
