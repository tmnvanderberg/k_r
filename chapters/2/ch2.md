# data types
- char
- int
- float
- double
# data type qualifiers
- short <= int <= long
- signed (modulo 2^n)
# arithmatic operators
- no % for float, double
- % sign machine-dependent for negative operands
# conversions for binary operators
- "low to high"
- either long double -> convert to long double
- either double -> convert to double
- either float -> convert to float
- char and short -> int
- either long -> convert to long
# unsigned conversions
- comparison between unsigned types are machine-dependent
- int 16, long 32 -> -1L > 1UL
why? unsigned long is 'bigger'
- every integer type has an integer conversion 'rank'
- signed integer types are ordered by capacity
- i.e.: long long int > long int > int > short int > signed char
- unsigned integer has the same rank as 'corresponding" signed integer type
- char == signed char == unsigned char
- bool has lowerr rank than all other standerd integer types
- enums have rank equal to underlying integer type
- the rank of extended signed integer types relative to another extended signed integer type is implementation-defined
- rank is transitive.

# bit shifting
- left shift <-> mup 2
- vacated bits filled with 0
- example 0101 => 1010
- right shift <-> div 2
- right shifting signed is machine-dependent:
				either 0-bits (logical) or bit signs (arithmatic)
