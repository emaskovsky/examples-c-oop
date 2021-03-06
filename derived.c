
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "derived.h"


IMPLEMENT_CLASS(Derived)


DEFINE_CLASS_CONSTRUCTOR(Derived)(Derived *self, int x, int y)
{
    assert(self != NULL);
    Base_construct((Base *)self, x);
    Object_VT_update(self, &Derived_VT);
    ((Derived_DATA *)&self->data)->y = y;
    return self;
}


IMPLEMENT_DEFAULT_DESTRUCTOR(Derived)
IMPLEMENT_DEFAULT_COPY(Derived)


static void Derived_setX(void *this, int x)
{
    printf("Derived::setX()\n");
    Base_VT.setX(this, x);
}


static int Derived_getX(void *this)
{
    printf("Derived::getX()\n");
    return Base_VT.getX(this);
}


static void Derived_setY(void *this, int y)
{
    printf("Derived::setY()\n");
    ((Derived_DATA *)&((Derived *)this)->data)->y = y;
}


static int Derived_getY(void *this)
{
    printf("Derived::getY()\n");
    return ((Derived_DATA *)&((Derived *)this)->data)->y;
}


IMPLEMENT_CLASS_VTABLE_BEGIN(Derived, Base)
    &Derived_setX,
    &Derived_getX,
    &Derived_setY,
    &Derived_getY
IMPLEMENT_CLASS_VTABLE_END(Derived)
