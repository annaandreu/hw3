#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and heap_vector members you need below
std::vector<T> heap_vector;
PComparator comp;
int max; // max number of children nodes 

};

// Add implementation of member functions here

//consructor
template <typename T, typename PComparator >
Heap<T,PComparator>::Heap(int m, PComparator c){
  max = m; 
	comp = c; 
}

//deconstructor
template <typename T, typename PComparator >
Heap<T, PComparator>::~Heap() {   
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
	heap_vector.push_back(item);
    std::size_t index = heap_vector.size() - 1; 

		while (index > 0) {
        std::size_t parent_index = (index - 1) / max; // div by max (ex 2 when binary tree)

        T& parent = heap_vector[parent_index];
				T& current = heap_vector[index];
        
				if (comp(parent, current)) {
            break;
        }
				std::swap(current, parent);
        index = parent_index;
    }

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
  throw std::underflow_error("heap is empty");
  }
  return heap_vector.front();

  
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("heap is empty");
  }
	else if(heap_vector.size() == 1){  
		heap_vector.pop_back();
		
	}

	else { // >1 
	heap_vector[0] = heap_vector.back(); // set first item to last
	heap_vector.pop_back();
	
	//heapify 
    std::size_t index = 0; 
		
    while(true){ // while not a leaf node 
			std::size_t best_child = ((max * index) + 1);
			if(best_child >= heap_vector.size()){ // 
				break;
			}
			std::size_t copy = ((max * index) + 1);

      if(heap_vector.size() <= 1){ // edge case
        return; 
      }

 // check all children
      for(int i= 1; i < max; i++){
        if(copy + i < heap_vector.size()){ // if i child exists
          if(comp(heap_vector[copy + i], heap_vector[best_child])){ // if i child is better than current best child 
            best_child = copy + i; // i child becomes best
          }
      }
      }

    if(comp(heap_vector[best_child], heap_vector[index])){ // if best child index index is better than current index 
				std::swap(heap_vector[index], heap_vector[best_child]);
				index = best_child; // set index so u can heapify again
    }
		else{
			break; 
		}
     
		//index = best_child; // set index so u can heapify again
		
    }// while 
	} // else
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{

if(heap_vector.empty()){
		return true;
	}
	else{
		return false;
	}

}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return heap_vector.size();

}


#endif

