# Offset1 - Величина смещения1

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamSurface ](ipoint3dparamsurface.html) > [IPoint3DParamSurface - свойства ](ipoint3dparamsurface_props.html) |  Scroll [ [ [ ](ipoint3dparamsurface_offset2.html "К следующему разделу")](ipoint3dparamsurface_props.html "На уровень выше")](ipoint3dparamsurface_offsettype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparamsurface.html)

Тип данных: double

Синтаксис Automation:

Offset1 = iObject.Offset1; | Получить свойство ([* ](1.html))  
---|---  
iObject.Offset1 = Offset1; | Установить свойство ([* ](1.html))  
Offset1 = iObject.GetOffset1(); | Получить свойство ([**](2.html))  
iObject.SetOffset1( Offset1 ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Offset1( &Offset1 ); | Получить свойство  
---|---  
iObject->put_Offset1( Offset1 ); | Установить свойство  
  
Примечание:

1\. Для типа смещения по параметру U и V (ksOffsetByUV) - свойство 0..100 (величина U в %).

2\. Для типа смещения по расстояниям от плоских объектов (ksOffsetByLenFromObj) - свойство определяет расстояние от плоского объекта 1.

Подразделы:

(отсутствуют)
