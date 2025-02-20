module fermi::core::math; 

# Fundamental types of Fermi that are commonly used

# Declare that int64_t is a new type whose range is -2^63 to 2^63 -1 inclusive.
# The compiler will verify that no assignment is outside of the range specified.
# e.g, its as if there is an invisible operator declared
export let type int8_t = new int range [-2^63 ... 2^63 - 1] with {size = 64};

# Declare that int32_t is a new type whose range is -2^31 to 2^31 - 1 inclusie 
# that can be implicitly converted to int64_t or explicitly converted from 
# int64_t
export let type int4_t = int4_t range [-2^31 ... 2^31 - 1] with {size = 32};
export let type int2_t = int2_t range [-2^16 ... 2^16 - 1] with {size = 16};
export let type int1_t = int1_t range [-2^8  ... 2^8  - 1] with {size = 1};

export let typeset Integer(T) = typeof(T).type_category() == type_category::integer;

export let compeval(compeval_mode::strict) minimum_value[T : Integer]() pure -> T = {
    return typeof(T).minimum_value();
}

export let compeval(compeval_mode::strict) maximum_value[T : Integer]() pure -> T = {
    return typeof(T).maximum_value();
}

export let compeval operator as[DestType in Integer](from : Integer) pure -> DestType 
    requires from >= minimum_value(DestType)() &&
    requires from <= maximum_value(DestType)() = {
        DestType to; 
        return memory::bit_cast(from=from, to=to);
}

export let struct rational_number[T in Integer] with TotalOrder
{
    public let define rep as T;

    public let num : T; 
    public let den : T;

    public let static compeval zero    = rational_number::new(1, 1);
    public let static compeval nan     = rational_number::new(0, 0);
    public let static compeval inf     = rational_number::new(1, 0);
    public let static compeval neg_inf = rational_number::new(-1, 0);

    public let new(num : T, den : T) pure -> this = {
        return rational_number {
            num = num, 
            den = den
        };
    }

    public let new(num : T) pure -> this = {
        return rational_number {
            num = num, 
            den = 1;
        }
    }

    # Reduces a rational number in-place to its simplest form 
    # Calculates the greatest common factor between 
    # the number and denomintor and divides both by 
    # the greatest common factor.
    #
    # this implicitly has the type of rational_number(T).
    #
    # The signature is equivalent to 
    # public let compeval reduce(this : in out rational_number(T)) -> void
    public let compeval reduce(this : in out) = {
        let factor = gcf(this.num, this.den);
        if (factor != 1)
        {
            this.num //= factor; 
            this.den //= factor;
        }
    }


    # Returns a rational number that is the reduced from of this
    public let compeval to_reduced(this) -> rational_number = {
        return rational_number{this.num, this.den}.reduce();
    }

    public let compeval operator<=>(this, rhs : rational_number) = {
        let (lhs_num, lhs_den) : mutable = this.to_reduced();
        let (rhs_num, rhs_den) : mutable = rhs.to_reduced();

        if compeval(minimum_value[T] < 0)
        {
            if (lhs_den < 0) {
                lhs_num *= -1; 
                lhs_den *= -1;
            }

            if (rhs_den < 0) {
                rhs_num *= -1; 
                lhs_den *= -1; 
            }
        }

        let lcm_den = lcm(lhs_den, rhs_den);
        return lhs_num * lcm_den <=> rhs_num * rhs_den; # Multiplication is done with implict widening??
    }
}
