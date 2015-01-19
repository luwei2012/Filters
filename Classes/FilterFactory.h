//
//  FilterFactory.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-17.
//
//

#ifndef MyPlane_FilterFactory_h
#define MyPlane_FilterFactory_h
#include <stdio.h>
#include <map>
using namespace std;


#define REGISTER_CLASS(BASE_CLASS, DERIVED_CLASS) RegisterInpFactory<BASE_CLASS, DERIVED_CLASS> Register##DERIVED_CLASS(#DERIVED_CLASS)
#define CREATE_CLASS(BASE_CLASS, DERIVED_CLASS) FilterFactory<BASE_CLASS>::instance().Create(DERIVED_CLASS)


template <class ManufacturedType, typename ClassIDKey=string>
class FilterFactory
{
    typedef ManufacturedType* (*BaseCreateFn)();
    
    typedef map<ClassIDKey, BaseCreateFn> FnRegistry;
    
    FnRegistry registry;
    
    FilterFactory(){}
    
    FilterFactory(const FilterFactory&)  {}  // 没有实现
    
    FilterFactory &operator=(const FilterFactory&) {} // 没有实现
    
public:
    static FilterFactory& instance()
    {
        static FilterFactory<ManufacturedType,ClassIDKey> bf;
        return bf;
    }
    
    void RegCreateFn(const ClassIDKey &classname, BaseCreateFn fn)
    {
        registry[classname] = fn;
    }
    
    ManufacturedType* Create(const ClassIDKey &classname) const
    {
        ManufacturedType* theObject=NULL;
        typename FnRegistry::const_iterator regEntry = registry.find(classname);
        if (regEntry != registry.end())
        {
            theObject = regEntry->second();
        }
        return theObject;
    }
};

template <class AncestorType, class ManufacturedType, typename ClassIDKey=string>
class RegisterInpFactory
{
public:
    static AncestorType* CreateInstance()
    {
        return (new ManufacturedType);
    }
    RegisterInpFactory(const ClassIDKey &id)
    {
        FilterFactory<AncestorType,ClassIDKey>::instance().RegCreateFn(id, CreateInstance);
    }
};


#endif
