# ksGetMacroParamSize - Получить размер памяти параметров указанного макроэлемента

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](ksdocument2d_ksgetmacrowaitdblclickedit.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_ksendobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetMacroParamSize](getmacroparamsize.html).

Синтаксис Automation:

long ksGetMacroParamSize (long ref);

Входной параметр:

ref | \- указатель на макроэлемент.  
---|---  
  
Возвращаемое значение:

размер памяти | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

При ref = 0 выдается размер памяти параметров макроэлемента, редактирование которого производится в данный момент (если таковой имеется).

Подразделы:

(отсутствуют)
