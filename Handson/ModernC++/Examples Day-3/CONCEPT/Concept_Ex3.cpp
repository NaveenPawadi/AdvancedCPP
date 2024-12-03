#include <concepts>
#include <iostream>
/*  inline version */
// void Print(std::integral auto i) 
// {
//     std::cout << "Integral: " << i << '\n';
// }

/*  prefix version */
// template<typename T> requires std::integral<T> void Print(T i)
// {
//     std::cout << "Integral: " << i << '\n';
// }

/*  postfix version */
// template<typename T> void Print(T i) requires std::integral<T>
// {
//     std::cout << "Integral: " << i << '\n';
// }

/*  template inline version */
template<std::integral T> void Print(T i)
{
    std::cout << "Integral: " << i << '\n';
}

void Print(auto x) {
    std::cout << "Non-integral: " << x << '\n';
}
 
int main()
{
    Print('a');
    Print(100);
    Print(45.12);
    //Print("a");
    return 0;
}