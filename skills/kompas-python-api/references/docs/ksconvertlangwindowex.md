# ksConvertLangWindowEx - Конвертировать окно с входящими дочерними окнами в соответствии с текущим словарем

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](ksconvertlangwindowexw.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksconvertlangwindow.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksConvertLangWindowEx](kompasobject_ksconvertlangwindowex.html).

Синтаксис:

int ksConvertLangWindowEx (HWND hWnd,

HINSTANCE hInstance,

char* dlgID);

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

При использовании Unicode следует использовать функцию [ksConvertLangWindowExW](ksconvertlangwindowexw.html).

Подразделы:

(отсутствуют)
