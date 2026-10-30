# ksClearGroup - Очистить группу объектов

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Группы объектов ](bt1732733.html) |  Scroll [ [ [ ](ksdocument2d_ksendgroup.html "К следующему разделу")](bt1732733.html "На уровень выше")](ksdocument2d_ksaddobjgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksClearGroup](kscleargroup.html).

Синтаксис Automation:

long ksClearGroup (long group, BOOL deleteTmp);

Входные параметры:

group | \- указатель на очищаемую группу (0 - очищается группа селектирования),  
---|---  
deleteTmp | \- признак удаления временных элементов: TRUE - временные элементы удаляются, FALSE - временные элементы сохраняются.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
