# GetAreaEx - Получить площадь грани

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IFace ](iface.html) > [IFace - методы ](iface_methods.html) |  Scroll [ [ [ ](iface_getconeparam.html "К следующему разделу")](iface_methods.html "На уровень выше")](iface_getarea.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iface.html)

Синтаксис Automation:

double GetAreaEx( ksLengthUnitsEnum Unit, double AngleTolerance );

Синтаксис COM:

HRESULT GetAreaEx( ksLengthUnitsEnum Unit, double AngleTolerance, double * Result );

Входные параметры:

Unit | \- единицы измерения длины из перечисления [ksLengthUnitsEnum](kslengthunitsenum.html),  
---|---  
AngleTolerance | \- ограничение углового отклонения при аппроксимации оболочки треугольными пластинами.  
  
Компас Версия v21

Подразделы:

(отсутствуют)
