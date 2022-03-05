#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

using namespace std;

const int MAX_SIZE = 100000; //the maximum amount of elements our heap should have.
// when a record is removed from the heap set array[k]->position = -1

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
      }
      else if (elements == 0){
         elements++;
         array[0] = item;    
      }
      else {
         item->position = elements;
         array[elements] = item;
         upHeap(item->position)
         elements++;
      }
      return;
   };  	
   Object* remove_min(){
      if (elements ==0){
		   cout << "empty heap error, can't delete"<<endl;
	   }
      if(elements == 1){
         elements--;
         return array[0];
      }
      Object* temp = array[0]; // store minimum value
      array[0]->position = -1;
      array[elements-1]->position = 0; // most recently inserted is now @root position
      array[0] = array[elements-1];
      elements--;
      downHeap(0);
      return temp;
   };       // Remove the smallest element in the heap & restructure heap
   
   void decreaseKey(int pos, int val)// Decreases Key in pos to val
   {
      if(pos >= elements){
         cout << "Position " << pos << "is out of the range of the heap" << endl;
         return;
      }
      array[pos]->key = val;
      upHeap(pos);
      return;
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
      bool flag;
      while(2*pos+1 >= elements){
         if(array[2*pos+2]->key >= array[2*pos+1]->key){
            flag = true;
         }
         else{
            flag = false;
         }
         if(flag && array[2*pos+1]->key < array[pos]->key){ // node smaller than children already
            item = array[pos];
            array[pos] = array[2*pos+1]; // left child
            array[2*pos+1] = item;
            array[pos]->position = pos;
            array[2*pos+1]->position = 2*pos+1;
            pos = 2*pos+1;
         }
         else if (!flag && array[2*pos+2]->key < array[pos]->key){
            item = array[pos];
            array[pos] = array[2*pos+2]; // right child
            array[2*pos+2] = item;
            array[pos]->position = pos;
            array[2*pos+2]->position = 2*pos+2;
            pos = 2*pos+2;
         }
         else{
            break;
         }
         return;
      }
   }; 

   void upHeap(int new_pos){// starting with element in position int, sift it up the heap
                       // until it is in final min-heap position
      Object* item = array[new_pos];
      while(new_pos!=0 && array[new_pos]->key < array[(new_pos-1)/2]->key){
         item = array[new_pos];
         array[new_pos] = array[(new_pos-1)/2];
         array[(new_pos-1)/2] = item;
         array[new_pos]->position = new_pos;
         array[(new_pos-1)/2]->position = (new_pos-1)/2;
         new_pos = (new_pos-1)/2;
      }
      return;
   };   
};
#endif
