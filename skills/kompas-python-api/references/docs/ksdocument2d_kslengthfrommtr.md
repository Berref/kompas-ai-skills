# ksLengthFromMtr - Пересчитать длину из локальной системы координат в СК вида

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kslengthintomtr.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksisslavespcopened.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций -[ ksLengthFromMtr](kslengthfrommtr.html).

Синтаксис Automation:

long ksLengthFromMtr (double* len);

Входной и Выходной параметр:

len | \- длина.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Параметр len является одновременно и входным, и выходным. На входе он представляет собой длину в локальной СК, а в результате работы функции преобразуется в длину в СК вида.

Подразделы:

(отсутствуют)
