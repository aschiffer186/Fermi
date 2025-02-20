module fermi::memory;

export let compeval aligned_distance[Alignment : uint64_t, T](from : T*, to : T*) 
    requires (Alignmment & (Alignment - 1) == 0) -> int64_t {
        return __builtin_aligned_distance(from, t, Alignment);
    }

export let compeval aligned_ofset[Alignment : uint64_t, T](ptr : T*, offset : int64_t, alignment : uint64_t) 
    requires (Alignmment & (Alignment - 1) == 0) -> T* = {
    return __builtin_aligned_offset(ptr, offse, alignment);
}

export let compeval aligned_ofset[Alignment : uint64_t, T](ptr : T mutable*, offset : int64_t, alignment : uint64_t) 
    requires (Alignmment & (Alignment - 1) == 0) -> T mutable* = {
    return __builtin_aligned_offset(ptr, offset, alignment);
}

export let ? mem_copy[Alignment : uint64_t = typeof(T).alignment(), T](begin : T*, end : T*, dest : T* mutable) 
    requires (Alignmment & (Alignment - 1) == 0) -> void = {
    __builtin_mem_copy(Alignment, begin, end, dest);
}

export let compeval pointer_distance[T](from : T*, to : T*) = {
    return aligned_distance[typeof(T).alignment()](from, to);
}

export let compeval pointer_offset[T](from : T*, amount : uint64_t) = {
    return aligned_offset[typeof(T).alignment()](from, amount);
}