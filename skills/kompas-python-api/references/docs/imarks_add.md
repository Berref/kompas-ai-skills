# Add - Создать марку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarks ](imarks.html) > [IMarks - методы ](imarks_methods.html) |  Scroll [ [ [ ](icutunitmarkings.html "К следующему разделу")](imarks_methods.html "На уровень выше")](imarks_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarks.html)

Синтаксис Automation:

LPDISPATH Add( DrawingObjectTypeEnum MarkType );

Синтаксис COM:

HRESULT Add([in] DrawingObjectTypeEnum MarkType,

[out, retval] IMark** Result);

Входные параметры:

MarkType | \- тип объекта из перечисления [DrawingObjectTypeEnum](objtypes.html).  
---|---  
  
Возможные значения MarkType

ksDrMarkOnLeader | 52 | [IMarkOnLeader](imarkonleader.html) \- Марка/позиционное обозначение с линией-выноской.  
---|---|---  
ksDrMarkOnLine | 53 | [IMarkOnLine](imarkonline.html) \- Марка/позиционное обозначение на линии.  
ksDrMarkInsideForm | 54 | [IMarkInsideForm](imarkinsideform.html) \- Марка/позиционное обозначение без линии-выноски.  
  
Возвращаемое значение:

Result | \- указатель на базовый интерфейс для марок [IMark](imark.html).  
---|---  
  
Примечание:

Метод позволяет создать новый интерфейс марки. После получения нового интерфейса нужно задать параметры марки и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
