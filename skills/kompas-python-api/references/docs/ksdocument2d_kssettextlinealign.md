# ksSetTextLineAlign - Установить выравнивание текста

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Текстовые надписи ](bt1731191.html) |  Scroll [ [ [ ](ksdocument2d_kssettablecolumntext.html "К следующему разделу")](bt1731191.html "На уровень выше")](ksdocument2d_kssettextalign.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksSetTextLineAlign](kssettextlinealign.html).

Синтаксис Automation:

int ksSetTextLineAlign (short align);

Входной параметр:

align | \- признак выравнивания: 0 - по левому краю, 1 - по центру, 2 - по правому краю, 3 - по ширине.  
---|---  
  
Возвращаемое значение:

предыдущий признак выравнивания | \- в случае успешного завершения,  
---|---  
-1 | \- в случае неудачи.  
  
Примечание.

Функция [ksDocument2D::ksSetTextLineAlign](ksdocument2d_kssettextlinealign.html) должна использоваться внутри блока, т.е. необходимо, чтобы был открытый на редактирование текст. Иначе функция не работает.

Подразделы:

(отсутствуют)
