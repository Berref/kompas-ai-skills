# GetMateParams - Получить параметры математических объектов, участвующих в сопряжении

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IMateConstraint3D ](imateconstraint3d.html) > [IMateConstraint3D - методы ](imateconstraint3d_methods.html) |  Scroll [ [ [ ](imate3dbyangle.html "К следующему разделу")](imateconstraint3d_methods.html "На уровень выше")](imateconstraint3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imateconstraint3d.html)

Синтаксис Automation:

ksMateType GetMateParams( long Index, VARIANT * Params );

Синтаксис COM:

HRESULT GetMateParams( long Index, VARIANT * Params, ksMateType * Result );

Возвращаемое значение:

тип математического объекта, участвующего в сопряжении из ksMateType | \- если параметры получены,  
---|---  
ksMateUnknown | \- в случае ошибки.  
  
Входные параметры:

Index | \- индекс объекта.  
---|---  
  
Выходные параметры:

Params | \- параметры объекта массив SafeArray вещественных чисел.  
---|---  
  
Примечание:

1\. Параметры возвращаются в системе координат сборки. При необходимости их можно перевести в систему координат нужного компонента с помощью функции [IPart::TransformPoint](kspart_transformpoint.html).

2\. Геометрический объект для сопряжения описывается набором из 8-ми вещественных чисел, сгруппированных следующим образом:

•три координаты точки Pc, Pc = { pointX, pointY, pointZ },

•три координаты вектора V, V = { vectorI, vectorJ, vectorK },

•две координаты, соответствующие радиусам, V = { vectorI, vectorJ, vectorK }.

Подразделы:

(отсутствуют)
