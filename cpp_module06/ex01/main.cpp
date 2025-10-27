#include "Serializer.hpp"

int main()
{
    Data data;
    std::cout << "Original value: " << &data << std::endl;
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized value: " << ptr << std::endl;

    return 0;
}