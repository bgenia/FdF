# FdF

# .fdf file format
Grammar:
```
fdf			::= file
file		::= line+
line		::= point+ '\n'
point		::= height [ ',' color ]
height		::= int
color		::= '0x' uint_hex
int			::= [ '-' ] digit [ digit* ]
uint_hex	::= hex_digit [ hex_digit* ]
digit		::= '0'..'9'
hex_digit	::= '0'..'9' | 'a'..'f' | 'A'..'F'
```
