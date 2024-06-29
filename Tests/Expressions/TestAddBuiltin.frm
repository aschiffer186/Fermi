# Unsigned integer addition
Fermi::println(1 + 2); # Expect 3
Fermi::println((1 + 2) + 3); # Expect 6
Fermi::println(1 + (2 + 3)); # Expect 6
Fermi::println(1 + 3'000'000'000_u64); # Expect 3_000_000_001 (32-bit integer promoted to 64-bit integer)
Fermi::println(3'000'000'000_u64 + 1); # Expect 3_000_000_001 (32-bit integer promoted to 64-bit integer)

# Signed integer addition
Fermi::println(-2 + -2) # Expect -4
Fermi::println(-2 + 1) # Expect -1 (Mixing signed and unsigned integers)

# Rational type addition
Fermi::println(3/2 + 1/4) # Expect 7/4
Fermi::println(-3/2 + 1/4) # Expect -5/4
Fermi::println(2/2 + 3) # Expect 5/1 (Integer type promoted to rational type)
Fermi::println(3 + 2/2) # Expect 5/1 (Integer type promoted to rational type)


# Floating point addition
Fermi::println(1.5 + 2); # Expect 3.5 (Integral type promoted to floating-point type)
Fermi::println(2 + 1.5); # Expect 3.5 (Integral type promoted to floating-point type)
Fermi::println(1.5 + 3/2); # Expect 3.0 (Rational type promoted to floating-point type)
Fermi::println(3/2 + 1.5); # Expect 3.0 (Rational type promoted to floating-point type)

# Complex addition
Fermi::println(1i + 2 + 3i); # Expect 2.0 + 4.0i (Components of complex numbers are always floating-point types)

# Test overflow
Fermi::println(1 + Fermi::Traits<uint32_t>::max());
Fermi::println(1 + Fermi::Traits<int32_t>::max()); 
Fermi::println(1.0 + Fermi::Traits<float64_t>::max());
