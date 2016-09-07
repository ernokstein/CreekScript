#include <creek/Expression_Debug.hpp>

#include <iostream>

#include <creek/Scope.hpp>
#include <creek/Variable.hpp>


namespace creek
{
    // ExprPrint constructor.
    // @param  expression  Expression to get value.
    ExprPrint::ExprPrint(Expression* expression) : m_expression(expression)
    {

    }

    Variable ExprPrint::eval(Scope& scope)
    {
        // Data* data = m_expression->eval(scope);
        // std::cout << data->debug_text() << std::endl;
        // return data;
        Variable v(m_expression->eval(scope));
        std::cout << v->debug_text() << std::endl;
        return v;
    }
}