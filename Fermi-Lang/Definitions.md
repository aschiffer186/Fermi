# Fundamentals
* Entity: an entity is the smallest semantic unit of Fermi; it has a type, a value, and an associated object 
    * The value of an entity is either
        1. If the type of an entity is a fundamental type, the in memory representation of the associated object
* Object: an object has an address, a size, and an in-memory representation
* Variable: a variable is a strongly-typed identifier that has an associated entity
* Type: an type has a name, a set of valid operations, and a size
* Expression: an expression takes as an input one or more entities and returns one entity. The type of expression is the type of the returned entity and the value of the expression is the value of the returned entity.
# Basic Types
## Arithmetic Types
### Integer Types
* Fermi defines five signed integer types 
    * `int8_t`: a one byte (8-bit) signed integer type whose range is -2^7 to 2^7 - 1
    * `int16_t`: a two byte (16-bit) signed integer type whose range is -2^15 to 2^15 - 1
    * `int32_t`: a four byte (32-bit) signed integer type whose range is -2^31 to 2^31 - 1
    * `int64_t`: an eight bye (64-bit) signed integer type whose range is -2^63 to 2^63 - 1
    * `int128_t`: a sixteen byte (128-bit) signed integer type whose range is -2^127 to 2^127 - 1 (maybe???)
### Floating-Point Types
* Fermi defines two floating-point types
    * `float32_t`: an IEEE-754 32-bit floating-point type
    * `float64_t`: an IEEE-754 64-bit floating-point type
### Type Promotion Rules
* The arithmetic type promotion rules describe the legality of implicit conversions between fundamental arithmetic types as well as the type deduction guidelines for expressions involving arithmetic types. 
* A fundamental arithmetic type `T1` is said to be _implicitly convertible_ to or _promotable_ to another fundamental arithmetic type `T2` if one of the following is true:
    1. `T1` and `T2` are exactly the same type.
    2. `T1` ane `T2` are both signed integral types and the size of `T2` is larger than the size of `T1`.
    3. `T1` and `T2` are both floating-point types and the size of `T2` is larger than the size of `T1`.
    4. `T1` is a signed integral type and `T2` is a floating-point type whose size is at least as large as the size of `T1`. 
* A Fermi program that attempts to implicitly convert an arithmetic type to a type it is not implicitly convertible to is ill-formed.
* Given the binary expressions "+", "-", "*", and "^", where the types of in the input entities are both fundamental arithmetic types, the type of the output entity will be determined as follows. Let `T1` be the type of the first input entity and `T2` be the type of the second input entity; the type `TO` of the output entity will be 
    1. `T1` if `T1` and `T2` are exactly the same type. 
    2. If `T1` and `T2` are both signed integer types, `TO` will be the the larger of the two types. 
    3. If `T1` and `T2` are both floating-point types, `TO` will be the larger of thw two types. 
    4. If one of `T1` and `T2` is a floating-point type and the other is a signed-integer type and the floating-point type is at least as big as the signed-integer type; `T0` will be the floating-point type.
    5. Otherwise the program is ill-formed.
# Expression
* An expression takes as an input one or more not necessarily distinct entities and returns an entity.
* Each expression has a value and a type; the value of an expression is the value of the returned entity; the type of an expression is the type of the returned expression. 
* There are two types of expressions: identity expressions and creational expressions.
## Identity Expressions
* An identity takes as an input an entity and returns that entity unchanged. 
* There are two types of identity expressions: literals and identifiers (when used in the context of an expression).
### Identifier
* The input to an identifier expression is the entity associated with the variable named by the identifier and the same identity is returned. 
### Literal
* The input to a literal expression is the entity whose value is given by the value of the literal and whose type is the type of the literal; the same literal is returned.
## Creational Expressions
* A creational expression takes as an input one or more entities and returns an entity. 
* A creational expression does not modify its input entity
### Binary Expressions
* Binary creational expressions take in two entities and return an entity
#### Binary Addition
* The binary addition expression takes the canonical form `E1 + E2` where `E1` and `E2` are the input entities to the expression. 
* If both inputs are signed integer types, the value of the created entity is the signed addition of the two input entities.
    * If one type is larger than the other, the smaller type will be promoted to the larger type prior to the addition.
* If either or both inputs are floating-point types, the value of the created entity is the floating-point addition of the two input entities.
    * If one entity is a signed-integer type, it will be converted to a floating-point type prior to the addition.
* The type of the created entity is the type defined by the arithmetic type promotion rules.
#### Binary Subtraction
* The binary subtraction expression takes the canonical form `E1 - E2` where `E1` and `E2` are the input entities to the expression. 
* If both inputs are signed integer types, the value of the created entity is the signed subtraction of the two input entities.
    * If one type is larger than the other, the smaller type will be promoted to the larger type prior to the addition.
* If either or both inputs are floating-point types, the value of the created entity is the floating-point subtraction of the two input entities.
    * If one entity is a signed-integer type, it will be converted to a floating-point type prior to the subtraction.
* The type of the created entity is the type defined by the arithmetic type promotion rules.
#### Binary Multiplication
* The binary multiplication expression takes the canonical form `E1 + E2` where `E1` and `E2` are the input entities to the expression.
* If both inputs are signed integer types, the value of the created entity is the signed multiplication of the two input entities. 
* If either or both inputs are floating-point types, the value of the created entity is the floating-point addition of the two input entities
    * If one entity is a signed-integer type, it will be converted to a floating-point type prior to the multiplication.
* The type of the created entity is teh type defined by the arithmetic type promotion rules. 
#### Binary Floating-Point Division
* The binary floating-point division expression takes the canonical form `E1 / E2` where `E1` and `E2` are the input entities to the expression.
* Regardless of the types of the input entities, floating-point division is performed. 
* Any signed-integer type is converted to a floating-point type prior to the division
* The type of the created entity is `float64_t`. 
#### Binary Integer Division 
* The binary integer division expression takes the canonical form `E1 // E2` where `E1` and `E2` are the input entities to the expression 
* Regardless of the type of the input entities, integer division is performed. 
    * Integer division produces a result equivalent to the following procedure:
        1. The operands are divided using floating-point division
        2. Any decimal part in the division is discarded
* The type of the created entity is a signed-integer type that is the same size as the larger type of the two inputs.
#### Binary Exponentiation
* The binary exponentiation expressions takes the canonical form `E1 ^ E2` where `E1` and `E2` are the input entities to the expression
* If the type of both input entities are signed-integer types then exponentiation is performed as if by the following:
    * If the type of one input entity is smaller than the other