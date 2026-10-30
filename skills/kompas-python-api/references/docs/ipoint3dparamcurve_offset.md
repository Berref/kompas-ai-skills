# Offset - Величина смещения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamCurve ](ipoint3dparamcurve.html) > [IPoint3DParamCurve - свойства ](ipoint3dparamcurve_props.html) |  Scroll [ [ [ ](ipoint3dparamcurve_offsettype.html "К следующему разделу")](ipoint3dparamcurve_props.html "На уровень выше")](ipoint3dparamcurve_direction.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparamcurve.html)

Тип данных: double

Синтаксис Automation:

Offset = iObject.Offset; | Получить свойство ([* ](1.html))  
---|---  
iObject.Offset = Offset; | Установить свойство ([* ](1.html))  
Offset = iObject.GetOffset(); | Получить свойство ([**](2.html))  
iObject.SetOffset( Offset ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Offset( &Offset ); | Получить свойство  
---|---  
iObject->put_Offset( Offset ); | Установить свойство  
  
Примечание:

1.Для типа смещения ksOffsetByU свойство определяет величину смещения в % от длины кривой (0...100).

2.Для типа смещения ksOffsetByLen свойство определяет длину сегмента.

3.Для типа смещения ksOffsetByAngle свойство определяет центральный угол дуги.

Подразделы:

(отсутствуют)
