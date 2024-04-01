#include <data.h>
#include <stdio.h>

int main()
{
    Variable x = {10};
    Variable y = {5};
    Variable z = {1};
    Variable t1 = _add(&x, &y);
    Variable t2 = _div(&t1, &z);
    Variable t3 = _mul(&t2, &y);
    backward(&t3, 1.0);
    printf("%f\n", x.grad);
    return 0;
}