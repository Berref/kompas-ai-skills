# ksCreateSheetStandartViews - Создать стандартные ассоциативные виды

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Создание видов ](bt1730395.html) |  Scroll [ [ [ ](bt1732273.html "К следующему разделу")](bt1730395.html "На уровень выше")](ksdocument2d_kscreatesheetsectionview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCreateSheetStandartViews](kscreatesheetstandartviews.html).

Синтаксис Automation:

BOOL ksCreateSheetStandartViews (LPDISPATCH par, long bitVector, double dx, double dy);

Входные параметры:

par | \- указатель на интерфейс [ksAssociationViewParam](ksassociationviewparam.html) параметров ассоциативного вида,  
---|---  
bitVector | \- набор [типов](standartviewtypes.html), которые нужно создать,  
dx | \- расстояние между видами по горизонтали,  
dy | \- расстояние между видами по вертикали.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Последний из созданных видов становится текущим.

Подразделы:

(отсутствуют)
