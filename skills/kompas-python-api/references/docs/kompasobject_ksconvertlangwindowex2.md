# ksConvertLangWindowEx2 - Конвертировать окно в соответствии с текущим словарем

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_kscreateinsertionfragment.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksconvertlangwindowex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании экспортных функций [ksConvertLangWindowEx](ksconvertlangwindowex.html).

Синтаксис Automation:

BOOL ksConvertLangWindowEx2(long hWnd, VARIANT hInstance, BSTR dlgID);

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

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данную функцию вместо [KompasObject::ksConvertLangWindowEx](kompasobject_ksconvertlangwindowex.html).

Подразделы:

(отсутствуют)
