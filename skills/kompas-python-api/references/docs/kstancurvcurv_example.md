# ksTanCurvCurv - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double x = 0, y = 0;

if ( Cursor( NULL, &x, &y, NULL) )

{

reference obj1 = FindObj( x, y, ::ksGetCursorLimit() );

if ( obj1 )

{

if ( Cursor( NULL, &x, &y, NULL) )

{

reference obj2 = FindObj( x, y, ::ksGetCursorLimit() );

if ( obj2 && obj2 != obj1 )

{

reference pointArr1 = CreateArray( POINT_ARR, NULL );

reference pointArr2 = CreateArray( POINT_ARR, NULL );

if ( pointArr1 && pointArr2 )

{

int res = ksTanCurvCurv( obj1, obj2, pointArr1, pointArr2 );

if ( res == 1 )

{

int count = GetArrayCount( pointArr1 );

for ( int i = 0; i < count; i )

{

MathPointParam point1;

MathPointParam point2;

GetArrayItem( pointArr1, i, &point1, sizeof(MathPointParam) );

GetArrayItem( pointArr2, i, &point2, sizeof(MathPointParam) );

LineSeg( point1.x, point1.y, point2.x, point2.y, 1 );

}

}

}

DeleteArray( pointArr1 );

DeleteArray( pointArr2 );

}

}

}

}
