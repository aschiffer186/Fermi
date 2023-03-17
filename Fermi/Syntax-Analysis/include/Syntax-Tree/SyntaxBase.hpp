#ifndef SYNTAX_BASE_HPP
#define SYNTAX_BASE_HPP

namespace Fermi::SyntaxAnalysis
{
    template<typename Derived>
    class SyntaxNode
    {
    public:
        Derived& self() 
        {
            return static_cast<Derived&>(*this);
        }

        const Derived& self() const 
        {
            return static_cast<const Derived&>(*this);
        }

        
    };
}

#endif