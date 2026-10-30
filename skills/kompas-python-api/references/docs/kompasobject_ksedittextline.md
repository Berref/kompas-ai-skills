# ksEditTextLine - Вызвать диалог редактирования сложноструктурированного текста

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksexecdialpredefinedtext.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksdrawkompastext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksEditTextLine](ksedittextline.html).

Синтаксис Automation:

BSTR ksEditTextLine (long HWindow, long* res, BSTR str);

Входные параметры:

Hwindow | \- дескриптор окна,  
---|---  
str | \- входная строка текста.  
  
Выходные параметры:

res | \- строка текста.  
---|---  
  
Возвращаемое значение:

1 | \- выход из диалога по кнопке OK,  
---|---  
0 | \- выход из диалога по кнопке Отмена.  
  
Подразделы:

(отсутствуют)
