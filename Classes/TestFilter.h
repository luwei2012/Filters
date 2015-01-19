//
//  TestFilter.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-17.
//
//

#ifndef __MyPlane__TestFilter__
#define __MyPlane__TestFilter__

#include "Filter.h"

class TestFilter : public Filter
{
public:
    TestFilter();
    
private:
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
};

REGISTER_CLASS(Filter,TestFilter);

#endif /* defined(__MyPlane__TestFilter__) */
