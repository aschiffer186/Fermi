module fermi::core::matrix;

import fermi::memory;

let compeval dynamic_size : int64_t = -1;

let struct matrix_shape[NumRows : int64_t, NumColumns : int64_t]
{

}

let struct matrix_shape[NumRows : int64_t](NumRows, dynamic_size)
{
    let _num_columns : int64_t;
}

let struct matrix_shape[NumColumns : int64_t](dynamic_size, NumColumns)
{
    let _num_rows : int64_t;
}

let struct matrix_shape(dynamic_size, dynamic_size)
{
    let _num_rows    : int64_t; 
    let _num_columns : int64_t;
}

let struct matrix_storage[T, NumRows : int64_t, NumColumns : int64_t, Alloc]
    where Alloc in allocator 
{
    let _data : T mutable[NumRows * NumColumns];
    let _shape : matrix_shape(NumRows, NumColumns);
}

let struct matrix_storage[T, NumRows : int64_t, Alloc](T, NumRows, dynamic_size, Alloc)
{
    let _data : T mutable* mutable;
    let _shape : matrix_shape(NumRows, NumColumns);
}