# Integer type range -180 to 180 (inclusive)
let type Integer1 = int[-180, 180];
# Subtype of integer range -90 to 90. Implicilty convertible to Integer1
let type Integer2 = Integer1 as Integer1[-180, 180];