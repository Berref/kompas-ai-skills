# ksColouringEx - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double x = 0; double y = 0;

// Указать точку в замкнутой области

if ( Cursor( NULL, &x, &y, NULL ) ) {

// Создать контур из объектов окружающих данную точку

reference group = ksMakeEncloseContours( 0, x, y );

if ( group ) {

// Создать заливку для группы

ksColouringEx( RGB(255, 0, 0), group );

// Удалить временную группу

DeleteObj( group );

}

}
