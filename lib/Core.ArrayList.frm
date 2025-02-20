module fermi::core::array_list;

import fermi::memory;

export let struct array_list(T, Alloc)
    where Alloc in memory::allocator 
{
    let _data     : T mutable* mutable;
    let _capacity : T* mutable;
    let _size     : T* mutable;
}