# ksGetStyleParam - Получить параметры стиля из документа

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Стили ](bt1730613.html) |  Scroll [ [ [ ](ksdocument2d_ksisstyleindocument.html "К следующему разделу")](bt1730613.html "На уровень выше")](ksdocument2d_ksaddstyle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetStyleParam](getstyleparam.html).

Синтаксис Automation:

long ksGetStyleParam (short type, short styleId, LPDISPATCH param);

Входные параметры:

type | \- тип стиля,  
---|---  
styleId | \- номер стиля,  
param | \- указатель на интерфейс соответствующего типа.  
  
[Типы стилей и интерфейсы...](sttypes.html)

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

В случае неудачи структура param заполняется параметрами стиля по умолчанию.

Подразделы:

(отсутствуют)
