# ksIsStyleInDocument - Проверить, существует ли стиль в текущем документе

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Стили ](bt1730613.html) |  Scroll [ [ [ ](bt1730148.html "К следующему разделу")](bt1730613.html "На уровень выше")](ksdocument2d_ksgetstyleparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksIsStyleInDocument](ksisstyleindocument.html).

Синтаксис Automation:

long ksIsStyleInDocument (short type,

LPDISPATCH param,

short copy);

Входные параметры:

type | \- тип стиля,  
---|---  
param | \- указатель на интерфейс соответствующего типа,  
copy | \- признак используемой структуры стиля: 0 - создать вручную, 1- взять стиль из библиотеки.  
  
[Типы стилей и интерфейсы...](sttypes.html)

Возвращаемое значение:

1 | \- стиль в документе есть,  
---|---  
0 | \- стиля в документе нет.  
  
Примечание:

В случае, когда стиль берется из библиотеки, param - указатель на интерфейс [ksLibStyle](kslibstyle.html).

Подразделы:

(отсутствуют)
