# ksAddStyle - Добавить в документ новый стиль

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Стили ](bt1730613.html) |  Scroll [ [ [ ](ksdocument2d_ksgetstyleparam.html "К следующему разделу")](bt1730613.html "На уровень выше")](ksdocument2d_ksdeletestylefromdocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [AddStyle](addstyle.html).

Синтаксис Automation:

long ksAddStyle (short type, LPDISPATCH param, short copy);

Входные параметры:

type | тип стиля,  
---|---  
param | указатель на интерфейс соответствующего типа,  
copy | \- признак создания стиля: 0 - создать вручную, 1- взять стиль из библиотеки.  
  
[Типы стилей и интерфейсы...](sttypes.html)

Возвращаемое значение:

идентификатор стиля | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. В настоящее время метод реализован для стилей кривых, текстов и штриховок.

2\. При копировании стиля из библиотеки param - указатель на интерфейс [ksLibStyle](kslibstyle.html).

Подразделы:

(отсутствуют)
