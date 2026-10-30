# Пример

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Для подсчета количества компонентов определенного типа на заданном уровне сборки нужно у интерфейса компонентов [IPart7](ipart7.html) получить список уникальных компонентов с помощью свойства PartsEx[ ( long)ksUniqueParts ]. В списке найденных следует найти нужный компонент и у IPart7 получить количество вставок InstanceCount найденного компонента.

Пример:

if ( newKompasAPI ) // newKompasAPI - интерфейс IApplicationPtr

{

IKompasDocument3DPtr doc3D( newKompasAPI->ActiveDocument );

if ( doc3D )

{

IPart7Ptr topPart ( doc3D->TopPart );

if ( topPart )

{

long count = topPart->GetInstanceCount( NULL ); // Общее количество компонентов

Message( _bstr_t( count) );

_variant_t uniqueParts( topPart->PartsEx[( long)ksUniqueParts] );

if ( uniqueParts.vt == ( VT_ARRAY | VT_DISPATCH ) )

{

int count = uniqueParts.parray->rgsabound[0].cElements - uniqueParts.parray->rgsabound[0].lLbound;

if ( uniqueParts.parray->cDims == 1 )

{

HRESULT hr;

LPDISPATCH HUGEP *pvar;

hr = ::SafeArrayAccessData( uniqueParts.parray, ( void HUGEP* FAR*)&pvar);

if ( !FAILED( hr) && pvar )

{

for ( int i = 0; i < count; i++ )

{

IPart7Ptr obj( pvar[i] );

if ( obj )

{

long count = topPart->GetInstanceCount( obj ); // Количество вставок компонента Obj

Message( _bstr_t( count) );

}

}

hr = ::SafeArrayUnaccessData( uniqueParts.parray);

}

}

}

}

}

}
