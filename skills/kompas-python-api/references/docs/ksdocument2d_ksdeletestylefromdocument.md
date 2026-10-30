# DeleteStyleFromDocument - Удалить стиль из текущего документа

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Стили ](bt1730613.html) |  Scroll [ [ [ ](ksdocument2d_ksaddstyle.html "К следующему разделу")](bt1730613.html "На уровень выше")](bt1730613.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksDeleteStyleFromDocument](ksdeletestylefromdocument.html).

Синтаксис Automation:

long ksDeleteStyleFromDocument (short type,

LPDISPATCH param,

short copy);

Входные параметры:

type | тип стиля,  
---|---  
param | указатель на интерфейс соответствующего типа,  
copy | \- признак используемой структуры стиля: 0 - создать вручную, 1- взять стиль из библиотеки.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

В случае, когда стиль берется из библиотеки, param - указатель на интерфейс [ksLibStyle](kslibstyle.html).

Подразделы:

(отсутствуют)
