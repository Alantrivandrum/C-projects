#include "bitset.h"



// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size)
{
	struct bitset * result = calloc(1,sizeof(struct bitset));
	result->universe_size = size;
	result->size_in_words = (size + 63)/64;
	result->bits = calloc(result->size_in_words, sizeof(uint64_t));

	return result;
}




// get the size of the universe of items that could be stored in the set
int bitset_size(struct bitset * this)
{
	return this->universe_size;
}






// get the number of items that are stored in the set
int bitset_cardinality(struct bitset * this)
{
	
	int count = 0;
	for(int i=0; i<this->size_in_words; i++)
	{
		uint64_t word = this->bits[i];
		
		if(word & 1)
		{
			count++;
			word = word >> 1;
		}	
	}
	return count;
}





// check to see if an item is in the set
int bitset_lookup(struct bitset * this, int item)
{
	uint64_t mask = 1;
	uint64_t word;
       
		word = this->bits[(int)item/64];
		if(item > 64)
		{
			item = item % 64;
		}
		word = word >> item;
		if(word & mask)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	

}

// add an item, with number 'item' to the set
// has no effect if the item is already in the set
void bitset_add(struct bitset * this, int item)
{
	uint64_t tempItem = 0;
	uint64_t tempWord = 0;
	uint64_t mask = 1;
	uint64_t word;
       
		word = this->bits[item/64];
		tempItem = item % 64;
		tempWord = word;
		word = word >> tempItem;
		if(!(word & mask))
		{
			word = 1;
			//word = word << tempItem;
			word = word << tempItem;
			word = tempWord | word;
			this->bits[(int)item/64] = word;
		}
		

}
 
// remove an item with number 'item' from the set
void bitset_remove(struct bitset * this, int item)
{
/*
	uint64_t mask = 1;
	uint64_t word;
       
	word = this->bits[(int)item/64];
	item = item % 64;
	mask = mask << item;
	mask = ~mask;
	word = word | mask;
	this->bits[(int)item/64] = word;
*/
	uint64_t mask = 1;
	int word = floor(item / 64);
	item = item % 64;
	mask = mask << item;
	mask = ~mask;
	this->bits[word] = this->bits[word] & mask;		
		
}

// place the union of src1 and src2 into dest;
// all of src1, src2, and dest must have the same size universe
void bitset_union(struct bitset * dest, struct bitset * src1, struct bitset * src2)
{
		for(int i=0; i < src1->size_in_words; i++)
		{
			dest->bits[i] = src1->bits[i] | src2->bits[i];
		}
	

}

// place the intersection of src1 and src2 into dest
// all of src1, src2, and dest must have the same size universe
void bitset_intersect(struct bitset * dest, struct bitset * src1,struct bitset * src2)
{

		for(int i=0; i < src1->size_in_words; i++)
		{
			dest->bits[i] = src1->bits[i] & src2->bits[i];
		}
	
}
