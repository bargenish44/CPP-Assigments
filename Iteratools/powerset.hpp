#include<vector> 
#include<cmath> 

using namespace std;
namespace itertools{

// print vecotr(present a subvector)
  template <typename E>
  ostream & operator << (ostream & output, const vector<E> & input){
    output << "{";
    auto it = input.begin();
    if(it != input.end()) { // first element is without comma seperator.
      output << *it;
      ++it;}
    while (it != input.end()){
      output << ',' << *it;
      ++it;}
    output << "}";
    return output; 
  }


  template<typename T>
  class powerset{

    public:

      powerset(T temp) : container(temp){}
      auto begin() const{return iterator<decltype(container.begin())>(container.begin(), container.end());}
      auto end() const{return iterator<decltype(container.begin())>(container.end(), container.end());}
    
    private:

      T container; // one 

    template<typename E>
    class iterator{

      private :
        E start;
        E stop;
        uint index;
        size_t size;
        vector<vector<E>> list;

        vector<vector<E>>  getAllSubsets(const vector<E> & set){
          vector<vector<E>> subset;
          vector<E> empty;
          subset.push_back( empty );
          for (int i = 0; i < set.size(); i++){
            vector<vector<E>> subsetTemp = subset;
            for (int j = 0; j < subsetTemp.size(); j++)
              subsetTemp[j].push_back( set[i] );
            for (int j = 0; j < subsetTemp.size(); j++)
              subset.push_back( subsetTemp[j] );
          }
          return subset;
        }

        vector<E> change(const E i,const E j){
          vector<E> ans;
          E runner = i;
          while(runner != j){
            ans.push_back(runner);
            ++runner;
          }
          return ans;
        }

        size_t length(const E start,const E stop){
          E runner = start;
          size_t ans = 0;
          while(runner != stop){
            ans++;
            ++runner;
          }
          return pow(2,ans);
        }

        public :

        iterator(E start_temp,E stop_temp) : start(start_temp),stop(stop_temp),size(length(start_temp,stop_temp)),index(0){}

        auto operator*(){
          vector<E> v = change(start,stop);
          list = getAllSubsets(v);
          vector<typename remove_const<typename remove_reference<decltype(*start)>::type>::type> vector; // every call to this operator function the vector is absoulutly new
          for(auto i : list[index]){
            vector.push_back(*i);
          }
          return vector;
        }

        auto operator++() { // advaced value
          ++index;
          return *this;
        }

        bool operator!= (const iterator & temp){
          return (index != size);
        }

    };
  };
};
