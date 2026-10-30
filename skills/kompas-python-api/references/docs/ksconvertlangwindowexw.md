# ksConvertLangWindowExW - Конвертировать окно с входящими дочерними окнами в соответствии с текущим словарем (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](ksexecutelibrarycommand.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksconvertlangwindowex.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksConvertLangWindowEx](kompasobject_ksconvertlangwindowex.html).

Синтаксис:

int LIB_FUNC ksConvertLangWindowExW (HWND hWnd,

HINSTANCE hInstance,

LPWSTR dlgID);

Входные параметры:

hWnd | \- дескриптор окна,  
---|---  
hInstance | \- HINSTANCE модуля, в котором находится переводимый диалог,  
dlgID | \- имя ресурса диалога.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksConvertLangWindowEx](ksconvertlangwindowex.html).

Подразделы:

(отсутствуют)
