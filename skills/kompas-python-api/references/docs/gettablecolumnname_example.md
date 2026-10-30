# GetTableName, GetColumnName - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char buf[128],nameOBDC[128]; //имя источника данных

//создать объект, обслуживающий базу данных

reference bd = CreateDB ("ODBC_DB");

if (ConnectDB (bd, nameOBDC)) {

if (GetTableName (bd, buf, 128, 'F')) {

do {

Message(buf);

if (GetColumnName (bd, buf, buf, 128, 'F')) {

do {

Message(buf);

} while (GetColumnName (bd, buf, buf, 128, 'N'));

}

} while (GetTableName (bd, buf, 128, 'N')) ;

}

}
