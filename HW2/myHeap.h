#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

using namespace std;

const int MAX_SIZE = 100000; //the maximum amount of elements our heap should have.

template <typename Object>
class Heap
{
public:
   Heap(){
      elements = 0;
   };
   void insert(Object* item){// Add the object pointer item to the heap
	   if (elements >= MAX_SIZE){
		   cout << "Heap is full; can't insert "<< endl;
      // FILL IN THE REST

			return;
	   }

   };  	
   Object* remove_min(){
      if (elements ==0){
		   cout << "empty heap error, can't delete"<<endl;
	   }
      Object* temp = array[0];
      // FILL IN THE REST

      return temp;
   };       // Remove the smallest element in the heap & restructure heap
   
   void decreaseKey(int pos, int val)// Decreases Key in pos to val
   {
         // FILL IN THE REST
   }; 
   

   bool IsEmpty() const {  return (elements <= 0);};
   bool IsFull() const {return (elements >=MAX_SIZE );};
   int count() const {return elements;};
   Object* value(int pos) const{ //return a pointer to an object in heap position
	   if (pos >= elements){
		   cout << "Out of range of heap " << pos << "elements " << elements << endl;
	   }
      return (array[pos]);
   };  
protected:
   Object* array[MAX_SIZE];
   int elements;       //  how many elements are in the heap
private:
   void downHeap(int pos){// starting with element in position pos, sift it down the heap 
                       // until it is in final min-heap position
      Object* item = array[pos];

      // FILL THIS IN

   }; 

   void upHeap(int new_pos){// starting with element in position int, sift it up the heap
                       // until it is in final min-heap position
      Object* item = array[new_pos];
      
      //FILL IN THE REST 
   };   
};
#endif
