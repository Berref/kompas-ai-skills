# SetBaseObject - Установить базовый объект выноски

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IBranchs ](ibranchs.html) > [IBranchs - методы ](ibranchs_methods.html) |  Scroll [ [ [ ](ibrandleader.html "К следующему разделу")](ibranchs_methods.html "На уровень выше")](ibranchs_getbaseobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs.html)

Синтаксис Automation:

BOOL SetBaseObject( long Index, IDrawingObject * NewObject, long SegmentIndex );

Синтаксис COM:

HRESULT SetBaseObject( long Index, IDrawingObject * NewObject, long SegmentIndex, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс, с которым добавляется ответвление.  
---|---  
NewObject | \- указатель на интерфейс объекта,  
SegmentIndex | \- индекс сегмента.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
