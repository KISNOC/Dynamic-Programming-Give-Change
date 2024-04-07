#ifndef COIN
#define COIN

#include <string>

class Coin {
public:
private:
    std::string m_name;
    unsigned int m_value;

    /* Constructor */
    Coin (const std::string& name, unsigned int value)
            : m_name(name),
              m_value(value)
    {}

    /* Copy constructor */
    Coin (const Coin& coin)
            : m_name(coin.m_name),
              m_value(coin.m_value)
    {}

    unsigned int value() const { return m_value; }
    const std::string& name() const { return m_name; }
};
#endif
