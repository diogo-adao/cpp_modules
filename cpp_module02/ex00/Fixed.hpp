#include <iostream>

class Fixed {
    private:
        int fixed;
        static const int f_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& f);
        Fixed& operator=(const Fixed& f);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};