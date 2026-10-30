# Пример описания ресурсов

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
#define END_OF_STRING_RESOURCE_TABLE 0

#define END_OF_RESOURCE_TABLE 0xffff

#define ID_PROP_ELEMENT_PARAM 20000 // Группа параметры элемента

#define PROP_DOUBLE_LIST 20001 // Cписок вещественных значений

#define PROP_INT_LIST 20002 // Cписок целых значений

#define PROP_STRING_LIST 20003 // Cписок строк

#define ID_PROP_VIEW 20004 // Вид

STRINGTABLE DISCARDABLE

BEGIN

ID_PROP_ELEMENT_PARAM "Параметры элемента"

PROP_DOUBLE_LIST "Cписок вещественных значений"

PROP_INT_LIST "Cписок целых значений"

PROP_STRING_LIST "Cписок строк"

END

Для фиксированного списка вещественных значений:

PROP_DOUBLE_LIST RCDATA

{

L"1.0\0"

L"2.0\0"

L"3.0\0"

L"4.0\0"

L"5.0\0"

END_OF_STRING_RESOURCE_TABLE

}

Для фиксированного списка целых значений:

PROP_INT_LIST RCDATA

{

L"1\0"

L"2\0"

L"3\0"

L"4\0"

L"5\0"

END_OF_STRING_RESOURCE_TABLE

}

Для фиксированного списка строк:

PROP_STRING_LIST RCDATA

{

L"Первая строка\0"

L"Вторая строка\0"

L"Третья строка\0"

END_OF_STRING_RESOURCE_TABLE

}

Пример описания ресурсов для списка битмапов ksOPControlListBmp:

#define IDB_ID_VIEW 1101 // ID_VIEW - Вид

#define IDB_ID_VIDSEC 1102 // ID_VIDSEC - Вид разрез

#define IDB_ID_TOPVID 1103 // ID_TOP - Вид сверху

#define IDB_ID_SIDEVID 1111 // ID_SIDE - Вид сбоку

IDB_ID_VIEW ICON DISCARDABLE "res\\\G_VIEW.ico"

IDB_ID_TOPVID ICON DISCARDABLE "res\\\G_TOP.ico"

IDB_ID_SIDEVID ICON DISCARDABLE "res\\\G_LEFT.ico"

IDB_ID_VIDSEC ICON DISCARDABLE "res\\\G_SEC.ico"

STRINGTABLE DISCARDABLE

BEGIN

ID_PROP_VIEW "Вид"

IDB_ID_VIEW "Вид"

IDB_ID_TOPVID "Вид сверху"

IDB_ID_SIDEVID "Вид сбоку"

IDB_ID_VIDSEC "Вид\\\разрез"

END

// Список значений

ID_PROP_VIEW RCDATA

{

IDB_ID_VIEW

IDB_ID_TOPVID

IDB_ID_SIDEVID

IDB_ID_VIDSEC

END_OF_RESOURCE_TABLE

}
