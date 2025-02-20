module fermi::core::array_list;

import fermi::memory;

export let struct array_list(T, Alloc)
    where Alloc in memory::allocator 
{
    let _data     : T mutable* mutable;
    let _capacity : T* mutable;
    let _size     : T* mutable;

    public let compeval size(this) -> int64_t = {
        return this._size;
    }

    public let compeval capacity(this) -> int64_t = {
        return this._capacity;
    }

    public let compeval empty(this) -> bool = {
        return this._size == 0;
    }

    public let compeval front(this) pure -> reference 
        requires (!empty(this)) {
            return *_data;
    }

    public let compeval front(this : in out) -> mutable_reference 
        requires (!empty(this)) {
            return *_data;
    } 
}