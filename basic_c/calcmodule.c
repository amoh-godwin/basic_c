#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static PyObject *StringTooShortError = NULL;

static PyObject *method_calc(PyObject *self, PyObject *args) {
    int x, y = 0;
    int a, b = 0;
    const char *s;
    const char *t = "calc";
    char u[4];
    int total = 1;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "iis", &x, &y, &s)) {
        return NULL;
    }

    a = x;
    b = y;

    printf("S compare here: %d", strcmp(s, "calc"));

    if (strcmp(s, "calc") < 1)
        total = a + b;
    else
        total = 129;

    // return PyLong_FromLong(total);
    return PyUnicode_FromFormat("%s", "fromcalc");
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

