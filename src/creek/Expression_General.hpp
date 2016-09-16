#pragma once

#include <creek/Expression.hpp>

#include <memory>
#include <vector>

#include <creek/api_mode.hpp>


namespace creek
{
    /// @defgroup   expression_general  General expressions.
    /// @{

    /// Expression: Call a function.
    /// Returns value returned by the function.
    class CREEK_API ExprCall : public Expression
    {
    public:
        /// `ExprCall` constructor.
        /// @param  function    Function expression.
        /// @param  args        Arguments to pass to the function.
        ExprCall(Expression* function, const std::vector<Expression*>& args);

        Variable eval(Scope& scope) override;

    private:
        std::unique_ptr<Expression> m_function;
        std::vector< std::unique_ptr<Expression> > m_args;
    };


    /// Expression: Call a function with a variadic argument.
    /// Returns value returned by the function.
    class CREEK_API ExprVariadicCall : public Expression
    {
    public:
        /// `ExprVariadicCall` constructor.
        /// @param  function    Function expression.
        /// @param  args        Arguments to pass to the function.
        /// @param  vararg      Argument to expand before calling.
        ExprVariadicCall(Expression* function, const std::vector<Expression*>& args, Expression* vararg);

        Variable eval(Scope& scope) override;

    private:
        std::unique_ptr<Expression> m_function;
        std::vector< std::unique_ptr<Expression> > m_args;
        std::unique_ptr<Expression> m_vararg;
    };


    /// Expression: Get array subscript.
    /// Returns value of the array at the index.
    class CREEK_API ExprIndexGet : public Expression
    {
    public:
        /// `ExprIndexGet` constructor.
        /// @param  array   Expression for the array object.
        /// @param  index   Expression for the index.
        ExprIndexGet(Expression* array, Expression* index);

        Variable eval(Scope& scope) override;

    private:
        std::unique_ptr<Expression> m_array;
        std::unique_ptr<Expression> m_index;
    };


    /// Expression: Set array subscript.
    /// Returns new value of the array at the index.
    class CREEK_API ExprIndexSet : public Expression
    {
    public:
        /// `ExprIndexSet` constructor.
        /// @param  array       Expression for the array object.
        /// @param  index       Expression for the index.
        /// @param  value       Expression for the new value.
        ExprIndexSet(Expression* array, Expression* index, Expression* value);

        Variable eval(Scope& scope) override;

    private:
        std::unique_ptr<Expression> m_array;
        std::unique_ptr<Expression> m_index;
        std::unique_ptr<Expression> m_value;
    };

    /// @}
}