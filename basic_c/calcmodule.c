#include <Python.h>

static PyObject *StringTooShortError = NULL;

static PyObject *method_calc(PyObject *self, PyObject *args) {
    int x, y = 0;
    int a, b = 0;
    int total = 1;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "ii", &x, &y)) {
        return NULL;
    }

    a = x;
    b = y;
    total = a + b;

    return PyLong_FromLong(total);
}

static PyMethodDef CalcMethods[] = {
    {"calc", method_calc, METH_VARARGS, "Calculate two numbers and return its sum"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef calcmodule = {
    PyModuleDef_HEAD_INIT,
    "calc",
    "Module for providing calculation from C",
    -1,
    CalcMethods
};


PyMODINIT_FUNC PyInit_calc(void) {

    /* Assign Module Value */
    return PyModule_Create(&calcmodule);
}

