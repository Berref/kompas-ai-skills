# Offset2 - Величина смещения2

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamSurface ](ipoint3dparamsurface.html) > [IPoint3DParamSurface - свойства ](ipoint3dparamsurface_props.html) |  Scroll [ [ [ ](ipoint3dparamsurface_surfaceobject.html "К следующему разделу")](ipoint3dparamsurface_props.html "На уровень выше")](ipoint3dparamsurface_offset1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparamsurface.html)

Тип данных: double

Синтаксис Automation:

Offset2 = iObject.Offset2; | Получить свойство ([* ](1.html))  
---|---  
iObject.Offset2 = Offset2; | Установить свойство ([* ](1.html))  
Offset2 = iObject.GetOffset2(); | Получить свойство ([**](2.html))  
iObject.SetOffset2( Offset2 ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Offset2( &Offset2 ); | Получить свойство  
---|---  
iObject->put_Offset2( Offset2 ); | Установить свойство  
  
Примечание:

1\. Для типа смещения по параметру U и V (ksOffsetByUV) - свойство 0..100 (величина V в %).

2\. Для типа смещения по расстояниям от плоских объектов (ksOffsetByLenFromObj) - свойство определяет расстояние от плоского объекта 2.

Подразделы:

(отсутствуют)
