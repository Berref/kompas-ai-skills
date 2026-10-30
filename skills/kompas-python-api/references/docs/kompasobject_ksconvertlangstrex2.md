# ksConvertLangStrEx2 - Конвертировать строку в соответствии с текущим словарем

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksconvertlangwindow.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksconvertlangstrex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании экспортных функций [ksConvertLangStrEx](ksconvertlangstrex.html).

Синтаксис Automation:

BSTR ksConvertLangStrEx2( VARIANT hInstance, long strID );

Входные параметры:

hInstance | \- HINSTANCE модуля, в котором находится переводимая строка,  
---|---  
strID | \- идентификатор строки.  
  
Возвращаемое значение:

| \- переведенная строка.  
---|---  
  
Примечание:

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данную функцию вместо [KompasObject::ksConvertLangStrEx](kompasobject_ksconvertlangstrex.html).

Подразделы:

(отсутствуют)
