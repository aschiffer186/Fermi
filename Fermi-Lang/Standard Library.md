# Introduction 
* This document describes the Fermi standard library.
* The Fermi library is contained entirely in the Fermi module. 
* The Fermi module is split into several sub-modules
    1. Fermi::Core
    2. Fermi::Ranges
    3. Fermi::Algorithms
# Fermi::Core 
* The Fermi core sub-module contains fundamental constants, functions, types, and typesets that all Fermi programs are based on. 
* The Fermi::Core sub-module is implicitly imported by every program and all symbols from the module are imported.
* Implementations may split the Fermi::Core submodule into further submodules as long as all symbols may be imported as above.
## Fermi::Core::Math
* The Fermi::Core::Math submodule contains basic math useful to most Fermi programs. It consists of four parts: constants, fundamental data types, typsets and functions
### Constants
* The Fermi standard library defines the exact value, to the greatest precision possible, of the following fundamental constants.
```
module Fermi::Core::Math;

namespace Std 
{
    # pi
    export let compeval F_PI_V : template<T : type> = T{3.141592653589793};
    # pi/2 
    export let compeval F_PI_2_V : template<T : type> = T{1.570796326794897};
    # pi/4 
    export let compeval F_PI_4_V : template<T : type> = T{0.7853981633974483};
    # pi/6
    export let compeval F_PI_6_V : template<T : type> = T{0.5235987755982989};
    # 2*pi 
    export let compeval F_2PI_V : template<T : type> = T{6.283185307179586};
    # 1/pi 
    export let compeval F_1_PI_V : template<T : type> = T{0.3183098861837907};
    # 2/pi 
    export let compeval F_2_PI_V : template<T : type> = T{0.6366197723675813};
    # sqrt(2)
    export let compeval F_SQRT2_V : template<T : type> = T{1.414213562373095};
    # sqrt(3)
    export let compeval F_SQRT3_V : template<T : type> = T{1.732050807568877};
    # sqrt(5)
    export let compeval F_SQRT5_V : template<T : type> = T{2.236067977499790};
    # sqrt(2)/2
    export let compeval F_SQRT2_2_V : template<T : type> = T{0.7071067811865475};
    # sqrt(3)/2
    export let compeval F_SQRT3_2_V : template<T : type> = T{0.8660254037844386};
    # sqrt(pi)
    export let compeval F_SQRTPI_V : template<T : type> = T{1.772453850905516};
    # sqrt(2*pi)
    export let compeval F_SQRT2PI_V : template<T : type> = T{2.506628274631001};
    # e
    export let compeval F_E_V : template<T : type> = T{2.718281828459045};
    # 1/e
    export let compeval F_1_E_V : template<T : type> = T{0.3678794411714423};
    # ln(2)
    export let compeval f_ln2_v : template<T : type> = T{0.6931471805599453};
    # ln(1/2)
    export let compeval f_ln1_2_v : template<T : type> = T{-0.6931471805599453};
    # log2(e)
    export let compeval f_log2e_v : template<T : type> = T{1.442695040888963};
    # log2(10)
    export let compeval f_log210_v : template<T : type> = T{3.321928094887362};
    # Golden ratio
    export let compeval f_phi_v : template<T : type> T{1.618033988749895};

    # Instantiations 
    export let f_pi = f_pi_v<float64_t>;
    export let f_pi_2 = f_pi_2_v<float64_t>;
    export let f_pi_3 = f_pi_3_v<float64_t>;
    export let f_pi_4 = f_pi_4_v<float64_t>;
    export let f_pi_6 = f_pi_6_v<float64_t>;
    export let f_1_pi = f_1_pi_v<float64_t>;
    export let f_2_pi = f_2_pi_v<float64_t>;
    export let f_sqrt2 = f_sqrt2_v<float64_t>;
}
```