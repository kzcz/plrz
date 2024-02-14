#include <Python.h>
#include <string.h>
#define ui unsigned int
ui u(ui n){return 411849*n+20857;}
ui v(ui n){return (987*n*n+37*n+3811727);}
ui q(ui n){return (13*n+7);}
void mix(ui *a,ui *b, ui *c){
	ui x=u(*a);ui y=v(*b);ui z=q(*c);
	x=v(v(x)*x);
	y=q(q(y)*y);
	z=u(u(z)*z);
	*a=y*z;*b=x*z;*c=x*y;
	}
char * pzash(char *str){
	int l=0;
	while(*(str+l)){l++;}
	char *mem=malloc(32);
	for(char c=0;c<32;c++){
		*(mem+c)=0;
		}
    memcpy(mem,str,l>32?32:l);
    if(l>32){
        for(char w=0;w<l-32;w++){
            *(mem+(w)%32)=*(str+w)^*(mem+(w)%32);
            }
        }
	ui *a,*b;a=(ui *)(mem+4);b=(ui *)(mem+28);
	for(;a!=b;){mix((ui*)mem,a,b);a++;b--;}
	for(a=(ui*)mem;a!=(ui*)(mem+28);a++){
		mix(a,a+1,a+2);
		}
	for(;a!=(ui*)(mem+28);){mix((ui*)mem,a,(ui*)(mem+4));a++;}
	for(a=(ui*)mem;a!=(ui*)(mem+28);a++){
		mix(a+2,a+1,a);
		}
	return mem;
	}
static PyObject * hash(PyObject *sf,PyObject *arg){
    if(!PyBytes_Check(arg)){PyErr_SetString(PyExc_TypeError,"Expected bytes.");return NULL;}
char *imp=PyBytes_AsString(arg);
imp=pzash(imp);
PyObject *ret=PyBytes_FromStringAndSize(imp,32);
free(imp);
return ret;
}
static PyMethodDef methods[] = {
    {"hash", hash,8, ""},
    {NULL, NULL, 0, NULL}
};
static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "plrz",
    "",
    -1,
    methods
};
PyMODINIT_FUNC PyInit_plrz(void) {
    return PyModule_Create(&module);
}