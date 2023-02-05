# Fundamental Arithmetic Type
* int8_t: signed byte; range: -2^7 - +2^7 - 1
* int16_t: signed word; range: -2^15 - +2^15 - 1
* int32_t: signed double word; range: -2^31 - +2^31 - 1
* int64_t: signed quadword; range: -2^64 - +2^64 - 1
* float32_t: IEEE 754 32-bit floating point type 
* float64_t: IEEE 754 64-bit floating type

# Fundamental Operations:
* Addition, + operator 
* Subtraction, - operator 
* Multiplication, * operator 
* Division, / operator (performs floating point division)
* Exponentiation, ^ operator 
* Modulo/Remainder, % operator 
* Identity: literal/identifier

# Type conversion
* Implicit conversion from smaller integral type to larger integral type and smaller floating point type to larger 
* Implicit conversion from integral type to larger float type 
* The type of an arithmetic operator is the smallest type that can hold the results

# Variable declaration 
let identifier : type-opt = expression ;

# Print statement 
print(expression, expression, ..., expression) ;

