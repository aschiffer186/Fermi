module fermi::core::array; 

export let struct array[T, Sizes : int64_t..., Alignment = typeof(T).alignment()]
{
    # Note, regardless of dimension, arrays are contiguous in memory (stored in row major order)
    # A 1D array: [1, 2, 3, 4] is represented as a pointer to the block {1, 2, 3, 4}
    # and a tuple of sizes (4,)
    #
    # A 2D array: [[1, 2, 3], [4, 5, 6]] is represeted as a pointer to the block {1, 2, 3, 4, 5, 6}
    # and a tuple of sizes (2,3)
    let _data : T mutable*;
    let _sizes : typeof(Sizes);

    let compeval new(data : T mutable*, sizes : typeof(Sizes)) -> this = {
        return array {
            _data = memory::assume_aligned[Alignment](data);
            _sizes = sizes;
        };
    }

    # Helper
    let compeval indices_to_linear(indices : int64_t...) -> int64_t = {
        
    }

    let compeval indices_in_range(indices : int64_t...) --> bool = {

    }

    public let compeval empty(this) -> bool = {
        # Arrays are never empty
        return false;
    }

    public let compeval size(this) -> int64_t = {

    }
}



# Arrays are implemented under the hood as
#
# let x : int[] = {1, 2, 3, 4, 5};
# Re-written as: let x = array(int, 5, typeof(int).alignment())::new(/*address of {1, 2, 3, 4, 5}*/, 5);
#
#
# let x2 : int[][] = {{1, 2, 3}, {4, 5, 6}};
# Re-written as let x2 = array(int, 2, 3)::new(/*address of {{1, 2, 3}, {4, 5, 6}}, 2, 3);
