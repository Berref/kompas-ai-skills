# ksCreateQualityIterator - Создать итератор для перемещения по квалитетам

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Итератор (Интерфейс ksIterator) ](ksiterator.html) > [ksIterator - методы ](ksiterator_methods.html) |  Scroll [ [ [ ](ksiterator_kscreatespciterator.html "К следующему разделу")](ksiterator_methods.html "На уровень выше")](ksiterator_kscreateiterator.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksiterator.html)

Аналог данного метода при использовании API экспортных функций - [ksCreateQualityIterator](kscreatequalityiterator.html).

Синтаксис Automation:

BOOL ksCreateQualityIterator (short system,

short withLimitation);

Входные параметры:

system | \- система допуска 1 - система отверстия, 0 - система вала,  
---|---  
withLimitation | \- признак учета ограничений, наложенных в системе: 0 - без учёта ограничений, 1 - с учётом ограничений.  
  
Возвращаемое значение:

указатель на итератор | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
