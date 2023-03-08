# Introduction
* Entities are the smallest unit of semantic meaning in Fermi. 
* An entity has a value, a type, and an associated object.
    * The value of an entity is one of the following:
        * If the entity is a fundamental type; the value si the byte-representation of the associated object.
* An object is an in-memory representation of an object. It has a size, determined by the associated entity's types, and an address where the first byte of the object starts. The object is a contiguous stretch of size of bytes starting at its address.
    * An entity's associated object does not change for the duration of the lifetime of the entity.
* A variable is a label with an associated entity. Once the variable is declared; the associated entity of the variable cannot change. 
    * The label of the variable is called the _identifier_ of the variable. 
    * All variables have a type; the type of the variable is the type of the associated entity. 
* The types of variables are fixed and are known at compile-time.
* Variables and entities both have lifetimes; the lifetime of a variable or entity is the portion of a Fermi program in which the variable or entity can be used. 
* The lifetime of a variable starts at its declaration and continues to the end of the scope it is declared in. 
* If an entity is associated with a variable, the lifetime of the entity is the same as its associated variable. 
* If an entity is not associated with a variable, the lifetime of an entity begins at its allocation and ends at the completion of the top most expression containing the expression triggering its allocation. (TODO: Re-word this).
