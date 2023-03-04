# Introduction 
* A statement is the smallest unit of executable code. 

# Variable Declaration
```
variable-declaration :=
      "let" IDENTIFIER ":" type
    | "let" IDENTIFIER ":" type "=" expression 
    | "let" IDENTIFIER ":" type "=" expression
```
* A variable declaration introduces a new name and associates an entity with the variable.
* If the type of the variable is given in the variable declaration; the type of the variable and the associated entity is the given type. 
    * If an initializer is provided, the type of the output entity of the expression must be implicitly convertible to the type of the variable.
* If no type is given; the type is deduced from the initializer.
* The lifetime of a variable begins when it is declared and continues until the end of its enclosing scope; however, no memory is allocated for the associated entity's associated object until the first time it is assigned to.
* If an initializer is present, memory is allocated for the the associated entity's associated object and the value of the output entity of the initializer expression is copied into the variable's associated entity.
