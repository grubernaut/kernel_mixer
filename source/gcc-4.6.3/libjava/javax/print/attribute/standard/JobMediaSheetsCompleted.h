
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_print_attribute_standard_JobMediaSheetsCompleted__
#define __javax_print_attribute_standard_JobMediaSheetsCompleted__

#pragma interface

#include <javax/print/attribute/IntegerSyntax.h>
extern "Java"
{
  namespace javax
  {
    namespace print
    {
      namespace attribute
      {
        namespace standard
        {
            class JobMediaSheetsCompleted;
        }
      }
    }
  }
}

class javax::print::attribute::standard::JobMediaSheetsCompleted : public ::javax::print::attribute::IntegerSyntax
{

public:
  JobMediaSheetsCompleted(jint);
  jboolean equals(::java::lang::Object *);
  ::java::lang::Class * getCategory();
  ::java::lang::String * getName();
private:
  static const jlong serialVersionUID = 1739595973810840475LL;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_print_attribute_standard_JobMediaSheetsCompleted__
