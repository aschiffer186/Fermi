module Fermi.Containers.Vector;

export let struct Vector(T) 
{
    let private size_ : nat64_t;
    let private data_ : T[];

    let public size(this : in) pure -> nat64_t; 
    let public isEmpty(this : in) pure -> bool;
    let public operator[](this, idx : nat64_t);
}

Vector(T) = {
    size(this : in) = {
        return this.size_;
    }

    isEmpty(this) = {
        return this.size_ == 0;
    }

    operator[](this, idx : nat64_t) = {
        return this.data_[idx][
    }

}