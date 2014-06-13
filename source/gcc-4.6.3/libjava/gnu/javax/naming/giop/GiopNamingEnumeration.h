
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_naming_giop_GiopNamingEnumeration__
#define __gnu_javax_naming_giop_GiopNamingEnumeration__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace naming
      {
        namespace giop
        {
            class GiopNamingEnumeration;
        }
      }
    }
  }
  namespace org
  {
    namespace omg
    {
      namespace CosNaming
      {
          class Binding;
          class BindingIterator;
          class BindingIteratorHolder;
          class BindingListHolder;
      }
    }
  }
}

class gnu::javax::naming::giop::GiopNamingEnumeration : public ::java::lang::Object
{

public: // actually package-private
  GiopNamingEnumeration(::org::omg::CosNaming::BindingListHolder *, ::org::omg::CosNaming::BindingIteratorHolder *, jint);
public:
  virtual ::java::lang::Object * convert(::org::omg::CosNaming::Binding *) = 0;
  virtual void close();
  virtual jboolean hasMore();
  virtual ::java::lang::Object * next();
  virtual jboolean hasMoreElements();
  virtual ::java::lang::Object * nextElement();
public: // actually package-private
  virtual jboolean getMore();
  JArray< ::org::omg::CosNaming::Binding * > * __attribute__((aligned(__alignof__( ::java::lang::Object)))) list;
  ::org::omg::CosNaming::BindingIterator * iterator;
  jint batch;
  jint p;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_naming_giop_GiopNamingEnumeration__
