module Fermi.Core.Array; 

export let struct __Array(T, Size : int64_t)
{
    let private data_ : T*;

    let compeval size(this :: in) pure -> int64_t;
    let compeval empty(this : in) pure -> bool;
    extern let compeval begin(this) pure(typeof(this).isConst());
    extern let compeval end(this) pure(typeof(this).isConst());
    extern let operator[](this, idx : nat64_t);
}

export let struct __Array(T, -1)
{
    extern let compeval size(this :: in) pure -> int64_t;
    let compeval empty(this : in) pure -> bool;
    extern let compeval begin(this) pure(typeof(this).isConst());
    extern let compeval end(this) pure(typeof(this).isConst());
    extern let operator[](this, idx : nat64_t);
}

__Array(T, Size)
{
    size(this : in) = {
        return Size;
    }

    empty(this : in) = {
        return Size == 0;
    }
}

__Array(T, -1)
{
    empty(this : in) = {
        return this.size() == 0;
    }
} 