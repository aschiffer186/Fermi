# Introduction
* A type is named category of entities and the operations that may be performed on those values. 
* All types have the following operations defined for them:
    * The _identity function_: maps a type to itself; takes in a entity and returns the same entity unchanged
    * The _size function_: maps a type to an `int64_t`: takes in an entity and returns the number of bytes required for its associated object.
        * This function returns the same value for all entities of a particular type. 
    * The _address function_: maps a type to a ??: takes in an entity and returns the address of its associated object. 
* There is a special type called the _void_ set that contains no values. 
* A type may have one or more labels that provide alternative names for the type. These labels do not create distinct types. 
* There are 1 categories of types:
    * Arithmetic Types 
# Arithmetic Types
* Arithmetic types provide representations of the real number system and its subsets.
* There are two types of arithmetic types: integer-types and floating-point types. 
## Integer Types
* Integer types represent signed-integer types.
    * The associated objects of entities of signed-integer types are represented using the twos-complement representation.
* There are four integer types: `int8_t`, `int16_t`, `int32_t`, `int64_t`
    * `int8_t` is a signed 8-bit, 1-byte integer type.
        * The range of this type is -128 to 127
    * `int16_t` is a signed 16-bit, 2-byte integer type.
        * The range of this type is -32,768 to 32,767
    * `int32_t` is a signed 32-bit, 4-byte integer type.
        * The range of this type is -2,147,483,648 to 2,147,483,647
    * `int64_t` is a signed 64-bit, 8-byte integer type.
        * The range of this type is -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
## Floating Point Types
* Floating-points are approximations of real-numbers.
* There are two floating-point types: `float32_t` and `float64_`
    * `float32_t` is a 32-bit IEEE-754 floating-point type
        * The range of exponents supported by the type is -126 to 127
        * The significant has 24-bits of precision
    * `float64_t` is a 64-bit IEEE-754 floating-point type
        * The range of exponents is -1022 to 1023
        * The significant has 53-bits of precision
* All floating-point types additionally have 4 specialize values
    1. Quiet NaN (qNaN)
    2. Signaling Nan (sNaN)
    3. ∞
    4. -∞
## Arithmetic Type Promotion
* The arithmetic type promotion rules determine how arithmetic types can be implicitly converted. 
* An entity of a smaller integral type can be implicitly converted to an entity of an equal or larger integral type.
* An entity of type `float32_t` can be implicitly converted to an entity of type `float64_t`.
* An entity of type `int8_t`, `int16_t`, or `int32_t` can be implicitly converted to an entity of type `float64_t`.
* An entity of any integral type can be converted to an entity of a `float64_t`.
* The _common type_ of two integer types is the larger of the two types.
* The _common type_ of two floating-point types is the larger of the two types.
* The _common type_ of an integer type and a floating-point type is the largest floating-point type that can contain the maximum value of both types.
    * This may result in implicit promotion of the floating-point types.