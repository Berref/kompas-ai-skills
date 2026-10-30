# ksConvertLangWindowEx - Конвертировать окно с входящими дочерними окнами в соответствии с текущим словарем

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksconvertlangwindowex2.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksconvertlangwindow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании экспортных функций [ksConvertLangWindowEx](ksconvertlangwindowex.html).

Синтаксис Automation:

BOOL ksConvertLangWindowEx (long hWnd,

long hInstance,

BSTR dlgID);

Входной параметр:

hWnd | \- дескриптор окна,  
---|---  
hInstance | \- HINSTANCE модуля, в котором находится переводимый диалог,  
dlgID | \- имя ресурса диалога.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Функция устарела. Использование данной функции может привести к ошибке в библиотеке, собранной с конфигурацией x64. Рекомендуется использовать функцию [KompasObject::ksConvertLangWindowEx2](kompasobject_ksconvertlangwindowex2.html).

Подразделы:

(отсутствуют)
