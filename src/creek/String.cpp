#include <creek/String.hpp>

#include <creek/Expression_DataTypes.hpp>
#include <creek/GlobalScope.hpp>
#include <creek/utility.hpp>


namespace creek
{
    String::String(Value value) : m_value(value)
    {

    }

    const String::Value& String::value() const
    {
        return m_value;
    }

    String::Value& String::value()
    {
        return m_value;
    }

    Data* String::copy() const
    {
        return new String(m_value);
    }

    std::string String::class_name() const
    {
        return "String";
    }

    std::string String::debug_text() const
    {
        return std::string("\"") + escape_string(m_value) + std::string("\"");
    }

    Expression* String::to_expression() const
    {
        return new ExprString(m_value);
    }


    bool String::bool_value() const
    {
        return true;
    }

    char String::char_value() const
    {
        return m_value.size() == 0 ? '\0' : m_value.front();
    }

    const std::string& String::string_value() const
    {
        return m_value;
    }

    // void String::string_value(const std::string& new_value)
    // {
        // m_value = new_value;
    // }

    Data* String::index(Data* key)
    {
        Value value = this->string_value();

        int pos = key->int_value();
        if (pos < 0)
        {
            pos = value.size() + pos;
        }

        return new String(value.substr(pos, 1));
    }

    Data* String::index(Data* key, Data* new_data)
    {
        int pos = key->int_value();
        if (pos < 0)
        {
            pos = m_value.size() + pos;
        }
        m_value[pos] = new_data->int_value();

        return new_data;
    }

    Data* String::add(Data* other)
    {
        return new String(this->string_value() + other->string_value());
    }

    // Data* String::sub(Data* other)
    // {
    //     return new String(this->double_value() - other->double_value());
    // }

    Data* String::mul(Data* other)
    {
        Value old_value = this->string_value();
        size_t new_size = old_value.size() * other->double_value();
        Value new_value(new_size, ' ');

        for (size_t i = 0; i < new_value.size(); ++i)
        {
            new_value[i] = old_value[i % old_value.size()];
        }

        return new String(new_value);
    }

    // Data* String::div(Data* other)
    // {
    //     return new String(this->double_value() / other->double_value());
    // }

    // Data* String::mod(Data* other)
    // {
    //     int this_int = this->double_value();
    //     int other_int = other->double_value();
    //     return new String(this_int % other_int);
    // }

    // Data* String::exp(Data* other)
    // {
    //     return new String(std::pow(this->double_value(), other->double_value()));
    // }

    // Data* String::min()
    // {
    //     return new String(-this->double_value());
    // }

    // Data* String::bit_and(Data* other)
    // {
    //     int this_int = this->double_value();
    //     int other_int = other->double_value();
    //     return new String(this_int & other_int);
    // }

    // Data* String::bit_or(Data* other)
    // {
    //     int this_int = this->double_value();
    //     int other_int = other->double_value();
    //     return new String(this_int | other_int);
    // }

    // Data* String::bit_xor(Data* other)
    // {
    //     int this_int = this->double_value();
    //     int other_int = other->double_value();
    //     return new String(this_int ^ other_int);
    // }

    // Data* String::bit_not()
    // {
    //     int this_int = this->double_value();
    //     return new String(~this_int);
    // }

    int String::cmp(Data* other)
    {
        return this->string_value().compare(other->string_value());
    }

    Data* String::get_class() const
    {
        return GlobalScope::class_String->copy();
    }
}
