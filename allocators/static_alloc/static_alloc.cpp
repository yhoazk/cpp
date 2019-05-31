
#include <iostream>


class static_allocator{
private:
    const size_t block_size;
    const size_t block_count;
    unsigned char allocator_id;
    unsigned char* mem_pool;
    unsigned char* public_pool;
    unsigned char* block_map;
    /* The  first block will be used for book keeping*/
    void fill_block_map(void){
        block_map = mem_pool;
        // what when the number of blocks is bigger than the first block?
        // how to avoid overwritting the next block ie the public_pool
        for (size_t i = 0; i < block_count; i++){
            block_map[i] = 0;
        }
    }

public:
    void print_block_map(){
        char id;
        for (size_t i = 1; i < block_count; i++)
        {
            if((i % 16) == 0 ){ std::cout << std::endl; }
            id = (block_map[i] != 0)? '@' + block_map[i] : '_';
            std::cout << id;
        }
        std::cout << "\n";   
    }

    static_allocator(size_t blk_cnt, size_t blk_size, unsigned char* mptr): allocator_id(1),
                                                                            block_count(blk_cnt),
                                                                            block_size(blk_size),
                                                                            mem_pool(mptr){
        fill_block_map();
        public_pool = &(mem_pool[block_size]);
     };
    size_t mem_size(void){
        return block_count * block_size;
    }

    /** AA AA AA AA AA
     * allocates the required blocks in fixed sitzes
     */
    void* alloc(size_t blks){
        // find if there are blks contigous blocks
        size_t blk_cnt = 0; // counts the free blocks
        size_t offset = 0;
        for (; offset < block_count; offset++){
            if(0 == block_map[offset]){
                blk_cnt++;
            } else {
                blk_cnt = 0;
            }

            if(blk_cnt >= blks){
                // contiguous free block found allocate
                std::cout << "offset: " << offset << "\n";
                break;
            }
        }
        if(offset == block_count){
            // no block found
            return nullptr;
        }
        // fill the block_map with the id of the allocator
        for (int i = offset - (blks-1); i < offset; i++){
            block_map[i] = allocator_id;
        }
        allocator_id++;
        return static_cast<void*>(&public_pool[ block_size * (offset-blks)]);
    }

    void dealloc(void* mem_addr){
        // find the id of the alloc and map it to the address
        unsigned char* blk_to_free = static_cast<unsigned char*>(mem_addr);
        unsigned char current_id;
        size_t offset  = (static_cast<size_t>(blk_to_free - public_pool) / block_size) + 1u;
        std::cout << "Dealloc Offset " << offset << "\n";
        // free the blocks
        current_id = block_map[offset];
        while (current_id == block_map[offset]){
            block_map[offset++] = 0;
        }
    }

};



int main(int argc, char const *argv[])
{
    static const size_t BLOCK_SIZE = (1<< 8) -1;
    static const size_t BLOCK_COUNT = (1<< 6);
    unsigned char mem[BLOCK_COUNT * BLOCK_SIZE];
    unsigned char* blk0 = nullptr;
    unsigned char* blk1 = nullptr;
    unsigned char* blk2 = nullptr;
    unsigned char* blk3 = nullptr;
    static_allocator salloc(BLOCK_COUNT, BLOCK_SIZE, mem);
    std::cout << "Count(" << BLOCK_COUNT << ") * size(" << BLOCK_SIZE << ") = " << \
                                                     salloc.mem_size() << std::endl;
    salloc.print_block_map();
    blk0 = static_cast<unsigned char*>(salloc.alloc(12));
    std::cout << "\nAllocate:\n";
    salloc.print_block_map();
    blk1 = static_cast<unsigned char*>(salloc.alloc(12));
    std::cout << "\nAllocate:\n";
    salloc.print_block_map();
    blk2 = static_cast<unsigned char*>(salloc.alloc(5));
    std::cout << "\nAllocate:\n";
    salloc.print_block_map();
    
    salloc.dealloc(blk1);
    salloc.print_block_map();

    blk3 = static_cast<unsigned char*>(salloc.alloc(5));
    std::cout << "\nAllocate:\n";
    blk1 = static_cast<unsigned char*>(salloc.alloc(15));
    salloc.dealloc(blk3);
    salloc.print_block_map();
    blk3 = static_cast<unsigned char*>(salloc.alloc(15));
    salloc.print_block_map();
    
    return 0;
}
