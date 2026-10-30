# ksGetToleranceColumnText - Получить текст ячейки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_ksopentable.html "К следующему разделу")](bt1731193.html "На уровень выше")](ksdocument2d_ksgettableitemscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetToleranceColumnText](ksgettolerancecolumntext.html).

Синтаксис Automation:

long ksGetToleranceColumnText (long* numb, LPDISPATCH par);

Выходные параметры:

numb | \- номер ячейки,  
---|---  
par | \- указатель на интерфейс параметров строки текста [ksTextLineParam](kstextlineparam.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция используется в режиме редактирования допуска формы.

Нумерация ячеек начинается с единицы.

Если не определен номер ячейки с помощью функции [ksDocument2D::ksColumnNumber](ksdocument2d_kscolumnnumber.html), метод начинает работу с первой ячейки.

После выполнения метода происходит смещение на следующую ячейку.

Если par=NULL, все графы пройдены.

После использования массив par->pTextItem желательно удалить.

Подразделы:

(отсутствуют)
