# NewConstraint - пример использования при создании ассоциативного размера

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
…

IParametriticConstraintPtr association = dimObj1->NewConstraint();

if ( association )

{

_variant_t partner = CreatePartner( obj1, obj2 ); // obj1, obj2 - объекты с которыми ассоциируем размер

// Создаем ограничение Ассоциативность

association->ConstraintType = ksCAssociation;

association->Partner = partner;

association->Create();

}

...

//-------------------------------------------------------------------------------

// Создать массив SafeArray типа LPDISPATCH

// ---

_variant_t CreatePartner( LPDISPATCH obj1, LPDISPATCH obj2 )

{

_variant_t res;

if ( obj2 )

{

SAFEARRAY * pSANew = NULL;

SAFEARRAYBOUND rgsabound;

rgsabound.lLbound = 0;

rgsabound.cElements = 2; // количество элементов в массиве

pSANew = ::SafeArrayCreate(VT_DISPATCH, 1, &rgsabound);

if ( pSANew )

{

long i1 = 0;

long i2 = 1;

::SafeArrayPutElement( pSANew, &i1, obj1 ); // положить первый объект

::SafeArrayPutElement( pSANew, &i2, obj2 ); // положить второй объект

res.vt = VT_ARRAY | VT_DISPATCH;

V_ARRAY(&res) = pSANew;

}

}

else

{

if ( obj1 )

res = obj1;

}

return res;

}
