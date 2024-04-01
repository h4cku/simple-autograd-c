#include <data.h>
#include <stdlib.h>
void backward(Variable *v, double loss)
{
    if (v)
    {
        if (v->backward_fn)
        {
            v->backward_fn(v->record, loss);
        }
        else
        {
            v->grad += loss;
        }
    }
}

void add_backward_fn(Variable **record, double loss)
{
    backward(record[0], loss);
    backward(record[1], loss);
}

void sub_backward_fn(Variable **record, double loss)
{
    backward(record[0], loss);
    backward(record[1], -1 * loss);
}

void mul_backward_fn(Variable **record, double loss)
{
    backward(record[0], record[1]->val * loss);
    backward(record[1], record[0]->val * loss);
}

void div_backward_fn(Variable **record, double loss)
{
    backward(record[0], loss / record[1]->val);
    backward(record[1], -record[0]->val * loss / (record[1]->val * record[1]->val));
}

Variable _add(Variable *x, Variable *y)
{
    Variable **record = (Variable **)malloc(sizeof(Variable *) * 2);
    record[0] = x;
    record[1] = y;
    Variable res = {x->val + y->val, 0.0, record, add_backward_fn};
    return res;
}

Variable _sub(Variable *x, Variable *y)
{
    Variable **record = (Variable **)malloc(sizeof(Variable *) * 2);
    record[0] = x;
    record[1] = y;
    Variable res = {x->val - y->val, 0.0, record, sub_backward_fn};
    return res;
}

Variable _mul(Variable *x, Variable *y)
{
    Variable **record = (Variable **)malloc(sizeof(Variable *) * 2);
    record[0] = x;
    record[1] = y;
    Variable res = {x->val * y->val, 0.0, record, mul_backward_fn};
    return res;
}

Variable _div(Variable *x, Variable *y)
{
    Variable **record = (Variable **)malloc(sizeof(Variable *) * 2);
    record[0] = x;
    record[1] = y;
    Variable res = {x->val / y->val, 0.0, record, div_backward_fn};
    return res;
}
