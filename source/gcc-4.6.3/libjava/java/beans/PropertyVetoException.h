
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_beans_PropertyVetoException__
#define __java_beans_PropertyVetoException__

#pragma interface

#include <java/lang/Exception.h>
extern "Java"
{
  namespace java
  {
    namespace beans
    {
        class PropertyChangeEvent;
        class PropertyVetoException;
    }
  }
}

class java::beans::PropertyVetoException : public ::java::lang::Exception
{

public:
  PropertyVetoException(::java::lang::String *, ::java::beans::PropertyChangeEvent *);
  virtual ::java::beans::PropertyChangeEvent * getPropertyChangeEvent();
private:
  static const jlong serialVersionUID = 129596057694162164LL;
  ::java::beans::PropertyChangeEvent * __attribute__((aligned(__alignof__( ::java::lang::Exception)))) evt;
public:
  static ::java::lang::Class class$;
};

#endif // __java_beans_PropertyVetoException__
