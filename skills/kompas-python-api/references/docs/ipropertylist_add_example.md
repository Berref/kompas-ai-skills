# Пример передачи в список массива

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
long varsCount = 100;

// Массив для наполнения комбобокса

SAFEARRAYBOUND sabNewArray;

sabNewArray.cElements = varsCount;

sabNewArray.lLbound = 0;

SAFEARRAY * pSafe = ::SafeArrayCreate( VT_R8, 1, &sabNewArray );

if( pSafe )

{

for ( long j = 0; j < varsCount; j++ )

{

double val = j * 0.5;

::SafeArrayPutElement( pSafe, &j, &val);

}

_variant_t varArr;

varArr.vt = VT_ARRAY | VT_R8;

varArr.parray = pSafe;

// Передадим массив значений в контрол

dt->Add( varArr );

\---
