# Introduction
* This document describes the Fermi programming language.
## Definitions
* Some operations in this specification are defined using the following terms
* _Requirements_: Conditions that must hold true or else the program is ill-formed.
* _Preconditions_: Conditions that must hold true of the postconditions are not guaranteed and the compiler may not be able to enforce.
* _Postconditions_: Guarantees about the behavior of a function or piece of Fermi code. Used to define the observable behavior of Fermi.
* _Purity_: Specification if the code is unconditionally pure, conditionally pure, or unconditionally impure. 
# Basic Concepts 
## Entities and Objects
* An entity is the basic structure of semantic meaning in Fermi.
* An entity is an exposition-only construct used to define the semantic of a Fermi program. Implementations are not required to allocate memory or perform runtime operations on entities except where noted in the standard. 
    * All runtime effects are observed by the entity's associated object (see below).
* An _entity_ has a value, a type, and an associated object. 
* The value of an entity of the following:
    * If the entity is a fundamental type, the value is the byte-representation of the associated object. 
    * If the entity is a type composed of sub-entities, the value of the entity is the union of value of the sub-entities.
    * If the entity is a variant-type, the value of the entity is the value of the currently active sub-entity
* The value of an entity may change over the course of its lifetime but its type is fixed and may not change.
* An _object_ is the in-memory representation of an object. It has an size, determined by the associated entity's type, and an address of where the first byte starts. 
    * An entity's associated object is not necessarily unique; two entities can have the same associated object. 
* The byte-representation of an object is the contiguous stretch of bytes starting at the address of the object and continue for the size of the object bytes.
    * Not all bytes in an object's representation contribute to its associated entity's value. 
## Variables 
* A _variable_ is a label with an associated entity. 
* The label of the variable is called the _identifier_ of variable. 
* All variables have a type; the type of the variable is the type of the associated entity. 
* The entity associated with a variable may not change over the course of its lifetime. 
## Lifetimes 
* Entities, objects, and variables have lifetimes. 
* The _lifetime_ of a variable or entity is the portion of a Fermi program in which the variable or entity can be used. The _lifetime_ of an object is the portion of a Fermi program during which memory is allocated for the object.
* The lifetime of a variable starts at its declarations and continues to the end of the scope it is declared in.
* If an entity is associated with a variable, its lifetime is the same as its associated variable. 
* If an entity is not associated with a variable, the lifetime of the entity depends on the manner of its allocation. 
* In all instances, the lifetime of an entity begins at its allocation. 
    * If an entity has _automatic lifetime_, the entity ends at the end of its expression 
    * If an entity has _dynamic lifetime_, the entity ends when a de-allocation function is called for it (TODO: improve this)
* The lifetime of an object begins when its associated entity is allocated and ends when its last associated entity's lifetime ends.
# Types
* A type is defined by a set of entities and the operations that may be performed on the entities. 
* The _size_ of a type is the number of bytes required to store the associated object of entities in the set defined by that type. This consists of the _value size_ of the type, which is the number of bytes required to store the value of the entity plus the number of bytes required for padding the element. 
## Common Operations 
* All types have the following operations defined on them 
## Sizeof Operator
* The _sizeof_ operator maps an entity to an int64_t that represents the number of bytes the required by the associated object of that entity
## Type Operator
* The _type_ operator maps an entity to a _type_ type representing the type of the entity 
## Address of Operator
* The _addressof_ operator maps an entity to an implementation-defined integer type that represents the address of the first byte of the associated object of that entity.
## Built-in Types
* Fermi contains the following classes of predefined types:
    * Integer Types
    * Rational Types
    * Floating-Point Types
    * Complex-Types
    * Bool Types
    * Character Types
    * Void type 
* Each of these classes corresponds to a predefined _typeset_ (see section N)
### Void Type
* The _void_ type is the unique type that is the empty set. 
    * It is not possible to construct an entity whose type is `void`
* `sizeof(void)` is defined to be 0. 
### Integer Types
* Integer types represent mathematical integers.
* The associated objects of integers represent integers using twos-complement.
* There are four predefined integer types: `int8_t`, `int16_t`, `int32_t`, and `int64_t`
* All integers have ranges defined by the constants INTXT_MIN and INTXT_MAX. Each integral type is capable of representing all values between INTXT_MIN and INTXT_MAX inclusive.
    * `int8_t` is a signed 1-byte integer 
        * INT8T_MIN = -2^7
        * INT8T_MAX = 2^7 - 1
        * `sizeof(int8_t) == 1`
    * `int16_t` is a signed 2-byte integer
        * INT16T_MIN = -2^15
        * INT16T_MAX = 2^15 - 1
        * `sizeof(int16_t) == 2`
    * `int32_t` is a signed 4-byte integer
        * INT32T_MIN = -2^31
        * INT32T_MAX = 2^31 - 1
        * `sizeof(int32_t) == 4`
    * `int64_t` is a signed 8-byte integer 
        * INT64T_MIN = -2^63
        * INT64T_MAX = 2^63 - 1
        * `sizeof(int64_t) == 4`
### Rational Types
* Rational types represent mathematical rational numbers. 
* Rational types are struct-templates whose
# Expressions 
## Introduction 
```
expression := identity-expression 
            | creation-expression 
            | transformation-expression 
```
* An _expression_ has an input of one or more entities and produces as its output an entity. 
* The inputs to an expression are called its _input entities_.
* The output of an expression is called its _output entity_.
* The value of an expression is the value of its output entity; the type of an expression is the type of its output entity.
    * Note: the type of an expression is always known statically.
* There are three types of expressions in Fermi: identity-expressions, creation-expression, and transformation-expressions.
* An _identity-expression_ returns an entity returns an expression unchanged; that is, the output entity of the expression is the same as its input expression. 
* A _creation-expression_ creates a new entity from the value of its input entities; the output entity of the expression is the created entity.
* A _transformation-expression_ transforms one or more of its input entities; however, it may also create a new entity. Its output entity may be one of its input entities or a new entity. 
* Orthogonal to the division of identity/creation/transformation expression is the distinction of static-expression and dynamic-expression. 
* A _static-expression_ is an expression whose type is eligible to be evaluated at compile-time.
* A _dynamic-expression_ is an expression whose type is not eligible to be evaluated at compile-time. 
    * Note: under the Fermi as-if rule, an implementation may evaluate a dynamic-expression at compile-time if the value happens to be known.
## Identity Expressions 
```
identity-expression := LITERAL 
                     | IDENTIFIER 
                     | ( expression )
```
* There are two types of expressions: literal expressions and identifier expressions. 
### Literal Expressions 
### Identifier Expressions 
* An identifier expression returns the associated entity of the variable whose label is the identifier 
* The input entity to the expression is the associated entity of the variable whose label is the identifier
* _Requirements_: The identifier is the label of a variable that has been declared
* _Preconditions_: The variable has been initialized 
* _Postconditions_: The output entity is the same entity as the associated entity of the variable whose label is the identifier.
## Creation Expressions 
```
creation-expression := binary-expression-expression
                     | unary-creation-expression
```
### Binary-Creation-Expression 
* A _binary-creation-expression_ is a creation-expression that has two input entities.
```
binary-creation-expression := 
      expression "+" expression 
    | expression "-" expression 
    | expression "*" expression
```
#### Binary Addition
* Binary addition represents the arithmetic addition of two entities. 
* The built-in addition operator is defined for integral, rational, floating-point, and complex types.
##### Binary Signed-Integer Addition
* Binary signed addition performs the addition of two signed-integers. 
* The type of the output entity is the common-type of the two input entities. 
    * Prior to the addition, the two input entities are promoted to their common type if necessary.
* _Preconditions_: The sum of the two input entities is within the range of their common type
* _Postconditions_ Let a, b, and c be signed integers
    1. a + b == the exact sum of the values of the input entities if no overflow occurs
    2. a + b == b + a (integer addition is commutative)
    3. a + (b + c) == (a + b) + c (integer addition is associative)
    4. a + b only overflows if the sum is not representable by the *common type* of a and b.
        * For example, if a is an `int8_t` with a value of 254 and b is a `int32_t` with a value of 65,556, no overflow should occur.
    5. a + 0 == a
* _Purity_: This expression is unconditionally pure 
##### Binary Rational Addition 
* Binary rational addition performs the addition of two rational types or a rational type and an integer-type.
* The type of the output entity is 
    * If both input entities are rational types, let T1 and T2 be the types of the input entities. The type of the output entity is 
    ```
    rational<common-type<T1::ScalarType, T2::ScalarType>>
    ```
    * If one input entity is an integer type and one input entity is a rational type, let T1 be the integer type and T2 be the rational type. The type of the output entity is 
    ```
    rational<common-type<T1, T2::ScalarType>>
    ```
* Prior to the addition, both input entities are promoted to the type of the output entity if necessary. 
* _Preconditions_: The sum of the two input entities is in the set of values expressible by the type of the output entity 
* _Postconditions_: Let r1, r2, and r3 be rational types and a be a signed integer 
    1. r1 + r2 == the exact sum of the values of the input entities if no overflow occurs 
    2. r1 + a == the exact sum of the values of the input entities if no overflow occurs 
    3. r1 + r2 == r2 + r1 
    4. r1 + a == a + r1
    5. r1 + (r2 + r3) == (r1 + r2) + r3
    6. r1 + (a + r2) == (r1 + a) + r2
    7. r1 + r2 only overflows if the sum is not representable by the type of the output entity 
    8. r1 + a only overflows if the sum is not representable by the type of the output entity 
    9. r1 + 0 == r1
* _Purity_: This expression is unconditionally pure