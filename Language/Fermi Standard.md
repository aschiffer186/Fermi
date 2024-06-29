# Introduction
* This document describes the specification for the Fermi programming language.
# Lexical Analysis
## Identifiers
* Identifiers are used to refer to name entities in Fermi. Valid identifiers are given by the following regular expression:
```
IDENTIFIER: [_a-zA-Z][_a-zA-Z0-9]*
```
Identifiers containing a double underscore "__" are reserved to the Fermi implementation. A program that uses a reserved underscore is ill-formed, no diagnostic required.
## Literals
### Real Literals
* Real literals are string of characters corresponding to floating-point types. Valid decimal literal strings are given by the following regular expression:
```
REAL_LITERAL: [0-9]*\.[0-9]+([+-]?[eE][0-9]+)?
```
Note that it is not possible for a string of characters to be both a real literal and an integer literal.
### Integer Literals
* Integer literals are strings of characters corresponding to integral types. Valid integer literal strings are given by the following regular expression:
```
INTEGER_LITERAL := DECIMAL_LITERAL | BASED_LITERAL 
DECIMAL_LITERAL := [0-9]("'"[0-9]|[0-9])*[eE]+?[0-9]+)?
BASED_LITERAL := [0-9]{1,2}_[0-9a-zA-Z]("'[0-9a-zA-Z]|[0-9a-zA-Z])*_([eE]+?[0-9]+)?
```
## Identifiers
* Identifiers are used to name entities. They are given by the following regular expression. 
```
IDENTIFIER: [_a-zA-Z][0-9a-zA-Z_]*
```
* Identifiers beginning with a double underscore (__) are reserved to the implementation. A program that uses such an identifier is ill-formed, no diagnostic required. 
# Basic Concepts 
## Entities and Objects
* The smallest meaningful semantic unit in Fermi is an _entity_. An entity is an abstract representation of values in Fermi.
* An entity has three components: a type, a value, and an associated object providing the physical representation of the entity.
    * Note: Unless otherwise specified, an implementation is not required to emit any representation of an entity.
* An object is the representation of an object in memory. It consists of a contiguous sequence of 1 or more bytes. 
* Each object is associated with an entity. The _size_ of the object is the number of bytes used to represent the object in memory. The size of the object is determined by the type of the associated entity.
* the bytes of an object can be grouped into two categories: value bytes and padding bytes. Value bytes are the bytes used to represent th value of the entity. Padding bytes are used for implementation details and adhering to alignment requirements.
* All objects have an _alignment requirement_. 
# Types
# Expressions 
## Introduction
* An expression takes zero or more entities as an input and returns a entity as an output. These are referred to as the _input entities_ and _output entities_ respectively. 
* Expressions can be divided into _static expressions_ and _dynamic expressions_.
* A static expression is an expression where the associated object of the output entity of the expression can be determined during translation. 
    * Note: this does not require that the associated object of the output entity be calculated during translation. 
* A dynamic expression is an expression where the associated object of the output entity cannot be calculated until execution.
* Expression can also be divided into _pure_ and non-pure expressions.
## Pure Expressions
* A pure expression is an expression that meets the following requirements.
    1. The expression does not have any observable side effects. 
    2. The expression does not modify any of its input entities. 
    3. Given two sets of input entities, if the sets of input entities are identical then the output entities produced by the expression with each set of input entities are identical.
* For a pure expression, it is legal for an implementation to calculate the output entity once and replace subsequent occurrences of the expression with that output entity. It is implementation defined if/when this happens.
```js
// Example: 
let y = 3 + pureFunction(1) + pureFunction(3);
let z = pureFunction(1); 
// The code could be written as follows without changing the semantics of the program.
let __z = pureFunction(1);
let y = 3 + __z + pureFunction(3);
let z = __z;
```
* Any expression that does not meet the requirements above is an impure expression.
* The following expressions are always pure.
    1. Evaluating a built-in literal type.
    2. Arithmetic operations performed using built-in types as input entities.
    3. Bitwise operations performed using built-in types as input entities.
    4. Evaluating an identifier.
    5. Logical operations.
    6. Assignment or creation of a built-in type.
    7. A call to `Fermi::abort` or `Fermi::exit`.
    8. A call to a function with the `pure` specifier.
* Any expression not listed above is potentially impure.
* The pureness of a function can be queried with the `pure` operator.
* `pure` is a stronger guarantee than `nothrow`, and it implies `nothrow`.
## Operators
### Binary Operators
### Unary Operators
### Function Like Operators
* The `pure` operator can be used to determine if an expression is a pure expression. It evaluates to `true` if its argument is a pure expression and `false` if its argument is not a pure expression. It may be used in a static expression. It does not evaluate its argument. The `pure` operator is a pure expression i.e. `pure(pure(expression))` evaluates to `true`.
```js
// Examples
let func() pure;
let func2();
pure(1 + 1) // Evaluates to true
pure(func()) // Evaluates to true
pure(func2()) // Evaluates to false
pure(func2) // Evaluates to true
pure(pure(func2())) // Evaluates to true
```
# Appendix A 
This appendix provides a complete overview of the grammar of the Fermi language in approximately EBNF notation
```
INTEGER_LITERAL := DECIMAL_LITERAL | BASED_LITERAL 
DECIMAL_LITERAL := [0-9]("'"[0-9]|[0-9])*[eE]+?[0-9]+)?
BASED_LITERAL := [0-9]{1,2}_[0-9a-zA-Z]("'[0-9a-zA-Z]|[0-9a-zA-Z])*_([eE]+?[0-9]+)?
REAL_LITERAL := [0-9]*/.[0-9]+([eE][+-]?[0-9]+)?
IDENTIFIER := [a-zA-Z_][0-9a-zA-Z_]*

fermi-program := {statement}
statement := declaration-statement | expression-statement 
declaration-statement := 
    struct-declaration | 
    variable-declaration | 
    type-label-declaration |
    type-declaration |
    function-declaration | 
    typeset-declaration | 
    impl-block-declaration
expression-statement := expression ";"

struct-declaration := "let "struct" IDENTIFIER [template-declaration] ";"
struct-definition := "let" "struct" IDENTIFIER [template-declaration] "{" {struct-element } "}"
struct-element := variable-declaration | function-interface | type-label-definition | type-declaration
impl-block-declaration := IDENTIFIER [template-args-list] "=" "{" {impl-block-element} "}"
impl-block-element := member-variable-definition | member-function-definition 
member-variable-definition := IDENTIFIER "=" expression ";"
member-function-definition := 
    IDENTIFIER "(" [function-parameter-list] ")" "=" compound-statement |
    "operator" operator "(" [function-parameter-list] ")" "=" compound-statement

expression := primary-expression
primary-expression := INTEGER_LITERAL | DECIMAL_LITERAL | IDENTIFIER | "(" expression ")"
```
