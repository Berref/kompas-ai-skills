# IsGeomObject - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference itAllObj = CreateIterator( ALL_OBJ, //тип поиска объекта

0 ); //указатель на объект (для движения по группе и внутри макро)

if ( itAllObj ) {

reference obj;

if ( ExistObj( obj = MoveIterator( itAllObj, 'F' )) ){

do {

// проверим геометрический объект или нет

if ( IsGeomObject(obj) )

Message( "геометрический объект" );

// проверим кому принадлежит объект

if ( IsObjFromAssociativeView(obj) )

Message( "Объект из ассоциативного вида" );

// подсветим все объекты имеющие видимые и невидимые участки

if ( IsVisibleOrHiddenArraysInObject(obj) )

LightObj( obj, 1 );

} while( ExistObj ( obj = MoveIterator( itAllObj, 'N' )) );

}

}
