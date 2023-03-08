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
