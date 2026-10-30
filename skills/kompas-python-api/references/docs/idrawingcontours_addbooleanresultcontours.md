# AddBooleanResultContours - Булева операция над замкнутыми и не самопересекающимися кривыми

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IDrawingContours ](idrawingcontours.html) > [IDrawingContours - методы ](idrawingcontours_methods.html) |  Scroll [ [ [ ](idrawingcontours_makeenclosecontours.html "К следующему разделу")](idrawingcontours_methods.html "На уровень выше")](idrawingcontours_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingcontours.html)

Синтаксис Automation:

VARIANT AddBooleanResultContours( IDrawingObject * Contour1,IDrawingObject * Contour2, ksBooleanType BooleanType );

Синтаксис COM:

HRESULT AddBooleanResultContours( IDrawingObject * Contour1,IDrawingObject * Contour2, ksBooleanType BooleanType,VARIANT * Result );

Возвращаемое значение:

| \- Массив контуров [IDrawingContour](idrawingcontour.html) в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Входные параметры:

Contour1 | \- 1-й контур или кривая,  
---|---  
Contour2 | \- 2-й контур или кривая,  
BooleanType | \- тип булевой операции из перечисления [ksBooleanType](ksbooleantype.html).  
  
Метод позволяет выполнять над контурами операции пересечения, вычитания и объединения.

Примечание:

1\. Кривые должны быть замкнутыми и не иметь самопересечений.

2\. Если кривые не подходят или не пересекаются, вернется пустой массив.

3\. Если возвращается один объект, то тип VARIANT будет VT_DISPATCH.

4\. Если возвращается несколько объектов, то тип VARIANT будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
