// npy_util.h (Refactored)

#include <complex.h>    // for standard C99 complex
// #include <numpy/ndarrayobject.h> // if needed to pick up definition of npy_complex128

// Array access macros.
#define SM(x0, x1) (*(npy_complex128*)((PyArray_DATA(submatrix) + \
                    (x0) * PyArray_STRIDES(submatrix)[0] +       \
                    (x1) * PyArray_STRIDES(submatrix)[1])))
#define SM_shape(x0) (int) PyArray_DIM(submatrix, x0)

/**
 * If 'npy_complex128' is indeed defined as '_Complex double', 
 * you can directly use standard C99 expressions for initialization.
 */
static const npy_complex128 complex_one  = 1.0 + 0.0 * I;
static const npy_complex128 complex_zero = 0.0 + 0.0 * I;

//----------------------------------------------------------------------------
// Add two complex numbers
//----------------------------------------------------------------------------
npy_complex128 complex_add(npy_complex128 a, npy_complex128 b)
{
    return a + b;
}

//----------------------------------------------------------------------------
// Product of two complex numbers
//----------------------------------------------------------------------------
npy_complex128 complex_prod(npy_complex128 a, npy_complex128 b)
{
    return a * b;
}

//----------------------------------------------------------------------------
// Product of complex and float
//----------------------------------------------------------------------------
npy_complex128 complex_float_prod(npy_complex128 a, float b)
{
    // Cast b to double to match the precision of npy_complex128 (double).
    return a * (double)b;
}

//----------------------------------------------------------------------------
// Increment a by b
//----------------------------------------------------------------------------
void complex_inc(npy_complex128 *a, npy_complex128 b)
{
    *a += b;
}

//----------------------------------------------------------------------------
// Multiply a by b
//----------------------------------------------------------------------------
void complex_multiply(npy_complex128 *a, npy_complex128 b)
{
    *a *= b;
}