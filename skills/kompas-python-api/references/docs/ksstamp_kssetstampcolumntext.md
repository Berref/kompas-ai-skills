# ksSetStampColumnText - Задать текст в ячейке

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Основная надпись (Интерфейс ksStamp) ](ksstamp.html) > [ksStamp - методы ](ksstamp_methods.html) |  Scroll [ [ [ ](ksstamp_kssettextlinealign.html "К следующему разделу")](ksstamp_methods.html "На уровень выше")](ksstamp_ksopenstamp.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksstamp.html)

Аналог данного метода при использовании API экспортных функций - [SetStampColumnText](setstampcolumntext.html).

Синтаксис Automation:

long ksSetStampColumnText (long numb,

LPDISPATCH textArr);

Входные параметры:

numb | \- номер ячейки основной надписи,  
---|---  
textArr | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) строк текста типа TEXT_LINE_ARR.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод используется в режиме редактирования штампа.

Подразделы:

(отсутствуют)
