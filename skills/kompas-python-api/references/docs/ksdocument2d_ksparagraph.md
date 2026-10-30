# ksParagraph - Начать параграф

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Текстовые надписи ](bt1731191.html) |  Scroll [ [ [ ](ksdocument2d_ksreadtablefromfile.html "К следующему разделу")](bt1731191.html "На уровень выше")](ksdocument2d_ksgettextlengthfromreference.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [Paragraph](paragraph.html).

Синтаксис Automation:

long ksParagraph (LPDISPATCH param);

Входной параметр:

param | \- указатель на интерфейс [ksParagraphParam](ksparagraphparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Параграф - составной объект.

2\. Объекты [ksDocument2D::ksTextLine](ksdocument2d_kstextline.html), вводимые между методами [ksDocument2D::ksParagraph](ksdocument2d_ksparagraph.html) и [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), принадлежат параграфу.

3\. Параграф может состоять из нескольких строк, строки могут состоять из нескольких компонент. Компоненты могут изменять параметры текущего шрифта.

4\. ksDocument2D::ksEndObj возвращает указатель на параграф.

Подразделы:

(отсутствуют)
