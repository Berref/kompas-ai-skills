# Пример использования функции LibCommandState

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//-------------------------------------------------------------------------------

// Состояние команды

// ---

int WINAPI LibCommandState( unsigned int comm, int * enable, int * checked )

{

if ( enable )

{

int type = ksGetDocumentType( 0 );

*enable = type == lt_DocSheetStandart || type == lt_DocFragment || type == lt_DocSheetUser; // Команда доступна в 2D документе

}

return 0;

}
