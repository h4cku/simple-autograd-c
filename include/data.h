typedef struct Variable
{
    double val;
    double grad;
    struct Variable **record;
    void (*backward_fn)(struct Variable **, double);
} Variable;

void backward(Variable *v, double loss);

Variable _add(Variable *x, Variable *y);
Variable _sub(Variable *x, Variable *y);
Variable _mul(Variable *x, Variable *y);
Variable _div(Variable *x, Variable *y);