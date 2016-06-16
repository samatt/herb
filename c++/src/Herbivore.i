%module Herbivore
%include "std_string.i"
%include "std_vector.i"


// Instantiate templates used by example
namespace std {
   %template(IntVector) vector<int>;
   %template(DoubleVector) vector<double>;
   %template(StringVector) vector<string>;
   %template(ConstCharVector) vector<const char*>;
}

%{
#include "Interface.h"
#include "HerbivoreUtils.h"
%}

%include "Interface.h"
%include "HerbivoreUtils.h"



