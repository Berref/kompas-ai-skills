# ksTolerance - Проставить допуск формы

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Размеры и технологические обозначения ](bt1730488.html) |  Scroll [ [ [ ](ksdocument2d_ksviewpointer.html "К следующему разделу")](bt1730488.html "На уровень выше")](ksdocument2d_ksrough.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [Tolerance](tolerance.html).

Синтаксис Automation:

long ksTolerance (LPDISPATCH par);

Входной параметр:

par | \- указатель на интерфейс допуска формы [ksToleranceParam](kstoleranceparam.html).  
---|---  
  
Возвращаемое значение:

указатель на допуск формы | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Операторы [ksDocument2D::ksColumnNumber](ksdocument2d_kscolumnnumber.html) и [ksDocument2D::ksTextLine](ksdocument2d_kstextline.html), вводимые между операторами [ksDocument2D::ksTolerance ](ksdocument2d_kstolerance.html)и [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), принадлежат допуску формы.

ksColumnNumber определяет номер ячейки, куда помещать текст. Вначале считается, что допуск формы имеет таблицу из 10 колонок и 10 строк. Каждая ячейка таблицы имеет свой номер. Нумерация идет слева направо и сверху вниз.

По завершении создания объекта таблица форматируется, и лишние ячейки удаляются. ksEndObj возвращает указатель на допуск формы.

Подразделы:

(отсутствуют)
