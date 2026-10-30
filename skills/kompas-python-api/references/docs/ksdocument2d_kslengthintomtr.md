# ksLengthIntoMtr - Пересчитать длину из системы координат вида в локальную СК

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksmakeenclosecontours.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kslengthfrommtr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksLengthIntoMtr](kslengthintomtr.html).

Синтаксис Automation:

long ksLengthIntoMtr (double* len);

Входной и Выходной параметр:

len | \- длина.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Параметр len является одновременно и входным, и выходным. На входе он представляет собой длину в СК вида, а в результате работы функции преобразуется в длину в локальной СК.

Подразделы:

(отсутствуют)
