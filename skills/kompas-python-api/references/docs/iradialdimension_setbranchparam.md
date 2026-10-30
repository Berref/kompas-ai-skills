# SetBranchParam - Установить параметры ответвления для объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IRadialDimension ](iradialdimension.html) > [IRadialDimension - методы ](iradialdimension_methods.html) |  Scroll [ [ [ ](ibreakradialdimension.html "К следующему разделу")](iradialdimension_methods.html "На уровень выше")](iradialdimension_getbranchparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iradialdimension.html)

Синтаксис Automation:

BOOL SetBranchParam( long Index, double Xc, double Yc, double Angle1, double Angle2, BOOL Direction );

Синтаксис COM:

HRESULT SetBranchParam( long Index, double Xc, double Yc, double Angle1, double Angle2, BOOL Direction, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- номер ответвления,  
---|---  
Xc,Yc | \- координаты центра дуги,  
Radius | \- радиус дуги,  
Angle1 | \- 1-й угол дуги,  
Angle2 | \- 2-й угол дуги,  
Direction | \- направление дуги.  
  
Подразделы:

(отсутствуют)
